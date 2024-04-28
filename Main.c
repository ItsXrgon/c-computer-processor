#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALU.c"
#include "Registers.c"
#include "DataMemory.c"
#include "InstructionMemory.c"

int ClockCycle = 0;

void ResetProcessor(){
    ResetDataMemory();
    ResetInstructionMemory();
    ResetRegisters();
}

void PrintStatus() {
    printf("Clock Cycle: %d\n", ClockCycle);
    // Assuming you have functions to get the current instruction and parameters for each stage
    printf("Fetch Stage: %s\n", GetCurrentFetchInstruction());
    printf("Decode Stage: %s\n", GetCurrentDecodeInstruction());
    // Print register and memory updates
    PrintRegisterUpdates();
    PrintMemoryUpdates();
}

int main(){
    ResetProcessor();
    LoadProgram("assembly.txt");
    while (true)
    {
        fetch();
        decode();
        PrintStatus();
        ClockCycle++;
    }
    
    // Print final state of registers and memory
    PrintAllRegisters();
    PrintAllMemory();

    return 0;
}