#ifndef splitwise_hpp
#define splitwise_hpp

#include <iostream>
#include "expense.hpp"
#include <vector>
#include <unordered_map>
#include "expense_service.hpp"

using namespace std;

class SplitWise{
    private:
    vector<Expense*> expenses;
    unordered_map<string, User*> userMap;
    unordered_map<string, unordered_map<string, double> > balanceSheet;

    public:
    void addUser(User *user);
    void addExpense(ExpenseType expenseType, double amount, string paidBy, list<Split*> splits);
    void showBalance(string userId);
    void settleBalance(string userId1, string userId2);

    User* getUser(string userId);
    //void showBalances();

};

#endif
