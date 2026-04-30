#include "advice.h"
#include <iostream>
#include <iomanip>

using namespace std;

// returns 0 = fine, 1 = getting close, 2 = over budget
int analyzeGroceryVsBudget(double groceryTotal, double remaining) {
    if (remaining <= 0) return 2; // already in the red, no point calculating

    double ratio = groceryTotal / remaining;

    if (ratio <= 0.80)      return 0; // under 80% of what's left = good
    else if (ratio <= 1.00) return 1; // 80-100% = tight but technically okay
    else                    return 2; // over 100% = can't afford this
}

void displayDecision(int decision, double groceryTotal, double remaining) {
    cout << "\n~~~ Budget Decision ~~~" << endl;
    cout << fixed << setprecision(2);
    cout << "  Grocery total : E " << groceryTotal << endl;
    cout << "  Remaining     : E " << remaining    << endl;
    cout << endl;

    switch (decision) {
        case 0:
            cout << "  STATUS: WITHIN BUDGET" << endl;
            cout << "  You can afford this shop." << endl;
            cout << "  You'll still have E " << (remaining - groceryTotal) << " left after." << endl;
            break;

        case 1:
            cout << "  STATUS: RISKY" << endl;
            cout << "  Groceries will eat most of what's left." << endl;
            cout << "  Worth checking if anything on the list can wait." << endl;
            break;

        case 2:
            cout << "  STATUS: OVER BUDGET" << endl;
            cout << "  You're short by E " << (groceryTotal - remaining) << "." << endl;
            cout << "  Some items will need to come off the list." << endl;
            break;
    }
}

int findHighestExpense(const Budget &b) {
    if (b.expenseCount == 0) return -1;

    int maxIdx = 0;
    for (int i = 1; i < b.expenseCount; i++) {
        if (b.expenses[i].amount > b.expenses[maxIdx].amount)
            maxIdx = i;
    }
    return maxIdx;
}

void giveAdvice(const Budget &b) {
    cout << "\n~~~ Advice ~~~" << endl;

    int topIdx = findHighestExpense(b);

    if (topIdx != -1) {
        cout << "  Biggest expense: " << b.expenses[topIdx].name
             << " (E " << fixed << setprecision(2) << b.expenses[topIdx].amount << ")" << endl;

        double pct = (b.expenses[topIdx].amount / b.totalIncome) * 100.0;
        cout << "  That's " << setprecision(1) << pct << "% of your income." << endl;
    }

    cout << endl;

    if (b.remaining > b.totalIncome * 0.20) {
        cout << "  You have over 20% of income left that's a good position." << endl;
        cout << "  Consider putting E "
             << fixed << setprecision(2) << (b.remaining * 0.50)
             << " into savings this month." << endl;

    } else if (b.remaining > 0) {
        cout << "  Budget is tight but you're not in the red." << endl;

        if (topIdx != -1) {
            string top = b.expenses[topIdx].name;

            if (top == "Rent") {
                cout << "  Rent is the big one here, so you should consider downsizing or moving" << endl;
                cout << "  somewhere cheaper to make a real difference." << endl;
            } else if (top == "Transport") {
                cout << "  Transport is eating into your budget." << endl;
                cout << "  Look into carpooling or a monthly bus pass." << endl;
            } else if (top == "Electricity") {
                cout << "  Electricity is your biggest cost." << endl;
                cout << "  Check for appliances on standby and swap to energy-saving bulbs." << endl;
            } else {
                cout << "  Try trimming \"" << top << "\" by 10-15% next month." << endl;
            }
        }

    } else {
        // spending more than earning
        cout << "  WARNING: You're spending more than you earn." << endl;
        cout << "  Shortfall: E " << fixed << setprecision(2)
             << (b.remaining * -1) << " per month." << endl;
        cout << endl;
        cout << "  What to do:" << endl;
        cout << "  1. Go through every expense and find what can be cut." << endl;
        cout << "  2. Start with your biggest expense (shown above)." << endl;
        cout << "  3. Set a daily limit until you're back to even." << endl;
    }

    cout << endl;
}
