# Use an official Ubuntu base image
FROM ubuntu:20.04

# Set environment variables to avoid interactive prompts during package installation
ENV DEBIAN_FRONTEND=noninteractive

# Install the necessary packages
RUN apt-get update && \
    apt-get install -y \
    build-essential \
    cmake \
    gcc \
    g++ \
    libgtest-dev \
    wget

# Install Google Test
RUN cd /usr/src/gtest && \
    cmake CMakeLists.txt && \
    make && \
    cp ./lib/*.a /usr/lib

# Set the working directory
WORKDIR /app

# Copy the current directory contents into the container
COPY . .

# Create a build directory and switch to it
RUN mkdir -p build && cd build && cmake .. && make

# Specify the entry point for the main executable
ENTRYPOINT ["./build/StudentDatabase"]

# Run the tests
CMD cd build && ctest --output-on-failure
