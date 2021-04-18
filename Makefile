SRC = ./
TESTS = ./tests
OBJ_DIR = ./build
TARGET = tests.out
CFLAGS = -Wall -Wextra -Wpedantic -Wno-shadow -g -O0
CC = cc

$(OBJ_DIR)/%.o: $(TESTS)/%.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ_DIR)/%.o: $(SRC)/%.c
	$(CC) -c $(CFLAGS) -o $@ $<

all: $(TARGET)

clean:
	rm $(OBJ_DIR)/*.o
	rm $(TARGET)

OBJLIST = $(OBJ_DIR)/main.o \
          $(OBJ_DIR)/queue.o

$(TARGET): $(OBJLIST)
	$(CC) -o $(TARGET) $(OBJLIST)

$(OBJ_DIR)/main.o: $(TESTS)/main.c $(SRC)/queue.h
$(OBJ_DIR)/queue.o: $(SRC)/queue.c $(SRC)queue.h
