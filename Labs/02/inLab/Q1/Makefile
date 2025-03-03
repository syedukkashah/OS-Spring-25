CC = g++
CFLAGS = -Wall -Wextra -std=c++11
OBJ = main.o Student.o Teacher.o Course.o
TARGET = program

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
