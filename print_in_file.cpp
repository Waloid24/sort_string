
//printf in file
#include "print_in_file.h"
#include "work_with_qsort.h"
#include "work_with_src_file.h"

void print_buf_in_file (const char * ptr_1, int n_elem, FILE * output)
{
//	print_src_text (output);
//	
//	fprintf (output, "%s\n", ptr_1);
//	for (int i = 0; i < n_strings && *ptr_1 != EOF; )
//	{
//		if (*ptr_1 == '\0')
//		{
//			fprintf (output, "%s\n", ptr_1 = ptr_1+1);
//			i++;
//		}	
//		ptr_1++;
//	} //fwrite!

	fwrite ((const char *)ptr_1, n_elem, 1, output);
}

void print_array_in_file (struct str_ing * ptr_1, int n_string, FILE * output)
{
	for (int i = 0; i < n_string; i++)
	{
		fputs(ptr_1[i].p, output);
	}
	fprintf(output, "\n");
}

void print_alphabetical_sorting (FILE * output) 
{
	fprintf(output, "\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	fprintf(output, "\nALPHABETICAL SORTING\n");
	fprintf(output, "\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
}

void print_rhyming_lines (FILE * output)
{
	fprintf(output, "\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	fprintf(output, "\nRHYMING LINES\n");
	fprintf(output, "\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
}

void print_src_text (FILE * output)
{
	fprintf(output, "\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	fprintf(output, "\nSOURCE TEXT\n"); //?
	fprintf(output, "\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
}

