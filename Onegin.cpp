#include <stdlib.h>
#include "print_in_file.h"
#include "work_with_qsort.h"
#include "work_with_src_file.h"

//toLower, toUpper, argc проверить

int main (int argc, char * argv[])
{
	FILE * output  = nullptr; //file_output
	char * buf = nullptr; //buf_elements
	int n_elem    = reading_file (&buf, &output, argv[1], argv[2]);
	int n_strings = correct_buf (buf, n_elem);
//	struct str_ing * array_strings = (struct str_ing *)calloc (n_strings, sizeof(struct str_ing)); //не принято писать в main, проверить calloc
	struct str_ing * array_strings = array_space (n_strings, sizeof(struct str_ing));
//	struct str_ing * ptr   = array_strings; //!
	
	filling_struct (array_strings, buf, n_elem); //ptr

	print_alphabetical_sorting (output);
	qsort (array_strings, n_strings, sizeof(struct str_ing), alphabetcomp);
	print_array_in_file (array_strings, n_strings, output); //ptr
	
	FILE * output_sort_end = fopen (argv[2], "ab+");
	print_rhyming_lines (output);
	qsort (array_strings, n_strings, sizeof(struct str_ing), sort_from_end);
	print_array_in_file (array_strings, n_strings, output_sort_end); //ptr
	
	print_buf_in_file (buf, n_elem, output_sort_end); //fwrite
	
	return 0;
}





