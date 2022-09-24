#include <stdio.h>
//#include "print_in_file.h"
//#include "work_with_qsort.h"
//#include "work_with_src_file.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "my_assert.h"
#include <cstring>
#include <sys/stat.h>
#define DEBUG_SOFT

struct str_ing {
	char * p = nullptr;
	int length_str = 0;
};

void print_buf_in_file (const char * ptr_1, int n_strings, FILE * file_output);
void print_array_in_file (struct str_ing * ptr_1, int n_string, FILE * file_output);
void print_right_left (FILE * file_output);
void print_left_right (FILE * file_output);
void print_src_text   (FILE * file_output);

int  alphabetcomp (const void * str1, const void * str2);
void swap (const void * str1, const void * str2);
int my_strcmp (const char * string1, const char * string2);
int  sort_from_end (const void * srt1, const void * str2);

void filling_struct (struct str_ing * mass_1, char * buf, int n_elem_1);
int  reading_file (char ** buf_elements_1, FILE ** file_output_1, const char * arg_console_1, const char * arg_console_2);
int  correct_buf  (char * buf_elements, int n_elements);

int main (int argc, char * argv[])
{
	FILE * file_output  = nullptr;
	char * buf_elements = nullptr;
	int n_elem    = reading_file (&buf_elements, &file_output, argv[1], argv[2]);
	int n_strings = correct_buf (buf_elements, n_elem);
	struct str_ing * array = (struct str_ing *)calloc (n_strings, sizeof(struct str_ing));
	struct str_ing * ptr   = array;
	
	filling_struct (ptr, buf_elements, n_elem);
	
	print_left_right (file_output);
	qsort (array, n_strings, sizeof(struct str_ing), alphabetcomp);
	print_array_in_file (ptr, n_strings, file_output);
	
	FILE * output_sort_end = fopen (argv[2], "ab+");
	print_right_left (file_output);
	qsort (array, n_strings, sizeof(struct str_ing), sort_from_end);
	print_array_in_file (ptr, n_strings, output_sort_end);
	
	print_buf_in_file (buf_elements, n_strings, output_sort_end);
	
	return 0;
}
 
void print_buf_in_file (const char * ptr_1, int n_strings, FILE * file_output)
{
	print_src_text(file_output);

	fprintf(file_output, "%s\n", ptr_1);
	for (int i = 0; i < n_strings && *ptr_1 != EOF; )
	{
		if (*ptr_1 == '\0')
		{
			fprintf(file_output, "%s\n", ptr_1 = ptr_1+1);
			i++;
		}	
		ptr_1++;
	}
}

void print_array_in_file (struct str_ing * ptr_1, int n_string, FILE * file_output)
{
	for (int i = 0; i < n_string; i++)
	{
		fputs(ptr_1[i].p, file_output);
	}
	fprintf(file_output, "\n");
}

void print_left_right (FILE * file_output)
{
	fprintf(file_output, "\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	fprintf(file_output, "\nSORTING STRING FROM LEFT TO RIGHT\n");
	fprintf(file_output, "\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
}

void print_right_left (FILE * file_output)
{
	fprintf(file_output, "\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	fprintf(file_output, "\nSORTING STRING FROM RIGHT TO LEFT\n");
	fprintf(file_output, "\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
}

void print_src_text (FILE * file_output)
{
	fprintf(file_output, "\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	fprintf(file_output, "\nSOURCE TEXT\n");
	fprintf(file_output, "\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
}

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

void filling_struct (struct str_ing * mass_1, char * buf, int n_elem_1)
{
	mass_1[0].p = buf;
	for (int num_sym = 0, j = 0; num_sym < n_elem_1 && *buf != EOF; num_sym++)
	{
		(mass_1[j].length_str)++;
		if (*buf == '\0')
		{
			mass_1[j+1].p = buf + 1;
			j++;
		}
		buf++;
	}
}

int reading_file (char ** buf_elements_1, FILE ** file_output_1, const char * arg_console_1, const char * arg_console_2)
{
	struct stat file_info;
	FILE * file_input = fopen (arg_console_1, "rb");
	MY_ASSERT (file_input == NULL, "unable to open argv file[1]")
	
	*file_output_1 = fopen (arg_console_2, "wb");
	MY_ASSERT (file_output_1 == NULL, "unable to open argv file[2]");
	
	stat (arg_console_1, &file_info);
	int n_elem = file_info.st_size;
	
	*buf_elements_1 = (char *) calloc (n_elem + 1, sizeof(char));
	MY_ASSERT (*buf_elements_1 == NULL, "Error in allocating memory for saving");	
	(*buf_elements_1)[n_elem] = '\0';
	
	fread (*buf_elements_1, 1, n_elem, file_input);
	
	return n_elem;
}

int correct_buf (char * buf_elements_2, int n_elements)
{
	int n_strings = 0;
	
	for (int i = 0; i < n_elements; i++)
	{
		if (buf_elements_2[i] == '\n')
		{
			buf_elements_2[i] = '\0';
			n_strings++;
		}
	}
	return n_strings+1;
}
