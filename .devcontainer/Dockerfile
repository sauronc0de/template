FROM ubuntu:latest
RUN apt-get update -y
RUN apt-get upgrade -y
RUN apt-get install -y curl git

# C++ environment and SDL2
RUN apt-get install -y \
    gcc \
    g++ \
    gcc-multilib \
    g++-multilib \
    build-essential \
    xutils-dev \
    libsdl2-dev \
    libsdl2-gfx-dev \
    libsdl2-image-dev \
    libsdl2-mixer-dev \
    libsdl2-net-dev \
    libsdl2-ttf-dev \
    libreadline6-dev \
    libncurses5-dev \
    mingw-w64 \
    cmake

# Add clang compiler
RUN apt-get install -y clang

# Utilities
RUN apt-get update && apt install -y clang-format clangd

# Set the working directory in the container
WORKDIR /workspace/template

ENV XDG_RUNTIME_DIR=/tmp