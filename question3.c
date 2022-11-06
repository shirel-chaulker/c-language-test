#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning (disable:4996)

int Add(int num)
{
	if (num <= 100)
	{
		printf("%d\n", num);

		return Add(num + 1);
	}
	return 0;
}





int main_1()
{
	Add(1);
}