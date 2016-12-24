#include <stdio.h>
#define MaxN 10

int find( char puzzle[][MaxN], int row, int colomn, char orientation, char *word)
{
	int i, j = 0, errorC=0;
	switch (orientation)
	{
		case 'R':
		case 'r':
			for(i = colomn; i > 0 && word[j] != 0; i--)
			{
				if(word[j]!=puzzle[row][i])
					errorC++;
				j++;
			}
			break;
		case 'l':	
		case 'L':
			for(i = colomn; i < MaxN && word[j] != 0; i++)
			{
				if(word[j]!=puzzle[row][i])
					errorC++;
				j++;
			}
			break;
		case 'T':
		case 't':
			for(i = row; i < MaxN && word[j] != 0; i++)
			{
				if(word[j]!=puzzle[i][colomn])
					errorC++;
				j++;
			}
			break;
		case 'B':
		case 'b':
			for(i = row; i < MaxN && word[j] != 0; i++)
			{
				if(word[j]!=puzzle[i][colomn])
					errorC++;
				j++;
			}
			break;
		default:
			return -1;
			break;
	}

	if( errorC>0)
		return 0;
	return 1;
}

void main()
{
	char puzzle[MaxN][MaxN];
	int row, colomn, i, j;
	char ori;
	char word[MaxN];
	


	return;
}