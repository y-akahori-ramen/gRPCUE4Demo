package service

import (
	"context"
	"fmt"
	"log"
	"os"

	"github.com/y-akahori-ramen/gRPCUE4Demo/server/proto"
)

type UnaryDemoServiceServer struct {
	logger *log.Logger
	proto.UnimplementedUnaryDemoServiceServer
}

func NewUnaryDemoService() *UnaryDemoServiceServer {
	return &UnaryDemoServiceServer{logger: log.New(os.Stdout, "UnaryDemo", log.Default().Flags())}
}

func (server *UnaryDemoServiceServer) Request(_ context.Context, req *proto.UnaryDemoRequest) (*proto.UnaryDemoResponse, error) {
	server.logger.Printf("Receive: %+v", req)
	return &proto.UnaryDemoResponse{Message: fmt.Sprintf("Hello %v.", req.Name)}, nil
}
