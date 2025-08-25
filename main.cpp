#include <iostream>

using namespace std;

// Function declarations for basic arithmetic operations
double add(double a, double b)
{
    return a + b;
}

double subtract(double a, double b)
{
    return a - b;
}

double multiply(double a, double b)
{
    return a * b;
}

double divide(double a, double b)
{
    if (b == 0)
    {
        throw runtime_error("Division by zero is not allowed");
    }
    return a / b;
}

int main()
{
    cout << "=== C++ Calculator ===" << endl;

    double num1, num2;
    char operation;

    // Input
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter operation (+, -, *, /): ";
    cin >> operation;
    cout << "Enter second number: ";
    cin >> num2;

    // Perform calculation
    try
    {
        double result;
        switch (operation)
        {
        case '+':
            result = add(num1, num2);
            break;
        case '-':
            result = subtract(num1, num2);
            break;
        case '*':
            result = multiply(num1, num2);
            break;
        case '/':
            result = divide(num1, num2);
            break;
        default:
            throw runtime_error("Invalid operation");
        }
        cout << "Result: " << result << endl;
    }
    catch (const runtime_error &e)
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}