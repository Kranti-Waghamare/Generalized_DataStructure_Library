# Generalized Data Structures Library in C++

## 📌 Project Overview

**Generalized Data Structures Library in C++** is a collection of commonly used data structures implemented using **Generic Programming (Templates)** in C++.

The main purpose of this project is to provide reusable and type-independent implementations of different data structures. By using C++ templates, the same data structure can work with different data types such as `int`, `float`, `double`, `char`, etc., without rewriting the complete implementation.

This project focuses on understanding the concepts of:

* Generic Programming
* Object-Oriented Programming
* Data Structures
* Templates in C++
* Dynamic Memory Allocation
* Searching and Sorting
* Recursive and Iterative operations

---

## 🎯 Objectives

The main objectives of this project are:

1. To implement commonly used data structures using C++ templates.
2. To make data structures reusable for different data types.
3. To understand the practical implementation of data structures.
4. To provide common operations such as insertion, deletion, searching, counting and traversal.
5. To create a simple and reusable data structure library.
6. To improve understanding of Generic Programming in C++.

---

## 🛠️ Technologies Used

* **Programming Language:** C++
* **Concept:** Generic Programming
* **Compiler:** GCC / G++
* **IDE:** Visual Studio Code / Any C++ compatible IDE
* **Standard Libraries:** iostream, stdlib, etc.

---

## 📂 Project Structure

```text
Generalized Data Structures Library/
│
├── DataStructure_Library.cpp
├── README.md
└── requirements.txt
```

### File Description

| File                            | Description                                                               |
| ------------------------------- | ------------------------------------------------------------------------- |
| `DataStructure_Library.cpp`     | Contains the implementation of generalized data structures and algorithms |
| `README.md`                     | Project documentation                                                     |
| `requirements.txt`              | Contains the requirements needed to compile and run the project           |

---

# 📚 Data Structures Included

The project contains the following generalized data structures:

### 1. Singly Linear Linked List

A singly linear linked list consists of nodes where each node contains data and a pointer to the next node.

### Operations

* `InsertFirst()`
* `InsertLast()`
* `InsertAtPos()`
* `DeleteFirst()`
* `DeleteLast()`
* `DeleteAtPos()`
* `Display()`
* `Count()`

---

### 2. Singly Circular Linked List

A singly circular linked list is a linked list where the last node points back to the first node.

### Operations

* `InsertFirst()`
* `InsertLast()`
* `InsertAtPos()`
* `DeleteFirst()`
* `DeleteLast()`
* `DeleteAtPos()`
* `Display()`
* `Count()`

---

### 3. Doubly Linear Linked List

A doubly linear linked list contains two links in every node:

* Previous node pointer
* Next node pointer

### Operations

* `InsertFirst()`
* `InsertLast()`
* `InsertAtPos()`
* `DeleteFirst()`
* `DeleteLast()`
* `DeleteAtPos()`
* `Display()`
* `Count()`

---

### 4. Doubly Circular Linked List

A doubly circular linked list combines the features of a doubly linked list and a circular linked list.

The last node is connected to the first node and the first node is connected back to the last node.

### Operations

* `InsertFirst()`
* `InsertLast()`
* `InsertAtPos()`
* `DeleteFirst()`
* `DeleteLast()`
* `DeleteAtPos()`
* `Display()`
* `Count()`

---

### 5. Stack

Stack is a linear data structure that follows the **LIFO (Last In First Out)** principle.

### Operations

* `Push()`
* `Pop()`
* `Display()`
* `Count()`

Example:

Push(10)
Push(20)
Push(30)

Stack:

30  <- Top
20
10
```

The element `30` will be removed first.

---

### 6. Queue

Queue is a linear data structure that follows the **FIFO (First In First Out)** principle.

### Operations

* `Enqueue()`
* `Dequeue()`
* `Display()`
* `Count()`

Example:

10 -> 20 -> 30

Front          Rear
  |              |
  10 -> 20 -> 30
```

The element `10` will be removed first.

---

### 7. Binary Search Tree (BST)

Binary Search Tree is a hierarchical data structure in which:

* Values smaller than the root are stored on the left side.
* Values greater than the root are stored on the right side.
* Duplicate values are not inserted.

### Operations

* `Insert()`
* `Search()`
* `Inorder()`
* `Preorder()`
* `Postorder()`
* `Count()`
* `CountLeaf()`
* `CountParent()`

### Tree Traversals

#### Inorder

Left → Root → Right
```

Inorder traversal of a BST produces elements in sorted order.

#### Preorder

Root → Left → Right
```

#### Postorder

Left → Right → Root
```

# 🧩 Generic Programming

One of the main concepts used in this project is **Generic Programming**.

Instead of creating separate classes for every data type:

```cpp
class IntStack;
class FloatStack;
class DoubleStack;
```

C++ templates allow us to create a single generalized class:

```cpp
template<class T>
class Stack
{
    // implementation
};
```

The same class can then be used as:

```cpp
Stack<int> obj1;
Stack<float> obj2;
Stack<double> obj3;
Stack<char> obj4;
```

This makes the code:

* Reusable
* Flexible
* Type-independent
* Easier to maintain
* Less repetitive

---

# 💡 Example of Generic Class

```cpp
template<class T>
class Stack
{
public:
    void Push(T No);
    void Pop();
    void Display();
};
```

The same implementation can work with:

```cpp
Stack<int> iObj;
Stack<float> fObj;
Stack<char> cObj;
```
# 📝 Important Note

"GeneralizedDataStructures.cpp" contains the generalized data structure implementations.

The project is designed as a ""library-style implementation"", therefore the data structure classes are implemented without depending on a specific application or business problem.

A separate "main()" function can be created when testing individual data structures.

---

# 🧪 Example Usage

For example, a generalized linked list can be used with different data types:

```cpp
SinglyLL<int> obj1;

obj1.InsertFirst(10);
obj1.InsertLast(20);
obj1.InsertLast(30);

obj1.Display();
```

The same class can also be used with another data type:

```cpp
SinglyLL<float> obj2;

obj2.InsertFirst(10.5);
obj2.InsertLast(20.5);

obj2.Display();
```

This demonstrates the reusability of Generic Programming.

---

# 🌟 Key Features

* Generic implementation using C++ templates
* Supports multiple data types
* Reusable data structure classes
* Dynamic memory allocation
* Object-Oriented Programming approach
* Common data structure operations
* Clean and organized implementation
* Method-level documentation
* Easy to extend with additional data structures

---

# 📖 Concepts Demonstrated

This project demonstrates practical knowledge of:

* C++ Templates
* Generic Programming
* Classes and Objects
* Encapsulation
* Pointers
* Structures
* Dynamic Memory Allocation
* Recursion
* Linked Lists
* Stack
* Queue
* Binary Search Tree
* Function Overloading
* Iterative Programming
* Recursive Programming

---

# 🚀 Future Enhancements

The library can be extended in the future by adding:

* Priority Queue
* Heap
* Hash Table
* Graph
* AVL Tree
* Circular Queue
* Deque
* Additional searching algorithms
* Additional sorting algorithms
* Exception handling
* Iterator support
* Better memory management
* Unit testing

---

# 👩‍💻 Author

**Kranti Waghamare**

B.Tech – Computer Science Engineering