# Use a lightweight base image
FROM ubuntu:22.04

# Install dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    gcc \
    make \
    && rm -rf /var/lib/apt/lists/*

# Set working directory
WORKDIR /app

# Copy project files
COPY . .

# Build the firewall
RUN make clean && make all

# Set the entrypoint to run the firewall
ENTRYPOINT ["./bin/firewall"]
CMD []
