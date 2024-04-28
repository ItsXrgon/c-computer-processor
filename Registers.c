int generalRegisters[64];
int SREG[8]; // SREG[0] = C, SREG[1] = V, SREG[2] = N, SREG[3] = S, SREG[4] = Z
int pc = 0;
int ReadRegister(int reg)
{
    return generalRegisters[reg];
}

void WriteRegister(int address, int value)
{
    generalRegisters[address] = value;
}
void IncrementPC()
{
    pc++;
}

void SetPC(int value)
{
    pc = value;
}

int GetPC()
{
    return pc;
}
void updateCarryFlag(int operand1, int operand2, int result)
{
    if (result < operand1 || result < operand2)
    {
        SREG[0] = 1;
    }
    else
    {
        SREG[0] = 0;
    }
}

void updateOverflowFlag(int operand1, int operand2, int result)
{
    if (operand1 > 0 && operand2 > 0 && result < 0)
    {
        SREG[1] = 1;
    }
    else if (operand1 < 0 && operand2 < 0 && result > 0)
    {
        SREG[1] = 1;
    }
    else
    {
        SREG[1] = 0;
    }
}

void updateNegativeFlag(int result)
{
    if (result < 0)
    {
        SREG[2] = 1;
    }
    else
    {
        SREG[2] = 0;
    }
}

void updateSignFlag(int result)
{
    if (result == 0)
    {
        SREG[3] = 1;
    }
    else
    {
        SREG[3] = 0;
    }
}

void updateZeroFlag(int result)
{
    if (result == 0)
    {
        SREG[4] = 1;
    }
    else
    {
        SREG[4] = 0;
    }
}
void ResetRegisters()
{
    for (int i = 0; i < 64; i++)
    {
        generalRegisters[i] = 0;
    }
    for (int i = 0; i < 8; i++)
    {
        SREG[i] = 0;
    }
    pc = 0;
}