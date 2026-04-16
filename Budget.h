#ifndef BUDGET_H   //stops this file being read twice by the compiler
#define BUDGET_H
#include <string> // for std::string

struct Expense {
    std::string name;   
    double amount;      
};

struct Budget {
    
    double salary1;           
    double salary2;           

    Expense expenses[10];     
    int expenseCount;         

    double totalIncome;
    double totalExpenses;
    double remaining;         // totalIncome - totalExpenses
};

void initializeBudget(Budget &b);

void inputExpenses(Budget &b);

void calculateBudget(Budget &b);

void displayBudgetSummary(const Budget &b);

#endif 
