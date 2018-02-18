CC:=clang
CFLAGS:=-Wall -Wformat -std=c99 -lncurses
LIBS:=-lm


default: build

build:
	$(CC) $(CFLAGS) $(LIBS) -o c6502 src/c6502.c


install:
	@$(MAKE)
	@install ./c6502 /usr/local/bin


example: examples/example.c examples/example.s
	cc65 -v  -t sim6502 examples/example.c
	ca65 -v -s examples/example.s
	ld65 -t sim6502 -o example examples/example.o examples/sim6502.lib


uninstall:
	@rm -f /usr/local/bin/c6502

	
