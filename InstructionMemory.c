int instruction_memory[1024][16];


int ReadInstructionMemory(int address)
{
    return instruction_memory[address];
}

void WriteInstructionMemory(int address, int value)
{
    instruction_memory[address] = value;
}

void ResetInstructionMemory()
{
    for (int i = 0; i < 1024; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            instruction_memory[i][j] = 0;
        }
    }
}