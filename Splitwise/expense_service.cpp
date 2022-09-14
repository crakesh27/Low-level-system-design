#include "expense_service.hpp"
#include "equal_expense.hpp"
#include "percentage_expense.hpp"
#include "exact_expense.hpp"
#include "percentage_split.hpp"
#include "exact_split.hpp"
#include <cmath>

Expense* ExpenseService::createExpense(ExpenseType expenseType, double amount, User *paidBy, list<Split*> splits) {
    switch (expenseType) {
        case EXACT:{
            return new ExactExpense(paidBy, amount, splits);
            break;
        }
        case PERCETAGE:{
            for (Split *split : splits) {
                PercentSplit *percentSplit = static_cast<PercentSplit*>(split);
                split->setAmount((amount*percentSplit->getPercentage())/100.0);
            }
            return new PercentageExpense(paidBy, amount, splits);
            break;
        }
        case EQUAL:
        {
            int totalSplits = splits.size();
            double splitAmount = floor(amount*100.0/totalSplits)/100.0;
             for (Split *split : splits) {
                split->setAmount(splitAmount);
            }
            splits.front()->setAmount(splitAmount + (amount - splitAmount*totalSplits));
            return new EqualExpense(paidBy, amount, splits);
            break;
        }
    }
}
