CC = gcc
CFLAGS = -Wall -g
SRC = main.c game.c menu.c blocks.c inventory.c
OBJ = $(SRC:.c=.o)
EXEC = ArComCraft

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

clean:
	rm -f $(OBJ) $(EXEC)
