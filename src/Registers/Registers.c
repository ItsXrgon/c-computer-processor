/**
 * @file Registers.c
 * @brief Implementation of register-related functions.
 */

int generalRegisters[64]; // Array to store general purpose registers
int SREG[8]; // Array to store status register flags: C, V, N, S, Z
int pc = 0; // Program counter

/**
 * @brief Reads the value of a register.
 * @param reg The register number.
 * @return The value of the register.
 */
int ReadRegister(int reg)
{
    return generalRegisters[reg];
}

/**
 * @brief Writes a value to a register.
 * @param address The register number.
 * @param value The value to be written.
 */
void WriteRegister(int address, int value)
{
    generalRegisters[address] = value;
    printf("Updated: R%d: %d\n", address, value);
}

/**
 * @brief Increments the program counter by 1.
 */
void IncrementPC()
{
    pc++;
}

/**
 * @brief Sets the value of the program counter.
 * @param value The value to be set.
 */
void SetPC(int value)
{
    pc = value;
    printf("Updated: PC: %d\n", value);
}

/**
 * @brief Gets the value of the program counter.
 * @return The value of the program counter.
 */
int GetPC()
{
    return pc;
}

/**
 * @brief Updates the carry flag based on the result of an operation.
 * @param operand1 The first operand.
 * @param operand2 The second operand.
 * @param result The result of the operation.
 */
void updateCarryFlag(int operand1, int operand2, int result)
{
    int prev = SREG[0];
    if (result < operand1 || result < operand2)
    {
        SREG[0] = 1;
    }
    else
    {
        SREG[0] = 0;
    }
    if (prev != SREG[0])
    {
        printf("Carry Flag Updated: %d\n", SREG[0]);
    }
}

/**
 * @brief Updates the overflow flag based on the result of an operation.
 * @param operand1 The first operand.
 * @param operand2 The second operand.
 * @param result The result of the operation.
 */
void updateOverflowFlag(int operand1, int operand2, int result)
{
    int prev = SREG[1];
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
    // print the flag if it got updated
    if (prev != SREG[1])
    {
        printf("Overflow Flag Updated: %d\n", SREG[1]);
    }
}

/**
 * @brief Updates the negative flag based on the result of an operation.
 * @param result The result of the operation.
 */
void updateNegativeFlag(int result)
{
    int prev = SREG[2];
    if (result < 0)
    {
        SREG[2] = 1;
    }
    else
    {
        SREG[2] = 0;
    }
    if (prev != SREG[2])
    {
        printf("Negative Flag Updated: %d\n", SREG[2]);
    }
}

/**
 * @brief Updates the sign flag based on the result of an operation.
 * @param result The result of the operation.
 */
void updateSignFlag(int result)
{
    int prev = SREG[3];
    if (result == 0)
    {
        SREG[3] = 1;
    }
    else
    {
        SREG[3] = 0;
    }
    if (prev != SREG[3])
    {
        printf("Sign Flag Updated: %d\n", SREG[3]);
    }
}

/**
 * @brief Updates the zero flag based on the result of an operation.
 * @param result The result of the operation.
 */
void updateZeroFlag(int result)
{
    int prev = SREG[4];
    if (result == 0)
    {
        SREG[4] = 1;
    }
    else
    {
        SREG[4] = 0;
    }
    if (prev != SREG[4])
    {
        printf("Zero Flag Updated: %d\n", SREG[4]);
    }
}

/**
 * @brief Resets all registers and the program counter to zero.
 */
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

/**
 * @brief Prints the status register flags.
 */
void PrintStatusRegister()
{
    printf("Status Register:\n");
    printf("C: %d\n", SREG[0]);
    printf("V: %d\n", SREG[1]);
    printf("N: %d\n", SREG[2]);
    printf("S: %d\n", SREG[3]);
    printf("Z: %d\n", SREG[4]);
    printf("6: %d\n", SREG[5]);
    printf("7: %d\n", SREG[6]);
    printf("8: %d\n", SREG[7]);
}

/**
 * @brief Prints the values of all non-zero registers.
 */
void PrintAllRegisters()
{
    printf("General Registers:\n");
    for (int i = 0; i < 64; i++)
    {
        if(generalRegisters[i] != 0){
        printf("Register %d: %d\n", i, generalRegisters[i]);
        }
    }
    PrintStatusRegister();
}