#include "required_file.h"

int main (void)
{	
	char * buffer = nullptr;
	FILE * ptr_output_file = nullptr;
	
	int number_of_successfully_read_elements_fread = read_file (&buffer, &ptr_output_file);
	int number_of_strings = split_into_lines (&buffer, number_of_successfully_read_elements_fread);
	
	char ** mass = (char **) calloc (number_of_strings, sizeof(char *));
	
	mass = sorting_array (mass, number_of_successfully_read_elements_fread, number_of_strings, &buffer);
	
	sort_strings (mass, number_of_strings);
	
	print_array_in_file (mass, number_of_strings, ptr_output_file);

	free (buffer);
	
	return 0;	
}

void sort_strings (char * mass_of_pointer_to_strings[], int counter)
{
	char * temp = nullptr;
	for (int i = 0; i < counter - 1; i++)
		for (int j = i + 1; j < counter; j++)
			if (strcmp(mass_of_pointer_to_strings[i], mass_of_pointer_to_strings[j]) > 0)
			{
				temp = mass_of_pointer_to_strings[i];
				mass_of_pointer_to_strings[i] = mass_of_pointer_to_strings[j];
				mass_of_pointer_to_strings[j] = temp;
			}
}

void print_array_in_file (char ** array, int number_of_strings, FILE * ptr_output_file)
{
	for (int i = 0; i < number_of_strings; i++)
	{
		fputs (*array, ptr_output_file);
		array++;
	}
}

int read_file (char ** buffer_1, FILE ** ptr_output_file_1)
{
	FILE * ptr_file = fopen ("Hamlet.txt", "rb");
	*ptr_output_file_1 = fopen ("Output.txt", "wb");
		
	if (ptr_file == NULL)
	{
		printf("Reading file \"Hamlet.txt\" error.\n");
		return -1;
	}
	if (*ptr_output_file_1 == NULL)
	{
		printf("Reading file \"Output.txt\" error.\n");
		return -3;
	}
	
	fseek (ptr_file, 0, SEEK_END);
	long int size_of_file_in_bytes = ftell (ptr_file); 
	fseek (ptr_file, 0, SEEK_SET);
	long int number_of_elements = size_of_file_in_bytes / (sizeof(char));
	
	*buffer_1 = (char *) calloc (number_of_elements + 1, sizeof(char));
	
	if (*buffer_1 == NULL)
	{
		printf("It is impossible to allocate memory for a file.\n");
		exit(1);
	}
	
	size_t number_of_successfully_read_elements_fread = fread (*buffer_1, sizeof(char), number_of_elements, ptr_file);
	(*buffer_1)[number_of_elements] = '\0';
	
	if (number_of_successfully_read_elements_fread != number_of_elements)
	{
		printf("Reading error.\n");
		exit(2);
	}
	
	return number_of_successfully_read_elements_fread;
}

int split_into_lines (char ** buffer_1, int number_of_successfully_read_elements_fread)
{
	long int number_of_strings = 1;
	
	for (int i = 0; i < number_of_successfully_read_elements_fread; i++)
	{
		if ((*buffer_1)[i] == '\n')
		{
			(*buffer_1)[i] = '\0';
			number_of_strings++;
		}	
	}
	
	return number_of_strings;
}

char ** sorting_array (char ** mass_1, int number_of_successfully_read_elements_fread, int number_of_strings, char ** buffer_1)
{
	*mass_1 = &((*buffer_1)[0]);
	mass_1++;	
	
	for (int i = 0, j = 1; i < number_of_successfully_read_elements_fread, j < number_of_strings; i++)
	{
		if ((*buffer_1)[i] == '\0')
		{
			*mass_1 = &((*buffer_1)[i+1]);
			mass_1++;
			j++;
		}
	}
	return mass_1 - number_of_strings;
}