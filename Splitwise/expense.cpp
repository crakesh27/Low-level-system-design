#include "expense.hpp"

Expense::Expense(User *paidBy, double amount, list<Split*> splits){
    this->paidBy = paidBy;
    this->amount = amount;
    this->splits = splits;
    this->isSettled = false;
}

list<Split*> Expense::getSplits(){
    return this->splits;
}

double Expense::getAmount(){
    return this->amount;
}