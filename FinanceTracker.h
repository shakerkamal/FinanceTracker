#pragma once
class FinanceTracker
{
public:
	FinanceTracker();

	void addIncome(double amount);
	void addExpense(double amount);
	double calculateBalance() const;

private:
	double income;
	double expense;
};

