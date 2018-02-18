#include "c6502.h"
#include <time.h>

int main(int argc, char **argv) {

	char *filename = argv[argc - 1];
	
	romload(filename);
	raminit(0x8000);
	memdmp(rom, romsize);

	free(cpu);
	free(ram);
	free(rom);

	return 0;
}

