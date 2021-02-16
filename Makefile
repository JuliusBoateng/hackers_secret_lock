CC      = gcc
CFLAGS  = -g -std=c89 -Wall

PROGRAM = gridlock

all:    $(PROGRAM)

$(PROGRAM):  $(PROGRAM).c
	@echo "Compiling $@"
	@$(CC) $(CFLAGS) -o $@ $<

.PHONY: clean
clean:
	rm -f $(PROGRAM)

