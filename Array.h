#include "iostream"
#ifndef AADT_LAB1_ARRAY_H
#define AADT_LAB1_ARRAY_H


template<typename T>
class Array{
    T *array;
    int size = 0;
    int capacity = 0;

public:
    Array();
    Array(int inputsize);
    ~Array();
    void rezize(int newSize);
    void pushBack(T Value);
    void pushFront(T value);
    void print();
    void insert(int index, T Value);
    bool isEmpty();
    void pop(int index);
    T *getAt(int index);
    void swap(int index1, int index2);
    int getSize();
    int getCapacity();

};

template<typename T>
int Array<T>::getCapacity() {
    return capacity;
}


template<typename T>
int Array<T>::getSize() {
    return size;
}


template<typename T>
Array<T>::Array(): size(0), capacity(5){
    array = new T[capacity];
}


template<typename T>
Array<T>::Array(int inputsize) {
    if ( inputsize < 0 ){
        inputsize = 5;
    }
    capacity = inputsize;
    array = new T[capacity];
}


template<typename T>
Array<T>::~Array() {
    delete []array;
}


template<typename T>
void Array<T>::rezize(int newSize) {
    if ( newSize < 0 ) return;
    T *newArray = new T[newSize];
    if ( newSize < size ){
        size = newSize;
        for ( int i = 0; i < newSize; i++ ){
            newArray[i] = array[i];
        }
    }else{
        for ( int i = 0; i < size; i++ ){
            newArray[i] = array[i];
        }
    }
    capacity = newSize;
    delete []array;
    array = newArray;
}


template<typename T>
void Array<T>::pushBack(T value) {
    if ( size + 1 >= capacity ){
        capacity *= 2;
        T *newArray = new T[capacity];
        for ( int i = 0; i < size; i++ ){
            newArray[i] = array[i];
        }

        newArray[size] = value;
        delete []array;
        array = newArray;
    }else{
        *(array + size) = value;
    }
    size ++;

}


template<typename T>
void Array<T>::pushFront(T value) {
    if ( size + 1 >= capacity ){
        capacity *= 2;
        T *newArray = new T[capacity];
        newArray[0] = value;
        for ( int i = 0; i < size; i++ ){
            newArray[i + 1] = array[i];
        }
        size ++;

        delete []array;
        array = newArray;
    }else{
        *(array + size) = value;
    }
}


template<typename T>
void Array<T>::print() {
    if ( size == 0 )  {
        std::cout << "[]";
        return;
    }
    std::cout << "[" << *(array);
    for ( int i = 1; i < size; i++ ){
        std::cout << ", " << array[i];
    }
    std::cout << "]";
}


template<typename T>
void Array<T>::insert(int index, T value) {
    if ( size + 1 >= capacity ){
        capacity *= 2;
        T *newArray = new T[capacity];
        for ( int i = 0; i < size; i++ ){
            newArray[i] = array[i];
        }

        delete []array;
        array = newArray;
    }

    for ( int i = size - 1; i >= index; i-- ){
        array[i + 1] = array[i];
    }
    array[index] = value;
    size++;
}


template<typename T>
bool Array<T>::isEmpty() {
    if ( size == 0 ){
        return true;
    }
    return false;
}


template<typename T>
void Array<T>::pop(int index) {
    for (int i = index + 1; i < size; i ++){
        array[i - 1] = array[i];
    }
    size--;
}


template<typename T>
T *Array<T>::getAt(int index) {
    if ( index >= 0 && index < size ){
        return array + index;
    }
    return nullptr;
}


template<typename T>
void Array<T>::swap(int index1, int index2) {
    if ( index1 >= 0 && index2 >= 0 && index1 < size && index2 < size ){
        std::swap(*(array + index1), *(array + index2));
        return;
    }
    std::cout << "Invalid input";
}




#endif //AADT_LAB1_ARRAY_H
