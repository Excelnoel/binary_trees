#include "binary_trees.h"

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * Return: The value stored in the extracted root node, or 0 on failure
 */
int heap_extract(heap_t **root) {
    if (*root == NULL) {
        return 0;  // Handle empty heap case
    }

    // Store the root value for return
    int extracted_value = (*root)->n;

    // If single node, free it and set root to NULL
    if ((*root)->left == NULL && (*root)->right == NULL) {
        free(*root);
        *root = NULL;
        return extracted_value;
    }

    // Find last level-order node
    heap_t *last_node = _get_last_level_order_node(*root);

    // Swap root and last node values
    (*root)->n = last_node->n;

    // Remove the last node from the heap
    _remove_last_level_order_node(*root, last_node);

    // Heapify the root to maintain max-heap property
    _heapify_down(*root);

    return extracted_value;
}

// Helper function to find the last level-order node (optional)
heap_t *_get_last_level_order_node(heap_t *root) {
    // Implementation removed for brevity (similar to previous example)
}

// Helper function to remove the last level-order node (optional)
void _remove_last_level_order_node(heap_t *root, heap_t *node) {
    // Implementation removed for brevity (similar to previous example)
}

// Helper function to heapify a node downwards (optional)
void _heapify_down(heap_t *node) {
    // Implementation removed for brevity (similar to previous example)
}
