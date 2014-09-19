#CS 125 
#Makefile for pset 2

CC = clang

CFLAGS = -ggdb3 -O0 -Qunused-arguments -std=c99 -Wall -Werror

EXE = randmst

HDRS = queue.h

SRCS = randmst.c queue.c 

# don't know what this does
OBJS = $(SRCS:.c=.o)

LIBS =-lm


# random other shit from cs50 that we might need
$(EXE): $(OBJS) $(HDRS) Makefile
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

# dependencies--tells compiler that objs depends on headers
$(OBJS): $(HDRS) Makefile

clean: 
	rm -f core $(EXE) *.o