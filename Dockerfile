FROM ubuntu:20.04

LABEL maintainer="JuanDVal <jvalenciano@unal.edu.co>"

ARG TARGETARCH

ARG BAZEL_VERSION=1.24.1
ARG PROTOBUF_VERSION=29.0
ARG NUM_JOBS=-j$(nproc)

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    build-essential \
    curl \
    gnupg \
    unzip \
    bash \
    g++ \ 
    git \
    tar \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

#Install bazel
RUN curl -Lo /usr/local/bin/bazel https://github.com/bazelbuild/bazelisk/releases/download/v${BAZEL_VERSION}/bazelisk-linux-${TARGETARCH} && \
    chmod +x /usr/local/bin/bazel

RUN bazel --version

#Install protobuf
RUN curl -SL https://github.com/protocolbuffers/protobuf/releases/download/v${PROTOBUF_VERSION}/protobuf-${PROTOBUF_VERSION}.tar.gz | tar -zxC /opt && \
    cd /opt/protobuf-${PROTOBUF_VERSION} && \
    bazel build :protoc :protobuf && \
    cp bazel-bin/protoc /usr/local/bin

WORKDIR /workspace

ENTRYPOINT [ "/bin/bash" ]
