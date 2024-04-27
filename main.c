#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INSTRUCTION_LENGTH 100
int data_memory[1000];
int registers[16];
int pc = 0;
int instruction_memory[1000];

void execute_instruction(const char* instruction) {
    char* instruction_copy = strdup(instruction);
    char* token = strtok(instruction_copy, " ");
    if (strcmp(token, "ADD") == 0) {
        token = strtok(NULL, ", ");
        int dest_reg = atoi(token + 1);
        token = strtok(NULL, ", ");
        int src_reg1 = atoi(token + 1);
        token = strtok(NULL, ", ");
        int src_reg2 = atoi(token + 1);

        int result = ALU(ReadRegister(src_reg1), ReadRegister(src_reg2), 0);
        WriteRegister(dest_reg, result);
    } else if (strcmp(token, "SUB") == 0) {
        token = strtok(NULL, ", ");
        int dest_reg = atoi(token + 1);
        token = strtok(NULL, ", ");
        int src_reg1 = atoi(token + 1);
        token = strtok(NULL, ", ");
        int src_reg2 = atoi(token + 1);

        int result = ALU(ReadRegister(src_reg1), ReadRegister(src_reg2), 1);
        WriteRegister(dest_reg, result);
    } else if (strcmp(token, "MUL") == 0) {
        token = strtok(NULL, ", ");
        int dest_reg = atoi(token + 1);
        token = strtok(NULL, ", ");
        int src_reg1 = atoi(token + 1);
        token = strtok(NULL, ", ");
        int src_reg2 = atoi(token + 1);

        int result = ALU(ReadRegister(src_reg1), ReadRegister(src_reg2), 2);
        WriteRegister(dest_reg, result);
    } else if (strcmp(token, "DIV") == 0) {
        token = strtok(NULL, ", ");
        int dest_reg = atoi(token + 1);
        token = strtok(NULL, ", ");
        int src_reg1 = atoi(token + 1);
        token = strtok(NULL, ", ");
        int src_reg2 = atoi(token + 1);

        int result = ALU(ReadRegister(src_reg1), ReadRegister(src_reg2), 3);
        WriteRegister(dest_reg, result);
    } else if (strcmp(token, "AND") == 0) {
        token = strtok(NULL, ", ");
        int dest_reg = atoi(token + 1);
        token = strtok(NULL, ", ");
        int src_reg1 = atoi(token + 1);
        token = strtok(NULL , ", ");
        int src_reg2 = atoi(token + 1);
    }
}
int ReadDataMemory(int address) {
    return data_memory[address];
}
void WriteDataMemory(int address, int value) {
    data_memory[address] = value;
}
int ReadRegister(int reg) {
    return registers[reg];
}
void WriteRegister(int reg, int value) {
    registers[reg] = value;
}
int ReadInstructionMemory(int address) {
    return instruction_memory[address];
}
void WriteInstructionMemory(int address, int value) {
    instruction_memory[address] = value;
}
void IncrementPC() {
    pc++;
}
void SetPC(int value) {
    pc = value;
}
int GetPC() {
    return pc;
}
void ResetProcessor() {
    for (int i = 0; i < 1000; i++) {
        data_memory[i] = 0;
        instruction_memory[i] = 0;
    }
    for (int i = 0; i < 16; i++) {
        registers[i] = 0;
    }
    pc = 0;
}
void LoadProgram(const char* file_name) {
    FILE* file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Failed to open the program file.\n");
        return;
    }

    int address = 0;
    char line[MAX_INSTRUCTION_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        // Remove the newline character from the end of the instruction
        line[strcspn(line, "\n")] = '\0';

        WriteInstructionMemory(address, atoi(line));
        address++;
    }

    fclose(file);
}

int ALU (int operand1, int operand2, int operation) {
    switch (operation) {
        case 0: // ADD
            return operand1 + operand2;
        case 1: // SUB
            return operand1 - operand2;
        case 2: // MUL
            return operand1 * operand2;
        case 3: // DIV
            return operand1 / operand2;
        case 4: // AND
            return operand1 & operand2;
        case 5: // OR
            return operand1 | operand2;
        case 6: // XOR
            return operand1 ^ operand2;
        case 7: // NOT
            return ~operand1;
        case 8: // SHL
            return operand1 << operand2;
        case 9: // SHR
            return operand1 >> operand2;
        case 10: // MOD
            return operand1 % operand2;
        case 11: // CMP
            return operand1 - operand2;
        default:
            return 0;
    }
}



int main() {
    ResetProcessor();
    LoadProgram("assembly.txt");

    while (1) {
        int instruction = ReadInstructionMemory(GetPC());
        if (instruction == 0) {
            break;
        }

        execute_instruction("ADD R1, R2, R3");

        IncrementPC();
    }

    return 0;
}