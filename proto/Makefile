modulename = github.com/y-akahori-ramen/gRPCUE4Demo

generate:
	protoc  -I . --cpp_out=. test.proto
	protoc  -I . --go_out=. --go-grpc_out=. --go_opt=module=$(modulename) --go-grpc_opt=module=$(modulename) test.proto