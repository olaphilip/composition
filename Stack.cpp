// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Stack.h"
#include <iostream>
#include <stdexcept>

//
// Stack
//
template <typename T>
Stack <T>::Stack (void)
: arr(Array<T>(size_)),
top_(-1),
size_(0)
{

}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack)
:arr(stack.arr),
top_(stack.top_),
size_(stack.size_)
{
    for(int i = 0; i < size_; i++){
        arr[i] = stack.arr[i];
    }
}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{

}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
    if(size_ == arr.max_size_()){
        arr.resize(arr.max_size_() * 2);
    }
    arr.set(size_, element);
    size_ = size_ + 1;
    top_ = element;
    if(arr = nullptr){
        throw empty_exception("Stack Empty!!!");
    }
}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
    if(arr = nullptr){
        throw empty_exception("Stack Empty!!!");
    }
    size_ = size_ - 1;
    
    if (size_ == 0){
        top_ = nullptr;
    }
    else{
        top_ = arr[size_];
    }
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
    if (this != &rhs){
        top_ = rhs.top_();
        arr = Array <T> (rhs.arr.max_size_());
        size_ = rhs.size_();
        
        for (size_t i = 0; i < size_; i++){
            arr[i] = rhs.arr.data_[i];
        }
    }
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
    top_ = 0;
    size_ = 0;
    arr = Array<T>(size_);
}
