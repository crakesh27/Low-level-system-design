#include "exact_split.hpp"
#include "split.hpp"

ExactSplit::ExactSplit(User *user, double amount) : Split(user){
    this->amount = amount;
}
