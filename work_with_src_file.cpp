//work with source file
#include "work_with_qsort.h"
#include "print_in_file.h"
#include "my_assert.h"
#include <cstring>
#include <sys/stat.h>
#define DEBUG_SOFT


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