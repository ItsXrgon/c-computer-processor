#include "../Headers/InstructionMemory.h"



int MaxClockCycles ;
int clockcycles = 1;
extern Instruction instruction_memory[1024];
extern PipelineStage pipeline1;
extern PipelineStage pipeline2;
extern PipelineStage pipeline3;
extern PipelineStage pipeline4;
extern unsigned short DataMemory[1024];
extern int Registers[64];
extern int SREG[8]; // SREG[0] = C, SREG[1] = V, SREG[2] = N, SREG[3] = S, SREG[4] = Z
extern int pc;

void LoadProgram(char* file_name){
    FILE* file = fopen(file_name, "r");
    if (file == NULL)
    {
        printf("Error: Assembly file not found\n");
        printf("Please make sure the file exists\n");
        printf("Exiting...\n");
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
        instruction.operand1 = operand1[1] - '0';
        switch (instruction.opcode)
        {
        case 0:
        case 1:
        case 2:
        case 5:
        case 6:
            instruction.value2 = operand2[1] - '0';
            break;
        case 3:
        case 4:
        case 7:
        case 8:
        case 9:
        case 10:
            instruction.value2 = atoi(operand2);
            break;
        }
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

int main() {
    ResetProcessor();
    LoadProgram("/home/youssef/Documents/Guc/CA/project/c-computer-processor/src/Test/test2.txt");
    // Initialize pipeline stages
    PipelineStage IF = { .valid = 0 };
    PipelineStage ID = { .valid = 0 };
    PipelineStage EX = { .valid = 0 };

    printf("Program Workflow:\n");
    printf("1. Reset Processor\n");
    printf("2. Load Program\n");
    printf("3. Execute Clock Cycles\n");

    printf("Executing Clock Cycles:\n");
    Instruction instruction = ReadInstructionMemory(GetPC());
    while (
        ((&instruction != NULL)
     || (pipeline2.valid == true) 
     || (pipeline4.valid == true)) && (clockcycles < MaxClockCycles)) {

            printf("Cycle: %i \n", clockcycles);

            fetchPipeline();

            decodePipeline();

            excutePipeline();

            clockcycles++;
            printf("-------------------------------------------------- \n");

            instruction = ReadInstructionMemory(GetPC());
        }
    
    
    // Print final state of registers and memory
    printf("Final State of Registers:\n");

    PrintAllRegisters();

    printf("Final State of Data Memory: \n");

    PrintAllDataMemory();

    printf("Final State of Instruction Memory: \n");

    PrintAllInstructionMemory();

    return 0;
}