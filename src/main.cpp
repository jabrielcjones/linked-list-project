#include "../include/DoublyLinkedList.h"
#include <iostream>

int main() {
    DoublyLinkedList<int> list;

    list.append(1);
    list.append(2);
    list.append(4);

    std::cout << "List: ";
    list.print();

    Node<int>* secondNode = list.getHead()->next;
    list.insert(secondNode, 3);

    std::cout << "Modified List: ";
    list.print();

    return 0;
}
