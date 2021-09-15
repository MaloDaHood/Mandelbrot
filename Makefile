SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin

EXE := $(BIN_DIR)/tic_tac_toe
SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

CXX = g++
CXXFLAGS = -std=c++2a -Wall -Wextra -pedantic
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

all : $(EXE)
.PHONY : all clean

$(EXE) : $(OBJ) | $(BIN_DIR)
	$(CXX) $^ -o $@ $(SFMLFLAGS)

$(BUILD_DIR)/%.o : $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BIN_DIR) $(BUILD_DIR) :
	mkdir -p $@

clean :
	@$(RM) -rv $(BIN_DIR) $(BUILD_DIR)

run : $(EXE)
	@$(MAKE) && ./$(EXE)

-include $(OBJ:.o=.d)