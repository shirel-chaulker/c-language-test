#include <stdio.h>
#include <stdlib.h>   
#include <string.h> // bug-add a libary
#pragma warning(disable:4996)// syntax errors- first we write the libary


// struct to collect counting info about english letters found in a text file.
typedef struct letter {
	char small;
	char big;
	int counter;
	letter* prev;
	letter* next;
}letter; 



//Function to free linked list
void freeList(letter* head) {
	letter* releaseItem;
	letter* runItem = head;
	while (runItem != NULL) {
		releaseItem = runItem;
		runItem = runItem->next;
		free(releaseItem);
	}
}

int main()
{
	//Next two string represents all the english alphabets (small and capital)
	char* smallAlpha = "abcdefghijklmnopqrstuvwxyz";
	char* bigAlpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int lettersCountArr[26] = { 0 }; // change the size of array
	char readChar, ch;

	FILE* f;
	f = fopen("myFile.txt", "r");
	if (!f) // syntax errors- need to check if the is open
	{
		printf("the file not open");
	}
	// Display the content of myFile.txt and count letters
	 // syntax errors- printf not in the place
	else // bug- add else to the function 
	{
		// bug- need to take char from the to variable
		readChar = fgetc(f);
		printf("%c", readChar);
		while (readChar != EOF) { // syntax errors- the loop need to run until the end of file
			
			readChar = fgetc(f);
			printf("%c", readChar);

		}
	}
	
	printf("the content of myFile.txt :\n");
		while ((readChar = fgetc(f)) != EOF) { // syntax errors- the loop need to run until the end of file
			printf("%c", readChar);
			for (int i = 0; i < strlen(smallAlpha); ++i) {
				if (readChar == smallAlpha[i] || readChar == bigAlpha[i]) {

					lettersCountArr[i]++;

				}

			}
		}
	
	fclose(f);


	// Build Linked list from file content
		// Every node represent English letter (small and big).
	letter* HEAD = NULL;
	letter* TAIL = NULL;
	for (int j = 0; j < strlen(smallAlpha);++j) {
		letter* letterItem = (letter*)malloc(sizeof(letter));
		if (!letterItem) {
			printf("Error Allocating Memory!");
			exit(1);
		}
		letterItem->small = smallAlpha[j];// bug-change to fit all array
		letterItem->big = bigAlpha[j];
		letterItem->counter = lettersCountArr[j];
		// Creating the linked list

		if (HEAD == NULL) //bug- fix linked list
		{
			HEAD = letterItem;
			TAIL = letterItem;
			letterItem->prev = NULL;
			letterItem->next = NULL;
		}
		else
		{
			TAIL->next = letterItem;
			letterItem->prev = TAIL;
			TAIL = letterItem;
			letterItem->next = NULL;

		}
		
	}
	return 0;
}
	
	