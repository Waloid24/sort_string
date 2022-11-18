#include <stdlib.h>
#include "print_in_file.h"
#include "work_with_qsort.h"
#include "work_with_src_file.h"

int main (int argc, char * argv[])
{
	if (argc != 3)
	{
		printf ("Please enter the source file first and the output file second.\n");
		printf ("For example: \"./a.out Hamlet.txt Output.txt\"\n");
		return -1;
	}

	FILE * output  = nullptr;
	char * buf = nullptr;
	int n_elem    = reading_file (&buf, &output, argv[1], argv[2]);
	int n_strings = correct_buf (buf, n_elem);
	printf ("Number of strings = %d\n", n_strings);
	struct line_info * array_strings = array_space (n_strings, sizeof(struct line_info));

	filling_struct (array_strings, buf, n_elem);

	print_alphabetical_sorting (output);
	qsort (array_strings, n_strings, sizeof(struct line_info), alphabetcomp);
	print_array_in_file (array_strings, n_strings, output);

	print_rhyming_lines (output);
	qsort (array_strings, n_strings, sizeof(struct line_info), sort_from_end);
	print_array_in_file (array_strings, n_strings, output);

	print_buf_in_file (buf, n_strings, output);

	return 0;
}





