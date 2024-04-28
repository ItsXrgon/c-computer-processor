#include "InstructionMemory/InstructionMemory.h"
#include "DataMemory/DataMemory.h"
#include "Registers/Registers.h"
#include "Main.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ClockCycle = 0;
int MaxClockCycles ;

void LoadProgram(const char *file_name){
    FILE *file = fopen(file_name, "r");
    if (file == NULL)
    {
        printf("Error: File not found\n");
        exit(1);
    }
    int address = 0;
    while (!feof(file))
    {
        Instruction instruction;
        char opcode[4];
        char operand1[3];
        char operand2[3];
        fscanf(file, "%s %s %s", opcode, operand1, operand2);
        instruction.opcode = incodeOpcode(opcode);
        instruction.operand1 = operand1[1];
        instruction.value2 = atoi(operand2);
        WriteInstructionMemory(address, instruction);
        address++;
    }
    MaxClockCycles = address +3;
    fclose(file);
}

void ResetProcessor(){
    ResetDataMemory();
    ResetInstructionMemory();
    ResetRegisters();
}

void PrintStatus() {
    printf("Clock Cycle: %d\n", ClockCycle);
    // Assuming you have functions to get the current instruction and parameters for each stage
//     printf("Fetch Stage: %s\n", GetCurrentFetchInstruction());
//     printf("Decode Stage: %s\n", GetCurrentDecodeInstruction());
}

int main(){
    ResetProcessor();
    LoadProgram("assembly.txt");

    // Program Workflow
    printf("Program Workflow:\n");
    printf("1. Reset Processor\n");
    printf("2. Load Program\n");
    printf("3. Execute Clock Cycles\n");

    // Execute Clock Cycles
    printf("Executing Clock Cycles:\n");
    while (ClockCycle < MaxClockCycles)
    {   

        Instruction instruction = fetch();
        decode(instruction);
        PrintStatus();
        ClockCycle++;
    }
    
    // Print final state of registers and memory
    printf("Final State of Registers:\n");
    PrintAllRegisters();
    printf("Final State of Memory:\n");
    PrintAllMemory();

    return 0;
}