# all : debug release

CC=g++
TARGETS=test.o board.o 

bot : $(TARGETS)
	$(CC) $^ -o $@

test.o : test.cpp board.hpp 
	$(CC) -c test.cpp

board.o : board.cpp board.hpp 
	$(CC) -c board.cpp

clean:
	rm -f $(TARGETS)
    
# $@ nazwa celu
# $^ liczba zależności

# CC=gcc
# FLAGS=-O0 -g
# TARGETS=main.o foo.o 

# debug : $(TARGETS)
# 	$(CC) $(FLAGS) $^ -o $@
