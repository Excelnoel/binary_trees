# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89

# Source files (replace with your actual file names)
SOURCES = 132-array_to_heap.c 133-heap_extract.c 0-binary_tree_node.c 134-heap_to_sorted_array.c 100-binary_trees_ancestor.c 101-binary_tree_levelorder.c 13-binary_tree_nodes.c 102-binary_tree_is_complete.c 14-binary_tree_balance.c 103-binary_tree_rotate_left.c 15-binary_tree_is_full.c 104-binary_tree_rotate_right.c 16-binary_tree_is_perfect.c 10-binary_tree_depth.c 17-binary_tree_sibling.c 110-binary_tree_is_bst.c 18-binary_tree_uncle.c 111-bst_insert.c 1-binary_tree_insert_left.c 112-array_to_bst.c 2-binary_tree_insert_right.c 113-bst_search.c 3-binary_tree_delete.c 114-bst_remove.c 4-binary_tree_is_leaf.c 5-binary_tree_is_root.c 11-binary_tree_size.c 6-binary_tree_preorder.c 120-binary_tree_is_avl.c 7-binary_tree_inorder.c 121-avl_insert.c 8-binary_tree_postorder.c 122-array_to_avl.c 9-binary_tree_height.c 123-avl_remove.c binary_tree_print.c 124-sorted_array_to_avl.c binary_trees.h 12-binary_tree_leaves.c 130-binary_tree_is_heap.c 131-heap_insert.c

# Object files
OBJECTS = $(SOURCES:.c=.o)

# Executable name
EXEC = my_program

# All targets
all: $(EXEC)

# Rule to compile each C file into an object file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to link object files into the executable
$(EXEC): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJECTS) -o $@

# Rule to clean up object files and the executable
clean:
	rm -f $(OBJECTS) $(EXEC)
