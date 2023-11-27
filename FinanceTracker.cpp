#include "FinanceTracker.h"

FinanceTracker::FinanceTracker() : income(0.0), expense(0.0) {}

void FinanceTracker::addIncome(double amount) {
	income += amount;
}

void FinanceTracker::addExpense(double amount) {
	expense += amount;
}

double FinanceTracker::calculateBalance() const {
	return income - expense;
}
