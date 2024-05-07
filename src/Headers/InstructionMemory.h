#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

/* ^^ these are the include guards */

/* 
 * Prototypes for the functions
 */

#include "Structs.h"


/**
 * @brief Resets the pipeline.
 *
 * This function is responsible for resetting the pipeline in the computer processor.
 * It clears any stored instructions and prepares the pipeline for the execution of new instructions.
 */
void ResetPipeline();

/**
 * @brief Converts the opcode string to its corresponding integer value.
 * 
 * @param opcode The opcode string to be converted.
 * @return The integer value of the opcode.
 */
int incodeOpcode(char* opcode);

/**
 * @brief Writes an instruction to the instruction memory at the specified address.
 * 
 * @param address The address in the instruction memory where the instruction will be written.
 * @param instruction The instruction to be written.
 */
void WriteInstructionMemory(int address, Instruction instruction);

/**
 * @brief Reads an instruction from the instruction memory at the specified address.
 * 
 * @param address The address in the instruction memory from where the instruction will be read.
 * @return The instruction read from the instruction memory.
 */
Instruction ReadInstructionMemory(int address);

/**
 * @brief Fetches the next instruction from the instruction memory and updates the pipeline.
 */
void fetchPipeline();

/**
 * @brief Decodes the instruction in the pipeline and prepares the necessary data for execution.
 */
void decodePipeline();

/**
 * @brief Executes the instruction in the pipeline.
 */
void executePipeline();

/**
 * @brief Executes the given instruction.
 * 
 * @param ins The instruction to be executed.
 */
void execute(Instruction ins);

/**
 * @brief Resets the instruction memory, clearing all instructions.
 */
void ResetInstructionMemory();

/**
 * @brief Prints all instructions in the instruction memory.
 */
void PrintAllInstructionMemory();

#endif
