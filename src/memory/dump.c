#ifndef __6502_MEMORY_DUMPER__
#define __6502_MEMORY_DUMPER__

#include "types.h"
/**
 * A function to print the memory of either a rom or a ram
 * pointer in the style of hexdump or xxd
 */
void memdmp(byte_t *memory, int length) {
	int i;
	
	// Get a pointer to the start of the memory bytes
	unsigned char *m = (unsigned char*)memory;
	int count = 0xf;
	// Create a buffer of memory that will be used to
	// print the ascii representation of each line.
	unsigned char buff[count];

	// Process every byte in the data.
	for (i = 0; i < length; i++) {
		// Multiple of 16 means new line (with line offset).
		if ((i % count) == 0) {
			// Just don't print ASCII for the zeroth line.
			if (i != 0)
				printf("  %s\n", buff);
			// Output the offset.
			printf("%07x ", i);
		}
		// Now the hex code for the specific character.
		printf(" %02x", m[i]);
		// And store a printable ASCII character for later.
		if ((m[i] < 0x20) || (m[i] > 0x7e)) {
			buff[i % count] = '.';
		} else {
			buff[i % count] = m[i];
		}
		buff[(i % count) + 1] = '\0';
	}
	// Pad out last line if not exactly count characters.
	while ((i % count) != 0) {
		printf("   ");
		i++;
	}
	// And print the final ASCII bit.
	printf("  %s\n", buff);
}

#endif