#include "advice.h"
#include <iostream>
#include <iomanip>

using namespace std;


int analyzeGroceryVsBudget(double groceryTotal, double remaining) {
    if (remaining <= 0) {
        
        return 2;
    }

    double ratio = groceryTotal / remaining;   

    if (ratio <= 0.80)       return 0;   // WITHIN budget (under 80%)
    else if (ratio <= 1.00)  return 1;   // RISKY (80-100%)
    else                     return 2;   // OVER budget (more than 100%)
}

void displayDecision(int decision, double groceryTotal, double remaining) {
    cout << "\n~~~ Budget Decision ~~~" << endl;
    cout << fixed << setprecision(2);
    cout << "  Grocery total : E " << groceryTotal << endl;
    cout << "  Remaining     : E " << remaining    << endl;
    cout << endl;

    switch (decision) {
        case 0:
            cout << "  STATUS: ? WITHIN BUDGET" << endl;
            cout << "  You can afford this grocery run." << endl;
            cout << "  Leftover after groceries: E "
                 << (remaining - groceryTotal) << endl;
            break;

        case 1:
            cout << "  STATUS: ?  RISKY" << endl;
            cout << "  Groceries will use most of your remaining budget." << endl;
            cout << "  Consider removing a few items from the list." << endl;
            break;

        case 2:
            cout << "  STATUS: ? OVER BUDGET" << endl;
            cout << "  You cannot afford this grocery total this month." << endl;
            cout << "  You need to cut E " << (groceryTotal - remaining)
                 << " from the list." << endl;
            break;
    }
}

int findHighestExpense(const Budget &b) {
    if (b.expenseCount == 0) return -1;   

    int maxIndex = 0;   

    for (int i = 1; i < b.expenseCount; i++) {
        
        if (b.expenses[i].amount > b.expenses[maxIndex].amount) {
            maxIndex = i;
        }
    }

    return maxIndex;   
}

void giveAdvice(const Budget &b) {
    cout << "\n~~~ Advice System ~~~" << endl;

    // Find and name the biggest expense
    int highestIdx = findHighestExpense(b);
    if (highestIdx != -1) {
        cout << "  Your highest expense is: "
             << b.expenses[highestIdx].name
             << " (E " << fixed << setprecision(2)
             << b.expenses[highestIdx].amount << ")" << endl;

        double pct = (b.expenses[highestIdx].amount / b.totalIncome) * 100.0;
        cout << "  This is " << setprecision(1) << pct
             << "% of your monthly income." << endl;
    }

    cout << endl;

    if (b.remaining > b.totalIncome * 0.20) {
        cout << "  Great you have over 20% of income remaining!" << endl;
        cout << "  Suggestion: consider putting E "
             << fixed << setprecision(2) << (b.remaining * 0.50)
             << " into savings this month." << endl;

    } else if (b.remaining > 0) {
        cout << "  Budget is tight but manageable." << endl;

        // Give specific advice based on which expense is highest
        if (highestIdx != -1) {
            string topName = b.expenses[highestIdx].name;

            if (topName == "Rent") {
                cout << "  Rent is your biggest cost consider moving to" << endl;
                cout << "  a smaller place could save you money long-term" << endl;
            } else if (topName == "Transport") {
                cout << "  Transport is high look into carpooling or monthly bus passes" << endl;
            } else if (topName == "Electricity") {
                cout << "  Electricity is your top cost check for appliances left on" << endl;
                cout << "  standby and consider energy-saving bulbs" << endl;
            } else {
                // Generic advice for any other expense
                cout << "  Try to reduce \"" << topName << "\" by 10-15% next month" << endl;
            }
        }

    } else {
        cout << "  WARNING: You are spending more than you earn." << endl;
        cout << "  Deficit: E " << fixed << setprecision(2)
             << (b.remaining * -1) << " per month." << endl;   
        cout << endl;
        cout << "  Immediate steps:" << endl;
        cout << "  1. Review every expense above and find what can be cut." << endl;
        cout << "  2. Focus on your highest expense first (listed above)." << endl;
        cout << "  3. Set a strict daily spending limit until balanced." << endl;
    }

    cout << endl;
}
