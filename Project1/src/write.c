/*
 * write.c
 * @brief function to write a memory location
 * @author D.Doty
*/

/* Includes */
#include "write.h"

/* Defines */


/* Global Variables */


/* Private Function Prototypes */


/* Function Definition */
int8_t write(char* args)
{
	// Parse arguments
	uint64_t address = 0;
	uint64_t word = 0;
	io_parse(args, 2, &address, &word);

	if(valid_range(address, 1) != 0)
	{
		return 1;
	}

	// Write
	printf("Writing...\n");
	printf("Address\t\t\tContents Hex\tContents Dec\n");
	*((uint32_t*)address) = word;
	printf("0x%016lX\t0x%08X\t%u\n\n", address, *((uint32_t*)address), *((uint32_t*)address));
	return 0;
}