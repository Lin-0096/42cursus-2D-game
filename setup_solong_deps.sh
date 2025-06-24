#!/bin/bash

set -e

sudo apt update

sudo apt install -y \
    build-essential \
    libglfw3-dev \
    libgl1-mesa-dev \
    libglu1-mesa-dev \
    libxrandr-dev \
    libxinerama-dev \
    libxcursor-dev \
    libxi-dev \
    libpng-dev \
    cmake \
    git

echo "✅ done"
