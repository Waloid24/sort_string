//work with qsort
#include "work_with_qsort.h"

#include "print_in_file.h"
#include "work_with_src_file.h"

int alphabetcomp (const void * str1, const void * str2)
{
	return strcmp ((((struct str_ing *)str1)->p), ((struct str_ing *)str2)->p);	
}

void swap (const void * str1, const void * str2)
{
	const void * temp = nullptr;
	temp = str1; 
	str1 = str2;
	str2 = temp;
}

int my_strcmp (const char * string1, const char * string2)
{
	for (int i = 0, j = 0; string1[i] != '\0' && string2[j] != '\0'; i++, j++)
	{
		if (!isalpha(string1[i]))
			i++;
		if (!isalpha(string2[j]))
			j++;
		if ((string1[i] > string2[j]) && isalpha(string1[i]) && isalpha(string2[j]))
			return 1;
		else if ((string1[i] < string2[j]) && isalpha(string1[i]) && isalpha(string2[j]))
			return -1;
		else 
			continue;
	}
	return 0;
}

int sort_from_end (const void * str1, const void * str2)
{
	char * p1 = ((struct str_ing *)str1)->p;
	int length_1 = ((struct str_ing *)str1)->length_str;
	char * p2 = ((struct str_ing *)str2)->p;
	int length_2 = ((struct str_ing *)str2)->length_str;
	
	for (int x_1 = length_1, x_2 = length_2; x_1 > 0 && x_2 > 0; x_1--, x_2--)
	{
		if (!isalpha(p1[x_1-1]))
			x_1--;
		if (!isalpha(p2[x_2-1]))
			x_2--;
		if ((p1[x_1-1] > p2[x_2-1]) && isalpha(p1[x_1-1]) && isalpha(p2[x_2-1]))
			return 1;
		else if ((p1[x_1-1] < p2[x_2-1]) && isalpha(p1[x_1-1]) && isalpha(p2[x_2-1]))
			return -1;
		else 
			continue;
	}
	return 0;	
}