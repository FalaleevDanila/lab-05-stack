// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>

#include "header.hpp"
#include "stack.h"
#include "stacknoncopy.h"



TEST(Stack,push_test_1)
{
    Stack<int> my_stack;
    for (size_t index = 1;index<=10;++index)
        my_stack.push(index);
    EXPECT_EQ(my_stack.head(),10);

}

TEST(Stack,push_test_2)
{
    Stack<int> my_stack;

    my_stack.push(std::move(1));
    my_stack.push(std::move(5));
    my_stack.push(std::move(10));

    EXPECT_EQ(my_stack.head(),10);

}


TEST(Stack,push_test_3)
{
    Stack<int> my_stack;

    my_stack.push(std::move(1));
    EXPECT_EQ(my_stack.head(),1);
    my_stack.push(std::move(5));
    EXPECT_EQ(my_stack.head(),5);
    my_stack.push(std::move(10));
    EXPECT_EQ(my_stack.head(),10);
}



TEST(Stack,push_test_4)
{
    Stack<int> my_stack;
    int one = 90;
    my_stack.push(one);
    EXPECT_EQ(my_stack.head(),90);
    my_stack.push(5);
    EXPECT_EQ(my_stack.head(),5);
    my_stack.push(10);
    EXPECT_EQ(my_stack.head(),10);
}

TEST(Stack,pop_test_1)
{
    Stack<int> my_stack;

    my_stack.push(std::move(1));
    my_stack.push(std::move(5));
    my_stack.pop();

    EXPECT_EQ(my_stack.head(),1);

}

TEST(Stack,Exeption)
{
    Stack<int> my_stack;
    EXPECT_THROW(my_stack.head(),std::runtime_error);
    EXPECT_THROW(my_stack.pop(),std::runtime_error);
    StackNotCopy<int> my_new_stack;
    EXPECT_THROW(my_new_stack.head(),std::runtime_error);
    EXPECT_THROW(my_new_stack.pop(),std::runtime_error);


}

TEST(StackNonCopy, test1)
{
    StackNotCopy<int> my_stack;

    my_stack.push(std::move(1));
    my_stack.push(5);

    my_stack.push_emplace(4);
    my_stack.push_emplace(3);

    EXPECT_EQ(my_stack.head(),3);
    EXPECT_EQ(my_stack.pop(),3);
}

TEST(StackNonCopy, test2){

    StackNotCopy<int> my_stack;

    my_stack.push(std::move(1));
    my_stack.push(5.);
    my_stack.push_emplace('f');
    my_stack.push_emplace(true);

    EXPECT_EQ(my_stack.head(),true);
    EXPECT_EQ(my_stack.pop(),true);
    EXPECT_EQ(my_stack.head(), 'f');

    EXPECT_EQ(my_stack.pop(),'f');
    EXPECT_EQ(my_stack.head(), 5.);

    EXPECT_EQ(my_stack.pop(),5.);
    EXPECT_EQ(my_stack.head(), 1);

    EXPECT_EQ(my_stack.pop(),1);


    EXPECT_THROW(my_stack.head(),std::runtime_error);
    EXPECT_THROW(my_stack.pop(),std::runtime_error);


}

TEST(StackNonCopy, test3){
    StackNotCopy<std::pair<std::string,int >> my_stack;
    std::pair<std::string,int > one;
    one.first = "key";
    one.second = true;
    my_stack.push_emplace(one);

    std::pair <std::string, int> second;
    second.first = "key";
    second.second = true;
    my_stack.push_emplace(second);
    EXPECT_EQ(my_stack.head(), second);
    EXPECT_EQ(my_stack.pop(), second);
    EXPECT_EQ(my_stack.head(), one);

}