modulename = github.com/y-akahori-ramen/gRPCUE4Demo/server
go_out = ../server/proto
cpp_out = ../gRPCDemoProject/Source/gRPCDemoProject/proto

# protoファイルからC++とGoのコードを生成する。UnrealEngineはWindows環境での開発を想定しているためCRLFに改行コードを変換させる
# また、C++の警告とエラー抑制のためC++のソースはTHIRD_PARTY_INCLUDES_START~THIRD_PARTY_INCLUDES_ENDで囲い、C4125,C4005を追加で無効にする
generate:
	rm -f  $(go_out)/*
	rm -f  $(cpp_out)/*
	protoc --proto_path . ./*.proto --cpp_out=$(cpp_out) --grpc_out=$(cpp_out) --plugin=protoc-gen-grpc=`which grpc_cpp_plugin`
	protoc --proto_path . ./*.proto --go_out=$(go_out) --go-grpc_out=$(go_out) --go_opt=module=$(modulename) --go-grpc_opt=module=$(modulename) 
	find $(cpp_out) -type f | xargs -n 10 sed -e "1i #pragma warning (disable : 4125)" -i
	find $(cpp_out) -type f | xargs -n 10 sed -e "1i #pragma warning (disable : 4005)" -i
	find $(cpp_out) -type f | xargs -n 10 sed -e "1i THIRD_PARTY_INCLUDES_START" -i
	find $(cpp_out) -type f | xargs -n 10 sed -e "$$ a THIRD_PARTY_INCLUDES_END" -i
	find $(cpp_out) -type f | xargs -n 10 nkf -Lw --overwrite