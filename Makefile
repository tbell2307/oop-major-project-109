# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall

# Directories
SRC_DIR := src
INC_DIR := inc
LIBS_DIR := libs
BUILD_DIR := build
BIN_DIR := bin

# External libraries (assuming they are git submodules)
# You may need to adjust the library names and paths
# EXTERNAL_LIBS := $(LIBS_DIR)/external_lib1

# Source files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)

# Object files
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Include directories
INC := -I$(INC_DIR)

# Linker flags
LDFLAGS := $(foreach lib, $(EXTERNAL_LIBS), -L$(lib)/lib -Wl,-rpath,$(lib)/lib)
# LDLIBS := -lmy_external_lib

# Output binary
TARGET := $(BIN_DIR)/my_program

# Default target
all: $(TARGET)

$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CXX) $(LDFLAGS) $(OBJS) -o $@ $(LDLIBS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

.PHONY: all clean
