#include "iostream"
#ifndef AADT_LAB1_LINKEDLIST_H
#define AADT_LAB1_LINKEDLIST_H

template <typename T>
class listNode {
public:
    T data;
    listNode* prev, *next;
    explicit listNode(T inputData);
};

template<typename T>
listNode<T>::listNode(T inputData):data(inputData) {}


template <typename T>
class LinkedList {
    int length;
    listNode<T> *head = nullptr, *tail = nullptr;

public:
    LinkedList(int length = 0);
    int len();
    void print();
    void insert(int index, T value);
    void append(T value);
    void pop(int index);
    int getIndex(T value);
    listNode<T> *getAt(int index);
    void swap(int index1, int index2);

};

template<typename T>
listNode<T> *LinkedList<T>::getAt(int index) {
    listNode<T> *cur = head;
    if ( index < 0 || index >= length ){
        return nullptr;
    }
    for ( int i = 0; i < index; i++ ){
        cur = cur->next;
    }
    return cur;
}


template <typename T>
LinkedList<T>::LinkedList(int length): length(length) {}


template<typename T>
void LinkedList<T>::insert(int index, T value) {
    listNode<T> *newNode = new listNode(value);

    if ( index == 0 ){
        newNode->next = head;
        head->prev = newNode;
        head = newNode;

    }else if ( index == length ){
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;

    }else {
        listNode<T> *cur = getAt(index);
        newNode->prev = cur->prev;
        newNode->next = cur;
        cur->prev->next = newNode;
        cur->prev = newNode;
    }
}


template<typename T>
int LinkedList<T>::len() {
    return this->length;
}


template<typename T>
void LinkedList<T>::append(T value) {
    this->tail->next = new listNode<T>(value);
    this->tail = this->tail->next;
}


template<typename T>
void LinkedList<T>::pop(int index){
    listNode<T> *cur = this->head;
    for ( int i = 0; i < index; i++ ){
        cur = cur->next;
    }
    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    delete cur;
}


template<typename T>
int LinkedList<T>::getIndex(T value) {
    listNode<T> *cur = this->head;
    int counter = -1;
    while ( cur ){
        counter++;
        if ( cur->data == value ){
            break;
        }
    }
    return counter;
}


template<typename T>
void LinkedList<T>::swap(int index1, int index2) {
    if (index1 == index2 || index1 < 0 || index1 > this->length - 1 || index2 < 0 || index2 > this->length - 1) {
        return;
    }

    listNode<T> *cur = this->head;
    listNode<T> *el1, *el2;
    for (int i = 0; i < std::max(index1, index2); i++) {
        if (i == std::min(index1, index2)) {
            el1 = cur;
        }
        cur = cur->next;
    }
    el2 = cur;

    if ( el1 == this->head ){
        this->head = el2;
    }

    if ( el2 == this->tail ){
        this->tail = el1;
    }
    if ( el1->prev ){
        el1->prev->next = el2;
    }
    if ( el2->next){
        el2->next->prev = el1;
    }
    std::swap(el1->prev, el2->prev);
    std::swap(el1->next, el1->prev);
    std::swap(el2->next, el1->next);
}


template<typename T>
void LinkedList<T>::print() {
    listNode<T> *cur = this->head;
    std::cout << cur->data;
    cur = cur->next;
    while ( cur ){
        std::cout << ", " << cur->data;
        cur = cur->next;
    }
}






#endif //AADT_LAB1_LINKEDLIST_H
