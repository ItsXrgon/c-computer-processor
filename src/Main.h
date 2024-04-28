
#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Instruction{
    int opcode;
    int operand1;
    int value2;//operand2 or immediate value or address
    char type;
};
typedef struct Instruction Instruction;


/* ^^ these are the include guards */

/* Prototypes for the functions */


//Registers
void updateCarryFlag(int operand1, int operand2, int result);
void updateOverflowFlag(int operand1, int operand2, int result);
void updateNegativeFlag(int result);
void updateSignFlag(int result);
void updateZeroFlag(int result);
int ReadRegister(int reg);
void WriteRegister(int reg, int value);
void ResetRegisters();
void PrintAllRegisters();
void PrintStatusRegister();
int GetPC();
void SetPC(int value);
void IncrementPC();

//ALU
int ALU(int operand1, int operand2, int operation);

//Data Memory
int loadWord(int address);
void storeWord(int address, int value);
void PrintAllMemory();
void ResetDataMemory();

//Instruction Memory
int incodeOpcode(char *opcode);
void WriteInstructionMemory(int address, Instruction intstruction);
Instruction ReadInstructionMemory(int address);
Instruction fetch();
void decode(Instruction instruction);
void excute(int opcode, int operand1, int operand2);
void ResetInstructionMemory();

#endif
