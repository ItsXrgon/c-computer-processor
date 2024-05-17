# MOVI Test

## Instructions

| ID  | Instruction | Opcode | Output   | Status Reg | Notes                    |
| --- | ----------- | ------ | -------- | ---------- | ------------------------ |
| 0   | MOVI R0 0   | 3      | R0 = 0   | nth        |                          |
| 1   | MOVI R1 2   | 3      | R1 = 2   | nth        |                          |
| 2   | MOVI R2 4   | 3      | R2 = 4   | nth        |                          |
| 3   | MOVI R3 -2  | 3      | R3 = -2  | nth        | # doesn't input negative |
| 4   | MOVI R4 40  | 3      | R4 = 40  | nth        | # R4 = -24               |
| 5   | MOVI R5 200 | 3      | R5 = 200 | nth        |                          |
| 6   | MOVI R6 20  | 3      | R6 = 20  | nth        |                          |
| 7   | MOVI R7 -1  | 3      | R7 = -1  | nth        | # abort here             |
| 8   | MOVI R8 -5  | 3      | R8 = -5  | nth        |                          |
| 9   | MOVI R9 -5  | 3      | R9 = -5  | nth        |                          |

## Registers

| Register | Value |
| -------- | ----- |
| 0        | 0     |
| 1        | 2     |
| 2        | 4     |
| 3        | -2    |
| 4        | 40    |
| 5        | 200   |
| 6        | 20    |
| 7        | -1    |
| 8        | -5    |
| 9        | -5    |

## Data Memory

| Address | Data |
| ------- | ---- |

## Instruction Memory

| Instruction | Opcode | Register | Reg/IMM | Type |
| ----------- | ------ | -------- | ------- | ---- |
| 0           | 3      | 0        | 0       | I    |
| 1           | 3      | 1        | 2       | I    |
| 2           | 3      | 2        | 4       | I    |
| 3           | 3      | 3        | -2      | I    |
| 4           | 3      | 4        | 40      | I    |
| 5           | 3      | 5        | 200     | I    |
| 6           | 3      | 6        | 20      | I    |
| 7           | 3      | 7        | -1      | I    |
| 8           | 3      | 8        | -5      | I    |
| 9           | 3      | 9        | -5      | I    |

# ADD Test

## Instructions

| ID  | Instruction | Opcode | Output              | Status Reg                  | Notes                             |
| --- | ----------- | ------ | ------------------- | --------------------------- | --------------------------------- |
| 0   | MOVI R0 -20 | 3      | R0 = -20            | nth                         | # doesn't show input negative     |
| 1   | MOVI R1 -10 | 3      | R1 = -10            | nth                         | # doesn't show input negative     |
| 2   | MOVI R2 15  | 3      | R2 = 15             | nth                         |                                   |
| 3   | MOVI R3 14  | 3      | R3 = 14             | nth                         |                                   |
| 4   | MOVI R4 3   | 3      | R4 = 3              | nth                         |                                   |
| 5   | MOVI R5 0   | 3      | R5 = 0              | nth                         |                                   |
| 6   | ADD R0 10   | 0      | R0 = -20 + 10 = -10 | C = V = S = Z = 0, N = 1    | # Need Nasser to take a look here |
| 7   | ADD R3 R0   | 0      | R3 = 14             | C = V = N = S = Z = 0       |                                   |
| 8   | ADD R1 10   | 0      | R1 = -10 + 10 = 0   | C = V = N = 0, S = 1, Z = 1 |                                   |
| 9   | ADD R3 R1   | 0      | R3 = 14             | nth                         |                                   |
| 10  | ADD R2 15   | 0      | R2 = 15 + 15 = 30   | C = V = N = S = Z = 0       | #output stays the same            |
| 11  | ADD R2 15   | 0      | R2 = 30 + 15 = 45   | C = V = N = S = Z = 0       | #output satys the same            |
| 12  | ADD R4 2    | 0      | R4 = 3 + 2 = 5      | C = V = N = S = Z = 0       | #no output                        |
| 13  | ADD R4 5    | 0      | R4 = 5 + 5 = 10     | C = V = N = S = Z = 0       | #no output                        |
| 14  | ADD R5 9    | 0      | R5 = 0 + 9 = 9      | C = V = N = S = Z = 0       | #wrong output                     |
| 15  | ADD R5 10   | 0      | R5 = 9 + 10 = 19    | C = V = N = S = Z = 0       | #wrong output                     |

## Registers

| Register | Value |
| -------- | ----- |
| 0        | -10   |
| 1        | 0     |
| 2        | 45    |
| 3        | 14    |
| 4        | 10    |
| 5        | 19    |

## Data Memory

| Address | Data |
| ------- | ---- |

## Instruction Memory

| Instruction | Opcode | Register | Reg/IMM | Type |
| ----------- | ------ | -------- | ------- | ---- |
| 0           | 3      | 0        | -20     | I    |
| 1           | 3      | 1        | -10     | I    |
| 2           | 3      | 2        | 15      | I    |
| 3           | 3      | 3        | 14      | I    |
| 4           | 3      | 4        | 3       | I    |
| 5           | 3      | 5        | 0       | I    |
| 6           | 0      | 0        | 10      | R    |
| 7           | 0      | 3        | R0      | R    |
| 8           | 0      | 1        | 10      | R    |
| 9           | 0      | 3        | R1      | R    |
| 10          | 0      | 2        | 15      | R    |
| 11          | 0      | 2        | 15      | R    |
| 12          | 0      | 4        | 2       | R    |
| 13          | 0      | 4        | 5       | R    |
| 14          | 0      | 5        | 9       | R    |
| 15          | 0      | 5        | 10      | R    |

# SUB Test

## Instructions

| ID  | Instruction | Opcode | Output              | Status Reg               | Notes                         |
| --- | ----------- | ------ | ------------------- | ------------------------ | ----------------------------- |
| 0   | MOVI R0 -20 | 3      | R0 = -20            | nth                      | # doesn't show input negative |
| 1   | MOVI R1 -10 | 3      | R1 = -10            | nth                      | # doesn't show input negative |
| 2   | MOVI R2 15  | 3      | R2 = 15             | nth                      |                               |
| 3   | MOVI R3 14  | 3      | R3 = 14             | nth                      |                               |
| 4   | MOVI R4 3   | 3      | R4 = 3              | nth                      |                               |
| 5   | MOVI R5 0   | 3      | R5 = 0              | nth                      |                               |
| 6   | SUB R0 -2   | 1      | R0 = -20 - -2 = -18 | C = V = S = Z = 0, N = 1 | #TF the output is -15         |
| 7   | SUB R1 2    | 1      | R1 = -10 - 2 = -12  | C = V = N = S = Z = 0    | #NO output                    |
| 8   | SUB R2 R1   | 1      | R2 = 15             | C = V = N = S = Z = 0    |                               |
| 9   | SUB R3 6    | 1      | R3 = 14 - 6 = 8     | C = V = N = S = Z = 0    | #NO output                    |
| 10  | SUB R4 3    | 1      | R4 = 3 - 3 = 0      | C = V = N = S = Z = 1    | #NO output                    |
| 11  | SUB R5 5    | 1      | R5 = 0 - 5 = -5     | C = V = N = S = Z = 0    | #NO output                    |
| 12  | SUB R0 -1   | 1      | R0 = -18 - -1 = -17 | C = V = S = Z = 0, N = 1 | #TF the output is -15         |
| 13  | SUB R1 1    | 1      | R1 = -12 - 1 = -13  | C = V = N = S = Z = 0    | #NO output                    |
| 14  | SUB R2 R0   | 1      | R2 = 15             | C = V = N = S = Z = 0    | #TF the output is 30          |
| 15  | SUB R3 -2   | 1      | R3 = 8 + 2 = 10     | C = V = N = S = Z = 0    | #TF the output is -16         |
| 16  | SUB R4 3    | 1      | R4 = 0 - 3 = -3     | C = V = N = S = Z = 0    | #NO output                    |
| 17  | SUB R5 -5   | 1      | R5 = -5 + 5 = 0     | C = V = N = S = Z = 1    |                               |

## Registers

| Register | Value |
| -------- | ----- |
| 0        | -17   |
| 1        | -13   |
| 2        | 15    |
| 3        | 10    |
| 4        | -3    |
| 5        | 0     |

## Data Memory

| Address | Data |
| ------- | ---- |

## Instruction Memory

| Instruction | Opcode | Register | Reg/IMM | Type |
| ----------- | ------ | -------- | ------- | ---- |
| 0           | 3      | 0        | -20     | I    |
| 1           | 3      | 1        | -10     | I    |
| 2           | 3      | 2        | 15      | I    |
| 3           | 3      | 3        | 14      | I    |
| 4           | 3      | 4        | 3       | I    |
| 5           | 3      | 5        | 0       | I    |
| 6           | 1      | 0        | -2      | R    |
| 7           | 1      | 1        | 2       | R    |
| 8           | 1      | 2        | R1      | R    |
| 9           | 1      | 3        | 6       | R    |
| 10          | 1      | 4        | 3       | R    |
| 11          | 1      | 5        | 5       | R    |
| 12          | 1      | 0        | -1      | R    |
| 13          | 1      | 1        | 1       | R    |
| 14          | 1      | 2        | R0      | R    |
| 15          | 1      | 3        | -2      | R    |
| 16          | 1      | 4        | 3       | R    |
| 17          | 1      | 5        | -5      | R    |

# MUL Test

## Instructions

| ID  | Instruction | Opcode | Output             | Status Reg   | Notes                        |
| --- | ----------- | ------ | ------------------ | ------------ | ---------------------------- |
| 0   | MOVI R0 -5  | 3      | R0 = -5            | nth          | doesn't show input negative  |
| 1   | MOVI R1 -10 | 3      | R1 = -10           | nth          | doesn't show input negative  |
| 2   | MOVI R2 4   | 3      | R2 = 4             | nth          |                              |
| 3   | MOVI R3 8   | 3      | R3 = 8             | nth          |                              |
| 4   | MOVI R4 0   | 3      | R4 = 0             | nth          |                              |
| 5   | MOVI R5 5   | 3      | R5 = 5             | nth          |                              |
| 6   | MUL R0 2    | 2      | R0 = -5 x 2 = -10  | N = 1, Z = 0 | doesn't show output negative |
| 7   | MUL R1 -2   | 2      | R1 = -10 x -2 = 20 |              | TF the output is 0           |
| 8   | MUL R2 3    | 2      | R2 = 4 x 3 = 12    |              | NO output                    |
| 9   | MUL R3 -2   | 2      | R3 = 8 x -2 = -16  |              | TF the output is 32          |
| 10  | MUL R4 6    | 2      | R4 = 0 x 6 = 0     |              | NO output                    |
| 11  | MUL R5 0    | 2      | R5 = 5 x 0 = 0     |              | NO output                    |

## Registers

| Register | Value |
| -------- | ----- |

## Data Memory

| Address | Data |
| ------- | ---- |

## Instruction Memory

| Instruction | Opcode | Register | Reg/IMM | Type |
| ----------- | ------ | -------- | ------- | ---- |

# SAL Test

MOVI R0 -8
MOVI R1 -10
MOVI R2 15
MOVI R3 4
MOVI R4 3
MOVI R5 0
SAL R0 1
SA R0 -2
SAL R1 1
SAL R1 -2
SAL R2 2
SAL R2 3  
SAL R2 1
SAL R3 2  
SAL R4 0
SAL R5 -2
SAL R5 0
SAL R4 -2

## Instructions

| ID  | Instruction | Opcode | Output | Status Reg | Notes |
| --- | ----------- | ------ | ------ | ---------- | ----- |

## Registers

| Register | Value |
| -------- | ----- |

## Data Memory

| Address | Data |
| ------- | ---- |

## Instruction Memory

| Instruction | Opcode | Register | Reg/IMM | Type |
| ----------- | ------ | -------- | ------- | ---- |

# SAR Test

MOVI R0 -8
MOVI R1 -10
MOVI R2 15
MOVI R3 4
MOVI R4 3
MOVI R5 0
SAR R0 1
SAR R0 -2
SAR R1 1
SAR -2
SAR R2 1  
SAR R3 2  
SAR R4 0  
SAR R5 -2  
SAR R5 0  
SAR R4 -2

## Instructions

| ID  | Instruction | Opcode | Output | Status Reg | Notes |
| --- | ----------- | ------ | ------ | ---------- | ----- |

## Registers

| Register | Value |
| -------- | ----- |

## Data Memory

| Address | Data |
| ------- | ---- |

## Instruction Memory

| Instruction | Opcode | Register | Reg/IMM | Type |
| ----------- | ------ | -------- | ------- | ---- |

# EOR Test

## Instructions

| ID  | Instruction | Opcode | Output | Status Reg | Notes |
| --- | ----------- | ------ | ------ | ---------- | ----- |
| 0   | MOVI R0 0   | 3      | R0=0   |            |       |
| 1   | MOVI R1 1   | 3      | R1=1   |            |       |
| 2   | MOVI R2 12  | 3      | R2=12  |            |       |
| 3   | MOVI R3 4   | 3      | R3=4   |            |       |
| 4   | MOVI R4 7   | 3      | R4=7   |            |       |
| 5   | MOVI R5 16  | 3      | R5=16  |            |       |
| 6   | MOVI R6 3   | 3      | R6=3   |            |       |
| 7   | EOR R0 R1   | 5      | R0=1   |            |       |
| 8   | EOR R1 R2   | 6      | R1=13  |            |       |
| 9   | EOR R2 R3   | 7      | R2=8   |            |       |
| 10  | EOR R3 R4   | 8      | R3=3   |            |       |
| 11  | EOR R4 R5   | 9      | R4=23  |            |       |
| 12  | EOR R5 R6   | 10     | R5=19  |            |       |

## Registers

| Register | Value |
| -------- | ----- |
| 0        | 1     |
| 1        | 13    |
| 2        | 8     |
| 3        | 3     |
| 4        | 23    |
| 5        | 19    |

## Data Memory

| Address | Data |
| ------- | ---- |

## Instruction Memory

| Instruction | Opcode | Register | Reg/IMM | Type |
| ----------- | ------ | -------- | ------- | ---- |
| 0           | 3      | 0        | 0       | I    |
| 1           | 3      | 1        | 1       | I    |
| 2           | 3      | 2        | 12      | I    |
| 3           | 3      | 3        | 4       | I    |
| 4           | 3      | 4        | 7       | I    |
| 5           | 3      | 5        | 16      | I    |
| 6           | 3      | 6        | 3       | I    |
| 7           | 5      | 0        | 1       | R    |
| 8           | 6      | 1        | 2       | R    |
| 9           | 7      | 2        | 3       | R    |
| 10          | 8      | 3        | 4       | R    |
| 11          | 9      | 4        | 5       | R    |
| 12          | 10     | 5        | 6       | R    |

# ANDI Test

MOVI R0 0
MOVI R1 1
MOVI R2 12
MOVI R3 4
MOVI R4 7
MOVI R5 16
MOVI R6 3
ANDI R0 1
ANDI R1 2
ANDI R2 15
ANDI R3 3
ANDI R4 6
ANDI R5 15

## Instructions

| ID  | Instruction | Opcode | Output | Status Reg | Notes |
| --- | ----------- | ------ | ------ | ---------- | ----- |
| 0   | MOVI R0 0   | 3      | R0=0   |            |       |
| 1   | MOVI R1 1   | 3      | R1=1   |            |       |
| 2   | MOVI R2 12  | 3      | R2=12  |            |       |
| 3   | MOVI R3 4   | 3      | R3=4   |            |       |
| 4   | MOVI R4 7   | 3      | R4=7   |            |       |
| 5   | MOVI R5 16  | 3      | R5=16  |            |       |
| 6   | MOVI R6 3   | 3      | R6=3   |            |       |
| 7   | ANDI R0 1   | 5      | R0=0   |            |       |
| 8   | ANDI R1 2   | 5      | R1=1   |            |       |
| 9   | ANDI R2 15  | 5      | R2=12  |            |       |
| 10  | ANDI R3 3   | 5      | R3=0   |            |       |
| 11  | ANDI R4 6   | 5      | R4=6   |            |       |
| 12  | ANDI R5 15  | 5      | R5=0   |            |       |
| 13  | ANDI R6 3   | 5      | R6=3   |            |       |

## Registers

| Register | Value |
| -------- | ----- |
| 0        | 0     |
| 1        | 1     |
| 2        | 12    |
| 3        | 0     |
| 4        | 6     |
| 5        | 0     |
| 6        | 3     |


## Data Memory

## Instruction Memory

| Instruction | Opcode | Register | Reg/IMM | Type |
| ----------- | ------ | -------- | ------- | ---- |
| 0           | 3      | 0        | 0       | I    |
| 1           | 3      | 1        | 1       | I    |
| 2           | 3      | 2        | 12      | I    |
| 3           | 3      | 3        | 4       | I    |
| 4           | 3      | 4        | 7       | I    |
| 5           | 3      | 5        | 16      | I    |
| 6           | 3      | 6        | 3       | I    |
| 7           | 5      | 0        | 1       | I    |
| 8           | 5      | 1        | 2       | I    |
| 9           | 5      | 2        | 15      | I    |
| 10          | 5      | 3        | 3       | I    |
| 11          | 5      | 4        | 6       | I    |
| 12          | 5      | 5        | 15      | I    |
| 13          | 5      | 6        | 3       | I    |

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

## Registers

| Register | Value |
| -------- | ----- |
| 1        | 1     |
| 2        | 8     |
| 3        | -3    |
| 4        | 7     |
| 5        | 1     |
| 6        | 2     |

## Data Memory

| Address | Data |
| ------- | ---- |
| 0       | 8    |
| 1       | 2    |
| 2       | 1    |

## Instruction Memory

| Instruction | Opcode | Register | Reg/IMM | Type |
| ----------- | ------ | -------- | ------- | ---- |
| 0           | 3      | 0        | 0       | I    |
| 1           | 3      | 1        | 1       | I    |
| 2           | 3      | 2        | 0       | I    |
| 3           | 3      | 3        | 4       | I    |
| 4           | 3      | 4        | 7       | I    |
| 5           | 3      | 5        | 16      | I    |
| 6           | 3      | 6        | 1       | I    |
| 7           | 4      | 3        | 5       | I    |
| 8           | 0      | 2        | 1       | R    |
| 9           | 1      | 3        | 1       | R    |
| 10          | 8      | 6        | 1       | I    |
| 11          | 9      | 5        | 1       | I    |
| 12          | 11     | 5        | 0       | I    |
| 13          | 11     | 6        | 1       | I    |
| 14          | 11     | 2        | 2       | I    |
| 15          | 10     | 5        | 2       | I    |
| 16          | 10     | 6        | 1       | I    |
| 17          | 10     | 2        | 0       | I    |

# Test 2

## Instructions

| ID  | Instruction | Opcode | Output                 | Status Reg                        |
| --- | ----------- | ------ | ---------------------- | --------------------------------- |
| 0   | MOVI R0 20  | 3      | R0 = 10                | NTH                               |
| 1   | MOVI R9 10  | 3      | R9 = 8                 | nth                               |
| 2   | MOVI R2 15  | 3      | R2 = 15                | nth                               |
| 3   | MOVI R3 4   | 3      | R3 = 4                 | nth                               |
| 4   | MOVI R4 3   | 3      | R4 = 3                 | nth                               |
| 5   | MUL R9 R2   | 2      | R9 = 8 x 15 = 120      | N = 0 Z = 0                       |
| 6   | ADD R9 R3   | 0      | R9 = 120 + 4 = 124     | C = 0, V = 0, N = 0, S = 0, Z = 0 |
| 7   | MOVI R7 10  | 3      | R7 = 10                | nth                               |
| 8   | MOVI R6 1   | 3      | R6 = 1                 | nth                               |
| 9   | MUL R4 R7   | 2      | R4 = 10 x 3 = 30       | N = 0 Z = 0                       |
| 10  | MUL R0 R7   | 2      | R0 = 10 x 10 = 100     | N = 0 Z = 0                       |
| 11  | ADD R4 R0   | 0      | R4 = 30 + 100 = 130    | C = 0, V = 1, N = 0, S = 0, Z = 1 |
| 12  | SUB R4 R6   | 1      | R4 = 1 - 130 = -129    | C = 0, V = 1, N = 1, S = 0, Z = 0 |
| 13  | SUB R9 R4   | 1      | R9 = 124 - -129 = -353 | C = 0, V = 0, N = 1, S = 1, Z = 0 |

## Registers

| Register | Value | Comments                         |
| -------- | ----- | -------------------------------- |
| 0        | 100   |
| 2        | 15    |
| 3        | 4     |
| 4        | -129  | overflow will occur will be -127 |
| 6        | 1     |
| 7        | 10    |
| 9        | -383  | overflow occur will be -5        |

## Status Register

| Flage | Value |
| ----- | ----- |
| C     | 1     |
| V     |       |
| N     |       |
| S     |       |
| Z     |       |

## Data Memory

## Instruction Memory

| Instruction | Opcode | Register | Reg/IMM | Type |
| ----------- | ------ | -------- | ------- | ---- |
| 0           | 3      | 0        | 20      | I    |
| 1           | 3      | 9        | 10      | I    |
| 2           | 3      | 2        | 15      | I    |
| 3           | 3      | 3        | 4       | I    |
| 4           | 3      | 4        | 3       | I    |
| 5           | 2      | 9        | 2       | R    |
| 6           | 0      | 9        | 3       | R    |
| 7           | 3      | 7        | 10      | I    |
| 8           | 3      | 6        | 1       | I    |
| 9           | 2      | 4        | 7       | R    |
| 10          | 2      | 0        | 7       | R    |
| 11          | 0      | 4        | 0       | R    |
| 12          | 1      | 4        | 6       | R    |
| 13          | 1      | 9        | 4       | R    |

# Test 3

## Instructions

| ID  | Instruction | Opcode | Output        | Status Reg |
| --- | ----------- | ------ | ------------- | ---------- |
| 0   | MOVI R0 10  | 3      | R0 = 10       | nth        |
| 1   | MOVI R1 10  | 3      | R1 = 10       | nth        |
| 2   | MOVI R3 20  | 3      | R3 = 20       | nth        |
| 3   | SUB R0 R1   | 1      | R0 = 10-10=0  | nth        |
| 4   | BEQZ R0 0   | 4      | R0=0          | nth        |
| 5   | ADD R3 R1   | 0      | R3 = 20+10=30 | nth        |
| 6   | BR R0 R1    | 7      | R0=0          | nth        |
| 7   | STR R0 0    | 11     | Mem[0]= 0     | nth        |

smo please format into table

## Registers

| Register | Value |
| -------- | ----- |
| 0        | 0     |
| 1        | 10    |
| 3        | 30    |

## Data Memory

| Address | Data |
| ------- | ---- |
| 0       | 0    |

## Instruction Memory

| Instruction | Opcode | Register | Reg/IMM | Type |
| ----------- | ------ | -------- | ------- | ---- |
| 0           | 3      | 0        | 10      | I    |
| 1           | 3      | 1        | 10      | I    |
| 2           | 3      | 3        | 20      | I    |
| 3           | 1      | 0        | 1       | R    |
| 4           | 4      | 0        | 0       | I    |
| 5           | 0      | 3        | 1       | R    |
| 6           | 7      | 0        | 1       | R    |
| 7           | 11     | 0        | 0       | I    |

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

| Register | Value |
| -------- | ----- |
| 1        | 1     |
| 2        | 8     |
| 3        | 3     |
| 4        | 7     |
| 5        | 1     |
| 6        | 2     |

## Data Memory

| Address | Data |
| ------- | ---- |
| 0       | 8    |
| 1       | 2    |
| 2       | 1    |

## Instruction Memory

| Instruction | Opcode | Register | Reg/IMM | Type |
| ----------- | ------ | -------- | ------- | ---- |
| 0           | 3      | 0        | 0       | I    |
| 1           | 3      | 1        | 1       | I    |
| 2           | 3      | 2        | 0       | I    |
| 3           | 3      | 3        | 4       | I    |
| 4           | 3      | 4        | 5       | I    |
| 5           | 3      | 5        | 16      | I    |
| 6           | 4      | 3        | 1       | I    |
| 7           | 0      | 2        | 1       | R    |
| 8           | 1      | 3        | 1       | R    |
| 9           | 8      | 6        | 1       | I    |
| 10          | 9      | 5        | 1       | I    |
| 11          | 11     | 5        | 0       | I    |
| 12          | 11     | 6        | 1       | I    |
| 13          | 11     | 2        | 2       | I    |
| 14          | 10     | 5        | 2       | I    |
| 15          | 10     | 6        | 1       | I    |
| 16          | 10     | 2        | 0       | I    |

# Test 5

## Instructions

| ID  | Instruction | Opcode | Output          | Status Reg          |
| --- | ----------- | ------ | --------------- | ------------------- |
| 0   | MOVI R0 0   | 3      | R0 = 0          | nth                 |
| 1   | MOVI R1 1   | 3      | R1 = 1          | nth                 |
| 2   | MOVI R2 0   | 3      | R2 = 0          | nth                 |
| 3   | MOVI R3 0   | 3      | R3 = 0          | nth                 |
| 4   | MOVI R4 7   | 3      | R4 = 7          | nth                 |
| 5   | MOVI R5 16  | 3      | R5 = 16         | nth                 |
| 6   | MOVI R6 1   | 3      | R6 = 1          | nth                 |
| 7   | BEQZ R3 5   | 4      | nth             | nth                 |
| 8   | ADD R2 R1   | 0      | R2 = 0 + 1 = 1  | C = V = N = S = Z = |
| 9   | SUB R3 R1   | 1      | R3 = 0 - 1 = -1 | V = N = S = Z =     |
| 10  | SAL R6 1    | 8      | R6 = 2          | N = Z =             |
| 11  | SAR R5 1    | 9      | R5 = 8          | N = Z =             |
| 12  | STR R5 0    | 11     | Mem[0] = 8      | nth                 |
| 13  | STR R6 1    | 11     | Mem[1] = 2      | nth                 |
| 14  | STR R2 2    | 11     | Mem[2] = 1      | nth                 |
| 15  | LDR R5 2    | 10     | R5 = 1          | nth                 |
| 16  | LDR R6 1    | 10     | R6 = 2          | nth                 |
| 17  | LDR R2 0    | 10     | R2 = 8          | nth                 |

smo please format into table

## Registers

| Register | Value |
| -------- | ----- |
| 1        | 1     |
| 2        | 8     |
| 3        | -1    |
| 4        | 7     |
| 5        | 1     |
| 6        | 2     |

## Data Memory

| Address | Data |
| ------- | ---- |
| 0       | 8    |
| 1       | 2    |
| 2       | 1    |

## Instruction Memory

| Instruction | Opcode | Register | Reg/IMM | Type |
| ----------- | ------ | -------- | ------- | ---- |
| 0           | 3      | 0        | 0       | I    |
| 1           | 3      | 1        | 1       | I    |
| 2           | 3      | 2        | 0       | I    |
| 3           | 3      | 3        | 0       | I    |
| 4           | 3      | 4        | 7       | I    |
| 5           | 3      | 5        | 16      | I    |
| 6           | 3      | 6        | 1       | I    |
| 7           | 4      | 3        | 5       | I    |
| 8           | 0      | 2        | 1       | R    |
| 9           | 1      | 3        | 1       | R    |
| 10          | 8      | 6        | 1       | I    |
| 11          | 9      | 5        | 1       | I    |
| 12          | 11     | 5        | 0       | I    |
| 13          | 11     | 6        | 1       | I    |
| 14          | 11     | 2        | 2       | I    |
| 15          | 10     | 5        | 2       | I    |
| 16          | 10     | 6        | 1       | I    |
| 17          | 10     | 2        | 0       | I    |
