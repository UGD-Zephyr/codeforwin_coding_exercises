/* Programmer: Per Stoor
 * Date: 2022-07-30
 * Last changed: 2022-07-31
 * Type of Program: Reading a file and displaying
 * the contents to the console.
 *
 * Notes: There are two ways to read from a file: 
 * 1: Read every individual character, one by one.
 * 2: Read every line one by one.
 *
 * Nr. 1 is straightforward but nr. 2 has different outcomes depending
 * on '\0', EOF or '\n' terminators and care has to be taken.
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LENGTH 256
#define FILE_PATH "/mnt/c/WSL_Programming/C/codeforwin/files_handling/files_handling01_generated_file.txt"

int main (int argc, char *argv[]){

	int loop_counter1;
	char file_string[STRING_LENGTH];
	char total_string_length;
	char character_from_file;
	FILE *file_to_read;

	file_to_read = fopen(FILE_PATH, "r");
		if (file_to_read == NULL){
			printf("Error: Can not open file!\n");
			exit(EXIT_FAILURE);
		}

		/*
		 * This one works!
		loop_counter1 = 0;
		while (character_from_file != EOF){
			character_from_file = fgetc(file_to_read);
			putchar(character_from_file);
			loop_counter1++;
		}
		*/

		
		// The while-loop statement is the tricky one
		// for this part.
		loop_counter1 = 0;
		while (fgets(file_string, STRING_LENGTH, file_to_read) != NULL){
			total_string_length = strlen(file_string);

			if (file_string[total_string_length - 1] == '\n'){
				file_string[total_string_length - 1] == '\0';
			}
			else {
				file_string[total_string_length - 1] == file_string[total_string_length - 1];
			}
			printf("%s", file_string);
			loop_counter1++;
		}
		

	fclose(file_to_read);
return 0;
}
