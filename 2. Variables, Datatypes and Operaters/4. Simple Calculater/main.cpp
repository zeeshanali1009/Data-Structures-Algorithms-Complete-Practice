#include <iostream>
using namespace std;
int main() {
    float num1, num2;
    char op;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter an operator (+, -, *, /, %): ";
    cin >> op;
    cout << "Enter second number: ";
    cin >> num2;
    cout << endl;
    switch(op) {
        case '+':
            cout << "Result: " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Result: " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Result: " << num1 * num2 << endl;
            break;
        case '/':
            if(num2 != 0)
                cout << "Result: " << num1 / num2 << endl;
            else
                cout << "Error: Cannot divide by 0" << endl;
            break;
        case '%':
            if((int)num2 != 0)
                cout << "Result: " << (int)num1 % (int)num2 << endl;
            else
                cout << "Error: Cannot divide by 0" << endl;
            break;
        default:
            cout << "Invalid operator!" << endl;
    }
    return 0;
}
