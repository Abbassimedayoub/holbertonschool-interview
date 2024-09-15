#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * swap - Swap values of two nodes
 * @a: First node
 * @b: Second node
 */
void swap(heap_t *a, heap_t *b)
{
    int temp = a->n;
    a->n = b->n;
    b->n = temp;
}

/**
 * bubble_up - Restore the Max Heap property by bubbling up
 * @node: Node to bubble up
 */
void bubble_up(heap_t *node)
{
    while (node->parent && node->n > node->parent->n)
    {
        swap(node, node->parent);
        node = node->parent;
    }
}

/**
 * insert_last_node - Insert a new node at the end of the heap
 * @root: Pointer to the root of the heap
 * @node: New node to be inserted
 */
void insert_last_node(heap_t *root, heap_t *node)
{
    heap_t *current = root;
    
    heap_t **queue = malloc(sizeof(heap_t *) * 100); 
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear)
    {
        current = queue[front++];
        
        if (current->left)
        {
            queue[rear++] = current->left;
        }
        else
        {
            current->left = node;
            node->parent = current;
            free(queue);
            return;
        }

        if (current->right)
        {
            queue[rear++] = current->right;
        }
        else
        {
            current->right = node;
            node->parent = current;
            free(queue);
            return;
        }
    }
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root of the heap
 * @value: Value to insert
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node = binary_tree_node(NULL, value);

    if (new_node == NULL)
        return (NULL);

    if (*root == NULL)
    {
        *root = new_node;
        return (new_node);
    }

    insert_last_node(*root, new_node);
    bubble_up(new_node);

    return (new_node);
}
