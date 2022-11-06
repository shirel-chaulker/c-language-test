#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning (disable:4996)

char str[10000] = "";
typedef struct lotto {
	int lotteryNumber;
	char date[20];
	struct lotto* next;
	struct lotto* prev;
}t_lotto;

t_lotto* head;
t_lotto* tail;

void add(char* num)
{
     t_lotto* currentItem;
	currentItem = (t_lotto*)malloc(sizeof(t_lotto));
	if (currentItem == NULL)
	{
		printf("error");
		return;
	}
	else
	{
		char* token = strtok(num, ",");


		currentItem->lotteryNumber = atoi(token);
	  token = strtok(NULL, ",");
		strcpy(currentItem->date, token);


		if (head == NULL)
		{

			head = currentItem;
			tail = currentItem;
			currentItem->next = NULL;
			currentItem->prev = NULL;
		}
		else
		{
			
			tail->next = currentItem;
			currentItem->prev = tail;
			currentItem->next = NULL;
			tail = currentItem;
		}
	}
	printf("%s %d\n", currentItem->date, currentItem->lotteryNumber);
}




t_lotto* search(int key)
{
	t_lotto* move = head;
	t_lotto* searching = NULL;


	while (move != NULL)
	{
		searching = move;
		

		if (searching->lotteryNumber == key)
		{
			printf("the date of the lottery number is: %s", searching->date);
			return searching;
		}

		else
		{
			printf("searching  was not found");
			return NULL;
		}
		move = move->next;

	}
	
}

int main_2()
{
	FILE* f = fopen("lotto.txt", "r");
	if (!f) {
		printf("error");
		return;
	}
	char str[10000] = "";
	fgets(str, 10000, f);



	while (fgets(str, 10000, f))
	{

		add(str);


	}
	fclose(f);


	    char userResponse[5]={0};
		int lottoNumber;
		printf("Please enter the letter N to pick which lottery number or Q to exit from program\n");
        scanf("%c", userResponse);
	
		if (strcmp(userResponse,"N")==0)
		{
			scanf("%d", &lottoNumber);
			search(lottoNumber);
		}
		else
		{
			printf("quit from the program");
		}
	
	
}