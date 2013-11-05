CC = gcc
CXX = g++

INCLUDES = -I.
CFLAGS = -g -Wall $(INCLUDES)
CXXFLAGS = -g Wall $(INCLUDES)

LDFLAGS = -g 

deminimizehtml: deminimizehtml.o
deminimizehtml.o: deminimizehtml.c

.PHONY: clean
clean: 
	@rm -f mdb-lookup *.a a.out *.o *~
.PHONY: all
all: clean deminimizehtml

