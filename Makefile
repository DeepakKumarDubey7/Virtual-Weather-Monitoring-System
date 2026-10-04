CXX      = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Iinclude
SRC      = $(wildcard src/*.cpp)
OBJ      = $(SRC:src/%.cpp=build/%.o)
TARGET   = weather_monitor

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

build/%.o: src/%.cpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf build $(TARGET)

.PHONY: all run clean
