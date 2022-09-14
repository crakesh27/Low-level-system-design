#ifndef percentage_expense_hpp
#define percentage_expense_hpp

#include <iostream>
#include <string>
#include <list>
#include "user.hpp"
#include "split.hpp"
#include "expense.hpp"

using namespace std;

class PercentageExpense : public Expense{

    public:
    PercentageExpense(User *paidBy, double amount, list<Split*> splits);

    bool validate();

};

#endif