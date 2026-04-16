#include "budget.h"       
#include <iostream>       
#include <iomanip>        // controls decimal places in output
#include <string>

using namespace std;      

void initializeBudget(Budget &b){

    b.salary1 = 15000.00;   
    b.salary2 = 8000.00;    

    b.expenseCount = 0;     
    
    for (int i = 0; i < 10; i++) {
        b.expenses[i].name   = "";
        b.expenses[i].amount = 0.0;
    }
}

void inputExpenses(Budget &b) {
    cout << "\n~~~ Monthly Expense Input ~~~" << endl;
    cout << "Please enter the prices of all your monthly expenses"<< endl;
    cout << "Enter R 0 for any item you don't have\know the price off\n" << endl;

    double amount;  

    cout << "  Rent: E ";
    cin >> amount;
    if (amount > 0) { b.expenses[b.expenseCount].name = "Rent"; b.expenses[b.expenseCount].amount = amount; b.expenseCount++; }

    cout << "  Water: E ";
    cin >> amount;
    if (amount > 0) { b.expenses[b.expenseCount].name = "Water"; b.expenses[b.expenseCount].amount = amount; b.expenseCount++; }

    cout << "  Electricity: E ";
    cin >> amount;
    if (amount > 0) { b.expenses[b.expenseCount].name = "Electricity"; b.expenses[b.expenseCount].amount = amount; b.expenseCount++; }

    cout << "  Transport: E ";
    cin >> amount;
    if (amount > 0) { b.expenses[b.expenseCount].name = "Transport"; b.expenses[b.expenseCount].amount = amount; b.expenseCount++; }

    cout << "  School Fees: E ";
    cin >> amount;
    if (amount > 0) { b.expenses[b.expenseCount].name = "School Fees"; b.expenses[b.expenseCount].amount = amount; b.expenseCount++; }

    cout << "  Insurance: E ";
    cin >> amount;
    if (amount > 0) { b.expenses[b.expenseCount].name = "Insurance"; b.expenses[b.expenseCount].amount = amount; b.expenseCount++; }

    cout << "  Other costs: E ";
    cin >> amount;
    if (amount > 0) { b.expenses[b.expenseCount].name = "Other costs"; b.expenses[b.expenseCount].amount = amount; b.expenseCount++; }
}

void calculateBudget(Budget &b) {
	
    b.totalIncome = b.salary1 + b.salary2;

    b.totalExpenses = 0;
    for (int i = 0; i < b.expenseCount; i++) {
        b.totalExpenses += b.expenses[i].amount;
    }

    b.remaining = b.totalIncome - b.totalExpenses;
}

void displayBudgetSummary(const Budget &b) {

    cout << "\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "         MONTHLY BUDGET SUMMARY         " << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    // Show income sources
    cout << left << setw(25) << "Salary 1"
         << "E " << fixed << setprecision(2) << b.salary1 << endl;

    // Only show salary 2 if it's non-zero
    if (b.salary2 > 0) {
        cout << left << setw(25) << "Salary 2"
             << "E " << fixed << setprecision(2) << b.salary2 << endl;
    }

    cout << "----------------------------------------" << endl;
    cout << left << setw(25) << "Total Income"
         << "E " << fixed << setprecision(2) << b.totalIncome << endl;
    cout << "----------------------------------------" << endl;

    // Show each expense that was entered
    cout << "\n  Expenses:" << endl;
    for (int i = 0; i < b.expenseCount; i++) {
        cout << "  " << left << setw(23) << b.expenses[i].name
             << "E " << fixed << setprecision(2) << b.expenses[i].amount << endl;
    }

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << left << setw(25) << "Total Expenses"
         << "E " << fixed << setprecision(2) << b.totalExpenses << endl;

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << left << setw(25) << "Remaining"
         << "E " << fixed << setprecision(2) << b.remaining;

    if (b.remaining < 0)        cout << "  !!NO MORE FUNDS!!";
    else if (b.remaining < 500) cout << "  (tight)";
    else                        cout << "  (ok)";

    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    cout << "\n  Expense breakdown (% of income):" << endl;
    for (int i = 0; i < b.expenseCount; i++) {
        // percentage = (expense / income) * 100
        double pct = (b.expenses[i].amount / b.totalIncome) * 100.0;
        cout << "  " << left << setw(23) << b.expenses[i].name
             << setprecision(1) << pct << "%" << endl;
    }

    // for daily budget divide remaining by 30 days
    double daily = b.remaining / 30.0;
    cout << "\n  Daily spending budget: E "
         << fixed << setprecision(2) << daily << endl;
}
