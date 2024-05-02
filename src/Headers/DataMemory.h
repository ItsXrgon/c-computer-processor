#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

/* ^^ these are the include guards */

/* 
 * Function: ReadDataMemory
 * ------------------------
 * Reads the value stored in the data memory at the specified address.
 *
 * address: the memory address to read from
 *
 * returns: the value stored at the specified address
 */
int ReadDataMemory(int address);

/* 
 * Function: WriteDataMemory
 * -------------------------
 * Writes the specified value to the data memory at the specified address.
 *
 * address: the memory address to write to
 * value: the value to be written
 *
 * returns: void
 */
void WriteDataMemory(int address, int value);

/* 
 * Function: PrintAllDataMemory
 * ----------------------------
 * Prints the contents of the data memory.
 *
 * returns: void
 */
void PrintAllDataMemory();

/* 
 * Function: ResetDataMemory
 * -------------------------
 * Resets the data memory by clearing all its contents.
 *
 * returns: void
 */
void ResetDataMemory();

#endif