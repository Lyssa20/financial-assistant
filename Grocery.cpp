#include "grocery.h"
#include <iostream>
#include <iomanip>
#include <limits>    //clears bad input)

using namespace std;

void initGroceryList(GroceryList &g) {
    g.itemCount = 0;
    g.totalCost = 0.0;

    for (int i = 0; i < 50; i++) {
        g.items[i].name  = "";
        g.items[i].price = 0.0;
    }
}

void inputGroceryItems(GroceryList &g) {
    cout << "\n~~ Grocery List: please add your items ~~" << endl;
    cout << "Type each item and press Enter, Type 'done' when your done\n" << endl;

    string itemName;
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (g.itemCount < 50) {   // stay within array bounds
        cout << "  Item " << (g.itemCount + 1) << ": ";
        getline(cin, itemName);  

        if (itemName == "done" || itemName == "Done") break;

        // Don't store blank entries
        if (itemName.empty()) continue;

        g.items[g.itemCount].name  = itemName;
        g.items[g.itemCount].price = 0.0;
        g.itemCount++;
    }

    cout << "\n" << g.itemCount << " items added to your list." << endl;
}

void inputGroceryPrices(GroceryList &g) {
    cout << "\n~~~ Grocery List: please enter Prices ~~~" << endl;
    cout << "Enter the price for each item (type 0 if you didn't buy it).\n" << endl;

    for (int i = 0; i < g.itemCount; i++) {
        cout << "  Price for \"" << g.items[i].name << "\": E ";
        cin  >> g.items[i].price;

        // Input validation: reject negative prices (user typo)
        if (g.items[i].price < 0) {
            cout << "  (Price can't be negative, Setting to 0.)" << endl;
            g.items[i].price = 0.0;
        }
    }
}

void calculateGroceryTotal(GroceryList &g) {
    g.totalCost = 0.0;
    for (int i = 0; i < g.itemCount; i++) {
        g.totalCost += g.items[i].price;
    }
}

void displayGroceryList(const GroceryList &g) {
    cout << "\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "           GROCERY LIST                 " << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    for (int i = 0; i < g.itemCount; i++) {
        // Only show items that were actually bought
        if (g.items[i].price > 0) {
            cout << "  " << left << setw(25) << g.items[i].name
                 << "E " << fixed << setprecision(2) << g.items[i].price << endl;
        }
    }

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << left << setw(25) << "  TOTAL"
         << "E " << fixed << setprecision(2) << g.totalCost << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}
