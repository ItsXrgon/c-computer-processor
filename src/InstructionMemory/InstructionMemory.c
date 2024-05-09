#include "../Headers/Registers.h"
#include "../Headers/Structs.h"
#include "../Headers/ALU.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables
short int instruction_memory[1024];
FetchedInstruction pipeline1; // Saving the fetched instruction to hand over to decode stage next CC
PipelineStage pipeline2; // holds the instruction to be decoded
PipelineStage pipeline3; // Saving the decoded instruction to hand over to excute stage next CC
PipelineStage pipeline4; // holds the instruction to be executed


// Function to reset the pipeline stages
void ResetPipeline() {
    pipeline2.valid = false;
    pipeline3.valid = false;
    pipeline4.valid = false;
    pipeline1.pcVal = 0;
    pipeline2.pcVal = 0;
    pipeline3.pcVal = 0;
    pipeline4.pcVal = 0;
    pipeline2.instruction.opcode = -1;
    pipeline3.instruction.opcode = -1;
    pipeline4.instruction.opcode = -1;
    pipeline2.instruction.operand1 = 0;
    pipeline3.instruction.operand1 = 0;
    pipeline4.instruction.operand1 = 0;
    pipeline2.instruction.value2 = 0;
    pipeline3.instruction.value2 = 0;
    pipeline4.instruction.value2 = 0;
    pipeline2.instruction.type = 'R';
    pipeline3.instruction.type = 'R';
    pipeline4.instruction.type = 'R';

    pipeline1.instruction = 0;
    
}

// Function to convert opcode string to corresponding opcode value
uint8_t incodeOpcode(char *opcode)
{
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
    else if (strcmp(opcode, "MOVI") == 0)
    {
        return 3;
    }
    else if (strcmp(opcode, "BEQZ") == 0)
    {
        return 4;
    }
    else if (strcmp(opcode, "ANDI") == 0)
    {
        return 5;
    }
    else if (strcmp(opcode, "EOR") == 0)
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
    else if (strcmp(opcode, "LDR") == 0)
    {
        return 10;
    }
    else if (strcmp(opcode, "STR") == 0)
    {
        return 11;
    }
    else
    {
        return -1;
    }
}


uint8_t GetOpcode(short int instruction)
{
    return instruction >> 12;
}
uint8_t GetOperand1(short int instruction)
{
    return (instruction >> 6) & 0x3F;
}

uint8_t GetValue2(short int instruction)
{
    return instruction & 0x3F;
}

char GetOpcodeType(uint8_t opcode)
{
    switch (opcode)
    {
    case 0:
    case 1:
    case 2:
    case 6:
    case 7:
        return 'R';
    case 3:
    case 4:
    case 5:
    case 8:
    case 9:
    case 10:
    case 11:
        return 'I';
    default:
        return 'R';
    }
}

// Function to write an instruction to the instruction memory at the given address
void WriteInstructionMemory(int address, short int instruction)
{
    instruction_memory[address] = instruction;
}

// Function to read an instruction from the instruction memory at the given address
short int ReadInstructionMemory(int address)
{
    return instruction_memory[address];
}

// Function to fetch an instruction from the instruction memory and update the fetch pipeline stage
void fetchPipeline()
{
    short int instruction = ReadInstructionMemory(GetPC());
    if (instruction == -1) {
        printf("No more Instructions\n");
        pipeline1.valid = false;
        return;
    }
    else
    {
        pipeline1.instruction = instruction;
        pipeline1.valid = 1;
        pipeline1.pcVal = GetPC();

        printf("Fetched Instruction %d: Opcode:%d  Register:%d Reg/IMM:%d Type:%c\n",
               pipeline1.pcVal,
               GetOpcode(instruction),
                GetOperand1(instruction),
                GetValue2(instruction),
                GetOpcodeType(GetOpcode(instruction)));
        IncrementPC();
    }
}
Instruction decode(short int instruction)
{
    Instruction ins;
    ins.opcode = GetOpcode(instruction);
    ins.operand1 = GetOperand1(instruction);
    ins.value2 = GetValue2(instruction);
    ins.type = GetOpcodeType(ins.opcode);
    return ins;
}

// Function to decode the instruction in the decode pipeline stage and update the execute pipeline stage
void decodePipeline()
{
    if (pipeline2.valid)
    {
        pipeline3.instruction = pipeline2.instruction;
        pipeline3.pcVal = pipeline2.pcVal;
        pipeline3.valid = true;
        pipeline2.valid = false;
        printf("Decoded Instruction %d : Opcode:%d  Register:%d Reg/IMM:%d Type:%c\n",
               pipeline2.pcVal,
               pipeline2.instruction.opcode,
               pipeline2.instruction.operand1,
               pipeline2.instruction.value2,
               pipeline2.instruction.type);
    }
    else
    {
        printf("No instruction to be decoded \n");
    }

    if (pipeline1.valid)
    {
        pipeline2.instruction = decode(pipeline1.instruction);
        pipeline2.pcVal = pipeline1.pcVal;
        pipeline2.valid = true;
    }
}

// Function to execute the instruction in the execute pipeline stage
void executePipeline()
{
    if (pipeline4.valid)
    {
        printf("Executed Instruction %d: Opcode:%d  Register:%d Reg/IMM:%d Type:%c\n",
               pipeline4.pcVal,
               pipeline4.instruction.opcode,
               pipeline4.instruction.operand1,
               pipeline4.instruction.value2,
               pipeline4.instruction.type);
        execute(pipeline4.instruction);
        pipeline4.valid = false;
    }
    else
    {
        printf("No instruction to be executed\n");
    }

    if (pipeline3.valid)
    {
        pipeline4.instruction = pipeline3.instruction;
        pipeline4.pcVal = pipeline3.pcVal;
        pipeline4.valid = true;
        pipeline3.valid = false;
    }
    else
    {
        pipeline4.valid = false;
    }
}



// Function to execute the given instruction
void execute(Instruction ins)
{
    switch (ins.opcode)
    {
    case 0:
        ADD(ins.operand1, ins.value2);
        break;
    case 1:
        SUB(ins.operand1, ins.value2);
        break;
    case 2:
        MUL(ins.operand1, ins.value2);
        break;
    case 3:
        MOVI(ins.operand1, ins.value2);
        break;
    case 4:
        BEQZ(ins.operand1, ins.value2);
        break;
    case 5:
        ANDI(ins.operand1, ins.value2);
        break;
    case 6:
        EOR(ins.operand1, ins.value2);
        break;
    case 7:
        BR(ins.operand1, ins.value2);
        break;
    case 8:
        SAL(ins.operand1, ins.value2);
        break;
    case 9:
        SAR(ins.operand1, ins.value2);
        break;
    case 10:
        LDR(ins.operand1, ins.value2);
        break;
    case 11:
        STR(ins.operand1, ins.value2);
        break;
    default:
        break;
    }
}

// Function to reset the instruction memory
void ResetInstructionMemory()
{
    for (int i = 0; i < 1024; i++)
    {
        instruction_memory[i] = -1;
    }
}

// Function to print all instructions in the instruction memory
void PrintAllInstructionMemory()
{
    for (int i = 0; i < 1024; i++)
    {
        if (instruction_memory[i] != -1)
        {
            printf("Instruction %d: Opcode:%d  Register:%d Reg/IMM:%d Type:%c\n",
                   i,
                   GetOpcode(instruction_memory[i]),
                   GetOperand1(instruction_memory[i]),
                   GetValue2(instruction_memory[i]),
                   GetOpcodeType(GetOpcode(instruction_memory[i])));
        }
    }
}
