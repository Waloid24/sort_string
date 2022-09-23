#ifndef PRINT_IN_FILE_H
#define PRINT_IN_FILE_H
#include <stdio.h>

struct str_ing {
	char * p = nullptr;
	int length_str = 0;
};

void print_buf_in_file (const char * ptr_1, int n_strings, FILE * file_output);
void print_array_in_file (struct str_ing * ptr_1, int n_string, FILE * file_output);
void print_right_left (FILE * file_output);
void print_left_right (FILE * file_output);
void print_src_text   (FILE * file_output);

#endif
