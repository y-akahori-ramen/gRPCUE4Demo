package service

import (
	"io"
	"log"
	"os"
	"path/filepath"

	"github.com/y-akahori-ramen/gRPCUE4Demo/server/proto"
	"google.golang.org/grpc/codes"
	"google.golang.org/grpc/status"
)

type ServerStreamingDemoServiceServer struct {
	logger       *log.Logger
	resourceRoot string
	proto.UnimplementedServerStreamingDemoServiceServer
}

func NewServerStreamingDemoServiceServer(resourceRoot string) *ServerStreamingDemoServiceServer {
	return &ServerStreamingDemoServiceServer{logger: log.New(os.Stdout, "[ServerStreamingDemo]", log.Default().Flags()), resourceRoot: resourceRoot}
}

func (server *ServerStreamingDemoServiceServer) GetTexture(
	req *proto.GetServerStreamingTextureRequest,
	stream proto.ServerStreamingDemoService_GetTextureServer) error {

	path := filepath.Join(server.resourceRoot, req.GetImageName())
	file, err := os.Open(path)
	if err != nil {
		server.logger.Print(err)
		return status.Error(codes.InvalidArgument, err.Error())
	}
	defer file.Close()

	const bufferSize int = 1024
	buffer := make([]byte, bufferSize)
	totalSize := 0

	server.logger.Printf("Start sending texture data. %v", path)
	for {

		n, err := file.Read(buffer)
		if err == io.EOF {
			break
		} else if err != nil {
			return status.Errorf(codes.Internal, "unexpected error:%v ", err)
		}

		stream.Send(&proto.GetServerStreamingTextureResponse{Chunk: buffer[:n]})
		totalSize += n
		server.logger.Printf("Send texture data. %v byte", totalSize)
	}
	server.logger.Printf("Complete sending texture data. %v", path)
	return nil
}
