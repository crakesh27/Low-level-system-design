#ifndef expense_service_hpp
#define expense_service_hpp

#include <iostream>
#include "user.hpp"
#include "expense.hpp"
#include "split.hpp"
#include <list>

enum ExpenseType {
    EQUAL,
    EXACT,
    PERCETAGE,
};

class ExpenseService {
    public:
    static Expense* createExpense(ExpenseType expenseType, double amount, User *paidBy, list<Split*> splits);
};

#endif