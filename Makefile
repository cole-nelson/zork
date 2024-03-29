CXX := g++
CXXFLAGS := -g -std=c++11 -Wvla -Wall -Werror --pedantic
INC := $(wildcard inc/*.h)
SRC := $(wildcard src/*.cpp)
OBJ := $(patsubst src/%.cpp, obj/%.o, $(SRC))

all: zork

zork: $(OBJ) $(INC)
	$(CXX) $(CXXFLAGS) $(OBJ) -o zork

obj/%.o: src/%.cpp inc/%.h
	@mkdir -p obj
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f zork
	rm -rf obj

