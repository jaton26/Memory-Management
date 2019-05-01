CXX = g++
CXXFLAGS = -Wall -g
BIN_DIR = bin
I_DIR = include
BUILD_DIR = build

TARGET = program
SRC = $(wildcard src/*.cpp) 
OBJECTS = $(SRC:%.cpp=$(BUILD_DIR)/%.o)

all: $(TARGET)

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -I $(I_DIR) -o $@ -c $<

$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $(BIN_DIR)/$(TARGET) $(OBJECTS)

.PHONY: clean 

clean:
	-@rm -rf $(BUILD_DIR)
	-@echo 'Cleaned'