#include <iostream>
#include "budget.h"    // Budget struct + budget functions
#include "grocery.h"   // GroceryList struct + grocery functions
#include "advice.h"    // analyzeGroceryVsBudget, displayDecision, giveAdvice
#include "fileio.h"    // saveReport

using namespace std;

void printWelcome() {
    cout << "\n";
    cout << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << ":          HELLO WELCOME TO...              :" << endl;
    cout << ":     FAMILY FINANCIAL ASSISTANT v1.0       :" << endl;
    cout << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "\nThis app will help track all your expenes by:" << endl;
    cout << "  1. Tracking your monthly income and expenses"     << endl;
    cout << "  2. Planning a grocery plan against your budget" << endl;
    cout << "  3. Giving advice on where to cut costs"  << endl;
    cout << "\n !Note salaries are pre-loaded  Let's begin:) \n"  << endl;
    cout << "\n             Let's begin:) \n" <<endl;
}

int main() {

    printWelcome();

    Budget myBudget;
    initializeBudget(myBudget);   

    inputExpenses(myBudget);

    calculateBudget(myBudget);
    displayBudgetSummary(myBudget);

    cout << "\nPress Enter to continue to grocery planning...";
    cin.ignore();   
    cin.get();      // wait for the user to press Enter

    GroceryList myGroceries;
    initGroceryList(myGroceries);     

    inputGroceryItems(myGroceries);  

    cout << "\nNow go to the store! When you're back, press Enter...";
    cin.ignore();
    cin.get();

    inputGroceryPrices(myGroceries);  //enter prices
    calculateGroceryTotal(myGroceries);
    displayGroceryList(myGroceries);

    int decision = analyzeGroceryVsBudget(myGroceries.totalCost, myBudget.remaining);
    displayDecision(decision, myGroceries.totalCost, myBudget.remaining);

    giveAdvice(myBudget);

    saveReport(myBudget, myGroceries, decision, "financial_report.txt");

    cout << "\nThank you for using the Family Financial Assistant;}" << endl;
    cout << "Your report has been saved. Goodbye!\n" << endl;

    return 0;   
}
