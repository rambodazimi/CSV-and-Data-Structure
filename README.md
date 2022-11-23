# CSV-and-Data-Structure
A program written in C

Description:

Write a C program that is complied using makefile and uses a CSV file as a database. This program will keep a database of friends, their birthdates, and their phone numbers. You will be able to add friends to the database, find friends in the database, and list all your friends. The database filename is phonebook.csv, the program source filenames are mini6main.c and mini6phone.c, and is compiled into the executable filename phonebook.

Example execution:

     $ rm phonebook.csv
     
     $ make
     
     $ ./phonebook
     
     Phonebook Menu: (1)Add, (2)Find, (3)List, (4)Quit> 3
     
     Phonebook.csv does not exist
     
     Phonebook Menu: (1)Add, (2)Find, (3)List, (4)Quit> 1
     
     Name: Bob Smith
     
     Birth: 2000-01-15
     
     Phone: 514-333-4444
     
     Phonebook Menu: (1)Add, (2)Find, (3)List, (4)Quit> 1
     
     Name: Mary Zhang
     
     Birth: 1999-05-20
     
     Phone: 1-234-567-1234
     
     Phonebook Menu: (1)Add, (2)Find, (3)List, (4)Quit> 3
     
     ----NAME--------- ------BIRTH------ -----PHONE-------
     
     Bob Smith         2000-01-15          514-333-4444
     
     Mary Zhang        1999-05-20        1-234-567-1234
     
     Phonebook Menu: (1)Add, (2)Find, (3)List, (4)Quit> 2
     
     Find name: Mary Zhang
     
     ----NAME--------- ------BIRTH------ -----PHONE-------
     
     Mary Zhang        1999-05-20        1-234-567-1234
     
     Phonebook Menu: (1)Add, (2)Find, (3)List, (4)Quit> 2
     
     Fine name: Tom Bombadil
     
     Does not exist
     
     Phonebook Menu: (1)Add, (2)Find, (3)List, (4)Quit> 4
     
     End of phonebook program
     
     $
     
<H4>The CSV File</h4>

a CSV file is a Comma Separated Vector text file. Each row of the text file contains information about a single record, and would look like the following given our example execution above:

     Name,birthdate,phone
     
     Bob Smith,2000-01-15,514-333-4444
     
     Mary Zhang,1999-05-20,1-234-567-1234
     
Your program must be able to handle the case when the phonebook.csv file exists and does not exist at the beginning of the execution of the program. Notice in our sample execution the CSV did not exist at the beginning. The program displayed an error message. This should be the case for all the menu options.

<h4>The Data Structure</h4>

Your program must use the following array to store the information from the CSV file:

     struct PHONE_RECORD {
     
        char name[50];
        
        char birthdate[12];
        
        char phone[15];
        
     } phonebook[10];
     
The array is loaded with the data from the CSV file before the menu is displayed. If the CSV file does not exist, no error message is displayed at this time. You will need a way to remember that nothing is in the array. The error message is displayed when the user selects a menu option that needs to get information from the data structure. The error message is not displayed when the user adds a new friend, however if the array is full, then selecting add will display the error message “No more space in the CSV file.”

When the user selects the Quit option from the menu, then the contents of the array must overwrite the CSV file before the program terminates. The TA must be able to type cat phonebook.csv to verify that the information is correct.

If the program is restarted without deleting the previous CSV file, then the information from the CSV file will be loaded into the data structure and can be queried again with the program.

<h4>The makefile</h4>

The makefile must compile the two source files of this assignment into the executable. You will use modular programming. This means that the file mini6main.c only contains the main() function and the menu() function. The file mini6phone.c contains the data structure and the functions addRecord(), findRecord(), listRecords(), loadCSV(), save CSV(). You are permitted to add helper functions. You will need to use the command extern to share information between the two source files.

To make your source files into modular files you will need to compile them separately and then link them together. You must do that using the makefile, but you can also do it by hand. I show it by hand here so that you understand what is going on:

To make each file modular, do:

 gcc -c mini6.main.c
 
     gcc -c mini6phone.c
     
Two files have been created, assuming no errors while compiling: mini6main.o and mini6phone.o. These are the two modular files.

We now must link them together to create the a.out program. Do the following: gcc mini6main.o mini6phone.o

You will now see an a.out program in your directory. You could have used the -o switch with gcc to rename the a.out file.

The format of the two modular files would look something like the following: 

File: mini6main.c

  #include files

  extern data structure // so that main can display output for findRecord()

  int menu() {}// to display the prompt and return the input

  int main() {} // loops until 4 selected, call mini6phone.c functions

  File: mini6phone.c

  #include files

The data structure

  int loadCSV() {}// return errorcode, otherwise load data structure

  int saveCSV() {} // return errorcode, otherwise save data structure

  int addRecord() {} // return errorcode, otherwise add a new phone entry int findRecord() {} // return errorcode, otherwise return index of found int 

  listRecords() {} // return errorcode, otherwise displays pretty all

You must pass parameters to the functions. The parameters are not shown in the above code. It will be up to you to implement it.
