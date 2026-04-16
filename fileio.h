#ifndef FILEIO_H
#define FILEIO_H
#include "budget.h"
#include "grocery.h"
#include <string>

// Saves the full session (budget + grocery + advice) to a txt file
void saveReport(const Budget &b, const GroceryList &g,
                int decision, const std::string &filename);

#endif
