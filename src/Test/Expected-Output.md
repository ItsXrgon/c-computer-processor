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

| Register | Value |
| -------- | ----- |
| 0        | 0     |
| 1        | 16    |
| 2        | 271   |
| 3        | 12    |
| 4        | 7     |
| 5        | 8     |
| 6        | 2     |

## Data Memory

## Instruction Memory

| Instruction | Opcode | Register | Reg/IMM | Type |
| ----------- | ------ | -------- | ------- | ---- |
| 0           | 3      | 0        | 0       | I    |
| 1           | 3      | 1        | 16      | I    |
| 2           | 3      | 2        | 255     | I    |
| 3           | 3      | 3        | 4       | I    |
| 4           | 3      | 4        | 7       | I    |
| 5           | 3      | 5        | 16      | I    |
| 6           | 3      | 6        | 1       | I    |
| 7           | 0      | 2        | 1       | R    |
| 8           | 1      | 3        | 1       | R    |
| 9           | 8      | 6        | 1       | I    |
| 10          | 9      | 5        | 1       | I    |

# Test 7

## Instructions

| ID  | Instruction | Opcode | Output   | Status Reg |
| --- | ----------- | ------ | -------- | ---------- |
| 0   | MOVI R0 0   | 3      | R0 = 0   | nth        |
| 1   | MOVI R1 1   | 3      | R1 = 1   | nth        |
| 2   | MOVI R2 128 | 3      | R2 = 128 | nth        |
| 3   | MOVI R3 4   | 3      | R3 = 4   | nth        |
| 4   | MOVI R4 7   | 3      | R4 = 7   | nth        |
| 5   | MOVI R5 16  | 3      | R5 = 16  | nth        |
| 6   | MOVI R6 3   | 3      | R6 = 3   | nth        |
| 7   | SAL R6 2    | 8      | R6 = 12  | N = Z =    |
| 8   | SAR R5 R2   | 9      | R5 = 0   | N = Z =    |

smo please format into table

## Registers

| Register | Value |
| -------- | ----- |
| 0        | 0     |
| 1        | 1     |
| 2        | 128   |
| 3        | 4     |
| 4        | 7     |
| 5        | 0     |
| 6        | 12    |

## Data Memory

## Instruction Memory

| Instruction | Opcode | Register | Reg/IMM | Type |
| ----------- | ------ | -------- | ------- | ---- |
| 0           | 3      | 0        | 0       | I    |
| 1           | 3      | 1        | 1       | I    |
| 2           | 3      | 2        | 128     | I    |
| 3           | 3      | 3        | 4       | I    |
| 4           | 3      | 4        | 7       | I    |
| 5           | 3      | 5        | 16      | I    |
| 6           | 3      | 6        | 3       | I    |
| 10          | 8      | 6        | 2       | I    |
| 11          | 9      | 5        | 2       | R    |
