# Doubly Linked List

This project implements a doubly linked list in C++.

## Overview

A doubly linked list is a data structure that consists of a sequence of elements, where each element contains a pointer to the next element in the sequence as well as a pointer to the previous element. This allows for efficient insertion and deletion of elements at any position in the list.

## Features

- Addition of elements to the end of the list (append)
- Insertion of elements after a specified node
- Removal of elements from the list by value
- Printing the contents of the list
- Printing the contents of the list in reverse order
- Getting the size of the list

## Usage

To use the doubly linked list, include `DoublyLinkedList.h` in your project and create a `DoublyLinkedList` object.

```cpp
#include "DoublyLinkedList.h"

int main() {

    DoublyLinkedList<int> list;

    list.append(1);
    list.append(2);
    list.append(3);

    list.print();

    return 0;
}
```

## Build Instructions

To build the project, you can use CMake. Navigate to the root directory of the project and run the following commands:

```bash
mkdir build
cd build
cmake ..
make
```

This will generate the executable `LinkedList` in the `build` directory.

## Running Tests

This project uses Google Test (gtest) for unit testing. To run the tests, follow these steps:

1. Build your project using CMake as described above.
1. Navigate to the build directory.
1. Run the test executable, which is typically named after your project appended with _test.

Here's an example command:

```bash
cd build
./LinkedList_test
This will execute all the unit tests and display the test results in the terminal.
```

## Author

Jabriel Jones
