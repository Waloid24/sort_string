#ifndef MY_ASSERT_H
#define MY_ASSERT_H

#include <stdio.h>

#ifdef MY_ASSERT
	#undef MY_ASSERT
#endif

////do while (0) обернуть if в это. Ограничивает область видимости перемнной. Использовать во всех больших DEFINE
//#if 0
//#define ASSIGN int x = 5
//
//int main () {
//
//	ASSIGN; // int x = 5;
//	do {
//		int x = 5;
//	} while (0);
//	int x = 0;
//
//}
//
//#define MY_DEF(cond) \
//	do {
//	
//		if (cond) printf ("Hallo\n");
//		int i = 0;
//		for (; i <10; ++i) ...
//	
//	} while (0)
//
//MY_DEF(true);
//#endif


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