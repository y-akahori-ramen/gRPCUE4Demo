package service

import (
	"bytes"
	"io"
	"log"
	"os"
	"path/filepath"

	"github.com/y-akahori-ramen/gRPCUE4Demo/server/proto"
	"google.golang.org/grpc/codes"
	"google.golang.org/grpc/status"
)

type ClientStreamingDemoServiceServer struct {
	logger     *log.Logger
	uploadRoot string
	proto.UnimplementedClinentStreamingDemoServiceServer
}

func NewClientStreamingDemoServiceServer(uploadRoot string) *ClientStreamingDemoServiceServer {
	return &ClientStreamingDemoServiceServer{logger: log.New(os.Stdout, "[ClientStreamingDemo]", log.Default().Flags()), uploadRoot: uploadRoot}
}

func (server *ClientStreamingDemoServiceServer) UploadTexture(stream proto.ClinentStreamingDemoService_UploadTextureServer) error {
	// 最初に保存する名前が入っている前提
	req, err := stream.Recv()
	if err != nil {
		return status.Errorf(codes.Unknown, "receive data error: %v", err)
	}
	imageName := req.GetImageName()
	if imageName == "" {
		return status.Error(codes.InvalidArgument, "invalid imageName")
	}

	server.logger.Printf("Start recieve texture data. %v", imageName)

	// 次から保存するテクスチャデータが送られてくる
	imageData := bytes.Buffer{}

	for {
		req, err := stream.Recv()
		if err == io.EOF {
			break
		}
		if err != nil {
			return status.Errorf(codes.Unknown, "receive data error: %v", err)
		}

		chunk := req.GetChunk()
		size := len(chunk)

		server.logger.Printf("recceived data size: %d", size)

		_, err = imageData.Write(chunk)
		if err != nil {
			return status.Errorf(codes.Internal, "cannnot write data: %v", err)
		}
	}

	path := filepath.Join(server.uploadRoot, imageName)
	imageFile, err := os.Create(path)
	if err != nil {
		return status.Errorf(codes.Internal, "create file error: %v", err)
	}
	defer imageFile.Close()

	imageFileSize, err := imageFile.Write(imageData.Bytes())
	if err != nil {
		return status.Errorf(codes.Internal, "%v", err)
	}

	return stream.SendAndClose(&proto.UploadClientTextureResponse{Size: uint32(imageFileSize)})
}
