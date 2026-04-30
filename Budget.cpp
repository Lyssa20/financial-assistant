#include "budget.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void initializeBudget(Budget &b) {
    // pre-loaded salaries for the demo, ideally these should be user inputs
    b.salary1 = 15000.00;
    b.salary2 = 8000.00;

    b.expenseCount = 0;

    for (int i = 0; i < 10; i++) {
        b.expenses[i].name   = "";
        b.expenses[i].amount = 0.0;
    }
}

void inputExpenses(Budget &b) {
    cout << "\n~~~ Monthly Expenses ~~~" << endl;
    cout << "Enter the amount for each expense." << endl;
    cout << "Type 0 for anything that doesn't apply to you.\n" << endl;

    double amt;

    // I'm doing this manually per-category instead of a loop
    // because the categories are fixed and named, making it easier to read

    cout << "  Rent: E ";
    cin >> amt;
    if (amt > 0) { b.expenses[b.expenseCount].name = "Rent"; b.expenses[b.expenseCount].amount = amt; b.expenseCount++; }

    cout << "  Water: E ";
    cin >> amt;
    if (amt > 0) { b.expenses[b.expenseCount].name = "Water"; b.expenses[b.expenseCount].amount = amt; b.expenseCount++; }

    cout << "  Electricity: E ";
    cin >> amt;
    if (amt > 0) { b.expenses[b.expenseCount].name = "Electricity"; b.expenses[b.expenseCount].amount = amt; b.expenseCount++; }

    cout << "  Transport: E ";
    cin >> amt;
    if (amt > 0) { b.expenses[b.expenseCount].name = "Transport"; b.expenses[b.expenseCount].amount = amt; b.expenseCount++; }

    cout << "  School Fees: E ";
    cin >> amt;
    if (amt > 0) { b.expenses[b.expenseCount].name = "School Fees"; b.expenses[b.expenseCount].amount = amt; b.expenseCount++; }

    cout << "  Insurance: E ";
    cin >> amt;
    if (amt > 0) { b.expenses[b.expenseCount].name = "Insurance"; b.expenses[b.expenseCount].amount = amt; b.expenseCount++; }

    cout << "  Other: E ";
    cin >> amt;
    if (amt > 0) { b.expenses[b.expenseCount].name = "Other"; b.expenses[b.expenseCount].amount = amt; b.expenseCount++; }
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

    cout << left << setw(25) << "Salary 1"
         << "E " << fixed << setprecision(2) << b.salary1 << endl;

    if (b.salary2 > 0) {
        cout << left << setw(25) << "Salary 2"
             << "E " << fixed << setprecision(2) << b.salary2 << endl;
    }

    cout << "----------------------------------------" << endl;
    cout << left << setw(25) << "Total Income"
         << "E " << fixed << setprecision(2) << b.totalIncome << endl;
    cout << "----------------------------------------" << endl;

    cout << "\n  Expenses:" << endl;
    for (int i = 0; i < b.expenseCount; i++) {
        cout << "  " << left << setw(23) << b.expenses[i].name
             << "E " << fixed << setprecision(2) << b.expenses[i].amount << endl;
    }

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << left << setw(25) << "Total Expenses"
         << "E " << fixed << setprecision(2) << b.totalExpenses << endl;

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << left << setw(25) << "Remaining"
         << "E " << fixed << setprecision(2) << b.remaining;

    if (b.remaining < 0)        cout << "  !! NO MORE FUNDS !!";
    else if (b.remaining < 500) cout << "  (tight)";
    else                        cout << "  (ok)";

    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    // show what each expense is as a % of income, this should help spot the big ones
    cout << "\n  Breakdown (% of income):" << endl;
    for (int i = 0; i < b.expenseCount; i++) {
        double pct = (b.expenses[i].amount / b.totalIncome) * 100.0;
        cout << "  " << left << setw(23) << b.expenses[i].name
             << setprecision(1) << pct << "%" << endl;
    }

    // divide by 30 should be good enough for a daily figure
    double daily = b.remaining / 30.0;
    cout << "\n  Daily spending budget: E "
         << fixed << setprecision(2) << daily << endl;
}
