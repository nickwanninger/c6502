#ifndef __CPU__
#define __CPU__

#include "./memory/types.h"

typedef struct {
	address_t pc; // Program Counter
	byte_t x; // X index register
	byte_t y; // Y index register
	byte_t ac; // Accumulator Register
	byte_t sr; // Status Register
	byte_t sp; // Stack Pointer
} cpu_t;

cpu_t *cpu;

#endif