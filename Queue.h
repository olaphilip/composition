#include "Array.h"
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Queue 
{
private:
    int front;
    int rear;
    size_t size;
    Array <T> arr;
    
public:
    Queue(void);
    void enqueue(T element);
    T dequeue();
    bool is_empty(void);
    void clear();
};