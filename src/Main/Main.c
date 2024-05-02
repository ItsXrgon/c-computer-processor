/**
 * @file Main.c
 * @brief This file contains the main function and related functions for the computer processor simulation.
 */

#include "../Headers/InstructionMemory.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MaxClockCycles ; // Global variable in main.c gets init in load program function after the while loop 
int clockcycles = 1; // global var to track the current clock cycle for the program
extern Instruction instruction_memory[1024]; /**< External array representing the instruction memory. */
extern PipelineStage pipeline1; /**< External variable representing the first pipeline stage. */
extern PipelineStage pipeline2; /**< External variable representing the second pipeline stage. */
extern PipelineStage pipeline3; /**< External variable representing the third pipeline stage. */
extern PipelineStage pipeline4; /**< External variable representing the fourth pipeline stage. */
extern unsigned short DataMemory[1024]; /**< External array representing the data memory. */
extern int Registers[64]; /**< External array representing the registers. */
extern int SREG[8]; /**< External array representing the status register. SREG[0] = C, SREG[1] = V, SREG[2] = N, SREG[3] = S, SREG[4] = Z */
extern int pc; /**< External variable representing the program counter. */


/**
 * @brief Loads the program from the given file into the instruction memory.
 * 
 * @param file_name The name of the assembly file to load.
 */
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
    /**
     * This while loop continues until the end of the file is reached.
     * It checks if the end-of-file indicator for the given file stream is set.
     * The feof() function returns a non-zero value if the end-of-file indicator is set,
     * and 0 otherwise.
     */
    while (!feof(file))
    {
        Instruction instruction;
        char opcode[4];
        char operand1[3];
        char operand2[3];
        /**
         * Reads three strings from the file using the specified format and stores them in the given variables.
         *
         * @param file The file to read from.
         * @param opcode The variable to store the first string.
         * @param operand1 The variable to store the second string.
         * @param operand2 The variable to store the third string.
         *
         * @return The number of items successfully read and assigned, or EOF if an error occurred.
         */
        fscanf(file, "%s %s %s", opcode, operand1, operand2);
        instruction.opcode = incodeOpcode(opcode);// incodes the opcode string to int
        instruction.operand1 = operand1[1] - '0'; 
        /**
         * This switch statement assigns values to the `instruction.value2` and `instruction.type` variables based on the `instruction.opcode`.
         * 
         * For cases where the instruction is of type R, the second input is a register address and is assigned to `instruction.value2`.
         * For cases where the instruction is of type I, the second input is an immediate value and is converted to an integer using `atoi()` and assigned to `instruction.value2`.
         * 
         * @param instruction The instruction struct containing the opcode, value2, and type.
         * @param operand2 The second operand of the instruction.
         */
        switch (instruction.opcode)
        {
            // Cases that the Instruction is of Type R, therefore the second input is a Register address
            case 0:
            case 1:
            case 2:
            case 6:
            case 7:
                instruction.value2 = operand2[1] - '0';
                instruction.type = 'R';
                break;
            // Cases that the Instruction is of Type I, therefore the second input is an IMM Value
            case 3:
            case 4:
            case 5:
            case 8:
            case 9:
            case 10:
            case 11:
                instruction.value2 = atoi(operand2);
                instruction.type = 'I';
                break;
        }
        WriteInstructionMemory(address, instruction);
        address++;
    }
    MaxClockCycles = address +3;
    fclose(file);
}

/**
 * @brief Resets the processor by resetting the data memory, instruction memory, and registers.
 */
void ResetProcessor(){
    ResetDataMemory();
    ResetInstructionMemory();
    ResetRegisters();
}

/**
 * @brief The main function that simulates the computer processor.
 * 
 * @return 0 indicating successful execution.
 */
int main() {
    ResetProcessor();
    //Only works with absolute path of the txt file
    LoadProgram("/home/youssef/Documents/Guc/CA/project/c-computer-processor/src/Test/assembly.txt");

    Instruction instruction = ReadInstructionMemory(GetPC());
    /**
     * This function represents the main loop of the processor. It executes the pipeline stages
     * (fetch, decode, execute) until certain conditions are met.
     *
     * Conditions for loop termination:
     *  - The instruction pointer is not NULL (needed for the first instruction and to check if there are instructions left to fetch)
     *  - The second pipeline stage (pipeline2) is valid, indicating that the last decode operation is still in progress
     *  - The fourth pipeline stage (pipeline4) is valid, indicating that the last execute operation is still in progress
     *  - The number of clock cycles is less than the maximum allowed clock cycles (MaxClockCycles)
     *
     * Inside the loop, the current clock cycle is printed, and the fetch, decode, and execute pipeline stages are executed.
     * After each iteration, the clock cycle is incremented, and a separator line is printed.
     * Finally, the instruction pointer is updated by reading the instruction memory at the current program counter (PC).
     */
    while (((&instruction != NULL) || (pipeline2.valid == true) || (pipeline4.valid == true)) && (clockcycles < MaxClockCycles)) {
        printf("Cycle: %i \n", clockcycles);

        fetchPipeline();

        decodePipeline();

        executePipeline();

        clockcycles++;
        printf("-------------------------------------------------- \n");

        instruction = ReadInstructionMemory(GetPC());
    }
    
    
    /**
     * Prints the final state of registers and memory.
     * Calls the functions to print the final state of registers, data memory, and instruction memory.
     */
    printf("Final State of Registers:\n");

    PrintAllRegisters(); 

    printf("Final State of Data Memory: \n");

    PrintAllDataMemory();

    printf("Final State of Instruction Memory: \n");

    PrintAllInstructionMemory(); 

    return 0;
}