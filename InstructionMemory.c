#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALU.c"
#include "Registers.c"
#include "DataMemory.c"

int instruction_memory [1024];
#define MAX_INSTRUCTION_LENGTH 100

void LoadProgram(const char *file_name){
    FILE *file = fopen(file_name, "r");
    if (file == NULL)
    {
        printf("Failed to open the program file.\n");
        return;
    }

    int address = 0;
    char line[MAX_INSTRUCTION_LENGTH];
    while (fgets(line, sizeof(line), file))
    {
        int instruction = atoi(line);
        
        address++;
    }

    fclose(file);
}

void WriteInstructionMemory(int address, int value){
    instruction_memory[address] = value;
}

int ReadInstructionMemory(int address){
    return instruction_memory[address];
}

int fetch(){
    int instruction = ReadInstructionMemory(GetPC());
    IncrementPC();
    return instruction;
}

void decode(int instruction){
    int opcode = instruction >> 12;
    int operand1 = (instruction >> 8) & 0xF;
    int operand2 = instruction & 0xFF;
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
        for (int j = 0; j < 16; j++)
        {
            instruction_memory[i] = 0;
        }
    }
}