#ifndef equal_split_hpp
#define equal_split_hpp

#include <iostream>
#include <string>
#include "user.hpp"
#include "split.hpp"

using namespace std;

class EqualSplit : public Split{

    public:
    EqualSplit(User *user);

};

#endif