#ifndef BUDGET_H   // stops the compiler from reading this file twice
#define BUDGET_H
#include <string>

struct Expense {
    std::string name;
    double amount;
};

struct Budget {
    double salary1;       
    double salary2;       

    Expense expenses[10]; // fixed array 10 categories is enough for a family
    int expenseCount;

    double totalIncome;
    double totalExpenses;
    double remaining;     // what's left after all expenses
};

void initializeBudget(Budget &b);
void inputExpenses(Budget &b);
void calculateBudget(Budget &b);
void displayBudgetSummary(const Budget &b);

#endif
