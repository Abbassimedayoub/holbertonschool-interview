#include <stdlib.h>
#include "binary_trees.h"

/**
 * swap_values - Swap the values of two nodes
 * @a: First node
 * @b: Second node
 */
void swap_values(heap_t *a, heap_t *b)
{
	int temp;

	temp = a->n;
	a->n = b->n;
	b->n = temp;
}

/**
 * heapify_up - Ensures Max Heap property is maintained after insertion
 * @node: The newly inserted node
 * Return: The pointer to the new position of the inserted node
 */
heap_t *heapify_up(heap_t *node)
{
	heap_t *parent;

	if (!node)
		return (NULL);

	parent = node->parent;
	while (parent && node->n > parent->n)
	{
		swap_values(parent, node);
		node = parent;
		parent = node->parent;
	}

	return (node);
}

/**
 * find_insertion_point - Finds the insertion point for the new node
 * @root: The root of the heap
 * Return: A pointer to the node where the new node should be inserted
 */
heap_t *find_insertion_point(heap_t *root)
{
	heap_t **queue;
	int head = 0, tail = 0, size = 1024;
	heap_t *current;

	if (!root)
		return (NULL);

	queue = malloc(sizeof(heap_t *) * size);
	if (!queue)
		return (NULL);

	queue[tail++] = root;

	while (head < tail)
	{
		current = queue[head++];
		if (!current->left || !current->right)
		{
			free(queue);
			return (current);
		}

		if (current->left)
		{
			if (tail >= size)
			{
				size *= 2;
				queue = realloc(queue, sizeof(heap_t *) * size);
				if (!queue)
					return (NULL);
			}
			queue[tail++] = current->left;
		}
		if (current->right)
		{
			if (tail >= size)
			{
				size *= 2;
				queue = realloc(queue, sizeof(heap_t *) * size);
				if (!queue)
					return (NULL);
			}
			queue[tail++] = current->right;
		}
	}

	free(queue);
	return (NULL);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * @value: The value to store in the new node
 * Return: Pointer to the inserted node or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *insert_point;

	if (!root)
		return (NULL);

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	insert_point = find_insertion_point(*root);
	if (!insert_point)
		return (NULL);

	new_node = binary_tree_node(insert_point, value);
	if (!new_node)
		return (NULL);

	if (!insert_point->left)
		insert_point->left = new_node;
	else
		insert_point->right = new_node;

	return (heapify_up(new_node));
}
