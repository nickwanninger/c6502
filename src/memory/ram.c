#ifndef __6502_RAM__
#define __6502_RAM__
#include "types.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

address_t ramsize = 0x0;
byte_t *ram;

void raminit(address_t size) {
	ramsize = size;
	ram = calloc(ramsize, 1);
}

byte_t ramread(address_t addr) {
	byte_t val = ram[addr];
	return val;
}

void ramwrite(byte_t val, address_t addr) {
	ram[addr] = val;
}

#endif