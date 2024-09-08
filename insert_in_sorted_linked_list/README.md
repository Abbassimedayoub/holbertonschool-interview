# Insert Node into Sorted Linked List

## Overview

This repository includes an implementation of a function to insert a new node into a sorted linked list. The function maintains the sorted order of the list after the insertion. The project is written in C and provides a practical example of manipulating linked lists.

## Function Signature

```c
listint_t *insert_node(listint_t **head, int number);
```
## Parameters
- head: A pointer to the pointer to the head of the list.
- number: The value to be inserted into the list.
## Return Value
- Returns a pointer to the new node if insertion is successful.
- Returns ```NULL``` if the allocation fails.
## Repository Structure

- **insert_in_sorted_linked_list.c**: Contains the implementation of the `insert_node` function.
- **insert_in_sorted_linked_list.h**: Header file with function declarations and definitions.
- **main.c**: Example usage and testing of the `insert_node` function.

## Building and Running

1. Clone the repository:
   ```bash
   git clone https://github.com/Abbassimedayoub/holbertonschool-interview.git
   ```
2. Compile the source code
   ```bash
    gcc -Wall -Werror -Wextra -pedantic 0-main.c linked_lists.c 0-insert_number.c -o insert
    ```
3. Run the program
    ```bash
    ./insert
    ```
## Contact

For any questions or issues, please contact Abbassi Mohamed Ayoub at [abbassimohamedayoub@gmail.com](mailto:abbassimohamedayoub@gmail.com).
