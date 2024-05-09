#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

template <typename T>
struct Node {
    T data;
    Node* prev;
    Node* next;

    Node(T value) : data(value), prev(nullptr), next(nullptr) {}
};

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void append(T value);
    void insert(Node<T>* prevNode, T value);
    void remove(T value);
    void print();
    void reversePrint();
    int getSize();
    Node<T>* getHead();
};

#endif
