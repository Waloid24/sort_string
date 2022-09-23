//printf in file
#include "print_in_file.h"

#include "work_with_qsort.h"
#include "work_with_src_file.h"

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

