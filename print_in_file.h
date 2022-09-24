#ifndef PRINT_IN_FILE_H
#define PRINT_IN_FILE_H
#include <stdio.h>
#include <stdlib.h>

struct str_ing {
	char * p = nullptr;
	int length_str = 0;
};

void print_buf_in_file (const char * ptr_1, int n_strings, FILE * output);
void print_array_in_file (struct str_ing * ptr_1, int n_string, FILE * output);
void print_rhyming_lines (FILE * output);
void print_alphabetical_sorting (FILE * output);
void print_src_text   (FILE * output);

#endif
