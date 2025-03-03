CC = gcc
CFLAGS = -Wall -Wextra -std=c11
SRC = main.c file_handler.c string_matching.c utils.c
OBJ = $(SRC:.c=.o)
TARGET = plagiarism_checker

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

clean:
	rm -f $(TARGET) $(OBJ)
