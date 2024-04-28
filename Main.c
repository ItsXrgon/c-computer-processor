#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALU.c"
#include "Registers.c"
#include "DataMemory.c"
#include "InstructionMemory.c"

#define MAX_INSTRUCTION_LENGTH 100

void execute_instruction(const char *instruction){
    char *instruction_copy = strdup(instruction);
    char *token = strtok(instruction_copy, " ");
    if (strcmp(token, "ADD") == 0)
    {
        token = strtok(NULL, ", ");
        int dest_reg = atoi(token + 1);
        token = strtok(NULL, ", ");
        int src_reg1 = atoi(token + 1);
        token = strtok(NULL, ", ");
        int src_reg2 = atoi(token + 1);

        int result = ALU(ReadRegister(src_reg1), ReadRegister(src_reg2), 0);
        WriteRegister(dest_reg, result);
    }
    else if (strcmp(token, "SUB") == 0)
    {
        token = strtok(NULL, ", ");
        int dest_reg = atoi(token + 1);
        token = strtok(NULL, ", ");
        int src_reg1 = atoi(token + 1);
        token = strtok(NULL, ", ");
        int src_reg2 = atoi(token + 1);

        int result = ALU(ReadRegister(src_reg1), ReadRegister(src_reg2), 1);
        WriteRegister(dest_reg, result);
    }
    else if (strcmp(token, "MUL") == 0)
    {
        token = strtok(NULL, ", ");
        int dest_reg = atoi(token + 1);
        token = strtok(NULL, ", ");
        int src_reg1 = atoi(token + 1);
        token = strtok(NULL, ", ");
        int src_reg2 = atoi(token + 1);

        int result = ALU(ReadRegister(src_reg1), ReadRegister(src_reg2), 2);
        WriteRegister(dest_reg, result);
    }
    else if (strcmp(token, "DIV") == 0)
    {
        token = strtok(NULL, ", ");
        int dest_reg = atoi(token + 1);
        token = strtok(NULL, ", ");
        int src_reg1 = atoi(token + 1);
        token = strtok(NULL, ", ");
        int src_reg2 = atoi(token + 1);

        int result = ALU(ReadRegister(src_reg1), ReadRegister(src_reg2), 3);
        WriteRegister(dest_reg, result);
    }
    else if (strcmp(token, "AND") == 0)
    {
        token = strtok(NULL, ", ");
        int dest_reg = atoi(token + 1);
        token = strtok(NULL, ", ");
        int src_reg1 = atoi(token + 1);
        token = strtok(NULL, ", ");
        int src_reg2 = atoi(token + 1);
    }
}









void ResetProcessor(){
    ResetDataMemory();
    ResetInstructionMemory();
    ResetRegisters();
}

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
        // Remove the newline character from the end of the instruction
        line[strcspn(line, "\n")] = '\0';

        WriteInstructionMemory(address, atoi(line));
        address++;
    }

    fclose(file);
}





int main(){
    ResetProcessor();
    LoadProgram("assembly.txt");

    while (1)
    {
        int instruction = ReadInstructionMemory(GetPC());
        if (instruction == 0)
        {
            break;
        }

        execute_instruction("ADD R1, R2, R3");

        IncrementPC();
    }

    return 0;
}
