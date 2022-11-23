// Author: Rambod Azimi
// Student ID: 260911967
// COMP 206 / Mini 5 / Winter 2022

#include <stdio.h>

// Externs
extern int loadCSV();
extern int addRecord();
extern int findRecord();
extern int saveCSV();
extern int listRecords();

// Function prototype
int menu();

int exist; // global variable to check existence of phonebook.csv file

int main(){

	// we must load the CSV file into array before displaying the menu to the user
	exist = loadCSV(); // if the CSV file exists, return 1. Ow, return 0. return 2 if the size of the array is 10

	menu(); // displaying the menu to the user

return 0;

} // end of main function

int menu(){


	// display the menu unless Quit is selected
	while(1){

		printf("Phonebook Menu: (1)Add, (2)Find, (3)List, (4)Quit>");

		int userInput;
		scanf("%d", &userInput);

		// if Quit is selected, terminate the while loop and overwrite the CSV file
		if(userInput == 4){
			printf("End of phonebook program\n");
			saveCSV(); // overwrite content of the array to the csv file
			break;
		}

		// Add
		if(userInput == 1){
			if(exist == 2){ // if array is full
				printf("No more space in the CSV file.\n");
			}else{ // if there is space to add more
				exist = 1;
				char name[50];
				char birthdate[12];
				char phone[15];
				char temp;

				// getting the required fields from the user
				printf("Name: ");
				scanf("%c", &temp);
				scanf("%[^\n]", name);

				printf("Birth: ");
				scanf("%s", birthdate);

				printf("Phone: ");
				scanf("%s", phone);

				// calling the function in mini6phone.c file
				int result = addRecord(name, birthdate, phone);
			}
		}

		// Find
		if(userInput == 2){
			if(exist == 0){ // if csv file does not exist
				printf("Phonebook.csv does not exist\n");
			} else{ // if file exists
				char name[50];
				printf("Find name: ");
				char temp;
				scanf("%c", &temp);
				scanf("%[^\n]", name); // getting the name from the user
				int result = findRecord(name); // 1 if found. 0 if not found
				if(result == 0){
					printf("Does not exist\n");
				}
			}
		}

		// List of all friends
		if(userInput == 3){
			if(exist == 0){ // if csv file does not exist
				printf("Phonebook.csv does not exist\n");
			} else{ // if file exists
				listRecords();	
			}
		}

	} // end of while loop

	return 0;

} // end of menu function
