
#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

void updateCarryFlag(int operand1, int operand2, int result);
void updateOverflowFlag(int operand1, int operand2, int result);
void updateNegativeFlag(int result);
void updateSignFlag(int result);
void updateZeroFlag(int result);
int ReadRegister(int reg);
void WriteRegister(int reg, int value);
void ResetRegisters();
void PrintAllRegisters();
void PrintStatusRegister();
int GetPC();
void SetPC(int value);
void IncrementPC();


#endif