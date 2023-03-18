CC = gcc
CFLAGS = -Wall -pedantic -g

LD = gcc
LFLAGS = -lSDL2

BIN = bin
OBJ = obj
SRC = src
OUT = $(BIN)/game

OBJS = $(OBJ)/main.o 

all: $(OUT)

$(OUT): $(OBJS) 
	$(LD) $(LFLAGS) $(OBJS) -o $(OUT) 

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	$(RM) $(BIN)/* $(OBJ)/*
