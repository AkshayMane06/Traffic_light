# Compiler
CC = gcc

# Directories
SRC_DIR = src
INCLUDE_DIR = include
TEST_DIR = test
BIN_DIR = bin

# Targets
TARGET = $(BIN_DIR)/traffic_light
TEST_TARGET = $(BIN_DIR)/test_traffic_light

# Source files
MAIN_SRC = $(SRC_DIR)/traffic_light.c
TEST_SRC = $(TEST_DIR)/test.c

# Flags
CFLAGS = -I$(INCLUDE_DIR)

# Default target
all: $(TARGET) $(TEST_TARGET)

# Build main program
$(TARGET): $(MAIN_SRC)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# Build test program
$(TEST_TARGET): $(TEST_SRC) $(MAIN_SRC)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -DTESTING -o $@ $^

# Run main program
run: $(TARGET)
	@$(TARGET)

# Run tests
test: $(TEST_TARGET)
	@$(TEST_TARGET)

# Clean build artifacts
clean:
	rm -rf $(BIN_DIR)

.PHONY: all run test clean
