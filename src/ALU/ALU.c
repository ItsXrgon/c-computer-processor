#include "../Headers/Registers.h"
#include "../Headers/DataMemory.h"

void ADD(int R1,int R2)
{
    int result = ReadRegister(R1) + ReadRegister(R2);
    int r1 = ReadRegister(R1);
    int r2 = ReadRegister(R2);
    updateCarryFlag(r1, r2 ,result);
    updateNegativeFlag(result);
    updateSignFlag(result);
    updateZeroFlag(result);
    updateOverflowFlag(r1, r2, result);
    WriteRegister(R1, result);
   
}

void SUB(int R1,int R2)
{
    int result = ReadRegister(R1) - ReadRegister(R2);
    int r1 = ReadRegister(R1);
    int r2 = ReadRegister(R2);
    updateNegativeFlag(result);
    updateSignFlag(result);
    updateZeroFlag(result);
    updateOverflowFlag(r1, r2, result);
    WriteRegister(R1, result);
}

void MUL(int R1,int R2)
{
    int result = ReadRegister(R1) * ReadRegister(R2);
    int r1 = ReadRegister(R1);
    int r2 = ReadRegister(R2);

    updateNegativeFlag(result);
    updateZeroFlag(result);
    WriteRegister(R1, result);
}

void MOVI(int R1,int R2)
{
   WriteRegister(R1, R2);
}

void BEQZ(int R1,int R2)
{
    if(ReadRegister(R1) == 0)
    {
        SetPC(GetPC() + R2);
    }
}

void ANDI(int R1,int R2)
{
    updateNegativeFlag(ReadRegister(R1) & R2);
    updateZeroFlag(ReadRegister(R1) & R2);
    WriteRegister(R1, ReadRegister(R1) & R2);
}


void EOR(int R1,int R2)
{
    int result = ReadRegister(R1) ^ ReadRegister(R2);
    int r1 = ReadRegister(R1);
    int r2 = ReadRegister(R2);
    updateNegativeFlag(result);
    updateZeroFlag(result);
    WriteRegister(R1, result);
}

void BR(int R1,int R2)
{
SetPC((ReadRegister(R1) << 16) | ReadRegister(R2));
}

void SAL(int R1,int R2)
{ 
    int result = ReadRegister(R1) << ReadRegister(R2);
    int r1 = ReadRegister(R1);
    int r2 = ReadRegister(R2);
    updateNegativeFlag(result);
    updateZeroFlag(result);
    WriteRegister(R1, result);
}

void SAR(int R1,int R2)
{
    int result = ReadRegister(R1) >> ReadRegister(R2);
    int r1 = ReadRegister(R1);
    int r2 = ReadRegister(R2);
    updateNegativeFlag(result);
    updateZeroFlag(result);
    WriteRegister(R1, result);
}

void LDR(int R1,int R2)
{
   WriteRegister(R1, ReadDataMemory(ReadRegister(R2)));
}

void STR(int R1,int R2)
{
   WriteDataMemory(ReadRegister(R2), ReadRegister(R1));
}

