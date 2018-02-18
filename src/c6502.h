#ifndef __6502_HEADER__
#define __6502_HEADER__
// Libraries
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
// My deps
#include "./memory/types.h"
#include "./memory/ram.c"
#include "./memory/rom.c"
#include "./memory/dump.c"
#include "cpu.h"
#include "io/io.h"
#include "opcodes/ops.h"

int8_t SP;
int16_t PC;

unsigned long framecount = 0;

#endif