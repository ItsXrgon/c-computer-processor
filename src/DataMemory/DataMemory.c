

int data_memory[2048];

int ReadDataMemory(int address){
    return data_memory[address];
}

void WriteDataMemory(int address, int value){
    data_memory[address] = value;
}

void PrintAllDataMemory(){
    for (int i = 0; i < 2048; i++)
    {   
        if (data_memory[i] != 0){
        printf("%d: %d\n", i, data_memory[i]);
        }
    }
}

void ResetDataMemory(){
    for (int i = 0; i < 2048; i++)
    {
        data_memory[i] = 0;
    }
}