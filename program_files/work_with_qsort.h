#ifndef WORK_WITH_QSORT_H
#define WORK_WITH_QSORT_H
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int  alphabetcomp (const void * str1, const void * str2);
int my_strcmp (const char * string1, const char * string2);
int  sort_from_end (const void * srt1, const void * str2);
void my_sort(void * First, size_t number, size_t size, int (* comparator)(const void * s1, const void * s2));
void swap(char* first, char* second, size_t size);

#endif
