#ifndef __6502_ROM__
#define __6502_ROM__

#include "types.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

address_t romsize = 0x0;
byte_t *rom;

void romload(char *filename) {
	FILE *source_file = fopen(filename, "rb");
	// seek to the end of the source file
	fseek(source_file, 0, SEEK_END);
	// get the position (size)
	romsize = ftell(source_file);
	// move back to the start
	rewind(source_file);
	// allocate enough space for the entire file
	rom = calloc(romsize + 1, 1);
	// read the entire file into the rom string
	fread(rom, romsize, 1, source_file);
	// close the file
	fclose(source_file);
}

byte_t romread(address_t addr) {
	return rom[addr];
}

#endif