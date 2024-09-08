#include <stdio.h>
#include "lists.h"
/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: double pointer to the head of the list
 * @number: number to insert into the list
 * Return: address of the new node, or NULL if it failed
 */
 #include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: double pointer to the head of the list
 * @number: number to insert into the list
 * 
 * Return: address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new_node;
    listint_t *current;
    listint_t *previous = NULL;

    // Allocate memory for the new node and check for failure
    new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = number;
    new_node->next = NULL;

    // If the list is empty or the new node should be inserted at the beginning
    if (*head == NULL || (*head)->n >= number)
    {
        new_node->next = *head;
        *head = new_node;
    }
    else
    {
        // Traverse the list to find the insertion point
        current = *head;
        while (current != NULL && current->n < number)
        {
            previous = current;
            current = current->next;
        }
        // Insert the new node at the correct position
        previous->next = new_node;
        new_node->next = current;
    }

    return (new_node);
}
