# Test 1

| Instruction | Opcode | Output         | Status Reg          |
| ----------- | ------ | -------------- | ------------------- |
| MOVI R0 0   | 3      | R0 = 0         | nth                 |
| MOVI R1 1   | 3      | R1 = 1         | nth                 |
| MOVI R2 0   | 3      | R2 = 0         | nth                 |
| MOVI R3 4   | 3      | R3 = 4         | nth                 |
| MOVI R4 7   | 3      | R4 = 7         | nth                 |
| MOVI R5 16  | 3      | R5 = 16        | nth                 |
| MOVI R6 1   | 3      | R6 = 1         | nth                 |
| BEQZ R3 5   | 4      | nth            | nth                 |
| ADD R2 R1   | 0      | R2 = 0 + 1 = 1 | C = V = N = S = Z = |
| SUB R3 R1   | 1      | R3 = 4 - 1 = 3 | V = N = S = Z =     |
| SAL R6 1    | 8      | R6 = 2         | N = Z =             |
| SAR R5 1    | 9      | R5 = 8         | N = Z =             |
| STR R5 0    | 11     | Mem[0] = 8     | nth                 |
| STR R6 1    | 11     | Mem[1] = 2     | nth                 |
| STR R2 2    | 11     | Mem[2] = 1     | nth                 |
| LDR R5 2    | 10     | R5 = 1         | nth                 |
| LDR R6 1    | 10     | R6 = 2         | nth                 |
| LDR R2 0    | 10     | R2 = 8         | nth                 |

# Test 2
