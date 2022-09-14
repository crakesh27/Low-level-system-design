#include "split.hpp"
#include "user.hpp"

Split::Split(User *user){
    this->user  = user;
}

Split::~Split(){};

double Split::getAmount(){
    return this->amount;
}

User* Split::getUser(){
    return this->user;
}

void Split::setAmount(double amount){
    this->amount = amount;
}