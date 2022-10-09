// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include <stdexcept>         // for std::out_of_bounds exception
#include <iostream>

//
// Array
//
template <typename T>
Array <T>::Array (void)
: cur_size_(0), 
max_size_(20), 
data_(new char[max_size_])
{
    
}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length)
: cur_size_(0), 
max_size_(length), 
data_(new char[length])
{

}

//
// Array (size_t, char)
//
template <typename T>
Array <T>::Array (size_t length, T fill)
: cur_size_(length), 
max_size_(length), 
data_(new char[length])
{
    for (int i = 0; i < length; i++){
        data_[i] = fill;
    }
}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & array)
: cur_size_(array.cur_size_), 
max_size_(array.max_size_)
{
    for (int j = 0; j < cur_size_; j++){
        data_ = new char[cur_size_];
        data_[j] = array.data_[j];
    }
}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{
    delete [] data_;
}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
    if(*this == this){
        return *this;
    }
    if (rhs.max_size_ > max_size_){
        max_size_ = rhs.max_size_;
        cur_size_ = rhs.cur_size_;
        
        for (int i = 0; i < cur_size_; i++){
            data_[i] = rhs.data_[i];
        }
    }
    return *this;
}

//
// operator []
//
template <typename T>
T & Array <T>::operator [] (size_t index)
{
    if (index > cur_size_){
        throw std::out_of_range("Index out of range");
    }
    else {
        return data_[index];
    }
}

//
// operator [] 
//
template <typename T>
const T & Array <T>::operator [] (size_t index) const
{
    if (index > cur_size_){
        throw std::out_of_range("Index out of range");
    }
    else {
        return data_[index];
    }
}

//
// get
//
template <typename T>
T Array <T>::get (size_t index) const
{
    if (index > cur_size_){
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}

//
// set
//
template <typename T>
void Array <T>::set (size_t index, T value)
{
    if(index < max_size_ && index > 0){
        data_[index] = value;
        cur_size_++;
    }
}

//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
    if (new_size > cur_size_){
        char *temp_data_ = new char[new_size];
        for (int i = 0; i < cur_size_; i++){
            temp_data_[i] = data_[i];
        }
        max_size_ = new_size;
        cur_size_ = new_size;
        delete[] data_;
        data_ = temp_data_;
    }
    else if (cur_size_ < new_size){
        char *temp_data_2 = new char[new_size];
        for (int i = 0; i < cur_size_; i++){
            temp_data_2[i] = data_[i];
        }
        max_size_ = new_size;
        cur_size_ = new_size;
        delete[] data_;
        data_ = temp_data_2;
    }
}

//
// find (char)
//
template  <typename T>
int Array <T>::find (T value) const
{
    for (int i = 0; i < cur_size_; i++){
        if (value == data_[i]){
            return i;
        }
    }
    return 0;
}

//
// find (char, size_t) 
//
template <typename T>
int Array <T>::find (T val, size_t start) const
{
    for (int i = start; i < cur_size_; i ++){
        if (val == data_[i]){
            return i;
        }
    }
    return 0;
}

//
// operator ==
//
template <typename T>
bool Array <T>::operator == (const Array & rhs) const
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

//
// operator !=
//
template <typename T>
bool Array <T>::operator != (const Array & rhs) const
{
    return !(*this == rhs);
}

//
// fill
//
template <typename T>
void Array <T>::fill (T value)
{
    for (int i = 0; i < max_size_; i++){
        data_[i] = value;
    }
}
