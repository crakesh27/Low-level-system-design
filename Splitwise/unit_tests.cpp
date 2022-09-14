#include <iostream>
#include "splitwise_service.hpp"
#include "user.hpp"
#include <gtest/gtest.h>
#include "expense_service.hpp"
#include "equal_split.hpp"
#include "exact_split.hpp"
#include "percentage_split.hpp"
#include "equal_expense.hpp"
#include "exact_expense.hpp"
#include "percentage_expense.hpp"
#include "expense.hpp"

using namespace std;

struct ExpenseTest : public ::testing::Test{
    public:

    User *user1 = new User("user1", "user1", "123");
    User *user2 = new User("user1", "user1", "123");
    User *user3 = new User("user1", "user1", "123");
    User *user4 = new User("user1", "user1", "123");

    void SetUp() {
        cout<<"Alive";
       
    }
    void TearDown() {
        cout<<"Dead";
 
    }
};

TEST_F(ExpenseTest, ValidEqualExpense){

    list<Split*> splits;
    splits.push_back(new EqualSplit(user2));
    splits.push_back(new EqualSplit(user3));
    splits.push_back(new EqualSplit(user4));
    
    Expense *expense = new EqualExpense(user1, 100, splits);

    ASSERT_TRUE(expense->validate());
}

TEST_F(ExpenseTest, InValidEqualExpense){

    list<Split*> splits;
    splits.push_back(new EqualSplit(user2));
    splits.push_back(new ExactSplit(user3, 12.0));
    splits.push_back(new PercentSplit(user4, 20));
    
    Expense *expense = new EqualExpense(user1, 100, splits);

    ASSERT_FALSE(expense->validate());
}

TEST_F(ExpenseTest, ValidExactExpense){

    list<Split*> splits;
    splits.push_back(new ExactSplit(user2, 20.0));
    splits.push_back(new ExactSplit(user3, 50.5));
    splits.push_back(new ExactSplit(user4, 29.5));
    
    Expense *expense = new ExactExpense(user1, 100, splits);

    ASSERT_TRUE(expense->validate());
}

TEST_F(ExpenseTest, InValidExactExpense){

    list<Split*> splits;
    splits.push_back(new ExactSplit(user2, 12.0));
    splits.push_back(new ExactSplit(user3, 13.0));
    splits.push_back(new ExactSplit(user4, 12.0));
    
    Expense *expense = new ExactExpense(user1, 100, splits);

    ASSERT_FALSE(expense->validate());
}

TEST_F(ExpenseTest, ValidPercentExpense){

    list<Split*> splits;
    splits.push_back(new PercentSplit(user2, 20));
    splits.push_back(new PercentSplit(user3, 60));
    splits.push_back(new PercentSplit(user4, 20));
    
    Expense *expense = new PercentageExpense(user1, 100, splits);

    ASSERT_TRUE(expense->validate());
}

TEST_F(ExpenseTest, InValidPercentExpense){

    list<Split*> splits;
    splits.push_back(new PercentSplit(user2, 20));
    splits.push_back(new PercentSplit(user3, 20));
    splits.push_back(new PercentSplit(user4, 20));
    
    Expense *expense = new PercentageExpense(user1, 100, splits);

    ASSERT_FALSE(expense->validate());
}