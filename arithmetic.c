//Daily Challenge #135 Easy
//Arithmetic Game
//By Henry Olson
//
//This game is pretty simple: the user starts by entering in a range of numbers and the computer generates a random equation with number in that range. The user then has to
//solve for the answer. The game may be modified to include some statistics.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void main()
{
	int i, min, max, userAnswer, realAnswer, constant[4];
	char operator[3];
	char signs[3]={'*','-','+'};

	srand(time(NULL));

	printf("\nWelcome to EasyArithmetic. Please enter a range of values to play with. One number after the other, separated by a space.\n");
	printf(">");
	
	while(scanf("%d %d", &min, &max)!=2)
	{
		printf("\nRANGE ERROR\n");
	}

	while(1)
	{
		//write four rand numbers in the range
		for(i=0;i<4;i++)
			constant[i]=rand() % (max-min+1) + min;

		//write the rand signs
		for(i=0;i<3;i++)
		{
			operator[i]=signs[rand() % 3];
			//printf("\n%c", operator[i]);
		}

		//calculate the realAnswer
		realAnswer=constant[0];
		for(i=0;i<3;i++)
		{
			if(operator[i]=='*')
				realAnswer*=constant[i+1];
			else if(operator[i]=='-')
				realAnswer-=constant[i+1];
			else
				realAnswer+=constant[i+1];
		}

		printf("%d %c %d %c %d %c %d = ?\n", constant[0], operator[0], constant[1], operator[1], constant[2], operator[2], constant[3]);

		printf(">");

		scanf("%d", &userAnswer);

		if(userAnswer==realAnswer)
			printf("\nCorrect!");
		else
			printf("\nIncorrect!");

		exit(1);
	}

	return;
}

	


