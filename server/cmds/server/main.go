package main

import (
	"flag"
	"fmt"
	"log"
	"net"
	"os"
	"os/signal"
	"sync"
	"syscall"

	"github.com/y-akahori-ramen/gRPCUE4Demo/server/proto"
	"github.com/y-akahori-ramen/gRPCUE4Demo/server/service"
	"google.golang.org/grpc"
)

func main() {
	port := flag.Int("port", 8080, "server port. default 8080")
	flag.Parse()

	grpcServer := grpc.NewServer()

	unaryDemoService := service.NewUnaryDemoService()
	proto.RegisterUnaryDemoServiceServer(grpcServer, unaryDemoService)

	log.Printf("Start server. port:%d", *port)
	listener, err := net.Listen("tcp", fmt.Sprintf(":%d", *port))
	if err != nil {
		log.Fatal("Fail to start server.")
	}

	sigChan := make(chan os.Signal, 1)
	signal.Notify(sigChan, syscall.SIGINT, syscall.SIGTERM)
	var wg sync.WaitGroup
	wg.Add(1)
	go func() {
		defer wg.Done()
		<-sigChan
		grpcServer.GracefulStop()
	}()

	grpcServer.Serve(listener)
	if err := grpcServer.Serve(listener); err != nil {
		if err != grpc.ErrServerStopped {
			log.Fatalf("Fail to start serve. %v", err.Error())
		}
	}

	wg.Wait()
}
