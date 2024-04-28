

int data_memory[2048];

int loadWord(int address){
    return data_memory[address];
}

void storeWord(int address, int value){
    data_memory[address] = value;
}

void PrintAllMemory(){
    for (int i = 0; i < 2048; i++)
    {
        printf("%d: %d\n", i, data_memory[i]);
    }
}

void ResetDataMemory(){
    for (int i = 0; i < 2048; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            data_memory[i] = 0;
        }
    }
}