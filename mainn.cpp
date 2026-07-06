#include <iostream>

int main() {
    double num1, num2;
    char operation;
    char continueChoice;
    
    std::cout << "=== Simple Calculator ===\n";
    
    do {
        // Get input from user
        std::cout << "\nEnter first number: ";
        std::cin >> num1;
        
        std::cout << "Enter second number: ";
        std::cin >> num2;
        
        std::cout << "Choose operation (+, -, *, /): ";
        std::cin >> operation;
        
        // Perform calculation
        switch (operation) {
            case '+':
                std::cout << num1 << " + " << num2 << " = " << (num1 + num2) << std::endl;
                break;
            case '-':
                std::cout << num1 << " - " << num2 << " = " << (num1 - num2) << std::endl;
                break;
            case '*':
                std::cout << num1 << " * " << num2 << " = " << (num1 * num2) << std::endl;
                break;
            case '/':
                if (num2 == 0) {
                    std::cout << "Error: Division by zero is not allowed!\n";
                } else {
                    std::cout << num1 << " / " << num2 << " = " << (num1 / num2) << std::endl;
                }
                break;
            default:
                std::cout << "Error: Invalid operation! Please use +, -, *, or /\n";
        }
        
        std::cout << "\nDo you want to perform another calculation? (y/n): ";
        std::cin >> continueChoice;
        
    } while (continueChoice == 'y' || continueChoice == 'Y');
    
    std::cout << "\nThank you for using the calculator!\n";
    
    return 0;
}