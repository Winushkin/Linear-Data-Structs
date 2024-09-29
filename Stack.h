#ifndef AADT_LAB1_STACK_H
#define AADT_LAB1_STACK_H

template <typename T>
class Node {
public:
    T data;
    Node *head;
    explicit Node(T inputData);
};


template <typename T>
class Stack {
    int length = 0;
    Node<T> *tail = nullptr;
public:
    Stack();
    void push(T value);
    T pop();
    bool isEmpty();
    T peek();
};


template<typename T>
Stack<T>::Stack(): length(0) {}


template<typename T>
void Stack<T>::push(T value) {
    auto *cur = new Node<T>;
    cur->data = value;
    cur->head = this->tail;
    this->tail = cur;
    length++;
}


template<typename T>
T Stack<T>::pop() {
    T val = this->tail->data;
    Node<T> dlt = this->tail;
    this->tail = this->tail->head;
    delete dlt;
    length--;
    return val;
}


template<typename T>
bool Stack<T>::isEmpty() {
    return !length;
}


template<typename T>
T Stack<T>::peek() {
    return this->tail->data;
}

#endif //AADT_LAB1_STACK_H
