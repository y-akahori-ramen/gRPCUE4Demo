THIRD_PARTY_INCLUDES_START
#pragma warning (disable : 4005)
#pragma warning (disable : 4125)
// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: clientStreamingDemo.proto

#include "clientStreamingDemo.pb.h"
#include "clientStreamingDemo.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace grpcDemo {

static const char* ClinentStreamingDemoService_method_names[] = {
  "/grpcDemo.ClinentStreamingDemoService/UploadTexture",
};

std::unique_ptr< ClinentStreamingDemoService::Stub> ClinentStreamingDemoService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< ClinentStreamingDemoService::Stub> stub(new ClinentStreamingDemoService::Stub(channel, options));
  return stub;
}

ClinentStreamingDemoService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_UploadTexture_(ClinentStreamingDemoService_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::CLIENT_STREAMING, channel)
  {}

::grpc::ClientWriter< ::grpcDemo::UploadClientTextureRequest>* ClinentStreamingDemoService::Stub::UploadTextureRaw(::grpc::ClientContext* context, ::grpcDemo::UploadClientTextureResponse* response) {
  return ::grpc::internal::ClientWriterFactory< ::grpcDemo::UploadClientTextureRequest>::Create(channel_.get(), rpcmethod_UploadTexture_, context, response);
}

void ClinentStreamingDemoService::Stub::async::UploadTexture(::grpc::ClientContext* context, ::grpcDemo::UploadClientTextureResponse* response, ::grpc::ClientWriteReactor< ::grpcDemo::UploadClientTextureRequest>* reactor) {
  ::grpc::internal::ClientCallbackWriterFactory< ::grpcDemo::UploadClientTextureRequest>::Create(stub_->channel_.get(), stub_->rpcmethod_UploadTexture_, context, response, reactor);
}

::grpc::ClientAsyncWriter< ::grpcDemo::UploadClientTextureRequest>* ClinentStreamingDemoService::Stub::AsyncUploadTextureRaw(::grpc::ClientContext* context, ::grpcDemo::UploadClientTextureResponse* response, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncWriterFactory< ::grpcDemo::UploadClientTextureRequest>::Create(channel_.get(), cq, rpcmethod_UploadTexture_, context, response, true, tag);
}

::grpc::ClientAsyncWriter< ::grpcDemo::UploadClientTextureRequest>* ClinentStreamingDemoService::Stub::PrepareAsyncUploadTextureRaw(::grpc::ClientContext* context, ::grpcDemo::UploadClientTextureResponse* response, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncWriterFactory< ::grpcDemo::UploadClientTextureRequest>::Create(channel_.get(), cq, rpcmethod_UploadTexture_, context, response, false, nullptr);
}

ClinentStreamingDemoService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ClinentStreamingDemoService_method_names[0],
      ::grpc::internal::RpcMethod::CLIENT_STREAMING,
      new ::grpc::internal::ClientStreamingHandler< ClinentStreamingDemoService::Service, ::grpcDemo::UploadClientTextureRequest, ::grpcDemo::UploadClientTextureResponse>(
          [](ClinentStreamingDemoService::Service* service,
             ::grpc::ServerContext* ctx,
             ::grpc::ServerReader<::grpcDemo::UploadClientTextureRequest>* reader,
             ::grpcDemo::UploadClientTextureResponse* resp) {
               return service->UploadTexture(ctx, reader, resp);
             }, this)));
}

ClinentStreamingDemoService::Service::~Service() {
}

::grpc::Status ClinentStreamingDemoService::Service::UploadTexture(::grpc::ServerContext* context, ::grpc::ServerReader< ::grpcDemo::UploadClientTextureRequest>* reader, ::grpcDemo::UploadClientTextureResponse* response) {
  (void) context;
  (void) reader;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace grpcDemo

THIRD_PARTY_INCLUDES_END
