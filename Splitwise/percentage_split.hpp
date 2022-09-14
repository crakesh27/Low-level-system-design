#ifndef percent_split_hpp
#define percent_split_hpp

#include <iostream>
#include <string>
#include "user.hpp"
#include "split.hpp"

using namespace std;

class PercentSplit : public Split{
    private:
    int percentage;
    
    public:
    PercentSplit(User *user, int percentage);

    int getPercentage();

};

#endif