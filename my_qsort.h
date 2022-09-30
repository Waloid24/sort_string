#include <stdio.h>
#include <string.h>
#include "my_assert.h"
#include <stdlib.h>

void my_qsort (void * first, size_t number, size_t size, int (*comparator ) (const void *, const void *));
int comp_num (const void * num1, const void * num2);
void swap (void * first_elem, void * second_elem, size_t size);