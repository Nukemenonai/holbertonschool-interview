# 0x0D. Array to AVL

Specializations - Interview Preparation ― Algorithms

### AVL - From sorted array

function that builds an AVL tree from an array

* Prototype: avl_t *sorted_array_to_avl(int *array, size_t size);
* Where array is a pointer to the first element of the array to be converted
* And size is the number of element in the array
* return a pointer to the root node of the created AVL tree, or NULL on failure
* it is assumed there will be no duplicate value in the array