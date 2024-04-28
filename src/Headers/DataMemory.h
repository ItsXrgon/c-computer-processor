
#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

/* ^^ these are the include guards */

/* Prototypes for the functions */

int ReadDataMemory(int address);
void WriteDataMemory(int address, int value);
void PrintAllDataMemory();
void ResetDataMemory();

#endif