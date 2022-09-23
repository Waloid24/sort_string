//#pragma once

#ifndef MY_ASSERT_H
#define MY_ASSERT_H

#include <stdio.h>
#include <math.h>

#include "print_in_file.h"
#include "work_with_qsort.h"
#include "work_with_src_file.h"

#ifdef MY_ASSERT
	#undef MY_ASSERT
#endif

#ifndef DEBUG_SOFT
	#ifndef NDEBUG
		#define MY_ASSERT(instruction, message) \
		if (instruction)\
		{\
			printf ("\v " #message "\n\n");\
			printf ("An error occurred in the file: %s \n\n"\
					"In line:                       %d \n\n"\
					"In function:                   %s \n\n",\
					__FILE__, __LINE__, __PRETTY_FUNCTION__);\
			abort();\
		}			
	#endif
#endif

#ifdef DEBUG_SOFT
	#define MY_ASSERT(instruction, message)\
		if(instruction)\
		{\
			printf ("\v " #message "\n\n");\
			printf ("An error occurred in the file: %s \n\n"\
					"In line:                       %d \n\n"\
					"In function:                   %s \n\n",\
					__FILE__, __LINE__, __PRETTY_FUNCTION__);\
		}			
#endif

#ifdef NDEBUG 
	#define MY_ASSERT(instruction, message)
#endif

#endif