#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

/* ^^ these are the include guards */

/* Prototypes for the functions */
#include "../Headers/Registers.h"
#include "../Headers/Structs.h"
#include "../Headers/ALU.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int incodeOpcode(char *opcode);
void WriteInstructionMemory(int address, Instruction intstruction);
Instruction ReadInstructionMemory(int address);
void fetchPipeline();
void decodePipeline();
void excutePipeline();
void execute(Instruction ins);
void ResetInstructionMemory();
void PrintAllInstructionMemory();

#endif