# Makefile para projeto DOCA Firewall

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -I./include
LDFLAGS = -lm

# Diretórios
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
BIN_DIR = bin

# Arquivos fonte
SOURCES = $(SRC_DIR)/main.c $(SRC_DIR)/firewall.c
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
TARGET = $(BIN_DIR)/firewall

# Targets padrão
all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)
	@echo "✓ Compilação concluída: $@"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "✓ Compilado: $<"

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)
	@echo "✓ Limpeza concluída"

run: $(TARGET)
	./$(TARGET)

help:
	@echo "Targets disponíveis:"
	@echo "  make all   - Compila o projeto"
	@echo "  make clean - Remove arquivos compilados"
	@echo "  make run   - Compila e executa"
	@echo "  make help  - Mostra este help"

.PHONY: all clean run help