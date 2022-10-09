#include "Basic_Array.h"
#include <stdexcept>         
#include <iostream>

template <typename T>
Basic_Array <T>::Basic_Array (void)
: cur_size_(0), 
max_size_(20), 
data_(new char[max_size_])
{
    
}

template <typename T>
Basic_Array <T>::Basic_Array (size_t length)
: cur_size_(0), 
max_size_(length), 
data_(new char[length])
{

}

template <typename T>
Basic_Array <T>::Basic_Array (size_t length, T fill)
: cur_size_(length), 
max_size_(length), 
data_(new char[length])
{
    for (int i = 0; i < length; i++){
        data_[i] = fill;
    }
}

template <typename T>
Basic_Array <T>::Basic_Array (const Basic_Array & array)
: cur_size_(array.cur_size_), 
max_size_(array.max_size_)
{
    for (int j = 0; j < cur_size_; j++){
        data_ = new char[cur_size_];
        data_[j] = array.data_[j];
    }
}

template <typename T>
Basic_Array <T>::~Basic_Array (void)
{
    delete [] data_;
}

template <typename T>
const Basic_Array <T> & Basic_Array <T>::operator = (const Basic_Array & rhs)
{
}

template <typename T>
T & Basic_Array <T>::operator [] (size_t index)
{
    if (index > cur_size_){
        throw std::out_of_range("Index out of range");
    }
    else {
        return data_[index];
    }
}

template <typename T>
const T & Basic_Array <T>::operator [] (size_t index) const
{
    if (index > cur_size_){
        throw std::out_of_range("Index out of range");
    }
    else {
        return data_[index];
    }
}

template <typename T>
T Basic_Array <T>::get (size_t index) const
{
    if (index > cur_size_){
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}

template <typename T>
void Basic_Array <T>::set (size_t index, T value)
{
    if(index < max_size_ && index > 0){
        data_[index] = value;
        cur_size_++;
    }
}

template  <typename T>
int Basic_Array <T>::find (T value) const
{
    for (int i = 0; i < cur_size_; i++){
        if (value == data_[i]){
            return i;
        }
    }
    return 0;
}

template <typename T>
int Basic_Array <T>::find (T val, size_t start) const
{
    for (int i = start; i < cur_size_; i ++){
        if (val == data_[i]){
            return i;
        }
    }
    return 0;
}

template <typename T>
bool Basic_Array <T>::operator == (const Basic_Array & rhs) const
{
    if(this != &rhs){
        if (cur_size_ == rhs.cur_size_){
            for (int i = 0; i < cur_size_; i++){
                if (data_[i] != rhs.data_[i]){
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}

template <typename T>
bool Basic_Array <T>::operator != (const Basic_Array & rhs) const
{
    return !(*this == rhs);
}

template <typename T>
void Basic_Array <T>::fill (T value)
{
    for (int i = 0; i < max_size_; i++){
        data_[i] = value;
    }
}
