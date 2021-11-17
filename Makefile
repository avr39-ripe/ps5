# variables
CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wno-vla-parameter
LDLIBS=-lm
OUTPUT=qr

# targets
all: $(OUTPUT)

$(OUTPUT): qr.o
	cppcheck --enable=performance,unusedFunction --error-exitcode=1 *.c
	$(CC) $(CFLAGS) $^ $(LDLIBS) -o $(OUTPUT)


qr.o: qr.c
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@

# remove compiled files
clean: 
	rm -rf $(OUTPUT) *.o
