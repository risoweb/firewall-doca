# Usa a imagem oficial DOCA da NVIDIA
FROM nvcr.io/nvidia/doca:latest

# Define diretório de trabalho
WORKDIR /app

# Instala dependências adicionais
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    pkg-config \
    libssl-dev \
    && rm -rf /var/lib/apt/lists/*

# Copia o código fonte
COPY . .

# Compila o projeto
RUN make

# Comando padrão
CMD ["/bin/bash"]