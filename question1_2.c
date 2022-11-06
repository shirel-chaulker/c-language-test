#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#pragma warning(disable:4996)



int main() {

	char str[100];

	printf("Enter a string : ");
	gets(str);

	printf("You entered: %s", str);
	int len = strlen(str) / 2;
	char str2[50];
	char str3[50];

	for (int i = 0; i < len; i++) {
		str2[i] = str[i];
	}

	str2[len] = NULL;
	printf("You entered: %s\n", str2);
	for (int s = 0; s < len; s++) {
		str3[s] = str[len + s];
	}
	str3[len] = NULL;
	printf("You entered: %s\n", str3);


	strcpy(str2, str);
	while (len > 0)
	{


		for (int s = 0; s < len; s++) {
			str3[s] = str2[s];

		}

		str3[len] = NULL;
		strcpy(str2, str3);
		printf("You entered: %s\n", str3);
		len = len / 2;

	}
	
	return 0;
}



