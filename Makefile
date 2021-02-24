CC      = gcc
CFLAGS  = -g -std=c89

PROGRAM = gridlock

all:    $(PROGRAM)

%:  %.c
	@echo "Compiling $@"
	@$(CC) $(CFLAGS) -o $@ $<

.PHONY: clean
clean:
	rm -f $(PROGRAM)

