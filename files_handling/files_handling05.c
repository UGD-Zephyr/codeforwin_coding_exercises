/* Programmer: Per Stoor
 * Date: 2022-08-07
 * Last changed: 2022-08-08
 * Type of program: Comparing two text files.
 *
 * Notes: I can get the line that mismatches.
 * I am still trying to figure out how to get
 * the program to show me what character is 
 * mismatched...
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LENGTH 256
#define FILE_PATH_COMPARE1 "/mnt/c/WSL_Programming/C/codeforwin/files_handling/compare1.txt"
#define FILE_PATH_COMPARE2 "/mnt/c/WSL_Programming/C/codeforwin/files_handling/compare2.txt"

int main(int argc, char *argv[]){

	int loop_counter1;
	int loop_counter2;
	char compare1_string[STRING_LENGTH];
	char compare2_string[STRING_LENGTH];
	char character_compare1;
	char character_compare2;
	FILE *file_compare1_to_read;
	FILE *file_compare2_to_read;

		file_compare1_to_read = fopen(FILE_PATH_COMPARE1, "r");
			if(file_compare1_to_read == NULL){
				printf("Error opening file!\n");
				exit(EXIT_FAILURE);
			}
		file_compare2_to_read = fopen(FILE_PATH_COMPARE2, "r");
			if(file_compare1_to_read == NULL){
				printf("Error opening file!\n");
				exit(EXIT_FAILURE);
			}

			loop_counter1 = 1;
			loop_counter2 = 1;
			while(  fgets(compare1_string, STRING_LENGTH, file_compare1_to_read) != NULL &&
				fgets(compare2_string, STRING_LENGTH, file_compare2_to_read) != NULL ){
					
					/*
					 * I tried a double loop, but loop_counter2 isn't
					 * incrementing properly...
					 * */
					while(  compare1_string[loop_counter2] != '\0' && 
						compare2_string[loop_counter2] != '\0'){
							character_compare2 = compare1_string[loop_counter2];
							character_compare2 = compare2_string[loop_counter2];		
							if (character_compare1 != character_compare2){
								printf("Mismatch on character %d\n", loop_counter2);
								break;
							}
							else{
								loop_counter2++;
							}
					}

					 if(strcmp(compare1_string, compare2_string) == 0){
						 loop_counter1++;
					 }
					 else if(strcmp(compare1_string, compare2_string) != 0){
						 printf("Files do not match.\n");
						 printf("Mismatch on line %d.\n", loop_counter1);
						 break;
					 }
			}
		
		fclose(file_compare1_to_read);
		fclose(file_compare2_to_read);

return 0;
}
