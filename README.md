# c-computer-processor

# Double Big Harvard combo large arithmetic shifts

## Program Flow

- You must write your program in assembly language in a text file.
- Your must read the instructions from the text file, and parse them according to their types/formats (opcode and other relevant fields).
- You must store the parsed version of the instructions in the instruction memory.
- You should start the execution of your pipelined implementation by fetching the first instruction from the instruction memory at Clock Cycle 1.
- You should continue the execution based on the example provided in the Datapath section of each package reflecting the different stages working in parallel.

## Printings

The following items must be printed in the console after each Clock Cycle:

1. The Clock Cycle number.

2. The Pipeline stages:

   - Which instruction is being executed at each stage?
   - What are the input parameters/values for each stage?

3. The updates occurring to the registers in case a register value was changed.

4. The updates occurring in the data memory in case a value was stored or updated in the memory.
5. The content of all registers after the last clock cycle.
6. The full content of the instruction and data memories after the last clock cycle.

## Data Path

a. Stages: 3

All instructions regardless of their type must pass through all 3 stages.

1. Instruction Fetch (IF):
   - Fetches the next instruction from the main memory using the address in the PC (Program Counter), and increments the PC.
2. Instruction Decode (ID):
   - Decodes the instruction and reads any operands required from the register file.
3. Execute (EX):

   - all ALU operations are done in this stage.
   - it performs any memory access required by the current instruction:
     - loads: it would load an operand from the main memory,
     - stores: it would store an operand into the main memory.
     - instructions that have a result (a destination register): it writes this result back to the register file.

b. Pipeline: 3 instructions (maximum) running in parallel

1.  Number of clock cycles:

    - 3 + ((n - 1) \* 1), where n = number of instructions

- Example a program with 7 instructions:
  - 3 + (6 \* 1) = 9 clock cycles

You are required to understand the pattern in the example and implement it.

## Instruction Set Architecture

1. Instruction Size: 16 bits
2. Instruction Types: 2
3. Instruction Count: 12

- The opcodes are from 0 to 11 according to the instructions order in the following table:

  | Name                   | Format         | Operation                       |
  | ---------------------- | -------------- | ------------------------------- |
  | Add                    | ADD R1 R2      | R1 = R1 + R2                    |
  | Subtract               | SUB R1 R2      | R1 = R1 - R2                    |
  | Multiply               | MUL R1 R2      | R1 = R1 \* R2                   |
  | Move Immediate         | MOVI R1 IMM    | R1 = IMM                        |
  | Branch if Equal Zero   | BEQZ R1 IMM    | if(R1 == 0){PC = PC + 1 + IMM } |
  | And IMM                | ANDI R1 IMM    | R1 = R1 & IMM                   |
  | Exclusive OR           | EOR R1 R2      | R1 = R1 XOR R2                  |
  | Branch Register        | BR R1 R2       | PC = R1 concat R2               |
  | Shift Arithmetic left  | SAL R1 IMM     | R1 = R1 << IMM                  |
  | Shift Arithmetic Right | SAR R1 IMM     | R1 = R1 >> IMM                  |
  | load to Register       | LDR R1 Address | R1 = MEM[Address]               |
  | Store from Register    | STR R1 Address | MEM[Address] = R1               |
