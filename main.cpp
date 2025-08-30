#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
#include <string>
using namespace std;
// Class to store calculation history
class CalculationHistory {
private:
    vector<string> history;

public:
    void addRecord(double num1, double num2, char op, double result) {
        string record = to_string(num1) + " " + op + " " + to_string(num2) + " = " + to_string(result);
        if (op == 's') {
            record = "sqrt(" + to_string(num1) + ") = " + to_string(result);
        }
        history.push_back(record);
    }

    void displayHistory() const {
        if (history.empty()) {
            cout << "No calculations in history." << endl;
            return;
        }
        cout << "\nCalculation History:" << endl;
        for (size_t i = 0; i < history.size(); ++i) {
            cout << i + 1 << ". " << history[i] << endl;
        }
    }
}; 

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

double power(double base, double exponent)
{
    return pow(base, exponent);
}

double squareRoot(double a)
{
    if (a < 0)
    {
        throw runtime_error("Square root of negative number is not allowed");
    }
    return sqrt(a);
}
void displayMenu()
{
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

bool getValidNumber(double &num)
{
    if (cin >> num)
    {
        return true;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return false;
}
int main()
{
    CalculationHistory calcHistory;
    cout << "=== C++ Calculator ===" << endl;
    while (true)
    {
        displayMenu();
        int choice;
        cin >> choice;

       if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: Invalid choice" << endl;
            continue;
        }

        if (choice == 8) {
            cout << "Exiting calculator..." << endl;
            break;
        }

        if (choice == 7) {
            calcHistory.displayHistory();
            continue;
        }

        if (choice < 1 || choice > 8) {
            cout << "Error: Invalid choice" << endl;
            continue;
        }

        double num1, num2;
        // Input
        cout << "Enter first number: ";
        if (!getValidNumber(num1))
        {
            cout << "Error: Invalid number" << endl;
            continue;
        }
        // for square root only one number is used

        if (choice != 6)
        {
            cout << "Enter second number: ";
            if (!getValidNumber(num2))
            {
                cout << "Error: Invalid number" << endl;
                continue;
            }
        }
        else
        {
            num2 = 0; // Dummy value for square root
        }

        // Perform calculation
        try
        {
            double result;
            char op;
            switch (choice)
            {
            case 1:
                    result = add(num1, num2);
                    op = '+';
                    break;
                case 2:
                    result = subtract(num1, num2);
                    op = '-';
                    break;
                case 3:
                    result = multiply(num1, num2);
                    op = '*';
                    break;
                case 4:
                    result = divide(num1, num2);
                    op = '/';
                    break;
                case 5:
                    result = power(num1, num2);
                    op = '^';
                    break;
                case 6:
                    result = squareRoot(num1);
                    op = 's';
                    break;
                default:
                    throw runtime_error("Invalid operation");
            }
            cout << "Result: " << result << endl;
            calcHistory.addRecord(num1, num2, op, result);
        }
        catch (const runtime_error &e)
        {
            cout << "Error: " << e.what() << endl;
        }
    }
    return 0;
}