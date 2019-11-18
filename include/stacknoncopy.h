//
// Created by danf2 on 08.11.2019.
//

#ifndef LAB_05_STACK_STACKNONCOPY_H
#define LAB_05_STACK_STACKNONCOPY_H

#include "header.hpp"

template <typename T>
class StackNotCopy: public ParentStack <T>
{
public:
    //
    template <typename ... Args>
    void push_emplace(Args&&... value){

        StackValue<T> *prevNode = this->headStack;

        StackValue<T>* temp = new StackValue<T>{std::forward<Args>(value)..., prevNode};
        this->headStack = temp;
    }


    T pop()
    {
        if (!this->headStack) {
            throw std::runtime_error("Stack is nullptr");
        }

        auto *prevNode = this->headStack;
        this->headStack = this->headStack->prev;

        T value = std::move(prevNode->value);

        delete prevNode;

        return value; //

    }
};

#endif //LAB_05_STACK_STACKNONCOPY_H
