#include "fileio.h"
#include "advice.h"    
#include <fstream>     // gives ofstream
#include <iostream>
#include <iomanip>
#include <ctime>       // gets the current date and time

using namespace std;
void saveReport(const Budget &b, const GroceryList &g,
                int decision, const string &filename) {
 
    ofstream file(filename.c_str());

    if (!file.is_open()) {
        cout << "  ERROR: Could not save report to \"" << filename << "\"" << endl;
        cout << "  Make sure you have write permission in this folder." << endl;
        return;   
    }

    // time_t stores a timestamp;
    time_t now = time(0);
    string timestamp = ctime(&now);

   
    if (!timestamp.empty() && timestamp[timestamp.length() - 1] == '\n') {
    timestamp.erase(timestamp.length() - 1);
    }

    file << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    file << "  FAMILY FINANCIAL ASSISTANT REPORT     " << endl;
    file << "  Generated: " << timestamp                  << endl;
    file << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    file << "\nINCOME" << endl;
    file << "  Salary 1 : E " << fixed << setprecision(2) << b.salary1 << endl;
    if (b.salary2 > 0)
        file << "  Salary 2 : E " << b.salary2 << endl;
    file << "  Total    : E " << b.totalIncome << endl;

    file << "\nEXPENSES" << endl;
    for (int i = 0; i < b.expenseCount; i++) {
        double pct = (b.expenses[i].amount / b.totalIncome) * 100.0;
        file << "  " << left << setw(20) << b.expenses[i].name
             << "E " << setw(10) << b.expenses[i].amount
             << "(" << setprecision(1) << pct << "%)" << endl;
    }
    file << "  Total expenses : E " << fixed << setprecision(2)
         << b.totalExpenses << endl;

    file << "\nRESULT" << endl;
    file << "  Remaining after expenses : E " << b.remaining << endl;
    file << "  Daily budget             : E " << b.remaining / 30.0 << endl;

    file << "\nGROCERY LIST" << endl;
    for (int i = 0; i < g.itemCount; i++) {
        if (g.items[i].price > 0) {
            file << "  " << left << setw(25) << g.items[i].name
                 << "E " << fixed << setprecision(2) << g.items[i].price << endl;
        }
    }
    file << "  Total grocery cost : E " << g.totalCost << endl;

    file << "\nDECISION: ";
    switch (decision) {
        case 0: file << "WITHIN BUDGET"  << endl; break;
        case 1: file << "RISKY"          << endl; break;
        case 2: file << "OVER BUDGET"    << endl; break;
    }

    int hi = findHighestExpense(b);
    if (hi != -1) {
        file << "\nHIGHEST EXPENSE: " << b.expenses[hi].name
             << " (E " << b.expenses[hi].amount << ")" << endl;
    }

    file << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    file << "  End of report" << endl;
    file << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    file.close();  

    cout << "\n  ? Report saved to \"" << filename << "\"" << endl;
}
