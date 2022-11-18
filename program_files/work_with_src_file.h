#ifndef WORK_WITH_SRC_FILE_H
#define WORK_WITH_SRC_FILE_H

#include <stdio.h>
#include "my_assert.h"
#include <stdlib.h>
#include <cstring>
#include <sys/stat.h>

void filling_struct (struct line_info * string_arr, char * buf, int n_elem);
int  reading_file (char ** buf, FILE ** output, const char * input_name, const char * output_name);
int  correct_buf  (char * buf, int n_elements);
struct line_info * array_space (int n_strings, size_t size);

#endif
