#include <iostream>
#include "budget.h"
#include "grocery.h"
#include "advice.h"
#include "fileio.h"

using namespace std;

void printWelcome() {
    cout << "\n";
    cout << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl;
    cout << ":         FAMILY FINANCIAL ASSISTANT       :" << endl;
    cout << ":                  v1.0                     :" << endl;
    cout << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*" << endl;
    cout << "\nHere's what we'll do:" << endl;
    cout << "  1. Log your monthly income and expenses" << endl;
    cout << "  2. Plan your grocery run against what's left" << endl;
    cout << "  3. Get some advice on where you can cut back" << endl;
    cout << "\nNote: salaries are pre-loaded for now. Lets get started\n" << endl;
}

int main() {

    printWelcome();

    Budget myBudget;
    initializeBudget(myBudget);

    inputExpenses(myBudget);
    calculateBudget(myBudget);
    displayBudgetSummary(myBudget);

    cout << "\nPress Enter when you're ready to plan groceries...";
    cin.ignore();
    cin.get();

    GroceryList myGroceries;
    initGroceryList(myGroceries);

    inputGroceryItems(myGroceries);

    cout << "\nOkay, go do your shopping, Press Enter when you're back...";
    cin.ignore();
    cin.get();

    inputGroceryPrices(myGroceries);
    calculateGroceryTotal(myGroceries);
    displayGroceryList(myGroceries);

    int decision = analyzeGroceryVsBudget(myGroceries.totalCost, myBudget.remaining);
    displayDecision(decision, myGroceries.totalCost, myBudget.remaining);

    giveAdvice(myBudget);

    saveReport(myBudget, myGroceries, decision, "financial_report.txt");

    cout << "\nThanks for using the Family Financial Assistant ;)" << endl;
    cout << "Report saved. Goodbye :)\n" << endl;

    return 0;
}
