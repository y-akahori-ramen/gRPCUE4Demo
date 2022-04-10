THIRD_PARTY_INCLUDES_START
#pragma warning (disable : 4005)
#pragma warning (disable : 4125)
// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: serverStreamingDemo.proto
#ifndef GRPC_serverStreamingDemo_2eproto__INCLUDED
#define GRPC_serverStreamingDemo_2eproto__INCLUDED

#include "serverStreamingDemo.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_generic_service.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/client_context.h>
#include <grpcpp/impl/codegen/completion_queue.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace grpcDemo {

class ServerStreamingDemoService final {
 public:
  static constexpr char const* service_full_name() {
    return "grpcDemo.ServerStreamingDemoService";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    std::unique_ptr< ::grpc::ClientReaderInterface< ::grpcDemo::GetServerStreamingTextureResponse>> GetTexture(::grpc::ClientContext* context, const ::grpcDemo::GetServerStreamingTextureRequest& request) {
      return std::unique_ptr< ::grpc::ClientReaderInterface< ::grpcDemo::GetServerStreamingTextureResponse>>(GetTextureRaw(context, request));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::grpcDemo::GetServerStreamingTextureResponse>> AsyncGetTexture(::grpc::ClientContext* context, const ::grpcDemo::GetServerStreamingTextureRequest& request, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::grpcDemo::GetServerStreamingTextureResponse>>(AsyncGetTextureRaw(context, request, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::grpcDemo::GetServerStreamingTextureResponse>> PrepareAsyncGetTexture(::grpc::ClientContext* context, const ::grpcDemo::GetServerStreamingTextureRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::grpcDemo::GetServerStreamingTextureResponse>>(PrepareAsyncGetTextureRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientReaderInterface< ::grpcDemo::GetServerStreamingMessageResponse>> GetMessage(::grpc::ClientContext* context, const ::grpcDemo::GetServerStreamingMessageRequest& request) {
      return std::unique_ptr< ::grpc::ClientReaderInterface< ::grpcDemo::GetServerStreamingMessageResponse>>(GetMessageRaw(context, request));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::grpcDemo::GetServerStreamingMessageResponse>> AsyncGetMessage(::grpc::ClientContext* context, const ::grpcDemo::GetServerStreamingMessageRequest& request, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::grpcDemo::GetServerStreamingMessageResponse>>(AsyncGetMessageRaw(context, request, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::grpcDemo::GetServerStreamingMessageResponse>> PrepareAsyncGetMessage(::grpc::ClientContext* context, const ::grpcDemo::GetServerStreamingMessageRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::grpcDemo::GetServerStreamingMessageResponse>>(PrepareAsyncGetMessageRaw(context, request, cq));
    }
    class async_interface {
     public:
      virtual ~async_interface() {}
      virtual void GetTexture(::grpc::ClientContext* context, const ::grpcDemo::GetServerStreamingTextureRequest* request, ::grpc::ClientReadReactor< ::grpcDemo::GetServerStreamingTextureResponse>* reactor) = 0;
      virtual void GetMessage(::grpc::ClientContext* context, const ::grpcDemo::GetServerStreamingMessageRequest* request, ::grpc::ClientReadReactor< ::grpcDemo::GetServerStreamingMessageResponse>* reactor) = 0;
    };
    typedef class async_interface experimental_async_interface;
    virtual class async_interface* async() { return nullptr; }
    class async_interface* experimental_async() { return async(); }
   private:
    virtual ::grpc::ClientReaderInterface< ::grpcDemo::GetServerStreamingTextureResponse>* GetTextureRaw(::grpc::ClientContext* context, const ::grpcDemo::GetServerStreamingTextureRequest& request) = 0;
    virtual ::grpc::ClientAsyncReaderInterface< ::grpcDemo::GetServerStreamingTextureResponse>* AsyncGetTextureRaw(::grpc::ClientContext* context, const ::grpcDemo::GetServerStreamingTextureRequest& request, ::grpc::CompletionQueue* cq, void* tag) = 0;
    virtual ::grpc::ClientAsyncReaderInterface< ::grpcDemo::GetServerStreamingTextureResponse>* PrepareAsyncGetTextureRaw(::grpc::ClientContext* context, const ::grpcDemo::GetServerStreamingTextureRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientReaderInterface< ::grpcDemo::GetServerStreamingMessageResponse>* GetMessageRaw(::grpc::ClientContext* context, const ::grpcDemo::GetServerStreamingMessageRequest& request) = 0;
    virtual ::grpc::ClientAsyncReaderInterface< ::grpcDemo::GetServerStreamingMessageResponse>* AsyncGetMessageRaw(::grpc::ClientContext* context, const ::grpcDemo::GetServerStreamingMessageRequest& request, ::grpc::CompletionQueue* cq, void* tag) = 0;
    virtual ::grpc::ClientAsyncReaderInterface< ::grpcDemo::GetServerStreamingMessageResponse>* PrepareAsyncGetMessageRaw(::grpc::ClientContext* context, const ::grpcDemo::GetServerStreamingMessageRequest& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
    std::unique_ptr< ::grpc::ClientReader< ::grpcDemo::GetServerStreamingTextureResponse>> GetTexture(::grpc::ClientContext* context, const ::grpcDemo::GetServerStreamingTextureRequest& request) {
      return std::unique_ptr< ::grpc::ClientReader< ::grpcDemo::GetServerStreamingTextureResponse>>(GetTextureRaw(context, request));
    }
    std::unique_ptr< ::grpc::ClientAsyncReader< ::grpcDemo::GetServerStreamingTextureResponse>> AsyncGetTexture(::grpc::ClientContext* context, const ::grpcDemo::GetServerStreamingTextureRequest& request, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReader< ::grpcDemo::GetServerStreamingTextureResponse>>(AsyncGetTextureRaw(context, request, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncReader< ::grpcDemo::GetServerStreamingTextureResponse>> PrepareAsyncGetTexture(::grpc::ClientContext* context, const ::grpcDemo::GetServerStreamingTextureRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReader< ::grpcDemo::GetServerStreamingTextureResponse>>(PrepareAsyncGetTextureRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientReader< ::grpcDemo::GetServerStreamingMessageResponse>> GetMessage(::grpc::ClientContext* context, const ::grpcDemo::GetServerStreamingMessageRequest& request) {
      return std::unique_ptr< ::grpc::ClientReader< ::grpcDemo::GetServerStreamingMessageResponse>>(GetMessageRaw(context, request));
    }
    std::unique_ptr< ::grpc::ClientAsyncReader< ::grpcDemo::GetServerStreamingMessageResponse>> AsyncGetMessage(::grpc::ClientContext* context, const ::grpcDemo::GetServerStreamingMessageRequest& request, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReader< ::grpcDemo::GetServerStreamingMessageResponse>>(AsyncGetMessageRaw(context, request, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncReader< ::grpcDemo::GetServerStreamingMessageResponse>> PrepareAsyncGetMessage(::grpc::ClientContext* context, const ::grpcDemo::GetServerStreamingMessageRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReader< ::grpcDemo::GetServerStreamingMessageResponse>>(PrepareAsyncGetMessageRaw(context, request, cq));
    }
    class async final :
      public StubInterface::async_interface {
     public:
      void GetTexture(::grpc::ClientContext* context, const ::grpcDemo::GetServerStreamingTextureRequest* request, ::grpc::ClientReadReactor< ::grpcDemo::GetServerStreamingTextureResponse>* reactor) override;
      void GetMessage(::grpc::ClientContext* context, const ::grpcDemo::GetServerStreamingMessageRequest* request, ::grpc::ClientReadReactor< ::grpcDemo::GetServerStreamingMessageResponse>* reactor) override;
     private:
      friend class Stub;
      explicit async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class async* async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class async async_stub_{this};
    ::grpc::ClientReader< ::grpcDemo::GetServerStreamingTextureResponse>* GetTextureRaw(::grpc::ClientContext* context, const ::grpcDemo::GetServerStreamingTextureRequest& request) override;
    ::grpc::ClientAsyncReader< ::grpcDemo::GetServerStreamingTextureResponse>* AsyncGetTextureRaw(::grpc::ClientContext* context, const ::grpcDemo::GetServerStreamingTextureRequest& request, ::grpc::CompletionQueue* cq, void* tag) override;
    ::grpc::ClientAsyncReader< ::grpcDemo::GetServerStreamingTextureResponse>* PrepareAsyncGetTextureRaw(::grpc::ClientContext* context, const ::grpcDemo::GetServerStreamingTextureRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientReader< ::grpcDemo::GetServerStreamingMessageResponse>* GetMessageRaw(::grpc::ClientContext* context, const ::grpcDemo::GetServerStreamingMessageRequest& request) override;
    ::grpc::ClientAsyncReader< ::grpcDemo::GetServerStreamingMessageResponse>* AsyncGetMessageRaw(::grpc::ClientContext* context, const ::grpcDemo::GetServerStreamingMessageRequest& request, ::grpc::CompletionQueue* cq, void* tag) override;
    ::grpc::ClientAsyncReader< ::grpcDemo::GetServerStreamingMessageResponse>* PrepareAsyncGetMessageRaw(::grpc::ClientContext* context, const ::grpcDemo::GetServerStreamingMessageRequest& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_GetTexture_;
    const ::grpc::internal::RpcMethod rpcmethod_GetMessage_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status GetTexture(::grpc::ServerContext* context, const ::grpcDemo::GetServerStreamingTextureRequest* request, ::grpc::ServerWriter< ::grpcDemo::GetServerStreamingTextureResponse>* writer);
    virtual ::grpc::Status GetMessage(::grpc::ServerContext* context, const ::grpcDemo::GetServerStreamingMessageRequest* request, ::grpc::ServerWriter< ::grpcDemo::GetServerStreamingMessageResponse>* writer);
  };
  template <class BaseClass>
  class WithAsyncMethod_GetTexture : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_GetTexture() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_GetTexture() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetTexture(::grpc::ServerContext* /*context*/, const ::grpcDemo::GetServerStreamingTextureRequest* /*request*/, ::grpc::ServerWriter< ::grpcDemo::GetServerStreamingTextureResponse>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestGetTexture(::grpc::ServerContext* context, ::grpcDemo::GetServerStreamingTextureRequest* request, ::grpc::ServerAsyncWriter< ::grpcDemo::GetServerStreamingTextureResponse>* writer, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncServerStreaming(0, context, request, writer, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_GetMessage : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_GetMessage() {
      ::grpc::Service::MarkMethodAsync(1);
    }
    ~WithAsyncMethod_GetMessage() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetMessage(::grpc::ServerContext* /*context*/, const ::grpcDemo::GetServerStreamingMessageRequest* /*request*/, ::grpc::ServerWriter< ::grpcDemo::GetServerStreamingMessageResponse>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestGetMessage(::grpc::ServerContext* context, ::grpcDemo::GetServerStreamingMessageRequest* request, ::grpc::ServerAsyncWriter< ::grpcDemo::GetServerStreamingMessageResponse>* writer, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncServerStreaming(1, context, request, writer, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_GetTexture<WithAsyncMethod_GetMessage<Service > > AsyncService;
  template <class BaseClass>
  class WithCallbackMethod_GetTexture : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_GetTexture() {
      ::grpc::Service::MarkMethodCallback(0,
          new ::grpc::internal::CallbackServerStreamingHandler< ::grpcDemo::GetServerStreamingTextureRequest, ::grpcDemo::GetServerStreamingTextureResponse>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpcDemo::GetServerStreamingTextureRequest* request) { return this->GetTexture(context, request); }));
    }
    ~WithCallbackMethod_GetTexture() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetTexture(::grpc::ServerContext* /*context*/, const ::grpcDemo::GetServerStreamingTextureRequest* /*request*/, ::grpc::ServerWriter< ::grpcDemo::GetServerStreamingTextureResponse>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerWriteReactor< ::grpcDemo::GetServerStreamingTextureResponse>* GetTexture(
      ::grpc::CallbackServerContext* /*context*/, const ::grpcDemo::GetServerStreamingTextureRequest* /*request*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithCallbackMethod_GetMessage : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_GetMessage() {
      ::grpc::Service::MarkMethodCallback(1,
          new ::grpc::internal::CallbackServerStreamingHandler< ::grpcDemo::GetServerStreamingMessageRequest, ::grpcDemo::GetServerStreamingMessageResponse>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpcDemo::GetServerStreamingMessageRequest* request) { return this->GetMessage(context, request); }));
    }
    ~WithCallbackMethod_GetMessage() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetMessage(::grpc::ServerContext* /*context*/, const ::grpcDemo::GetServerStreamingMessageRequest* /*request*/, ::grpc::ServerWriter< ::grpcDemo::GetServerStreamingMessageResponse>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerWriteReactor< ::grpcDemo::GetServerStreamingMessageResponse>* GetMessage(
      ::grpc::CallbackServerContext* /*context*/, const ::grpcDemo::GetServerStreamingMessageRequest* /*request*/)  { return nullptr; }
  };
  typedef WithCallbackMethod_GetTexture<WithCallbackMethod_GetMessage<Service > > CallbackService;
  typedef CallbackService ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_GetTexture : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_GetTexture() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_GetTexture() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetTexture(::grpc::ServerContext* /*context*/, const ::grpcDemo::GetServerStreamingTextureRequest* /*request*/, ::grpc::ServerWriter< ::grpcDemo::GetServerStreamingTextureResponse>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_GetMessage : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_GetMessage() {
      ::grpc::Service::MarkMethodGeneric(1);
    }
    ~WithGenericMethod_GetMessage() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetMessage(::grpc::ServerContext* /*context*/, const ::grpcDemo::GetServerStreamingMessageRequest* /*request*/, ::grpc::ServerWriter< ::grpcDemo::GetServerStreamingMessageResponse>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_GetTexture : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_GetTexture() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_GetTexture() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetTexture(::grpc::ServerContext* /*context*/, const ::grpcDemo::GetServerStreamingTextureRequest* /*request*/, ::grpc::ServerWriter< ::grpcDemo::GetServerStreamingTextureResponse>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestGetTexture(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncWriter< ::grpc::ByteBuffer>* writer, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncServerStreaming(0, context, request, writer, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_GetMessage : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_GetMessage() {
      ::grpc::Service::MarkMethodRaw(1);
    }
    ~WithRawMethod_GetMessage() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetMessage(::grpc::ServerContext* /*context*/, const ::grpcDemo::GetServerStreamingMessageRequest* /*request*/, ::grpc::ServerWriter< ::grpcDemo::GetServerStreamingMessageResponse>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestGetMessage(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncWriter< ::grpc::ByteBuffer>* writer, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncServerStreaming(1, context, request, writer, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_GetTexture : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_GetTexture() {
      ::grpc::Service::MarkMethodRawCallback(0,
          new ::grpc::internal::CallbackServerStreamingHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const::grpc::ByteBuffer* request) { return this->GetTexture(context, request); }));
    }
    ~WithRawCallbackMethod_GetTexture() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetTexture(::grpc::ServerContext* /*context*/, const ::grpcDemo::GetServerStreamingTextureRequest* /*request*/, ::grpc::ServerWriter< ::grpcDemo::GetServerStreamingTextureResponse>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerWriteReactor< ::grpc::ByteBuffer>* GetTexture(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_GetMessage : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_GetMessage() {
      ::grpc::Service::MarkMethodRawCallback(1,
          new ::grpc::internal::CallbackServerStreamingHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const::grpc::ByteBuffer* request) { return this->GetMessage(context, request); }));
    }
    ~WithRawCallbackMethod_GetMessage() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetMessage(::grpc::ServerContext* /*context*/, const ::grpcDemo::GetServerStreamingMessageRequest* /*request*/, ::grpc::ServerWriter< ::grpcDemo::GetServerStreamingMessageResponse>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerWriteReactor< ::grpc::ByteBuffer>* GetMessage(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/)  { return nullptr; }
  };
  typedef Service StreamedUnaryService;
  template <class BaseClass>
  class WithSplitStreamingMethod_GetTexture : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithSplitStreamingMethod_GetTexture() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::SplitServerStreamingHandler<
          ::grpcDemo::GetServerStreamingTextureRequest, ::grpcDemo::GetServerStreamingTextureResponse>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerSplitStreamer<
                     ::grpcDemo::GetServerStreamingTextureRequest, ::grpcDemo::GetServerStreamingTextureResponse>* streamer) {
                       return this->StreamedGetTexture(context,
                         streamer);
                  }));
    }
    ~WithSplitStreamingMethod_GetTexture() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status GetTexture(::grpc::ServerContext* /*context*/, const ::grpcDemo::GetServerStreamingTextureRequest* /*request*/, ::grpc::ServerWriter< ::grpcDemo::GetServerStreamingTextureResponse>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with split streamed
    virtual ::grpc::Status StreamedGetTexture(::grpc::ServerContext* context, ::grpc::ServerSplitStreamer< ::grpcDemo::GetServerStreamingTextureRequest,::grpcDemo::GetServerStreamingTextureResponse>* server_split_streamer) = 0;
  };
  template <class BaseClass>
  class WithSplitStreamingMethod_GetMessage : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithSplitStreamingMethod_GetMessage() {
      ::grpc::Service::MarkMethodStreamed(1,
        new ::grpc::internal::SplitServerStreamingHandler<
          ::grpcDemo::GetServerStreamingMessageRequest, ::grpcDemo::GetServerStreamingMessageResponse>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerSplitStreamer<
                     ::grpcDemo::GetServerStreamingMessageRequest, ::grpcDemo::GetServerStreamingMessageResponse>* streamer) {
                       return this->StreamedGetMessage(context,
                         streamer);
                  }));
    }
    ~WithSplitStreamingMethod_GetMessage() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status GetMessage(::grpc::ServerContext* /*context*/, const ::grpcDemo::GetServerStreamingMessageRequest* /*request*/, ::grpc::ServerWriter< ::grpcDemo::GetServerStreamingMessageResponse>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with split streamed
    virtual ::grpc::Status StreamedGetMessage(::grpc::ServerContext* context, ::grpc::ServerSplitStreamer< ::grpcDemo::GetServerStreamingMessageRequest,::grpcDemo::GetServerStreamingMessageResponse>* server_split_streamer) = 0;
  };
  typedef WithSplitStreamingMethod_GetTexture<WithSplitStreamingMethod_GetMessage<Service > > SplitStreamedService;
  typedef WithSplitStreamingMethod_GetTexture<WithSplitStreamingMethod_GetMessage<Service > > StreamedService;
};

}  // namespace grpcDemo


#endif  // GRPC_serverStreamingDemo_2eproto__INCLUDED
THIRD_PARTY_INCLUDES_END
