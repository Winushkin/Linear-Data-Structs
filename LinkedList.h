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
    listNode<T> *cur;
    if ( index < 0 || index >= length ){
        return nullptr;
    }

    if ( index < length / 2 ){
        cur = head;
        for ( int i = 0; i < index; i++ ){
            cur = cur->next;
        }
    }else{
        cur = tail;
        for ( int i = length - 1; i > index ; i-- ){
            cur = cur->prev;
        }
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
    listNode<T> *newNode = new listNode<T>(value);
    if ( length == 0 ){
        tail = newNode;
        head = newNode;
    }else{
        this->tail->next = newNode;
        newNode->prev = tail;
        this->tail = this->tail->next;
    }
    length++;
}


template<typename T>
void LinkedList<T>::pop(int index){

    if ( index > 0 && index < length ){
        listNode<T> *cur = this->head;
        for ( int i = 0; i < index; i++ ){
            cur = cur->next;
        }

        if ( !cur->prev ){
            cur->next->prev = nullptr;
            head = cur->next;
        } else if ( !cur->next ){
            cur->prev->next = nullptr;
            tail = cur->prev;
        }else{
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
        }
        delete cur;
    } else {
        std::cout << "Invalid index";
    }


}


template<typename T>
int LinkedList<T>::getIndex(T value) {
    bool flag = false;
    listNode<T> *cur = this->head;
    int counter = -1;
    while ( cur ){
        counter++;
        if ( cur->data == value ){
            flag = true;
            break;
        }
        cur = cur->next;
    }
    if ( flag ){
        return counter;
    }
    return -1;
}


template<typename T>
void LinkedList<T>::swap(int index1, int index2) {
    listNode<T>* ptr1 = getAt(index1);
    listNode<T>* ptr2 = getAt(index2);
    listNode<T>* left1 = getAt(index1-1);
    listNode<T>* left2 = getAt(index2-1);
    listNode<T>* right1 = getAt(index1+1);
    listNode<T>* right2 = getAt(index2+1);

    if (ptr1 == nullptr) return;
    else if (ptr2 == nullptr) return;
    else if (index1 == index2) return;

    if (left1 != nullptr) {
        left1->next = ptr2;
    } else {
        head = ptr2;
    }

    if (left2 != nullptr) {
        left2->next = ptr1;
    } else {
        head = ptr1;
    }

    if (right1 != nullptr) {
        right1->prev = ptr2;
    } else{
        tail = ptr2;
    }

    if (right2 != nullptr) {
        right2->prev = ptr1;
    } else{
        tail = ptr1;
    }

    listNode<T>* temp = ptr1->next;
    ptr1->next = ptr2->next;
    ptr2->next = temp;
    temp = ptr1->prev;
    ptr1->prev = ptr2->prev;
    ptr2->prev = temp;
}


template<typename T>
void LinkedList<T>::print() {
    listNode<T> *cur = this->head;
    std::cout << "[" << cur->data;
    cur = cur->next;
    while ( cur ){
        std::cout << ", " << cur->data;
        cur = cur->next;
    }
    std::cout << "]";
}






#endif //AADT_LAB1_LINKEDLIST_H
