# MOVI Test

MOVI R0 0
MOVI R10 10
MOVI R20 20
MOVI R30 30
MOVI R40 31
MOVI R50 22
MOVI R60 -2
MOVI R63 -3
MOVI R2 -31
MOVI R3 -20
MOVI R4 -10
MOVI R5 -5
MOVI R6 -8
MOVI R7 31
MOVI R8 30

## Instructions

| ID  | Instruction | Opcode | Output   | Status Reg |
| --- | ----------- | ------ | -------- | ---------- |
| 0   | MOVI R0 0   | 3      | R0 = 0   | nth        |
| 1   | MOVI R10 10 | 3      | R10 = 10 | nth        |
| 2   | MOVI R20 20 | 3      | R20 = 20 | nth        |
| 3   | MOVI R30 30 | 3      | R30 = 30 | nth        |
| 4   | MOVI R40 31 | 3      | R40 = 31 | nth        |
| 5   | MOVI R50 22 | 3      | R50 = 22 | nth        |
| 6   | MOVI R60 -2 | 3      | R60 = -2 | nth        |
| 7   | MOVI R63 -3 | 3      | R63 = -3 | nth        |
| 8   | MOVI R2 -4  | 3      | R2 = -31 | nth        |
| 9   | MOVI R3 -20 | 3      | R3 = -20 | nth        |
| 10  | MOVI R4 -10 | 3      | R4 = -10 | nth        |
| 11  | MOVI R5 -5  | 3      | R5 = -5  | nth        |
| 12  | MOVI R6 -8  | 3      | R6 = -8  | nth        |
| 13  | MOVI R7 31  | 3      | R7 = 31  | nth        |
| 14  | MOVI R8 30  | 3      | R8 = 30  | nth        |

## Registers

| Register | Value |
| -------- | ----- |
| 0        | 0     |
| 10       | 10    |
| 20       | 20    |
| 30       | 30    |
| 40       | 31    |
| 50       | 22    |
| 60       | -2    |
| 63       | -3    |
| 2        | -31   |
| 3        | -20   |
| 4        | -10   |
| 5        | -5    |
| 6        | -8    |
| 7        | 31    |
| 8        | 30    |

## Instruction Memory

| Instruction | Opcode | Register | Reg/IMM | Type |
| ----------- | ------ | -------- | ------- | ---- |
| 0           | 3      | 0        | 0       | I    |
| 1           | 3      | 10       | 10      | I    |
| 2           | 3      | 20       | 20      | I    |
| 3           | 3      | 30       | 30      | I    |
| 4           | 3      | 40       | 31      | I    |
| 5           | 3      | 50       | 22      | I    |
| 6           | 3      | 60       | -2      | I    |
| 7           | 3      | 63       | -3      | I    |
| 8           | 3      | 2        | -4      | I    |
| 9           | 3      | 3        | -20     | I    |
| 10          | 3      | 4        | -10     | I    |
| 11          | 3      | 5        | -5      | I    |
| 12          | 3      | 6        | -8      | I    |
| 13          | 3      | 7        | 31      | I    |
| 14          | 3      | 8        | 30      | I    |

# ADD Test

MOVI R0 -20
MOVI R1 -10
MOVI R2 15
MOVI R3 14
MOVI R4 3
MOVI R5 0
ADD R0 R1
ADD R1 R2
ADD R2 R1
ADD R2 R3
ADD R4 R5
ADD R5 R1
ADD R5 R5

## Instructions

| ID  | Instruction | Opcode | Output               | Status Reg               |
| --- | ----------- | ------ | -------------------- | ------------------------ |
| 0   | MOVI R0 -20 | 3      | R0 = -20             | nth                      |
| 1   | MOVI R1 -10 | 3      | R1 = -10             | nth                      |
| 2   | MOVI R2 15  | 3      | R2 = 15              | nth                      |
| 3   | MOVI R3 14  | 3      | R3 = 14              | nth                      |
| 4   | MOVI R4 3   | 3      | R4 = 3               | nth                      |
| 5   | MOVI R5 0   | 3      | R5 = 0               | nth                      |
| 6   | ADD R0 R1   | 0      | R0 = -20 + -10 = -30 | V = S = Z = 0, C = N = 1 |
| 7   | ADD R1 R2   | 0      | R1 = -10 + 15 = 5    | N = V = S = Z = 0, C = 1 |
| 8   | ADD R2 R1   | 0      | R2 = 15 + 5 = 20     | N = V = S = Z = C = 0    |
| 9   | ADD R2 R3   | 0      | R2 = 20 + 14 = 34    | N = V = S = Z = C = 0    |
| 10  | ADD R4 R5   | 0      | R4 = 3 + 0 = 3       | N = V = S = Z = C = 0    |
| 11  | ADD R5 R1   | 0      | R5 = 0 + 5 = 5       | N = V = S = Z = C = 0    |
| 12  | ADD R5 R5   | 0      | R5 = 5 + 5 = 10      | N = V = S = Z = C = 0    |

## Registers

| Register | Value |
| -------- | ----- |
| 0        | -30   |
| 1        | 5     |
| 2        | 20    |
| 3        | 14    |
| 4        | 3     |
| 5        | 10    |

## Instruction Memory

| Instruction | Opcode | Register | Reg/IMM | Type |
| ----------- | ------ | -------- | ------- | ---- |
| 0           | 3      | 0        | -20     | I    |
| 1           | 3      | 1        | -10     | I    |
| 2           | 3      | 2        | 15      | I    |
| 3           | 3      | 3        | 14      | I    |
| 4           | 3      | 4        | 3       | I    |
| 5           | 3      | 5        | 0       | I    |
| 6           | 0      | 0        | 1       | R    |
| 7           | 0      | 1        | 2       | R    |
| 8           | 0      | 2        | 1       | R    |
| 9           | 0      | 2        | 3       | R    |
| 10          | 0      | 4        | 5       | R    |
| 11          | 0      | 5        | 1       | R    |
| 12          | 0      | 5        | 5       | R    |

# SUB Test

MOVI R0 -20
MOVI R1 -10
MOVI R2 15
MOVI R3 14
MOVI R4 3
MOVI R5 0
SUB R0 R1
SUB R1 R2
SUB R2 R1
SUB R2 R3
SUB R4 R5
SUB R5 R1
SUB R5 R5

## Instructions

| ID  | Instruction | Opcode | Output               | Status Reg               |
| --- | ----------- | ------ | -------------------- | ------------------------ |
| 0   | MOVI R0 -20 | 3      | R0 = -20             | nth                      |
| 1   | MOVI R1 -10 | 3      | R1 = -10             | nth                      |
| 2   | MOVI R2 15  | 3      | R2 = 15              | nth                      |
| 3   | MOVI R3 14  | 3      | R3 = 14              | nth                      |
| 4   | MOVI R4 3   | 3      | R4 = 3               | nth                      |
| 5   | MOVI R5 0   | 3      | R5 = 0               | nth                      |
| 6   | SUB R0 R1   | 1      | R0 = -20 - -10 = -10 | C = V = S = Z = 0, N = 1 |
| 7   | SUB R1 R2   | 1      | R1 = -10 - 15 = -25  | N = V = S = Z = 0, N = 1 |
| 8   | SUB R2 R1   | 1      | R2 = 15 - -25 = 40   | N = V = S = Z = C = 0    |
| 9   | SUB R2 R3   | 1      | R2 = 40 - 14 = 26    | N = V = S = Z = C = 0    |
| 10  | SUB R4 R5   | 1      | R4 = 3 - 0 = 3       | N = V = S = Z = C = 0    |
| 11  | SUB R5 R1   | 1      | R5 = 0 - -25 = 25    | N = V = S = Z = C = 0    |
| 12  | SUB R5 R5   | 1      | R5 = 25 - 25 = 0     | N = V = C = 0, Z = S = 1 |

## Registers

| Register | Value |
| -------- | ----- |
| 0        | -10   |
| 1        | -25   |
| 2        | 40    |
| 3        | 26    |
| 4        | 3     |
| 5        | 0     |

## Instruction Memory

| Instruction | Opcode | Register | Reg/IMM | Type |
| ----------- | ------ | -------- | ------- | ---- |
| 0           | 3      | 0        | -20     | I    |
| 1           | 3      | 1        | -10     | I    |
| 2           | 3      | 2        | 15      | I    |
| 3           | 3      | 3        | 14      | I    |
| 4           | 3      | 4        | 3       | I    |
| 5           | 3      | 5        | 0       | I    |
| 6           | 1      | 0        | 1       | R    |
| 7           | 1      | 1        | 2       | R    |
| 8           | 1      | 2        | 1       | R    |
| 9           | 1      | 2        | 3       | R    |
| 10          | 1      | 4        | 5       | R    |
| 11          | 1      | 5        | 1       | R    |
| 12          | 1      | 5        | 5       | R    |

# MUL Test

MOVI R0 -2
MOVI R1 -3
MOVI R2 5
MOVI R3 4
MOVI R4 3
MOVI R5 0
MUL R0 R1
MUL R1 R2
MUL R2 R1
MUL R2 R3
MUL R4 R5
MUL R5 R1
MUL R5 R5

## Instructions

| ID  | Instruction | Opcode | Output              | Status Reg               |
| --- | ----------- | ------ | ------------------- | ------------------------ |
| 0   | MOVI R0 -2  | 3      | R0 = -2             | nth                      |
| 1   | MOVI R1 -3  | 3      | R1 = -3             | nth                      |
| 2   | MOVI R2 5   | 3      | R2 = 5              | nth                      |
| 3   | MOVI R3 4   | 3      | R3 = 4              | nth                      |
| 4   | MOVI R4 3   | 3      | R4 = 3              | nth                      |
| 5   | MOVI R5 0   | 3      | R5 = 0              | nth                      |
| 6   | MUL R0 R1   | 2      | R0 = -2 x -3 = 6    | N = V = S = Z = C = 0    |
| 7   | MUL R1 R2   | 2      | R1 = -3 x 5 = -15   | N = V = S = Z = C = 0    |
| 8   | MUL R2 R1   | 2      | R2 = 5 x -15 = -75  | V = S = Z = C = 0, N = 1 |
| 9   | MUL R2 R3   | 2      | R2 = -75 x 4 = -300 | V = S = Z = C = 0, N = 1 |
| 10  | MUL R4 R5   | 2      | R4 = 3 x 0 = 0      | N = V = S = C = 0, Z = 1 |
| 11  | MUL R5 R1   | 2      | R5 = 0 x -3 = 0     | N = V = S = C = 0, Z = 1 |
| 12  | MUL R5 R5   | 2      | R5 = 0 x 0 = 0      | N = V = S = C = 0, Z = 1 |

## Registers

| Register | Value |
| -------- | ----- |
| 0        | 6     |
| 1        | -15   |
| 2        | -75   |
| 3        | -300  |
| 4        | 0     |
| 5        | 0     |

## Instruction Memory

| Instruction | Opcode | Register | Reg/IMM | Type |
| ----------- | ------ | -------- | ------- | ---- |
| 0           | 3      | 0        | -2      | I    |
| 1           | 3      | 1        | -3      | I    |
| 2           | 3      | 2        | 5       | I    |
| 3           | 3      | 3        | 4       | I    |
| 4           | 3      | 4        | 3       | I    |
| 5           | 3      | 5        | 0       | I    |
| 6           | 2      | 0        | 1       | R    |
| 7           | 2      | 1        | 2       | R    |
| 8           | 2      | 2        | 1       | R    |
| 9           | 2      | 2        | 3       | R    |
| 10          | 2      | 4        | 5       | R    |
| 11          | 2      | 5        | 1       | R    |
| 12          | 2      | 5        | 5       | R    |

# SAL Test

MOVI R0 -8
MOVI R1 -10
MOVI R2 15
MOVI R3 4
MOVI R4 3
MOVI R5 0
SAL R0 1
SAL R0 2
SAL R1 1
SAL R1 2
SAL R2 2
SAL R4 0
SAL R5 2
SAL R5 0

## Instructions

| ID  | Instruction | Opcode | Output              | Status Reg                |
| --- | ----------- | ------ | ------------------- | ------------------------- |
| 0   | MOVI R0 -8  | 3      | R0 = -8             | nth                       |
| 1   | MOVI R1 -10 | 3      | R1 = -10            | nth                       |
| 2   | MOVI R2 15  | 3      | R2 = 15             | nth                       |
| 3   | MOVI R3 4   | 3      | R3 = 4              | nth                       |
| 4   | MOVI R4 3   | 3      | R4 = 3              | nth                       |
| 5   | MOVI R5 0   | 3      | R5 = 0              | nth                       |
| 6   | SAL R0 1    | 8      | R0 = -8 << 1 = -16  | V = S = Z = C = 0 , N = 1 |
| 7   | SAL R0 2    | 8      | R0 = -16 << 2 = -64 | V = S = Z = C = 0 , N = 1 |
| 8   | SAL R1 1    | 8      | R1 = -10 << 1 = -20 | V = S = Z = C = 0 , N = 1 |
| 9   | SAL R1 2    | 8      | R1 = -20 << 2 = -80 | V = S = Z = C = 0 , N = 1 |
| 10  | SAL R2 2    | 8      | R2 = 15 << 2 = 60   | N = V = S = Z = C = 0     |
| 11  | SAL R4 0    | 8      | R4 = 3 << 0 = 3     | N = V = S = Z = C = 0     |
| 12  | SAL R5 2    | 8      | R5 = 0 << 2 = 0     | V = S = N = C = 0 , Z = 1 |
| 13  | SAL R5 0    | 8      | R5 = 0 << 0 = 0     | V = S = N = C = 0 , Z = 1 |

## Registers

| Register | Value |
| -------- | ----- |
| 0        | -64   |
| 1        | -80   |
| 2        | 60    |
| 3        | 4     |
| 4        | 3     |
| 5        | 0     |

## Instruction Memory

| Instruction | Opcode | Register | Reg/IMM | Type |
| ----------- | ------ | -------- | ------- | ---- |
| 0           | 3      | 0        | -8      | I    |
| 1           | 3      | 1        | -10     | I    |
| 2           | 3      | 2        | 15      | I    |
| 3           | 3      | 3        | 4       | I    |
| 4           | 3      | 4        | 3       | I    |
| 5           | 3      | 5        | 0       | I    |
| 6           | 8      | 0        | 1       | R    |
| 7           | 8      | 0        | 2       | R    |
| 8           | 8      | 1        | 1       | R    |
| 9           | 8      | 1        | 2       | R    |
| 10          | 8      | 2        | 2       | R    |
| 11          | 8      | 4        | 0       | R    |
| 12          | 8      | 5        | 2       | R    |
| 13          | 8      | 5        | 0       | R    |

# SAR Test

MOVI R0 -8
MOVI R1 -10
MOVI R2 15
MOVI R3 4
MOVI R4 3
MOVI R5 0
SAR R0 1
SAR R0 2
SAR R1 1
SAR R2 1  
SAR R3 2  
SAR R4 0  
SAR R5 2  
SAR R5 0  
SAR R4 2

## Instructions

| ID  | Instruction | Opcode | Output             | Status Reg               |
| --- | ----------- | ------ | ------------------ | ------------------------ |
| 0   | MOVI R0 -8  | 3      | R0 = -8            | nth                      |
| 1   | MOVI R1 -10 | 3      | R1 = -10           | nth                      |
| 2   | MOVI R2 15  | 3      | R2 = 15            | nth                      |
| 3   | MOVI R3 4   | 3      | R3 = 4             | nth                      |
| 4   | MOVI R4 3   | 3      | R4 = 3             | nth                      |
| 5   | MOVI R5 0   | 3      | R5 = 0             | nth                      |
| 6   | SAR R0 1    | 9      | R0 = -8 >> 1 = -4  | V = S = Z = C = 0, N = 1 |
| 7   | SAR R0 2    | 9      | R0 = -4 >> 2 = -1  | V = S = Z = C = 0, N = 1 |
| 8   | SAR R1 1    | 9      | R1 = -10 >> 1 = -5 | V = S = Z = C = 0, N = 1 |
| 9   | SAR R2 1    | 9      | R2 = 15 >> 1 = 7   | V = S = Z = N = C = 0    |
| 10  | SAR R3 2    | 9      | R3 = 4 >> 2 = 1    | V = S = Z = N = C = 0    |
| 11  | SAR R4 0    | 9      | R4 = 3 >> 0 = 3    | V = S = Z = N = C = 0    |
| 12  | SAR R5 2    | 9      | R5 = 0 >> 2 = 0    | V = S = Z = N = C = 0    |
| 13  | SAR R5 0    | 9      | R5 = 0 >> 0 = 0    | V = S = Z = N = C = 0    |
| 14  | SAR R4 2    | 9      | R4 = 3 >> 2 = 0    | V = S = Z = N = C = 0    |

## Registers

| Register | Value |
| -------- | ----- |
| 0        | -1    |
| 1        | -5    |
| 2        | 7     |
| 3        | 1     |
| 4        | 0     |
| 5        | 0     |

## Instruction Memory

| Instruction | Opcode | Register | Reg/IMM | Type |
| ----------- | ------ | -------- | ------- | ---- |
| 0           | 3      | 0        | -8      | I    |
| 1           | 3      | 1        | -10     | I    |
| 2           | 3      | 2        | 15      | I    |
| 3           | 3      | 3        | 4       | I    |
| 4           | 3      | 4        | 3       | I    |
| 5           | 3      | 5        | 0       | I    |
| 6           | 9      | 0        | 1       | R    |
| 7           | 9      | 0        | 2       | R    |
| 8           | 9      | 1        | 1       | R    |
| 9           | 9      | 2        | 1       | R    |
| 10          | 9      | 3        | 2       | R    |
| 11          | 9      | 4        | 0       | R    |
| 12          | 9      | 5        | 2       | R    |
| 13          | 9      | 5        | 0       | R    |
| 14          | 9      | 4        | 2       | R    |

# EOR Test

## Instructions

| ID  | Instruction | Opcode | Output | Status Reg            |
| --- | ----------- | ------ | ------ | --------------------- |
| 0   | MOVI R0 0   | 3      | R0=0   | nth                   |
| 1   | MOVI R1 1   | 3      | R1=1   | nth                   |
| 1   | MOVI R1 1   | 3      | R1=1   | nth                   |
| 2   | MOVI R2 12  | 3      | R2=12  | nth                   |
| 3   | MOVI R3 4   | 3      | R3=4   | nth                   |
| 4   | MOVI R4 7   | 3      | R4=7   | nth                   |
| 5   | MOVI R5 16  | 3      | R5=16  | nth                   |
| 6   | MOVI R6 3   | 3      | R6=3   | nth                   |
| 7   | EOR R0 R1   | 5      | R0=1   | V = S = Z = N = C = 0 |
| 8   | EOR R1 R2   | 6      | R1=13  | V = S = Z = N = C = 0 |
| 9   | EOR R2 R3   | 7      | R2=8   | V = S = Z = N = C = 0 |
| 9   | EOR R2 R3   | 7      | R2=8   | V = S = Z = N = C = 0 |
| 10  | EOR R3 R4   | 8      | R3=3   | V = S = Z = N = C = 0 |
| 11  | EOR R4 R5   | 9      | R4=23  | V = S = Z = N = C = 0 |
| 12  | EOR R5 R6   | 10     | R5=19  | V = S = Z = N = C = 0 |

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

| ID  | Instruction | Opcode | Output | Status Reg                |
| --- | ----------- | ------ | ------ | ------------------------- |
| 0   | MOVI R0 0   | 3      | R0=0   | nth                       |
| 1   | MOVI R1 1   | 3      | R1=1   | nth                       |
| 2   | MOVI R2 12  | 3      | R2=12  | nth                       |
| 3   | MOVI R3 4   | 3      | R3=4   | nth                       |
| 4   | MOVI R4 7   | 3      | R4=7   | nth                       |
| 5   | MOVI R5 16  | 3      | R5=16  | nth                       |
| 6   | MOVI R6 3   | 3      | R6=3   | nth                       |
| 7   | ANDI R0 1   | 5      | R0=0   | V = S = N = C = 0 , Z = 1 |
| 8   | ANDI R1 2   | 5      | R1=0   | V = S = N = C = 0 , Z = 1 |
| 9   | ANDI R2 15  | 5      | R2=12  | V = S = N = C = Z = 0     |
| 10  | ANDI R3 3   | 5      | R3=0   | V = S = N = C = 0 , Z = 1 |
| 11  | ANDI R4 6   | 5      | R4=6   | V = S = N = C = Z = 0     |
| 12  | ANDI R5 15  | 5      | R5=0   | V = S = N = C = 0 , Z = 1 |

## Registers

| Register | Value |
| -------- | ----- |
| 0        | 0     |
| 1        | 0     |
| 2        | 12    |
| 3        | 0     |
| 4        | 6     |
| 5        | 0     |

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

# LDR - STR Test

MOVI R0 5
MOVI R1 10
MOVI R2 20
STR R0 0
STR R1 1
STR R2 2
LDR R0 2
LDR R1 1
LDR R2 0

## Instructions

| ID  | Instruction | Opcode | Output | Status Reg |
| --- | ----------- | ------ | ------ | ---------- |
| 0   | MOVI R0 5   | 3      | R0=5   | nth        |
| 1   | MOVI R1 10  | 3      | R1=10  | nth        |
| 2   | MOVI R2 20  | 3      | R2=20  | nth        |
| 3   | STR R0 0    | 11     | nth    | nth        |
| 4   | STR R1 1    | 11     | nth    | nth        |
| 5   | STR R2 2    | 11     | nth    | nth        |
| 6   | LDR R0 2    | 10     | R0=20  | nth        |
| 7   | LDR R1 1    | 10     | R1=10  | nth        |
| 8   | LDR R2 0    | 10     | R2=5   | nth        |

## Registers

| Register | Value |
| -------- | ----- |
| 0        | 20    |
| 1        | 10    |
| 2        | 5     |

## Data Memory

| Address | Value |
| ------- | ----- |
| 0       | 5     |
| 1       | 10    |
| 2       | 20    |

## Instruction Memory

| Instruction | Opcode | Register | Reg/IMM | Type |
| ----------- | ------ | -------- | ------- | ---- |
| 0           | 3      | 0        | 5       | I    |
| 1           | 3      | 1        | 10      | I    |
| 2           | 3      | 2        | 20      | I    |
| 3           | 11     | 0        | 0       | I    |
| 4           | 11     | 1        | 1       | I    |
| 5           | 11     | 2        | 2       | I    |
| 6           | 10     | 0        | 2       | I    |
| 7           | 10     | 1        | 1       | I    |
| 8           | 10     | 2        | 0       | I    |

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
