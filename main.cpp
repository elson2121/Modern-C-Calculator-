#include <iostream>
#include <cmath>

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

double power(double base, double exponent) {
    return pow(base, exponent);
}

double squareRoot(double a) {
    if (a < 0) {
        throw runtime_error("Square root of negative number is not allowed");
    }
    return sqrt(a);

}
void displayMenu() {
    cout << "\n=== C++ Calculator ===" << endl;
    cout << "Select operation:" << endl;
    cout << "1. Addition (+)" << endl;
    cout << "2. Subtraction (-)" << endl;
    cout << "3. Multiplication (*)" << endl;
    cout << "4. Division (/)" << endl;
    cout << "5. Power (^)" << endl;
    cout << "6. Square Root (s)" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter choice (1-7): ";
}



int main()
{
    cout << "=== C++ Calculator ===" << endl;
 while (true) {
        displayMenu();
        int choice;
        cin >> choice;

        if (choice == 7) {
            cout << "Exiting calculator..." << endl;
            break;
        }

        if (choice < 1 || choice > 7) {
            cout << "Error: Invalid choice" << endl;
            continue;
        }

    double num1, num2;
    // Input
    cout << "Enter first number: ";
    cin >> num1;
 if (choice != 6) {
            cout << "Enter second number: ";
            cin >> num2;
        } else {
            num2 = 0; // Dummy value for square root
        }

    // Perform calculation
    try
    {
        double result;
        switch (choice)
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