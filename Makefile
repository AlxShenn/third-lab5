CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude
SRC = main.cpp src/gestures.cpp src/players.cpp src/strategies.cpp
TARGET = Game

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)