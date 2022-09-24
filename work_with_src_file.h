#ifndef WORK_WITH_SRC_FILE_H
#define WORK_WITH_SRC_FILE_H
#include <stdio.h>
#include "my_assert.h"
#include <stdlib.h>
#include <cstring>
#include <sys/stat.h>
#define DEBUG_SOFT

void filling_struct (struct str_ing * mass_1, char * buf, int n_elem_1);
int  reading_file (char ** buf_elements_1, FILE ** file_output_1, const char * arg_console_1, const char * arg_console_2);
int  correct_buf  (char * buf_elements, int n_elements);

#endif
