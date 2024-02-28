#include "binary_trees.h"

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * Return: The value stored in the extracted root node, or 0 on failure
 */

int heap_extract(heap_t **root) {
    if (*root == NULL) {
        return 0;
    }

    int extracted_value = (*root)->n;

    if ((*root)->left == NULL && (*root)->right == NULL) {
        free(*root);
        *root = NULL;
        return extracted_value;
    }

    heap_t *last_node = _get_last_level_order_node(*root);

    (*root)->n = last_node->n;

    _remove_last_level_order_node(*root, last_node);

    _heapify_down(*root);

    return extracted_value;
}

heap_t *_get_last_level_order_node(heap_t *root){
    heap_t *current = root;
    while (current->right != NULL) {
        current = current->right;
    }
    return current;
}

void _remove_last_level_order_node(heap_t *root, heap_t *node){
    heap_t *parent = root;
    while (parent->right != NULL && parent->right != node) {
        parent = parent->right;
    }

    if (parent->left == node) {
        parent->left = NULL;
    } else {
        parent->right = NULL;
    }

    free(node);
}

void _heapify_down(heap_t *node){
    int largest = node->data;
    heap_t *largest_node = node;

    heap_t *left = node->left;
    heap_t *right = node->right;

    if (left != NULL && left->data > largest) {
        largest = left->data;
        largest_node = left;
    }

    if (right != NULL && right->data > largest) {
        largest = right->data;
        largest_node = right;
    }

    if (largest_node != node) {
        int temp = node->data;
        node->data = largest_node->data;
        largest_node->data = temp;
        _heapify_down(largest_node);
    }
}
