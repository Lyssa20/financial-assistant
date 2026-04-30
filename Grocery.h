#ifndef GROCERY_H
#define GROCERY_H

#include <string>

struct GroceryItem {
    std::string name;
    double price;
};

struct GroceryList {
    GroceryItem items[50]; // 50 items should be more than enough
    int itemCount;
    double totalCost;
};

void initGroceryList(GroceryList &g);
void inputGroceryItems(GroceryList &g);
void inputGroceryPrices(GroceryList &g);
void calculateGroceryTotal(GroceryList &g);
void displayGroceryList(const GroceryList &g);

#endif
