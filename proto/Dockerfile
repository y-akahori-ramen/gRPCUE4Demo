FROM  debian:bullseye AS builder

# Build and install gRPC and ProtocolBuffers
# https://grpc.io/docs/languages/cpp/quickstart/
RUN apt update
RUN apt install -y wget git build-essential autoconf libtool pkg-config
RUN wget -q -O cmake-linux.sh https://github.com/Kitware/CMake/releases/download/v3.19.6/cmake-3.19.6-Linux-x86_64.sh
RUN /bin/sh cmake-linux.sh -- --skip-license
RUN rm cmake-linux.sh
ENV MY_INSTALL_DIR /home/.local
WORKDIR $MY_INSTALL_DIR
RUN git clone --recurse-submodules -b v1.41.1 --depth 1 --shallow-submodules https://github.com/grpc/grpc
WORKDIR $MY_INSTALL_DIR/grpc/cmake/build
RUN cmake -DgRPC_INSTALL=ON -DgRPC_BUILD_TESTS=OFF -DCMAKE_INSTALL_PREFIX=$MY_INSTALL_DIR ../..
##  Compile error workaround  https://stackoverflow.com/questions/62107520/unable-to-build-grpc-v1-28-1-inside-a-container
RUN make -j$(nproc)
RUN make install

# Install Go plugins for protocol compiler
WORKDIR /usr/local/
RUN wget -q https://go.dev/dl/go1.18.linux-amd64.tar.gz
RUN tar -C /usr/local -xzf go1.18.linux-amd64.tar.gz
ENV PATH $PATH:/usr/local/go/bin
ENV PATH $PATH:/root/go/bin
RUN go install google.golang.org/protobuf/cmd/protoc-gen-go@v1.26
RUN go install google.golang.org/grpc/cmd/protoc-gen-go-grpc@v1.1

# Copy binary from builder stage
FROM debian:bullseye-slim
WORKDIR /usr/local/bin
COPY --from=builder  /home/.local/bin .
# Builder stage GOPATH is /root/go/bin
COPY --from=builder /root/go/bin .
# Install build tools
RUN apt update
RUN apt install -y make nkf