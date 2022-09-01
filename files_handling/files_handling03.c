/* Programmer: Per Stoor
 * Date: 2022-08-05
 * Last changed: 2022-08-07
 * Type of program: codeforwin's official file handling 3 exercise
 * Sort the numbers in numbers.txt into three new files; even.txt,
 * odd.txt and prime.txt
 *
 * Notes: This program has no output to console.
 * */

#include <stdio.h>
#include <stdlib.h>

#define STRING_LENGTH 50
#define FILE_PATH_NUMBERS "/mnt/c/WSL_Programming/C/codeforwin/files_handling/numbers.txt"
#define FILE_PATH_EVEN "/mnt/c/WSL_Programming/C/codeforwin/files_handling/even.txt"
#define FILE_PATH_ODD "/mnt/c/WSL_Programming/C/codeforwin/files_handling/odd.txt"
#define FILE_PATH_PRIME "/mnt/c/WSL_Programming/C/codeforwin/files_handling/prime.txt"

void add_prime_to_file(int prime_number);
void add_even_to_file(int even_number);
void add_odd_to_file(int odd_number);

int main (int argc, char *argv[]){

	int number_from_file1;
	int prime_flag;
	int loop_counter1;
	int loop_counter2;
	char string_read_from_file[STRING_LENGTH];
	FILE *file_read_numbers;

		file_read_numbers = fopen(FILE_PATH_NUMBERS, "r");
			if(file_read_numbers == NULL){
				printf("Error reading numbers file!\n");
				exit(EXIT_FAILURE);
			}
			
				while((fscanf(file_read_numbers, "%d", &number_from_file1) != - 1)){

					prime_flag = 1;

						for(loop_counter2 = 2; loop_counter2 <= (number_from_file1 / 2); loop_counter2++){
							if(number_from_file1 % loop_counter2 == 0){
								prime_flag = 0;
								break;
							}
						}

							if(prime_flag ==1 && number_from_file1 > 1){
								add_prime_to_file(number_from_file1);
							}
							else if((!(number_from_file1 & 1) == 1)){
								add_even_to_file(number_from_file1);
							}
							else if(((number_from_file1 & 1) == 1)){
								add_odd_to_file(number_from_file1);
							}
							else{
								printf("Error! Found non-prime, non-even or non-odd data.\n");
							}
				}

		fclose(file_read_numbers);

		return 0;
}

void add_prime_to_file(int prime_number){

	FILE *file_write_prime;

		file_write_prime = fopen(FILE_PATH_PRIME, "a+");
			if(file_write_prime == NULL){
				printf("Error opening PRIME file!\n");
				exit(EXIT_FAILURE);
			}

			fprintf(file_write_prime, "%d	", prime_number);

		fclose(file_write_prime);


}

void add_even_to_file(int even_number){

	FILE *file_write_even;
	
		file_write_even = fopen(FILE_PATH_EVEN, "a+");
			if(file_write_even == NULL){
				printf("Error opening EVEN file!\n");
				exit(EXIT_FAILURE);
			}

			fprintf(file_write_even, "%d	", even_number);

		fclose(file_write_even);

}

void add_odd_to_file(int odd_number){

	FILE *file_write_odd; 
	
		file_write_odd = fopen(FILE_PATH_ODD, "a+");
			if(file_write_odd == NULL){
				printf("Error opening ODD file!\n");
				exit(EXIT_FAILURE);
			}

			fprintf(file_write_odd, "%d	", odd_number);

		fclose(file_write_odd);

}
