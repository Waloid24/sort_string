#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t my_getline (char** dest_adr, int * size, FILE * stream);
void sort_strings (char * mass_of_pointer_to_strings[], int counter);
void print_array_in_file (char ** array, int number_of_strings, FILE * ptr_output_file);
int read_file (char ** buffer_1, FILE ** ptr_output_file_1);
int split_into_lines (char ** buffer_1, int number_of_successfully_read_elements_fread);
char ** sorting_array (char ** mass_1, int number_of_successfully_read_elements_fread, int number_of_strings, char ** buffer_1);

const int STANDART_SIZE = 10;