#include <stdio.h>
#include <stdlib.h>

double calculate(double num1, double num2, char op)
{
    if (op == '+')
    {
        return num1 + num2;
    }
    else if (op == '-')
    {
        return num1 - num2;
    }
    else if (op == '*')
    {
        return num1 * num2;
    }
    else if (op == '/')
    {
        return num1 / num2;
    }
    else
    {
        char op;

        printf("Enter valid symbol for operator: ");
        scanf(" %c", &op);
        calculate(num1, num2, op);
    }
}

int main()
{
    printf("%f", calculate(6, 6, 'p'));

    return 0;
}