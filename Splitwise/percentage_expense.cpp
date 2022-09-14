#include "percentage_expense.hpp"
#include "expense.hpp"
#include "split.hpp"
#include "percentage_split.hpp"

PercentageExpense::PercentageExpense(User *paidBy, double amount, list<Split*> splits) : Expense(paidBy, amount, splits){
}

bool PercentageExpense::validate(){
    for (Split *split : getSplits()) {
        if(!dynamic_cast<PercentSplit*>(split))
            return false;
    }

    int totalPercent = 100;
    int sumSplitPercent = 0;
    for (Split *split : getSplits()) {
        PercentSplit *percentSplit = dynamic_cast<PercentSplit*>(split);
        sumSplitPercent += percentSplit->getPercentage();
    }

    if (totalPercent != sumSplitPercent) {
        return false;
    }

    return true;
}