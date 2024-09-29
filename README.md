

# Dynamic Multilevel Caching System

## Introduction
This project implements a dynamic multilevel caching system in C++ that supports multiple cache levels with eviction policies like LRU and LFU.

## Features
- Supports dynamic addition/removal of cache levels.
- Implements both LRU and LFU eviction policies.
- Data retrieval and insertion across multiple levels.
- Efficient cache management using in-memory storage.

## How to Run
1. Clone the repository: `git clone <repository-link>`
2. Navigate to the project directory: `cd project-directory`
3. Compile the project: `make`
4. Run the program: `./cache_system`

## Assumptions
- Cache size is fixed for each level during initialization.
- All data is stored in-memory.

## Test Cases
You can find sample test cases in `test_cases/sample_test_cases.txt`.

## Key Design Decisions
- LRU is implemented using a doubly linked list with a hash map for O(1) access.
- LFU is implemented using a frequency map for efficient access to least frequently used items.
