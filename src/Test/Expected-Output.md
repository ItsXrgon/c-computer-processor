# Test 1

## Instructions

| ID  | Instruction | Opcode | Output         | Status Reg          |
| --- | ----------- | ------ | -------------- | ------------------- |
| 0   | MOVI R0 0   | 3      | R0 = 0         | nth                 |
| 1   | MOVI R1 1   | 3      | R1 = 1         | nth                 |
| 2   | MOVI R2 0   | 3      | R2 = 0         | nth                 |
| 3   | MOVI R3 4   | 3      | R3 = 4         | nth                 |
| 4   | MOVI R4 7   | 3      | R4 = 7         | nth                 |
| 5   | MOVI R5 16  | 3      | R5 = 16        | nth                 |
| 6   | MOVI R6 1   | 3      | R6 = 1         | nth                 |
| 7   | BEQZ R3 5   | 4      | nth            | nth                 |
| 8   | ADD R2 R1   | 0      | R2 = 0 + 1 = 1 | C = V = N = S = Z = |
| 9   | SUB R3 R1   | 1      | R3 = 4 - 1 = 3 | V = N = S = Z =     |
| 10  | SAL R6 1    | 8      | R6 = 2         | N = Z =             |
| 11  | SAR R5 1    | 9      | R5 = 8         | N = Z =             |
| 12  | STR R5 0    | 11     | Mem[0] = 8     | nth                 |
| 13  | STR R6 1    | 11     | Mem[1] = 2     | nth                 |
| 14  | STR R2 2    | 11     | Mem[2] = 1     | nth                 |
| 15  | LDR R5 2    | 10     | R5 = 1         | nth                 |
| 16  | LDR R6 1    | 10     | R6 = 2         | nth                 |
| 17  | LDR R2 0    | 10     | R2 = 8         | nth                 |

smo please format into table

## Registers

Register 1: 1
Register 2: 8
Register 3: 3
Register 4: 7
Register 5: 1
Register 6: 2

## Data Memory

Address:0 DataMemory Data: 8
Address:1 DataMemory Data: 2
Address:2 DataMemory Data: 1

## Instruction Memory

Instruction 0: Opcode:3 Register:0 Reg/IMM:0 Type:I
Instruction 1: Opcode:3 Register:1 Reg/IMM:1 Type:I
Instruction 2: Opcode:3 Register:2 Reg/IMM:0 Type:I
Instruction 3: Opcode:3 Register:3 Reg/IMM:4 Type:I
Instruction 4: Opcode:3 Register:4 Reg/IMM:7 Type:I
Instruction 5: Opcode:3 Register:5 Reg/IMM:16 Type:I
Instruction 6: Opcode:3 Register:6 Reg/IMM:1 Type:I
Instruction 7: Opcode:4 Register:3 Reg/IMM:5 Type:I
Instruction 8: Opcode:0 Register:2 Reg/IMM:1 Type:R
Instruction 9: Opcode:1 Register:3 Reg/IMM:1 Type:R
Instruction 10: Opcode:8 Register:6 Reg/IMM:1 Type:I
Instruction 11: Opcode:9 Register:5 Reg/IMM:1 Type:I
Instruction 12: Opcode:11 Register:5 Reg/IMM:0 Type:I
Instruction 13: Opcode:11 Register:6 Reg/IMM:1 Type:I
Instruction 14: Opcode:11 Register:2 Reg/IMM:2 Type:I
Instruction 15: Opcode:10 Register:5 Reg/IMM:2 Type:I
Instruction 16: Opcode:10 Register:6 Reg/IMM:1 Type:I
Instruction 17: Opcode:10 Register:2 Reg/IMM:0 Type:I

# Test 2
