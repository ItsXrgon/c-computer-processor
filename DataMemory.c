int data_memory[2048][8];
int ReadDataMemory(int address)
{
    return data_memory[address];
}

void WriteDataMemory(int address, int value)
{
    data_memory[address] = value;
}

void ResetDataMemory()
{
    for (int i = 0; i < 2048; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            data_memory[i][j] = 0;
        }
    }
}