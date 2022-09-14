#include "percentage_split.hpp"
#include "split.hpp"

PercentSplit::PercentSplit(User *user, int percentage) : Split(user){
    this->percentage = percentage;
}

int PercentSplit::getPercentage(){
    return percentage;
}