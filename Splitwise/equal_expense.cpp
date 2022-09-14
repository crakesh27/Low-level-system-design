#include "equal_expense.hpp"
#include "expense.hpp"
#include "split.hpp"
#include "equal_split.hpp"

EqualExpense::EqualExpense(User *paidBy, double amount, list<Split*> splits) : Expense(paidBy, amount, splits){
}

bool EqualExpense::validate(){
    for (Split *split : getSplits()) {
        if(!dynamic_cast<EqualSplit*>(split))
            return false;
    }

    return true;
}