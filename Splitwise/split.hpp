#ifndef split_hpp
#define split_hpp

#include <iostream>
#include <string>
#include "user.hpp"

using namespace std;

class Split{
    private:
    User *user;

    protected:
    double amount;

    public:
    Split(User *user);

    virtual ~Split();

    double getAmount();

    User* getUser();

    void setAmount(double amount);
};

#endif