#include "../Headers/Registers.h"
#include "../Headers/Structs.h"
#include "../Headers/ALU.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Instruction instruction_memory [1024];
PipelineStage pipeline1;
PipelineStage pipeline2;
PipelineStage pipeline3;
PipelineStage pipeline4;

short incodeOpcode(char *opcode){
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

void fetchPipeline() {
    Instruction instruction = ReadInstructionMemory(GetPC());
    if ( &instruction == NULL)
    {
        printf("No more Instructions\n");
        pipeline1.valid = 0;
        return;
    }
    else{

        pipeline1.instruction = instruction;
        pipeline1.valid = 1;
        pipeline1.pcVal = GetPC();

        printf("Fetched Instruction: %d %d %d %c\n", instruction.opcode, instruction.operand1, instruction.value2, instruction.type);
        IncrementPC();
    }
 }

void decodePipeline() {
   if(pipeline2.valid) {
            pipeline3.instruction = pipeline2.instruction;
            pipeline3.pcVal = pipeline2.pcVal;
            pipeline3.valid = true;
            pipeline2.valid = false;
            printf("Decoded Instruction: %d %d %d %c\n", pipeline2.instruction.opcode, pipeline2.instruction.operand1, pipeline2.instruction.value2, pipeline2.instruction.type);
        }
    else {
            printf("No instruction to be decoded \n");
        }
    if(pipeline1.valid){
            pipeline2.instruction = pipeline1.instruction;
            pipeline2.pcVal = pipeline1.pcVal;
            pipeline2.valid = true;
        }
}

void excutePipeline(){
    if (pipeline4.valid)
    {
        printf("Instruction executed %d %d %d %c\n", pipeline4.instruction.opcode, pipeline4.instruction.operand1, pipeline4.instruction.value2, pipeline4.instruction.type);
        execute(pipeline4.instruction);
        pipeline4.valid = false;
    }
    else {
        printf("No instruction to be executed\n");
    }
    if (pipeline3.valid)
    {
        pipeline4.instruction = pipeline3.instruction;
        pipeline4.pcVal = pipeline3.pcVal;
        pipeline4.valid = true;
        pipeline3.valid = false;
    }
    else {
        pipeline4.valid = false;
    }
}

void execute(Instruction ins){
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


void ResetInstructionMemory(){
    for (int i = 0; i < 1024; i++)
    {
        instruction_memory[i].opcode = 0;
        instruction_memory[i].operand1 = 0;
        instruction_memory[i].value2 = 0;
        instruction_memory[i].type = 'R';
    }
}

void PrintAllInstructionMemory(){
    for (int i = 0; i < 1024; i++)
    {
        if (instruction_memory[i].opcode != 0)
        {
            printf("%d: %d %d %d %c\n", i, instruction_memory[i].opcode, instruction_memory[i].operand1, instruction_memory[i].value2, instruction_memory[i].type);
        }
    }
    
}
