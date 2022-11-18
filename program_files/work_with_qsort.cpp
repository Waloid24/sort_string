#include "work_with_qsort.h"
#include "print_in_file.h"
#include "work_with_src_file.h"

int alphabetcomp (const void * str1, const void * str2)
{
	const char * first_str  = ((struct str_ing *)str1)->p;
	const char * second_str = ((struct str_ing *)str2)->p;

	return my_strcmp (first_str, second_str);
}

int my_strcmp (const char * string1, const char * string2)
{
	for (int i = 0, j = 0; string1[i] != '\0' && string2[j] != '\0'; i++, j++)
	{
		while (!isalpha(string1[i]) && string1[i] != '\0')
			i++;

		while (!isalpha(string2[j]) && string2[j] != '\0')
			j++;

		if (tolower(string1[i]) == tolower(string2[j]))
			continue;
		return (tolower(string1[i]) - tolower(string2[j]));
	}
	return (tolower(string1[0]) - tolower(string2[0]));
}

int sort_from_end (const void * str1, const void * str2)
{
	char * p1 = ((struct str_ing *)str1)->p; //str_ptr1
	int length_1 = ((struct str_ing *)str1)->length_str;
	char * p2 = ((struct str_ing *)str2)->p;
	int length_2 = ((struct str_ing *)str2)->length_str;

	for (int x_1 = length_1-1, x_2 = length_2-1; x_1 > 0 && x_2 > 0; x_1--, x_2--)
	{
		while (!isalpha(p1[x_1]) && x_1 > 0)
			x_1--;

		while (!isalpha(p2[x_2]) && x_2 > 0)
			x_2--;

		if (tolower(p1[x_1]) == tolower(p2[x_2]))
			continue;

		printf ("p1[x_1] = %c **** p2[x_2] = %c\n", p1[x_1], p2[x_2]);
		return (tolower(p1[x_1]) - tolower(p2[x_2]));
	}
	return (tolower(p1[length_1-1]) - tolower(p2[length_2-1]));
}

void my_sort(void * First, size_t number, size_t size, int (* comparator)(const void * s1, const void * s2))
{
    char * first = (char*) First;
    for (int i = 1; i < number; i++)
    {
        for (int j = 0; j < number - i; j++)
        {

            if ((*comparator)((void*)(first+((j+1)*size)), (void*)(first+(size*j))) < 0)
            {
                swap((first+(size*j)), (first+((j+1)*size)), size);
            }
        }
    }
}

void swap(char* first, char* second, size_t size)
{
    char *Temp = (char *)calloc(size, sizeof(char));
    for (int k = 0; k < size; k++)
    {
        Temp[k] = *(first + k);
    }

    for (int k = 0; k < size; k++)
    {
        *(first + k) = *(second + k);
    }

    for (int k = 0; k < size; k++)
    {
        *(second + k) = Temp[k];
    }

    free(Temp);
}

// void swap (const void * str1, const void * str2)
// {
// 	const void * temp = nullptr;
// 	temp = str1;
// 	str1 = str2;
// 	str2 = temp;
// }
