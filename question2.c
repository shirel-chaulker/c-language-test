#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996) // add pragma

int main_2()
{
	int x = 5;// define the variables x,y 
	int y = 3;
	int nums[6];
	int* arrPtr;


	/* Section A - Print the variables*/
	/* We were request to define x and y,and we dont need puts*/

	printf(" Base = %d\n", x);
	printf(" Height = %d\n", y);
	printf(" Area = %d\n", x * y);

	// Section B - Print the static array "nums".
	// bug- we dont need puts
	
	for (int i = 1;i <= 6;i++)   // bug- syntax errors, we need to using for loop
	{
		printf("%d \n", i); // bug - (nums[i]) print the memory not the value
	}
	/* Section C - Print allocated array.
	 bug- we dont need puts*/

	arrPtr = (int)malloc(sizeof(int) * 6); //bug- the size not match to what are we request, add type casting
	if (!arrPtr) { // bug- if isnt right, the pointer need to be different from null
		printf("Error Allocating Memory!\n");
		exit(1);
		// bug-first we need to check if alloction is Succeeded
	}
	else {

		for (int i = 1; i <= 6; i++) {  // bug- var i isnt define
			printf("%d\n", i);  //bug-arrPtr[i]) print the memory not the value
		}
	}
	
	return 0; // check with debug- the program is working
} // bug- dont have a {