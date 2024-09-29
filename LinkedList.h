#include "iostream"
#ifndef AADT_LAB1_LINKEDLIST_H
#define AADT_LAB1_LINKEDLIST_H

template <typename T>
class Node {
public:
    T data;
    Node* prev, *next;
    explicit Node(T inputData);
};

template<typename T>
Node<T>::Node(T inputData):data(inputData) {}


template <typename T>
class LinkedList {
    int length;
    Node<T> *head = nullptr, *tail = nullptr;

public:
    LinkedList(int length = 0);
    int len();
    void print();
    void insert(int index, T value);
    void append(T value);
    void pop(int index);
    int getIndex(T value);
    void swap(int index1, int index2);

};


template <typename T>
LinkedList<T>::LinkedList(int length): length(length) {}


template<typename T>
void LinkedList<T>::insert(int index, T value) {
    Node<T> *cur = this->head;
    for ( int i = 0; i < index; i++ ){
        cur = cur->next;
    }

}


template<typename T>
int LinkedList<T>::len() {
    return this->length;
}


template<typename T>
void LinkedList<T>::append(T value) {
    this->tail->next = new Node<T>(value);
    this->tail = this->tail->next;
}


template<typename T>
void LinkedList<T>::pop(int index){
    Node<T> *cur = this->head;
    for ( int i = 0; i < index; i++ ){
        cur = cur->next;
    }
    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    delete cur;
}


template<typename T>
int LinkedList<T>::getIndex(T value) {
    Node<T> *cur = this->head;
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

    Node<T> *cur = this->head;
    Node<T> *el1, *el2;
    for (int i = 0; i < std::max(index1, index2); i++) {
        if (i == std::min(index1, index2)) {
            el1 = cur;
        }
        cur = cur->tail;
    }
    el2 = cur;

    if ( el1 == this->head ){
        this->head = el2;
    }

    if ( el2 == this->tail ){
        this->tail = el1;
    }
    if ( el1->head ){
        el1->head->tail = el2;
    }
    if ( el2->tail){
        el2->tail->head = el1;
    }
    swap(el1->head, el2->head);
    swap(el1->tail, el1->head);
    swap(el2->tail, el1->tail);
}

template<typename T>
void LinkedList<T>::print() {
    Node<T> *cur = this->head;
    std::cout << cur->data;
    cur = cur->next;
    while ( cur ){
        std::cout << ", " << cur->data;
        cur = cur->next;
    }
}






#endif //AADT_LAB1_LINKEDLIST_H
