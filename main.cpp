#include "main.h"
#include <iostream>
#include <sstream>
#include <limits>

#include "FinanceTracker.h"

void displayHelp() {
    std::cout << "Available commands:\n"
                << "  h - Display available commands\n"
                << "  i <amount> - Add income\n"
                << "  e <amount> - Add expense\n"
                << "  b - Display balance\n"
                << "  ex - Exit the program\n";
}

bool validateAmount(double& amount) {
    if (amount >= 0.0) {
        return true;
    }
    else {
        std::cout << "Please provide an amount greater than 0.\n";
        return false;
    }
}

void processTransaction(FinanceTracker& tracker, const std::string& command, double amount) {
    if (validateAmount(amount)) {
        if (command == "i") {
            tracker.addIncome(amount);
            std::cout << "Income added.\n";
        }
        else {
            tracker.addExpense(amount);
            std::cout << "Expense added.\n";
        }
    }
}

int main() {
	FinanceTracker tracker;

    std::string userInput;
    std::cout << "Type 'h' for a list of commands.\n";

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, userInput);

        std::istringstream iss(userInput);
        std::string command;
        iss >> command;

        if (command == "h") {
            displayHelp();
        }
        else if (command == "i" || command == "e") {
            double amount;
            if (iss >> amount) {
                processTransaction(tracker, command, amount);
            }
            else {
                std::cout << "Invalid amount. Please enter a valid number.\n";
                // Clear the error state of the stream
                iss.clear();
                // Consume the invalid input
                iss.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        else if (command == "b") {
            // Display balance
            std::cout << "Balance: " << tracker.calculateBalance() << "\n";
        }
        else if (command == "ex") {
            // Exit the program
            std::cout << "Exiting...\n";
            break;
        }
        else {
            // Invalid command
            std::cout << "Invalid command. Type 'help' for a list of commands.\n";
        }
    }

    return 0;
}