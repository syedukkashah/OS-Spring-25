CXX = g++
CXXFLAGS = -Wall -Iinclude
SRC = src/LetterCount.cpp src/WordCount.cpp src/LineCount.cpp src/main.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = textcounter

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

src/%.o: src/%.cpp include/%.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)


