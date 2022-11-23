// Author: Rambod Azimi
// Student ID: 260911967
// COMP 206 / Mini 5 / Winter 2022

#include <stdio.h>
#include <string.h>

// creating a struct which has 3 strings as variables (name, dob, and phone number)
struct PHONE_RECORD {
	char name[50];
	char birthdate[12];
	char phone[15];
}phonebook[10];	// this array can hold up to 10 instances of PHONE_RECORD struct


int size;

int loadCSV(){ // if the file exists, return 1. Ow, return 0
	
	// opening the file	
	FILE *file = fopen("phonebook.csv" , "rt");

	if(file){ // if file exists, return 1
		
		char array[100];

		fgets(array, 100, file); //ignore the first line, which is a header

		int index = 0;
		size = 0;
		int stopLoading = 0;

		while(fgets(array, 100, file) != NULL){ // reads an entire line from the csv file
			
			// now it's time to save each entry into corresponding phonebook[] array
			char *token;
			token = strtok(array, ",");
			index = 0;
			while(token != NULL){

				if(size < 30){

				if(index % 3 == 0){ // it means the token is a name
					strcpy(phonebook[size].name, token);
					
				}else if(index % 3 == 1){ // it means the token is a dirthdate
					strcpy(phonebook[size].birthdate, token);
					
				}else{ // it means the token is phone
					strcpy(phonebook[size].phone, token);
				}
				size++;
				index++;
				token = strtok(NULL, ",");
			} else{ // if size >= 30
				return 2;
			}
			}
		}
		fclose(file); // closing the file
		return 1;
	} // if file does not exist, return 0
	return 0;
}

int saveCSV(){ // overwrite the content of the array into the csv file
	FILE *file = fopen("phonebook.csv", "wt"); // opening the file
	for(int i = 0 ; i < size/3; i++){ // iterate through all the indices of the array
		fprintf(file, "%s", phonebook[3*i].name);
		fprintf(file, ",");
		fprintf(file, "%s", phonebook[(3*i)+1].birthdate);
		fprintf(file, ",");
		fprintf(file, "%s", phonebook[(3*i)+2].phone);
		fprintf(file, "\n");
	}
	fclose(file); // closing the file
	return 0;
}

int addRecord(char name[], char birthdate[], char phone[]){
	if(size >= 30){
		printf("No more space in the CSV file.\n");
		return 0; // it fails to add due to full array
	}else{ // the array have empty cells to add more data
		strcpy(phonebook[size].name, name);
		strcpy(phonebook[size+1].birthdate, birthdate);
		strcpy(phonebook[size+2].phone, phone);
		size+=3;
	}	
	return 1;
}

int findRecord(char name[]){
	for(int i = 0 ; i < size/3 ; i++){ // iterate through all the words in the csv file and search for the name
		if(strcmp(name, phonebook[3*i].name) == 0){ // 0 means they are equal
			printf("----NAME--------- ------BIRTH------ -----PHONE-------\n");
			printf("%s        %s        %s\n", phonebook[3*i].name, phonebook[(3*i)+1].birthdate, phonebook[(3*i)+2].phone);
			return 1;
		}
	}
	return 0; // failed to find any data with the name
}

int listRecords(){
	printf("----NAME--------- ------BIRTH------ -----PHONE-------\n");
	for(int i = 0 ; i < size/3 ; i++){ // iterate through all indices of the array and print the proper fields
		printf("%s         %s         %s\n", phonebook[3*i].name, phonebook[(3*i)+1].birthdate, phonebook[(3*i)+2].phone);
	}
	return 0;
}
