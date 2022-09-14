#include "user.hpp"


User::User(string userId, string name, string mobileNum){
    this->userId = userId;
    this->name = name;
    this->mobileNum = mobileNum;

}

string User::getUserId(){
    return this->userId;
}

string User::getName(){
    return this->name;
}

string User::getMobileNum(){
    return this->mobileNum;
}