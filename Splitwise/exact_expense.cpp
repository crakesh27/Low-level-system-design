#include "exact_expense.hpp"
#include "expense.hpp"
#include "split.hpp"
#include "exact_split.hpp"

ExactExpense::ExactExpense(User *paidBy, double amount, list<Split*> splits) : Expense(paidBy, amount, splits){
}

bool ExactExpense::validate(){
    for (Split *split : getSplits()) {
        if(!dynamic_cast<ExactSplit*>(split))
            return false;
    }

    double totalAmount = getAmount();
    double sumSplitAmount = 0;
    for (Split *split : getSplits()) {
        ExactSplit *exactSplit = dynamic_cast<ExactSplit*>(split);
        sumSplitAmount += exactSplit->getAmount();
    }

    if (totalAmount != sumSplitAmount) {
        return false;
    }

    return true;
}