#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INSTRUCTION_LENGTH 100
int data_memory[2048][8];
int generalRegisters[64];
int SREG[5]; // SREG[0] = C, SREG[1] = V, SREG[2] = N, SREG[3] = S, SREG[4] = Z
int pc = 0;
int instruction_memory[1024][16];

void execute_instruction(const char *instruction)
{
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

int ReadDataMemory(int address)
{
    return data_memory[address];
}

void WriteDataMemory(int address, int value)
{
    data_memory[address] = value;
}

int ReadRegister(int reg)
{
    return registers[reg];
}

void WriteRegister(int reg, int value)
{
    registers[reg] = value;
}

int ReadInstructionMemory(int address)
{
    return instruction_memory[address];
}

void WriteInstructionMemory(int address, int value)
{
    instruction_memory[address] = value;
}

void IncrementPC()
{
    pc++;
}

void SetPC(int value)
{
    pc = value;
}

int GetPC()
{
    return pc;
}

void ResetProcessor()
{
    for (int i = 0; i < 1000; i++)
    {
        data_memory[i] = 0;
        instruction_memory[i] = 0;
    }
    for (int i = 0; i < 16; i++)
    {
        registers[i] = 0;
    }
    pc = 0;
}

void LoadProgram(const char *file_name)
{
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

void updateCarryFlag(int operand1, int operand2, int result)
{
    if (result < operand1 || result < operand2)
    {
        SREG[0] = 1;
    }
    else
    {
        SREG[0] = 0;
    }
}

void updateOverflowFlag(int operand1, int operand2, int result)
{
    if (operand1 > 0 && operand2 > 0 && result < 0)
    {
        SREG[1] = 1;
    }
    else if (operand1 < 0 && operand2 < 0 && result > 0)
    {
        SREG[1] = 1;
    }
    else
    {
        SREG[1] = 0;
    }
}

void updateNegativeFlag(int result)
{
    if (result < 0)
    {
        SREG[2] = 1;
    }
    else
    {
        SREG[2] = 0;
    }
}

void updateSignFlag(int result)
{
    if (result == 0)
    {
        SREG[3] = 1;
    }
    else
    {
        SREG[3] = 0;
    }
}

void updateZeroFlag(int result)
{
    if (result == 0)
    {
        SREG[4] = 1;
    }
    else
    {
        SREG[4] = 0;
    }
}

int ALU(int operand1, int operand2, int operation)
{
    int result;
    switch (operation)
    {
    case 0: // ADD
        result = operand1 + operand2;
        updateCarryFlag(operand1, operand2, result);
        updateOverflowFlag(operand1, operand2, result);
        updateNegativeFlag(result);
        updateSignFlag(result);
        updateZeroFlag(result);
        return result;
    case 1: // SUB
        result = operand1 - operand2;
        updateOverflowFlag(operand1, operand2, result);
        updateNegativeFlag(result);
        updateSignFlag(result);
        updateZeroFlag(result);
        return result;
    case 2: // MUL
        out = operand1 * operand2;
        updateNegativeFlag(result);
        updateZeroFlag(result);
        return result;
    case 3: // Move immediate
        WriteRegister(operand1, operand2);
        return 0;
    case 4: // Branch if equal zero
        if (operand1 == 0)
        {
            SetPC(operand2);
        }
        return 0;
    case 5: // AND Immediate
        result = operand1 & operand2;
        updateNegativeFlag(result);
        updateZeroFlag(result);
        return result;
    case 6: // Exclusive OR
        result = operand1 ^ operand2;
        updateNegativeFlag(result);
        updateZeroFlag(result);
    case 7: // Branch Register
        SetPC(operand1 || operand2);
        return 0;
    case 8: // Shift Arithmetic Left
        result = operand1 << operand2;
        updateNegativeFlag(result);
        updateZeroFlag(result);
        return result;
    case 9: // Shift Arithmetic Right
        result = operand1 >> operand2;
        updateNegativeFlag(result);
        updateZeroFlag(result);
        return result;
    case 10: // Load to Register
        WriteRegister(operand1, ReadDataMemory(operand2));
        return 0;
    case 11: // Store from Register
        WriteDataMemory(operand1, ReadRegister(operand2));
        return operand1;
    default:
        return 0;
    }
}

int main()
{
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