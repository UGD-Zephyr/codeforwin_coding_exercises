/* Programmer: Per Stoor
 * Date: 2022-07-31
 * Last changed: 2022-08-5
 * Type of program: Input even, odd or prime numbers
 * from the console and save to different .txt files
 * depending on the input.
 * 
 * Notes: This is slightly different then the codeforwins
 * website asked for.
 *
 * It creates the prime.txt file, but it stores all the 
 * numbers there and doesn't create any other files...
 *
 * Progress! all files are being created, the sorting of
 * the numbers is a bit off still...
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LENGTH 256
#define FILE_PATH_PRIME "/mnt/c/WSL_Programming/C/codeforwin/files_handling/files_handling03_prime.txt"
#define FILE_PATH_EVEN "/mnt/c/WSL_Programming/C/codeforwin/files_handling/files_handling03_even.txt"
#define FILE_PATH_ODD "/mnt/c/WSL_Programming/C/codeforwin/files_handling/files_handling03_odd.txt"

void print_prime_numbers();
int file_open_prime(int prime_number);
int file_open_even(int even_number);
int file_open_odd(int odd_number);

int main (int argc, char *argv[]){
	
	int user_inputted_number;
	int prime_flag;
	int loop_counter1;
	int loop_counter2;
	int strcmp_value;
	char user_inputted_string[STRING_LENGTH];
	char menu_exit_string[STRING_LENGTH] = {'q','u','i','t','\n'}; // to make sure strcmp evaluates to 0, 
								       // we have to add a '\n' character here.

		printf("Please enter a number('quit' to quit):");
		fgets(user_inputted_string, STRING_LENGTH, stdin);
		sscanf(user_inputted_string, "%d", &user_inputted_number);

		while (strcmp(user_inputted_string, menu_exit_string) != 0){
		
			for (loop_counter1 = 2; loop_counter1 <= user_inputted_number; loop_counter1++){	
				prime_flag = 1;

				for(loop_counter2 = 2; loop_counter2 <= (user_inputted_number / 2); loop_counter2++){


					if((user_inputted_number % loop_counter2) == 0){
						prime_flag = 0;
						break;
					}
				}
			}
			
			

					if((prime_flag == 1 && user_inputted_number > 1) ){
						file_open_prime(user_inputted_number);
					}
					else if((prime_flag == 0) && (user_inputted_number % 2 == 0)){
						file_open_even(user_inputted_number);
					}
					else if((prime_flag == 0) && (user_inputted_number % 2 != 0)){
						file_open_odd(user_inputted_number);
					}
			
			

						printf("Please enter a number ('quit' to quit):");
						fgets(user_inputted_string, STRING_LENGTH, stdin);
						sscanf(user_inputted_string, "%d", &user_inputted_number);
		}
return 0;
}

void print_prime_numbers(){

	int function_loop_counter1;
	int function_loop_counter2;
	
		for(function_loop_counter1 = 2; function_loop_counter1 <= 1000; function_loop_counter1++){
			for(function_loop_counter2 = 2; function_loop_counter1 - 1; function_loop_counter2++){
				if(function_loop_counter1 % function_loop_counter2 == 0){
					break;
				}
			}
			if (function_loop_counter2 == function_loop_counter1){
				printf("%d  ", function_loop_counter1); 
			}
		}
}

int file_open_prime(int prime_number){

	FILE *file_to_open_prime;
	
	file_to_open_prime = fopen(FILE_PATH_PRIME, "a+");
	fprintf(file_to_open_prime, "%d\n", prime_number);
	fclose(file_to_open_prime);
}

int file_open_even(int even_number){
	FILE *file_to_open_even;
	
	file_to_open_even = fopen(FILE_PATH_EVEN, "a+");
	fprintf(file_to_open_even, "%d\n", even_number);
	fclose(file_to_open_even);
}

int file_open_odd(int odd_number){
	FILE *file_to_open_odd;
	
	file_to_open_odd = fopen(FILE_PATH_ODD, "a+");
	fprintf(file_to_open_odd, "%d\n", odd_number);
	fclose(file_to_open_odd);
}
