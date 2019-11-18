// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <stdexcept>

template<class T>
struct StackValue
{
    T value;
    StackValue *prev = nullptr;
};


template <typename T>
class ParentStack
{
public:

    // возвращает указатель на последний элемент
    const T& head() const {
        if (!headStack) {
            throw std::runtime_error("Stack is nullptr");
        }

        return headStack->value;
    }
    // добавляет в конец
    void push(T&& value){
        //  чтобы не затухала rvalue ссысылс
        if(headStack== nullptr) {
            StackValue<T> *temp = new StackValue<T>{std::move(value), nullptr};
            headStack = temp;
        }
        else {
            StackValue<T> *temp = new StackValue<T>{std::move(value), headStack};
            headStack = temp;
        }

    }
    // убираем копирование для lvalue
    ParentStack &operator=(const ParentStack &stack) = delete;
    // убираем копирование для rvalue
    ParentStack &operator=(ParentStack &&stack) noexcept = default;

protected:
    StackValue<T> *headStack= nullptr;
};

#endif // INCLUDE_HEADER_HPP_
