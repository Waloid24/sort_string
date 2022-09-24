//#include <stdlib.h>
#include "print_in_file.h"
#include "work_with_qsort.h"
#include "work_with_src_file.h"

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





