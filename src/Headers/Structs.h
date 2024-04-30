#ifndef Structs_H_INCLUDED
#define Structs_H_INCLUDED

/* ^^ these are the include guards */
#include <stdbool.h>
typedef struct {
    short opcode;
    short operand1;
    short value2;//operand2 or immediate value or address
    char type;
}Instruction;

typedef struct {
    Instruction instruction;
    bool valid;
    short pcVal;
    Instruction fetched;
} PipelineStage;

#endif