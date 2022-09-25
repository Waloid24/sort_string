#include <stdlib.h>
#include "print_in_file.h"
#include "work_with_qsort.h"
#include "work_with_src_file.h"
#define DEBUG_SOFT

int main (int argc, char * argv[])
{
	MY_ASSERT (argc != 3, "Too many files in command line");
	
	FILE * output  = nullptr;
	char * buf = nullptr;
	int n_elem    = reading_file (&buf, &output, argv[1], argv[2]);
	int n_strings = correct_buf (buf, n_elem);
	struct str_ing * array_strings = array_space (n_strings, sizeof(struct str_ing));
	
	filling_struct (array_strings, buf, n_elem);
	
	print_alphabetical_sorting (output);
	qsort (array_strings, n_strings, sizeof(struct str_ing), alphabetcomp);
	print_array_in_file (array_strings, n_strings, output);
	
	FILE * output_sort_end = fopen (argv[2], "ab+");
	print_rhyming_lines (output);
	qsort (array_strings, n_strings, sizeof(struct str_ing), sort_from_end);
	print_array_in_file (array_strings, n_strings, output_sort_end);
	
	correct_buf_for_fwrite (buf, n_elem); //нужно, так как внутри print_buf_in_file не получится из-за конфликта const char * и char * в ф-ии fwrite
	print_buf_in_file (buf, n_elem, output_sort_end);
	
	fclose (output);
	free (buf);
	
	return 0;
}





