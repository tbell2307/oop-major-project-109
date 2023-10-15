# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++20 -Wall -Wextra -Iinc

# Directories
SRC_DIR := src
BUILD_DIR := build
INC_DIR := inc

# Source files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)

# Object files
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Target executable
TARGET := Run_Farm

.PHONY: all clean

all: $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

