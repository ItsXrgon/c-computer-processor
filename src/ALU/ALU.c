#include "../Headers/Registers.h"
#include "../Headers/DataMemory.h"

int ALU(int operand1, int operand2, int operation){
    int result;
    switch (operation)
    {
    case 0: // ADD
        result = operand1 + operand2;
        updateCarryFlag(operand1, operand2, result);
        updateOverflowFlag(operand1, operand2, result);
        updateNegativeFlag(result);
        updateSignFlag(result);
        updateZeroFlag(result);
        return result;
    case 1: // SUB
        result = operand1 - operand2;
        updateOverflowFlag(operand1, operand2, result);
        updateNegativeFlag(result);
        updateSignFlag(result);
        updateZeroFlag(result);
        return result;
    case 2: // MUL
        result = operand1 * operand2;
        updateNegativeFlag(result);
        updateZeroFlag(result);
        return result;
    case 3: // Move immediate
        WriteRegister(operand1, operand2);
        return 0;
    case 4: // Branch if equal zero
        if (operand1 == 0)
        {
            SetPC(operand2);
        }
        return 0;
    case 5: // AND Immediate
        result = operand1 & operand2;
        updateNegativeFlag(result);
        updateZeroFlag(result);
        return result;
    case 6: // Exclusive OR
        result = operand1 ^ operand2;
        updateNegativeFlag(result);
        updateZeroFlag(result);
    case 7: // Branch Register
        SetPC(operand1 || operand2);
        return 0;
    case 8: // Shift Arithmetic Left
        result = operand1 << operand2;
        updateNegativeFlag(result);
        updateZeroFlag(result);
        return result;
    case 9: // Shift Arithmetic Right
        result = operand1 >> operand2;
        updateNegativeFlag(result);
        updateZeroFlag(result);
        return result;
    case 10: // Load to Register
        WriteRegister(operand1, ReadDataMemory(operand2));
        return 0;
    case 11: // Store from Register
        WriteDataMemory(operand1, ReadRegister(operand2));
        return operand1;
    default:
        return 0;
    }
}