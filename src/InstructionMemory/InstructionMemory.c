#include "../Registers/Registers.h"
struct Instruction{
    int opcode;
    int operand1;
    int value2;//operand2 or immediate value or address
    char type;
};
typedef struct Instruction Instruction;

Instruction instruction_memory [1024];


int incodeOpcode(char *opcode){
    if (strcmp(opcode, "ADD") == 0)
    {
        return 0;
    }
    else if (strcmp(opcode, "SUB") == 0)
    {
        return 1;
    }
    else if (strcmp(opcode, "MUL") == 0)
    {
        return 2;
    }
    else if (strcmp(opcode, "MOV") == 0)
    {
        return 3;
    }
    else if (strcmp(opcode, "BEQ") == 0)
    {
        return 4;
    }
    else if (strcmp(opcode, "AND") == 0)
    {
        return 5;
    }
    else if (strcmp(opcode, "XOR") == 0)
    {
        return 6;
    }
    else if (strcmp(opcode, "BR") == 0)
    {
        return 7;
    }
    else if (strcmp(opcode, "SAL") == 0)
    {
        return 8;
    }
    else if (strcmp(opcode, "SAR") == 0)
    {
        return 9;
    }
    else if (strcmp(opcode, "LD") == 0)
    {
        return 10;
    }
    else if (strcmp(opcode, "ST") == 0)
    {
        return 11;
    }
    else
    {
        return -1;
    }
}

void WriteInstructionMemory(int address, Instruction intstruction){
    instruction_memory[address] = intstruction ;
}

Instruction ReadInstructionMemory(int address){
    return instruction_memory[address];
}

Instruction fetch(){
    Instruction instruction = ReadInstructionMemory(GetPC());
    IncrementPC();
    return instruction;
}

void decode(Instruction instruction) {
    int opcode = instruction.opcode;
    int operand1 = instruction.operand1;
    int operand2 = instruction.value2;
    excute(opcode, operand1, operand2);
}

void excute(int opcode, int operand1, int operand2){
    switch (opcode)
    {
    case 0: // ADD
        ALU(ReadRegister(operand1), ReadRegister(operand2), 0);
        break;
    case 1: // SUB
        ALU(ReadRegister(operand1), ReadRegister(operand2), 1);
        break;
    case 2: // MUL
        ALU(ReadRegister(operand1), ReadRegister(operand2), 2);
        break;
    case 3: // Move immediate
        ALU(operand1, operand2, 3);
        break;
    case 4: // Branch if equal zero
        ALU(operand1, operand2, 4);
        break;
    case 5: // AND Immediate
        ALU(ReadRegister(operand1), operand2, 5);
        break;
    case 6: // Exclusive OR
        ALU(ReadRegister(operand1), operand2, 6);
        break;
    case 7: // Branch Register
        ALU(ReadRegister(operand1), ReadRegister(operand2), 7);
        break;
    case 8: // Shift Arithmetic Left
        ALU(ReadRegister(operand1), operand2, 8);
        break;
    case 9: // Shift Arithmetic Right
        ALU(ReadRegister(operand1), operand2, 9);
        break;
    case 10: // Load to Register
        ALU(operand1, operand2, 10);
        break;
    case 11: // Store from Register
        ALU(operand1, operand2, 11);
        break;
    default:
        break;
    }
}


void ResetInstructionMemory(){
    for (int i = 0; i < 1024; i++)
    {
        instruction_memory[i].opcode = 0;
        instruction_memory[i].operand1 = 0;
        instruction_memory[i].value2 = 0;
        instruction_memory[i].type = 'R';
    }
    
}
