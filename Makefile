CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -g
SRC = src/main.c src/prioridade.c src/historico.c
OBJ = $(SRC:.c=.o)
TARGET = upa_system

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

clean:
	rm -f src/*.o $(TARGET)

test: all
	valgrind --leak-check=full ./$(TARGET) tests/1000_inputs.txt