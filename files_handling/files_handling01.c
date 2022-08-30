/* Programmer: Per Stoor
 * Date: 2022-07-30
 * Last changed: 2022-07-30
 * Type of program: Creating a file, saving some text from the console
 * and closing the file.
 *
 * Notes: This program is functioning as intended.
 * Future updates will be improvements only.
 * */

#include <stdio.h>
#include <stdlib.h>

#define STRING_LENGTH 256
#define FILE_PATH "/mnt/c/WSL_Programming/C/codeforwin/files_handling/files_handling01_generated_file.txt"

void entering_text_lines_to_file();

int main (int argc, char *argv[]){

	entering_text_lines_to_file();

return 0;
}

void entering_text_lines_to_file(){

	int function_loop_counter1;
	int function_loop_ender;
	int line_count_corrector;
	char user_inputted_amount_of_lines[STRING_LENGTH];
	char user_inputted_string[STRING_LENGTH];
	FILE *file_to_write;

		file_to_write = fopen(FILE_PATH, "a+");
			if (file_to_write == NULL){
				printf("Error: Could not open file.\n");
				exit(EXIT_FAILURE);
			}

			printf("Enter how many lines to add: ");
				fgets(user_inputted_amount_of_lines, STRING_LENGTH, stdin);
				sscanf(user_inputted_amount_of_lines, "%d", &function_loop_counter1);
	
			function_loop_ender = 0;
			line_count_corrector = 1;
			while (function_loop_counter1 > function_loop_ender){

				printf("Enter line %d:",(function_loop_counter1 
							- function_loop_counter1 
							+ line_count_corrector));

				fgets(user_inputted_string, STRING_LENGTH, stdin);
				fputs(user_inputted_string, file_to_write);
				function_loop_counter1--;
				line_count_corrector++;  
			}

		fclose(file_to_write);
}
