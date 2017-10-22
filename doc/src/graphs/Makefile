#file: geo/Makefile.simple

PROGRAM = graph
ARGUMENTS = #empty

CC = gcc
CFLAGS = -pedantic -Wall -Wextra -std=c11 -ggdb

LD = gcc
LDFLAGS = -lm #for example (not necessary in this case)

#configuration section
CFILES = $(wildcard *.c) #all c. files
OFILES = $(CFILES:.c=.o) # generate corresponding .o files

# new default target
all: clean depend $(PROGRAM) run

# first rule is default
$(PROGRAM): $(OFILES)
	$(LD) -o $@ $(OFILES) $(LDFLAGS)
# $@: voller Name des Zielobjekts
# LDFLAGS must come last! otherwise libraries might be skipt

#phony targets
.PHONY: all clean debug #never try to build a file named "clean"
clean:
	rm -f $(OFILES) $(PROGRAM)

run: $(PROGRAM)
	./$(PROGRAM) $(ARGUMENTS)

debug: $(PROGRAM)
	gdb $(PROGRAM) $(ARGUMENTS)

#dependfile
DEPENDFILE = .depend

#automatic generation
depend:
	$(CC) $(CFLAGS) -MM $(CFILES) > $(DEPENDFILE)

#include depend file
-include $(DEPENDFILE)