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
	int i = 0, j = 0;
	for (; string1[i] != '\0' && string2[j] != '\0'; i++, j++)
	{
		while (!isalpha(string1[i]) && string1[i] != '\0') 
			i++;
		while (!isalpha(string2[j]) && string2[j] != '\0')
			j++;
		if (tolower(string1[i]) == tolower(string2[j]))
			continue;
		return (tolower(string1[i]) - tolower(string2[j]));
	}
	
	while (!isalpha(string1[i]) && string1[i] != '\0') 
			i++;
		
	while (!isalpha(string2[j]) && string2[j] != '\0')
			j++;
	
	return (tolower(string1[i]) - tolower(string2[j]));
}

int sort_from_end (const void * str_ptr1, const void * str_ptr2)
{
	char * p1 = ((struct str_ing *)str_ptr1)->p; 
	int length_1 = ((struct str_ing *)str_ptr1)->length_str;
	char * p2 = ((struct str_ing *)str_ptr2)->p;
	int length_2 = ((struct str_ing *)str_ptr2)->length_str;
	int x_1 = length_1-1, x_2 = length_2-1;
	
	for (; x_1 >= 0 && x_2 >= 0; x_1--, x_2--)
	{
		while (!isalpha(p1[x_1]) && x_1 > 0)
			x_1--;
		
		while (!isalpha(p2[x_2]) && x_2 > 0)
			x_2--;
		
		if (tolower(p1[x_1]) == tolower(p2[x_2]))
			continue;	
			
		return (tolower(p1[x_1]) - tolower(p2[x_2]));
	}
	while (x_1<0)
		x_1++;
	while (x_2<0)
		x_2++;	

	return (tolower(p1[x_1]) - tolower(p2[x_2])); 
}

