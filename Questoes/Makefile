#======================================================================
CC=gcc
OPT=-O2
CFLAGS=-Wall -Wextra -pedantic-errors $(OPT)
#----------------------------------------------------------------------
BLD_DIR = build
INC_DIR = includes
SRC_DIR = src
#----------------------------------------------------------------------
# SRC = $(wildcard *.c)
# OBJS = $(patsubst %.c, $(BLD_DIR)/%.o, $(SRC))
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BLD_DIR)/%.o, $(SRC))
#----------------------------------------------------------------------
PROGRAM = main
#======================================================================

.DEFAULT_GOAL = all

all: setup $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CC) -I $(INC_DIR) $(CFLAGS) -o $@ $^ -lm

$(BLD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c -I $(INC_DIR) $(CFLAGS) -o $@ $^ -lm

setup:
	@mkdir -p $(BLD_DIR)

clean:
	rm -r $(BLD_DIR)
	rm $(PROGRAM)
