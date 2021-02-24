CC      = gcc
CFLAGS  = -Wno-error=implicit-function-declaration -g -std=c89

PROGRAM = gridlock

all:    $(PROGRAM)

%:  %.c
	@echo "Compiling $@"
	@$(CC) $(CFLAGS) -o $@ $<

.PHONY: clean
clean:
	rm -f $(PROGRAM)

