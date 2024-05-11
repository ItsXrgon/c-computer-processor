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

## Instructions
| ID  | Instruction  | Opcode | Output           | Status Reg          |
| --- | -----------  | ------ | ---------------- | ------------------- |
| 0   | MOVI R0 20   | 3      | R0 = 20          | nth                 |
| 1   | MOVI R9 10   | 3      | R9 = 10          | nth                 |
| 2   | MOVI R2 15   | 3      | R2 = 15          | nth                 |
| 3   | MOVI R3 4    | 3      | R3 = 4           | nth                 |
| 4   | MOVI R4 3    | 3      | R4 = 3           | nth                 |
| 5   | MUL R9 2     | 2      | R9 = 10 x 2=20   | nth                 |
| 6   | ADD R9 3     | 0      | R9 = 20 x 3=60   | nth                 |
| 7   | MOVI R7 10   | 3      | R7 = 10          | nth                 |
| 8   | MOVI R6  1   | 3      | R6 = 1           | C = V = N = S = Z = |
| 9   | MUL R4 R7    | 2      | R4 = 10x3=30     | V = N = S = Z =     |
| 10  | MUL R0 R7    | 2      | R0 = 20x10=200   | N = Z =             |
| 11  | ADD R4 R0    | 0      | R4 = 30+200=230  | N = Z =             |
| 12  | SUB R4 R6    | 1      | R4 = 1-230=-229  | nth                 |
| 13  | SUB R9 R4    | 1      | R9 = -229-60=-289| nth                 |

## Registers

Register 0: 200
Register 2: 15
Register 3: 4
Register 4: 229
Register 6: 1
Register 7: 10
Register 9: -289

## Data Memory

## Instruction Memory

Instruction 0: Opcode:3  Register:0 Reg/IMM:20 Type:I
Instruction 1: Opcode:3  Register:9 Reg/IMM:10 Type:I
Instruction 2: Opcode:3  Register:2 Reg/IMM:15 Type:I
Instruction 3: Opcode:3  Register:3 Reg/IMM:4 Type:I
Instruction 4: Opcode:3  Register:4 Reg/IMM:3 Type:I
Instruction 5: Opcode:2  Register:9 Reg/IMM:2 Type:I
Instruction 6: Opcode:0  Register:9 Reg/IMM:3 Type:I
Instruction 7: Opcode:3  Register:7 Reg/IMM:10 Type:I
Instruction 8: Opcode:3  Register:6 Reg/IMM:1 Type:I
Instruction 9: Opcode: 2 Register:4 Reg/IMM:7 Type:R
Instruction 10: Opcode:2 Register:0 Reg/IMM:7 Type:R
Instruction 11: Opcode:0 Register:4 Reg/IMM:0 Type:R
Instruction 12: Opcode:1 Register:4 Reg/IMM:6 Type:R
Instruction 13: Opcode:1 Register:9 Reg/IMM:4 Type:R


# Test 3 

## Instructions

| ID  | Instruction | Opcode | Output         | Status Reg          |
| --- | ----------- | ------ | -------------- | ------------------- |
| 0   | MOVI R0 10  | 3      | R0 = 10        | nth                 |
| 1   | MOVI R1 10  | 3      | R1 = 10        | nth                 |
| 2   | MOVI R3 20  | 3      | R3 = 20        | nth                 |
| 3   | SUB R0 R1   | 1      | R0 = 10-10=0   | nth                 |
| 4   | BEQZ R0 0   | 4      | nth            | nth                 |
| 5   | ADD R3 R1   | 0      | R3 = 20+10=30  | nth                 |
| 6   | BR R0 R1    | 7      | nth            | nth                 |
| 7   | STR R0 0    | 11     | Mem[0]= 0      | nth                 |



smo please format into table

## Registers
Register 0: 0
Register 1: 10
Register 3: 30

## Data Memory

Address:0 DataMemory Data: 0


## Instruction Memory

Instruction 0: Opcode:3 Register:0 Reg/IMM:10 Type:I
Instruction 1: Opcode:3 Register:1 Reg/IMM:10 Type:I
Instruction 2: Opcode:3 Register:3 Reg/IMM:20 Type:I
Instruction 3: Opcode:1 Register:0 Reg/IMM:1 Type:R
Instruction 4: Opcode:4 Register:0 Reg/IMM:0 Type:I
Instruction 5: Opcode:0 Register:3 Reg/IMM:1 Type:R
Instruction 6: Opcode:7 Register:0 Reg/IMM:1 Type:R
Instruction 7: Opcode:11 Register:0 Reg/IMM:0 Type:I

# Test 4 

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
| 7   | ADD R2 R1   | 0      | R2 = 0 + 1 = 1 | C = V = N = S = Z = |
| 8   | SUB R3 R1   | 1      | R3 = 4 - 1 = 3 | V = N = S = Z =     |
| 9   | SAL R6 1    | 8      | R6 = 2         | N = Z =             |
| 10  | SAR R5 1    | 9      | R5 = 8         | N = Z =             |
| 11  | STR R5 0    | 11     | Mem[0] = 8     | nth                 |
| 12  | STR R6 1    | 11     | Mem[1] = 2     | nth                 |
| 13  | STR R2 2    | 11     | Mem[2] = 1     | nth                 |
| 14  | LDR R5 2    | 10     | R5 = 1         | nth                 |
| 15  | LDR R6 1    | 10     | R6 = 2         | nth                 |
| 16  | LDR R2 0    | 10     | R2 = 8         | nth                 |

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
Instruction 6: Opcode:4 Register:3 Reg/IMM:5 Type:I
Instruction 7: Opcode:0 Register:2 Reg/IMM:1 Type:R
Instruction 8: Opcode:1 Register:3 Reg/IMM:1 Type:R
Instruction 9: Opcode:8 Register:6 Reg/IMM:1 Type:I
Instruction 10: Opcode:9 Register:5 Reg/IMM:1 Type:I
Instruction 11: Opcode:11 Register:5 Reg/IMM:0 Type:I
Instruction 12: Opcode:11 Register:6 Reg/IMM:1 Type:I
Instruction 13: Opcode:11 Register:2 Reg/IMM:2 Type:I
Instruction 14: Opcode:10 Register:5 Reg/IMM:2 Type:I
Instruction 15: Opcode:10 Register:6 Reg/IMM:1 Type:I
Instruction 16: Opcode:10 Register:2 Reg/IMM:0 Type:I

# Test 5

## Instructions

| ID  | Instruction | Opcode | Output         | Status Reg          |
| --- | ----------- | ------ | -------------- | ------------------- |
| 0   | MOVI R0 0   | 3      | R0 = 0         | nth                 |
| 1   | MOVI R1 1   | 3      | R1 = 1         | nth                 |
| 2   | MOVI R2 0   | 3      | R2 = 0         | nth                 |
| 3   | MOVI R3 0   | 3      | R3 = 0         | nth                 |
| 4   | MOVI R4 7   | 3      | R4 = 7         | nth                 |
| 5   | MOVI R5 16  | 3      | R5 = 16        | nth                 |
| 6   | MOVI R6 1   | 3      | R6 = 1         | nth                 |
| 7   | BEQZ R3 5   | 4      | nth            | nth                 |
| 8   | ADD R2 R1   | 0      | R2 = 0 + 1 = 1 | C = V = N = S = Z = |
| 9   | SUB R3 R1   | 1      | R3 = 0 - 1 = -1| V = N = S = Z =     |
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
Register 3: -1
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
Instruction 3: Opcode:3 Register:3 Reg/IMM:0 Type:I
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

# Test 6


## Instructions

| ID  | Instruction | Opcode | Output         | Status Reg          |
| --- | ----------- | ------ | -------------- | ------------------- |
| 0   | MOVI R0 0   | 3      | R0 = 0         | nth                 |
| 1   | MOVI R1 16  | 3      | R1 = 16        | nth                 |
| 2   | MOVI R2 255 | 3      | R2 = 255       | nth                 |
| 3   | MOVI R3 4   | 3      | R3 = 4         | nth                 |
| 4   | MOVI R4 7   | 3      | R4 = 7         | nth                 |
| 5   | MOVI R5 16  | 3      | R5 = 16        | nth                 |
| 6   | MOVI R6 1   | 3      | R6 = 1         | nth                 |
| 7   | ADD R2 R1   | 0      | R2 =255+16=271 | C = V = N = S = Z = |
| 8   | SUB R3 R1   | 1      | R3 =16-4=12    | V = N = S = Z =     |
| 9   | SAL R6 1    | 8      | R6 = 2         | N = Z =             |
| 11  | SAR R5 1    | 9      | R5 = 8         | N = Z =             |


smo please format into table

## Registers
Register 0: 0
Register 1: 16
Register 2: 271
Register 3: 12
Register 4: 7
Register 5: 8
Register 6: 2

## Data Memory

## Instruction Memory

Instruction 0: Opcode:3 Register:0 Reg/IMM:0 Type:I
Instruction 1: Opcode:3 Register:1 Reg/IMM:16 Type:I
Instruction 2: Opcode:3 Register:2 Reg/IMM:255 Type:I
Instruction 3: Opcode:3 Register:3 Reg/IMM:4 Type:I
Instruction 4: Opcode:3 Register:4 Reg/IMM:7 Type:I
Instruction 5: Opcode:3 Register:5 Reg/IMM:16 Type:I
Instruction 6: Opcode:3 Register:6 Reg/IMM:1 Type:I
Instruction 7: Opcode:0 Register:2 Reg/IMM:1 Type:R
Instruction 8: Opcode:1 Register:3 Reg/IMM:1 Type:R
Instruction 9: Opcode:8 Register:6 Reg/IMM:1 Type:I
Instruction 10: Opcode:9 Register:5 Reg/IMM:1 Type:I

# Test 7 

## Instructions

| ID  | Instruction | Opcode | Output         | Status Reg          |
| --- | ----------- | ------ | -------------- | ------------------- |
| 0   | MOVI R0 0   | 3      | R0 = 0         | nth                 |
| 1   | MOVI R1 1   | 3      | R1 = 1         | nth                 |
| 2   | MOVI R2 128 | 3      | R2 = 128       | nth                 |
| 3   | MOVI R3 4   | 3      | R3 = 4         | nth                 |
| 4   | MOVI R4 7   | 3      | R4 = 7         | nth                 |
| 5   | MOVI R5 16  | 3      | R5 = 16        | nth                 |
| 6   | MOVI R6 3   | 3      | R6 = 3         | nth                 |
| 7   | SAL R6 2    | 8      | R6 = 12        | N = Z =             |
| 8   | SAR R5 R2   | 9      | R5 = 0         | N = Z =             |


smo please format into table

## Registers
Register 0: 0
Register 1: 1
Register 2: 128
Register 3: 4
Register 4: 7
Register 5: 0
Register 6: 12

## Data Memory

## Instruction Memory

Instruction 0: Opcode:3 Register:0 Reg/IMM:0 Type:I
Instruction 1: Opcode:3 Register:1 Reg/IMM:1 Type:I
Instruction 2: Opcode:3 Register:2 Reg/IMM:128 Type:I
Instruction 3: Opcode:3 Register:3 Reg/IMM:4 Type:I
Instruction 4: Opcode:3 Register:4 Reg/IMM:7 Type:I
Instruction 5: Opcode:3 Register:5 Reg/IMM:16 Type:I
Instruction 6: Opcode:3 Register:6 Reg/IMM:3 Type:I
Instruction 10: Opcode:8 Register:6 Reg/IMM:2 Type:I
Instruction 11: Opcode:9 Register:5 Reg/IMM:2 Type:R

