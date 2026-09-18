# Data Structures Concepts in C

A structured collection of **Data Structures and Algorithms implemented in C**, designed as a practical reference for understanding core DSA concepts through clean, modular, and executable programs.

The repository covers fundamental and advanced data structures, including arrays, linked lists, stacks, queues, heaps, and multiple types of trees. Each implementation focuses on the underlying logic, operations, and algorithmic techniques commonly used in academic coursework, coding interviews, competitive programming, and software development.

---

## Overview

This repository is being developed as a consolidated DSA reference in C.

The objective is to maintain implementations that are:

* Easy to understand
* Easy to compile and execute
* Structured by topic
* Suitable for academic revision
* Useful for interview preparation
* Practical for building a strong DSA foundation

The repository will progressively expand to cover additional data structures and algorithms.

---

## Repository Structure

```text
DSA-in-C/
│
├── 01-Arrays/
│   └── arrays_all_operations.c
│
├── 02-Linked-List/
│   └── linked_lists_all_operations.c
│
├── 03-Stack/
│   └── stack_all_operations.c
│
├── 04-Queue/
│   └── queue_all_operations.c
│
├── 05-Trees/
│   ├── 01-bst_all_operations.c
│   ├── 02-avl_tree.c
│   ├── 03-red_black_tree.c
│   ├── 04-b_tree.c
│   ├── 05-b_plus_tree.c
│   ├── 06-top_down_tree.c
│   └── 07-bottom_up_tree.c
│
└── README.md
```
---

# Data Structures Covered

## 01. Arrays

The array implementation provides a consolidated program covering commonly used array operations.

### Concepts

* Array traversal
* Insertion
* Deletion
* Linear search
* Binary search
* Bubble sort
* Selection sort
* Insertion sort
* Array reversal
* Maximum and minimum
* Sum and average

### Implementation

```text
01-Arrays/
└── arrays_all_operations.c
```

---

## 02. Linked Lists

The linked-list implementation demonstrates multiple linked-list variants and their fundamental operations.

### Singly Linked List

* Insert at beginning
* Insert at end
* Insert at a specific position
* Delete from beginning
* Delete from end
* Delete from a specific position
* Search
* Display

### Doubly Linked List

* Insert
* Delete
* Forward traversal
* Backward traversal

### Circular Linked List

* Insert
* Delete
* Circular traversal

### Implementation

```text
02-Linked-List/
└── linked_lists_all_operations.c
```

---

## 03. Stack

The stack implementation demonstrates both array-based and linked-list-based approaches.

### Concepts

* Stack using arrays
* Stack using linked lists
* Push
* Pop
* Peek
* Display
* Infix to postfix conversion
* Postfix expression evaluation
* Parentheses matching

### Implementation

```text
03-Stack/
└── stack_all_operations.c
```

---

## 04. Queue

The queue implementation covers several important queue variants.

### Simple Queue

* Enqueue
* Dequeue
* Peek
* Display

### Circular Queue

* Enqueue
* Dequeue
* Display

### Deque

* Insert from front
* Insert from rear
* Delete from front
* Delete from rear
* Display

### Priority Queue

* Insertion
* Deletion
* Display

### Implementation

```text
04-Queue/
└── queue_all_operations.c
```

---

# 05. Trees

The tree section contains implementations ranging from fundamental binary search trees to balanced and multiway search trees.

---

## Binary Search Tree

The Binary Search Tree implementation covers the fundamental operations required to work with ordered binary trees.

### Concepts

* Node creation
* Insertion
* Searching
* Deletion
* Inorder traversal
* Preorder traversal
* Postorder traversal
* Level-order traversal
* Minimum and maximum
* Leaf-node counting
* Total-node counting
* Tree height
* Sum of nodes

```text
05-Trees/
└── 01-bst_all_operations.c
```

---

## AVL Tree

The AVL Tree implementation demonstrates self-balancing binary search trees.

### Concepts

* AVL insertion
* AVL deletion
* Searching
* Height calculation
* Balance factor
* LL rotation
* RR rotation
* LR rotation
* RL rotation
* Inorder traversal
* Preorder traversal
* Postorder traversal

```text
05-Trees/
└── 02-avl_tree.c
```

### Rotations

```text
LL → Right Rotation
RR → Left Rotation
LR → Left Rotation + Right Rotation
RL → Right Rotation + Left Rotation
```

---

## Red-Black Tree

The Red-Black Tree implementation demonstrates a self-balancing binary search tree based on node colors and structural properties.

### Concepts

* Red and Black nodes
* NIL sentinel
* BST insertion
* Recoloring
* Left rotation
* Right rotation
* Insertion fix-up
* BST deletion
* Deletion fix-up
* Searching
* Inorder traversal
* Preorder traversal
* Postorder traversal

```text
05-Trees/
└── 03-red_black_tree.c
```

---

## B-Tree

The B-Tree implementation is intended to demonstrate multiway balanced search trees and their use in efficient searching and storage systems.

### Concepts

* Multiway search tree
* Node splitting
* Searching
* Insertion
* Deletion
* Traversal

```text
05-Trees/
└── 04-b_tree.c
```

---

## B+ Tree

The B+ Tree section focuses on the structure commonly associated with database indexing and external storage systems.

### Concepts

* Multiway indexing
* Internal nodes
* Leaf nodes
* Linked leaf nodes
* Searching
* Insertion
* Traversal

```text
05-Trees/
└── 05-b_plus_tree.c
```

---

## Top-Down Tree

The Top-Down Tree implementation demonstrates top-down insertion using a 2-3-4 tree approach.

### Concepts

* Top-down insertion
* 2-3-4 tree
* Pre-splitting full nodes
* Node splitting
* Searching
* Inorder traversal
* Level-based display
* Height calculation

```text
05-Trees/
└── 06-top_down_tree.c
```

---

## Bottom-Up Tree

The Bottom-Up Tree implementation demonstrates insertion where node overflow is handled while propagating information back toward the root.

### Concepts

* Bottom-up insertion
* Multiway search tree
* Node splitting
* Key promotion
* Searching
* Inorder traversal
* Level-based display
* Height calculation

```text
05-Trees/
└── 07-bottom_up_tree.c
```

---

# Implementation Philosophy

The programs in this repository follow a few simple principles:

### 1. Topic-based organization

Each major DSA concept has its own directory so that related implementations can be found quickly.

### 2. Practical implementations

Programs are designed to be compiled and executed rather than being purely theoretical demonstrations.

### 3. Progressive complexity

The repository moves from basic linear structures toward more advanced structures such as balanced trees and multiway search trees.

### 4. Readability

Function names and program structure are kept straightforward so that the underlying algorithm remains easy to follow.

### 5. Single-file implementations

Where appropriate, related operations are consolidated into a single program, making each file convenient for learning, testing, and revision.

---

# Complexity Reference

| Data Structure     | Typical Search | Typical Insert | Typical Delete |
| ------------------ | -------------: | -------------: | -------------: |
| Array              |           O(n) |           O(n) |           O(n) |
| Sorted Array       |       O(log n) |           O(n) |           O(n) |
| Singly Linked List |           O(n) |          O(1)* |           O(n) |
| Doubly Linked List |           O(n) |          O(1)* |           O(n) |
| Stack              |           O(n) |           O(1) |           O(1) |
| Queue              |           O(n) |           O(1) |           O(1) |
| BST                |           O(h) |           O(h) |           O(h) |
| AVL Tree           |       O(log n) |       O(log n) |       O(log n) |
| Red-Black Tree     |       O(log n) |       O(log n) |       O(log n) |
| B-Tree             |       O(log n) |       O(log n) |       O(log n) |
| B+ Tree            |       O(log n) |       O(log n) |       O(log n) |

`*` When the required position/node is already known.

Actual performance can vary depending on implementation details and the structure of the input.

---

# How to Run

## Clone the Repository

```bash
git clone <your-repository-url>
cd DSA-in-C
```

## Compile a Program

Using GCC:

```bash
gcc 01-Arrays/arrays_all_operations.c -o arrays
```

## Run

Linux/macOS:

```bash
./arrays
```

Windows:

```bash
arrays.exe
```

The same approach can be used for the other programs.

Example:

```bash
gcc 05-Trees/03-red_black_tree.c -o red_black_tree
```

---

# Development Roadmap

The repository is being expanded progressively.

### Completed

* [x] Arrays
* [x] Linked Lists
* [x] Stack
* [x] Queue
* [x] Binary Search Tree
* [x] AVL Tree
* [x] Red-Black Tree
* [x] Top-Down Tree
* [x] Bottom-Up Tree
* [x] Hashing
* [x] Recursion

### Planned

* [ ] B-Tree
* [ ] B+ Tree
* [ ] Graphs
* [ ] BFS
* [ ] DFS
* [ ] Shortest Path Algorithms
* [ ] Minimum Spanning Tree
* [ ] Dynamic Programming
* [ ] Greedy Algorithms
* [ ] Divide and Conquer
* [ ] Advanced Sorting
* [ ] Advanced Searching

---

# Learning Goals

This repository is intended to build a strong understanding of:

* Data representation
* Dynamic memory allocation
* Pointers
* Recursion
* Searching techniques
* Sorting algorithms
* Tree balancing
* Graph traversal
* Algorithmic complexity
* Problem-solving using C

---

# Tech Stack

**Language:** C

**Compiler:** GCC / MinGW

**Development Environment:** VS Code / Any standard C IDE

**Version Control:** Git & GitHub

---

# Contributing

This is primarily a personal learning repository, but suggestions, improvements, bug fixes, and alternative implementations are welcome.

If you find an issue:

1. Identify the problem.
2. Open an issue or propose a fix.
3. Clearly describe the change.
4. Keep implementations focused on the relevant DSA concept.

---

# Author

**Priyanthi A**

Computer Technology
Madras Institute of Technology, Anna University

---

## Repository Status

**Actively expanding**

This repository will continue to grow into a comprehensive collection of Data Structures and Algorithms implemented in C, with emphasis on clarity, correctness, and practical understanding.
