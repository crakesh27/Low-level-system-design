#ifndef expense_hpp
#define expense_hpp

#include <iostream>
#include <string>
#include <list>
#include "user.hpp"
#include "split.hpp"

using namespace std;

class Expense{
    private:
    User *paidBy;
    double amount;
    bool isSettled;

    protected:
    list<Split*> splits;

    public:
    Expense(User *paidBy, double amount, list<Split*> splits);

    list<Split*> getSplits();

    double getAmount();
    
    virtual bool validate() = 0;

};

#endif