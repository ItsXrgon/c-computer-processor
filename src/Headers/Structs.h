#ifndef Structs_H_INCLUDED
#define Structs_H_INCLUDED

/* ^^ these are the include guards */

#include <stdbool.h>

/**
 * @brief Represents an instruction in the processor.
 */
typedef struct {
    short opcode;       /**< The opcode of the instruction. */
    short operand1;     /**< The first operand of the instruction. */
    short value2;       /**< The second operand or immediate value or address. */
    char type;          /**< The type of the instruction. */
} Instruction;

/**
 * @brief Represents a stage in the processor pipeline.
 */
typedef struct {
    Instruction instruction;    /**< The instruction in the pipeline stage. */
    bool valid;                 /**< Indicates if the stage is valid. */
    short pcVal;                /**< The program counter value. to be able to print it out during the pipeline*/
} PipelineStage;

#endif
