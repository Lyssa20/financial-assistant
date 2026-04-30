#include "grocery.h"
#include <iostream>
#include <iomanip>
#include <limits>

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
    cout << "\n~~~ Grocery List ~~~" << endl;
    cout << "Add your items one by one. Type 'done' when your finished.\n" << endl;

    string itemName;

    // remove leftover newline from previous cin >> so getline works properly
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (g.itemCount < 50) {
        cout << "  Item " << (g.itemCount + 1) << ": ";
        getline(cin, itemName);

        if (itemName == "done" || itemName == "Done") break;
        if (itemName.empty()) continue; // skip blanks

        g.items[g.itemCount].name  = itemName;
        g.items[g.itemCount].price = 0.0; // price comes later
        g.itemCount++;
    }

    cout << "\n" << g.itemCount << " items on your list." << endl;
}

void inputGroceryPrices(GroceryList &g) {
    cout << "\n~~~ Enter Prices ~~~" << endl;
    cout << "Enter the price for each item. Put 0 if you didn't get it.\n" << endl;

    for (int i = 0; i < g.itemCount; i++) {
        cout << "  " << g.items[i].name << ": E ";
        cin  >> g.items[i].price;

        if (g.items[i].price < 0) {
            cout << "  (Can't be negative so setting to 0)" << endl;
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
    cout << "            GROCERY LIST                " << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    for (int i = 0; i < g.itemCount; i++) {
        if (g.items[i].price > 0) {
            cout << "  " << left << setw(25) << g.items[i].name
                 << "E " << fixed << setprecision(2) << g.items[i].price << endl;
        }
    }

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "  " << left << setw(25) << "TOTAL"
         << "E " << fixed << setprecision(2) << g.totalCost << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}
