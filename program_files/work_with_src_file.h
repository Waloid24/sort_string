#ifndef WORK_WITH_SRC_FILE_H
#define WORK_WITH_SRC_FILE_H

#include <stdio.h>
#include "my_assert.h"
#include <stdlib.h>
#include <cstring>
#include <sys/stat.h>
#define  DEBUG_SOFT

void filling_struct (struct str_ing * string_arr, char * buf, int n_elem);
int  reading_file (char ** buf, FILE ** output, const char * input_name, const char * output_name);
int  correct_buf  (char * buf, int n_elements);
struct str_ing * array_space (int n_strings, size_t size);

#endif
