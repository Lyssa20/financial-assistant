#ifndef FILEIO_H
#define FILEIO_H
#include "budget.h"
#include "grocery.h"
#include <string>

void saveReport(const Budget &b, const GroceryList &g,
                int decision, const std::string &filename);

#endif
