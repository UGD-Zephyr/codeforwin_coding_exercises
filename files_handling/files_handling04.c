/* Programmer: Per Stoor
 * Date: 2022-08-07
 * Last changed: 2022-08-07
 * Type of program: Append string to already existing file.
 * */

#include <stdio.h>
#include <stdlib.h>

#define STRING_LENGTH 256 
#define FILE_PATH "/mnt/c/WSL_Programming/C/codeforwin/files_handling/files_handling04_file_string.txt"

int main (int argc, char *argv[]){

	char string_from_file[STRING_LENGTH];
	char user_inputted_string[STRING_LENGTH];
	FILE *append_to_file;

	
	append_to_file = fopen(FILE_PATH, "r");
		if(append_to_file == NULL){
			printf("Error opening file!\n");
			exit(EXIT_FAILURE);
		}

	printf("SOURCE FILE CONTENT:");
	printf("\n");
	printf("--------------------");
	printf("\n");

		while((fgets(string_from_file, STRING_LENGTH, append_to_file) != NULL)){
			printf("%s", string_from_file);
		}

	append_to_file = freopen(FILE_PATH, "a", append_to_file);
		if(append_to_file == NULL){
			printf("Error opening file!\n");
			exit(EXIT_FAILURE);
		}

	printf("\n");
	printf("STRING TO APPEND:");
	printf("\n");
	printf("-----------------");
	printf("\n");
	fgets(user_inputted_string, STRING_LENGTH, stdin);
	fprintf(append_to_file, "%s", user_inputted_string);

	append_to_file = freopen(FILE_PATH, "r", append_to_file);
		if(append_to_file == NULL){
			printf("Error opening file!\n");
			exit(EXIT_FAILURE);
		}

	printf("\n");
	printf("OUTPUT FILE CONTENT AFTER APPENDING STRING:");
	printf("\n");
	printf("-------------------------------------------");
	printf("\n");
		while((fgets(string_from_file, STRING_LENGTH, append_to_file) != NULL)){
			printf("%s", string_from_file);
		}

	fclose(append_to_file);

return 0;
