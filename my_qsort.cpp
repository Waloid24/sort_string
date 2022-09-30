#include "my_qsort.h"

// int main (void)
// {
//     int array[] = {2, 4, 1, 3, 13, 10, 12};
//     size_t n_elem_arr = sizeof(array)/sizeof(int); 
//     my_qsort (array, n_elem_arr, sizeof(int), comp_num);
    
//     printf ("after sorting: ");
//     for (int i = 0; i < n_elem_arr; i++)
//     {
//         printf ("%d ", array[i]);
//     }
//     printf ("\n");
// }
//2 12 1 10 5 3 4 0000|0000|0000|0000

//2 4  1 3  13 10 12 //////10
//
//2 12 1 10 13 3  4
//^               ^
//2 4  1 10 13 3  12   ///10
//     ^       ^
//2 4  1 3  13 10 12
//       ^   ^
//       l   f           middle

// sort (0; r)
// sort (l; до конца)

void swap (void * first_elem, void * second_elem, size_t size)
{
    MY_ASSERT (first_elem == nullptr, "The pointer to the first element is zero");
    MY_ASSERT (second_elem = nullptr, "The pointer to the second element is zero");

    for (size_t j = 0; j < size; j++)
    {
        unsigned char temp = ((unsigned char *) first_elem)[j];
        ((unsigned char *) first_elem) [j] = ((unsigned char *) second_elem)[j];
        ((unsigned char *) second_elem)[j] = temp;
    }
}

size_t partition(void *array, size_t left, size_t right, size_t element_size, int (*comparator) (const void*, const void*))
{
    MY_ASSERT (array != nullptr, "pointer to array is equal to nullptr");

    size_t pivot = left;
    void* p_val = calloc (1, element_size);

    MY_ASSERT (p_val == nullptr, "Memory allocation error");   

    memcpy (p_val, (unsigned char*)array + element_size * pivot, element_size);

    if (right - left > 1)
    {
        while (left < right)
        {
            while (comparator ((unsigned char*)array + element_size * left, p_val) <= 0)
                left++;
            
            while (comparator ((const void*)((unsigned char*)array + element_size * right), p_val) > 0)
                right--;

            if (left < right)
                swap ((unsigned char*)array + element_size * left, (unsigned char*)array + element_size * right, sizeof(element_size));
        }

        swap ((unsigned char*)array + element_size * pivot, (unsigned char*)array + element_size * right, sizeof(element_size));
    }
    else if (left < right)
    {
        if (comparator ((unsigned char*)array + element_size * left, (unsigned char*)array + element_size * right) > 0)
           swap ((unsigned char*)array + element_size * left, (unsigned char*)array + element_size * right, sizeof(element_size));
    }

    free (p_val);
    return right;
}

void quicksort(void *array, size_t start, size_t end, size_t element_size, int (*comparator) (const void*, const void*))
{
    MY_ASSERT (array != nullptr, "pointer to array is equal to nullptr");

    if (start < end)
    {
        size_t split_point = partition(array, start, end, element_size, comparator);

        quicksort(array, start, split_point - 1, element_size, comparator);
        quicksort(array, split_point + 1, end, element_size, comparator);
    }
}

void my_qsort (void *array, size_t n_memb, size_t element_size, int (*comparator) (const void*, const void*))
{
    quicksort (array, 0, n_memb - 1, element_size, comparator);
}
