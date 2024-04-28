#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

/* ^^ these are the include guards */

/* Prototypes for the functions */

struct Instruction{
    int opcode;
    int operand1;
    int value2;//operand2 or immediate value or address
    char type;
};
typedef struct Instruction Instruction;

int incodeOpcode(char *opcode);
void WriteInstructionMemory(int address, Instruction intstruction);
Instruction ReadInstructionMemory(int address);
Instruction fetch();
void decode(Instruction instruction);
void excute(int opcode, int operand1, int operand2);
void ResetInstructionMemory();


#endif