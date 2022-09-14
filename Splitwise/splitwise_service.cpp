#include "splitwise_service.hpp"
#include "expense_service.hpp"
#include <iostream>

using namespace std;

void SplitWise::addUser(User *user){
    userMap[user->getUserId()] = user;
};

void SplitWise::addExpense(ExpenseType expenseType, double amount, string paidBy, list<Split*> splits){
    Expense *expense = ExpenseService::createExpense(expenseType, amount, userMap[paidBy], splits);
    if(expense->validate())
        expenses.push_back(expense);
    else
        throw new exception();
   
    
    for (Split *split : expense->getSplits()) {
        string paidTo = split->getUser()->getUserId();
        if (balanceSheet[paidBy].find(paidTo)==balanceSheet[paidBy].end()) {
            balanceSheet[paidBy][paidTo] = 0.0;
        }
        
        balanceSheet[paidBy][paidTo] += split->getAmount();


        if (balanceSheet[paidTo].find(paidBy)==balanceSheet[paidTo].end()) {
            balanceSheet[paidTo][paidBy] = 0.0;
        }
        
        balanceSheet[paidTo][paidBy] -= split->getAmount();
    }
};

void SplitWise::showBalance(string userId){

    if(balanceSheet[userId].size() == 0){
        cout<<"No pending expenses for this user\n";
    }
    for(auto balance: balanceSheet[userId]){
        if(balance.second > 0)
            cout<<"User "<<balance.first<<" owes user "<<userId<<" amount "<<balance.second<<"\n";
        else
            cout<<"User "<<userId<<" owes user "<<balance.first<<" amount "<<-1*balance.second<<"\n";
    }
}

User* SplitWise::getUser(string userId){
    return userMap[userId];
}

void SplitWise::settleBalance(string userId1, string userId2){
    balanceSheet[userId1].erase(userId2);
    balanceSheet[userId2].erase(userId1);
}