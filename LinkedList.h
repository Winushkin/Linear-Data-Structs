//
// Created by Кирилл Беляев on 24.09.2024.
//

#ifndef AADT_LAB1_LINKEDLIST_H
#define AADT_LAB1_LINKEDLIST_H

template <typename T>
class Node {
public:
    T data;
    Node* prev, *next;
    explicit Node(T inputData);
};


template <typename T>
class LinkedList {
    int length;
    Node<T> *head = nullptr, *tail = nullptr;

public:
    LinkedList();
    int len();
    void print();
    void resize();
    void insert(int index, T value);
    void append(T value);
    void pop(int index);
    void getIndex(T value);
    void swap(int index1, int index2);

};


#endif //AADT_LAB1_LINKEDLIST_H
