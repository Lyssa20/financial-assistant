#ifndef ADVICE_H
#define ADVICE_H
#include "budget.h"    
#include "grocery.h"   

int analyzeGroceryVsBudget(double groceryTotal, double remaining);

void displayDecision(int decision, double groceryTotal, double remaining);

int findHighestExpense(const Budget &b);

void giveAdvice(const Budget &b);

#endif
