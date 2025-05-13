#include <iostream>
using namespace std;

void showMenu() {
    cout << "\n===== DIGITAL CALCULATOR =====\n";
    cout << "1. Addition (+)\n";
    cout << "2. Subtraction (-)\n";
    cout << "3. Multiplication (*)\n";
    cout << "4. Division (/)\n";
    cout << "5. Modulus (%)\n";
    cout << "6. Exit\n";
    cout << "Choose an operation (1-6): ";
}

bool isValidChoice(int choice) {
    return choice >= 1 && choice <= 6;
}

bool isInteger(float num) {
    return num == (int)num;
}

int main() {
    int choice;
    float num1, num2;

    while (true) {
        showMenu();
        cin >> choice;

        if (!isValidChoice(choice)) {
            cout << "? Invalid choice. Please try again.\n";
            continue;
        }

        if (choice == 6) {
            cout << "?? Thank you for using the calculator. Goodbye!\n";
            break;
        }

        cout << "Enter first number: ";
        while (!(cin >> num1)) {
            cout << "? Please enter a valid number: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        cout << "Enter second number: ";
        while (!(cin >> num2)) {
            cout << "? Please enter a valid number: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        switch (choice) {
            case 1:
                cout << "? Result: " << num1 + num2 << "\n";
                break;
            case 2:
                cout << "? Result: " << num1 - num2 << "\n";
                break;
            case 3:
                cout << "? Result: " << num1 * num2 << "\n";
                break;
            case 4:
                if (num2 != 0)
                    cout << "? Result: " << num1 / num2 << "\n";
                else
                    cout << "? Division by zero is not allowed.\n";
                break;
            case 5:
                if (isInteger(num1) && isInteger(num2)) {
                    if ((int)num2 != 0)
                        cout << "? Result: " << (int)num1 % (int)num2 << "\n";
                    else
                        cout << "? Modulus by zero is not allowed.\n";
                } else {
                    cout << "? Modulus only works with integers.\n";
                }
                break;
        }
    }

    return 0;
}

