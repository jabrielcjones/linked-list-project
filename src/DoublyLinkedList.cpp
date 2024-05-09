#include "../include/DoublyLinkedList.h"
#include <iostream>

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    while (head) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void DoublyLinkedList<T>::append(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

template <typename T>
void DoublyLinkedList<T>::insert(Node<T>* prevNode, T value) {
    if (!prevNode) {
        std::cout << "Previous node cannot be null" << std::endl;
        return;
    }

    Node<T>* newNode = new Node<T>(value);
    newNode->next = prevNode->next;
    if (prevNode->next) {
        prevNode->next->prev = newNode;
    }
    prevNode->next = newNode;
    newNode->prev = prevNode;

    if (newNode->next == nullptr) {
        tail = newNode;
    }

    size++;
}

template <typename T>
void DoublyLinkedList<T>::remove(T value) {
    Node<T>* current = head;
    while (current) {
        if (current->data == value) {
            if (current == head) {
                head = head->next;
                if (head) head->prev = nullptr;
            } else if (current == tail) {
                tail = tail->prev;
                if (tail) tail->next = nullptr;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            delete current;
            size--;
            return;
        }
        current = current->next;
    }
}

template <typename T>
void DoublyLinkedList<T>::print() {
    Node<T>* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template <typename T>
void DoublyLinkedList<T>::reversePrint() {
    Node<T>* current = tail;
    while (current) {
        std::cout << current->data << " ";
        current = current->prev;
    }
    std::cout << std::endl;
}

template <typename T>
int DoublyLinkedList<T>::getSize() {
    return size;
}

template <typename T>
Node<T>* DoublyLinkedList<T>::getHead() {
    return head;
}

template class DoublyLinkedList<int>;
template class Node<int>;
