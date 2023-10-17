# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++20 -Wall -Wextra -Iinc -I/opt/homebrew/Cellar/sfml/2.6.0/include

# Directories
SRC_DIR := .
BUILD_DIR := ../build
BIN_DIR := ../bin

# Source files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)

# Object files
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Target executable
TARGET := $(BIN_DIR)/output

# SFML library paths
SFML_LIB_DIR := /opt/homebrew/Cellar/sfml/2.6.0/lib
SFML_LIBS := -lsfml-graphics -lsfml-window -lsfml-system

# Debug and Release flags
DEBUG_FLAGS := -g -DDEBUG
RELEASE_FLAGS := -O2

.PHONY: all debug release clean run

all: release

debug: CXXFLAGS += $(DEBUG_FLAGS)
debug: $(BIN_DIR) $(TARGET)

release: CXXFLAGS += $(RELEASE_FLAGS)
release: $(BIN_DIR) $(TARGET)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BIN_DIR)/output: $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ -L$(SFML_LIB_DIR) $(SFML_LIBS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: release
	./$(TARGET)

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)
