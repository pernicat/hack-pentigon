#
# Makefile
#
SHELL = /bin/sh

CC = gcc -O

SOURCES = main.c
INCLUDES=
CFLAGES =
SLIBS   =
PROGRAM = hack

OBJECTS= $(SOURCES:.c=.o)

.KEEP_STATE:

debug := CFLAGES= -g

all debug: $(PROGRAM)

$(PROGRAM): $(INCLUDES) $(OBJECTS)
    $(LINK.c) -o $@ $(OBJECTS) $(SLIBS)

clean:
    rm -f $(PROGRAM) $(OBJECTS)
 

