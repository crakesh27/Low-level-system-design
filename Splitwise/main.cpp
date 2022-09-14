#include <iostream>
#include "splitwise_service.hpp"
#include "user.hpp"
#include <gtest/gtest.h>
#include "expense_service.hpp"
#include "equal_split.hpp"
#include "exact_split.hpp"
#include "percentage_split.hpp"

using namespace std;


int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);

    // return RUN_ALL_TESTS();

    SplitWise *splitWise = new SplitWise();
    splitWise->addUser(new User("user1", "user1", "123"));
    splitWise->addUser(new User("user2", "user2", "123"));
    splitWise->addUser(new User("user3", "user3", "123"));
    splitWise->addUser(new User("user4", "user4", "123"));

    while(true){
        int command;
        cout<<"1 - SHOW, 2 - ADD EXPENSE, 3 - SETTLE, 4 - EXIT\n";

        cin>>command;
        cout<<command<<endl;

        string userId;
        string paidBy;
        int userNum, userPercentage;
        int expenseType;
        double amount, userAmount;
        list<Split*> splits;

        switch(command){
            case 1:
                cin>>userId;
                splitWise->showBalance(userId);
                break;
            case 2:
                cin>>paidBy;
                cin>>amount;
                cin>>userNum;
                cin>>expenseType;
                switch (expenseType) {
                    case EQUAL:
                        for (int i = 0; i < userNum; i++) {
                            cin>>userId;
                            splits.push_back(new EqualSplit(splitWise->getUser(userId)));
                        }
                        splitWise->addExpense(EQUAL, amount, paidBy, splits);
                        break;
                    case EXACT:
                        for (int i = 0; i < userNum; i++) {
                            cin>>userId;
                            cin>>userAmount;
                            splits.push_back(new ExactSplit(splitWise->getUser(userId), userAmount));
                        }
                        splitWise->addExpense(EXACT, amount, paidBy, splits);
                        break;
                    case PERCETAGE:
                        for (int i = 0; i < userNum; i++) {
                            cin>>userId;
                            cin>>userPercentage;
                            splits.push_back(new PercentSplit(splitWise->getUser(userId), userPercentage));
                        }
                        splitWise->addExpense(EXACT, amount, paidBy, splits);
                        break;
                }

                break;
            case 3:
            {
                string userId1, userId2;
                cin>>userId1>>userId2;
                splitWise->settleBalance(userId1, userId2);
                break;
            }
            case 4:
                return 0;
                break;
            default:
                cout<<"Please enter the valid command\n";
                break;
        };
    }

    return 0;
}