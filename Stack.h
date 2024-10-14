#ifndef AADT_LAB1_STACK_H
#define AADT_LAB1_STACK_H


template <typename T>
class stackNode {
public:
    T data;
    int priority;
    stackNode *prev;
    stackNode(T inputData, int priority);
};


template <typename T>
stackNode<T>::stackNode(T inputData, int priority) {
    data = inputData;
    this->priority = priority;
    prev = nullptr;
}


template <typename T>
class Stack {
public:
    stackNode<T> *tail = nullptr, *head = nullptr;

    Stack();
    ~Stack();
    void push(T value, int priority);
    void pop();
    T peek();
};

template<typename T>
Stack<T>::Stack(): head(nullptr), tail(nullptr) {}


template<typename T>
Stack<T>::~Stack() {
    while(head != nullptr) pop();
}


template<typename T>
void Stack<T>::push(T value, int priority) {
    auto *node = new stackNode<T>(value, priority);
    node->prev = head;
    head = node;
    if (tail == nullptr) tail = node;
}


template<typename T>
void Stack<T>::pop() {
    if (head == nullptr) return;
    if (head == tail){
        delete tail;
        head = tail = nullptr;
        return;
    }
    stackNode<T> *node = head;
    head = node->prev;
    delete node;
}


template<typename T>
T Stack<T>::peek() {
    return *head;
}


#endif //AADT_LAB1_STACK_H
