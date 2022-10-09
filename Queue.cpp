#include "Queue.h"

template <typename T>
Queue <T>::Queue (void)
: arr(Array<T>(size)),
front(0),
rear(0),
size(arr.size_)
{

}

template <typename T>
void Queue <T>::enqueue (T element)
{
    if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1))){
                std::cout << "Queue full, dequeue elements";
            }
            else if (front == -1) {
                front = rear = 0;
                arr[rear] = element;
            }
            else if (rear = size - 1 && front != 0){
                rear = 0;
                arr[rear] = element;
            }
            else{
                rear++;
                arr[rear] = element;
            }
}

template <typename T>
T Queue <T>::dequeue(void)
{
    if(is_empty){
        throw Queue<T>::empty_exception("Queue Empty");
    }
    
    T temp = arr[0];
    
    for(size_t i = 0; i < this.size - 1; i++){
        arr[i] = arr[i + 1];
    }
    
    
    if (size == 0){
        is_empty = true;
    }
    
    return temp;
}

template <typename T>
bool Queue <T>::is_empty(void)
{
    if(this->cur_size_ == 0){
        return true;
    }
    return false;
}

template <typename T>
void Queue <T>::clear(void)
{
    arr.resize(0);
    size = 0;
    is_empty = 0;
}