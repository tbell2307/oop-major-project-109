# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -lstdc++fs -Wall -Wextra

# Directories
SRC_DIR := src
OBJ_DIR := obj
INC_DIR := inc
LIB_DIR := libs

# Executable name
TARGET := my_program

# Source files (replace <your_source_files> with actual source files)
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Include directories
INC_FLAGS := -I$(INC_DIR) -I$(LIB_DIR)/nlohmann/single_include -I$(LIB_DIR)/fmt/include -I$(LIB_DIR)/SFML/include


# Libraries
LIBS := -lsfml-graphics -lsfml-window -lsfml-system

# Build rule
$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

# Compilation rule
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INC_FLAGS) -c $< -o $@

# Ensure the obj directory exists
$(shell mkdir -p $(OBJ_DIR))

.PHONY: clean

clean:
	$(RM) -r $(OBJ_DIR)
	$(RM) $(TARGET)
