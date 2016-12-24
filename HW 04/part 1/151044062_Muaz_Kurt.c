#include <stdio.h>
#define MaxforSudoku 9


//User defined Functions:

//Takes the file's data and puts it's (only int values) to the given char array.
void takingIndextoChar(FILE *file_pointer, char onlyNumbers[][MaxforSudoku])
{
	int i, j;
	char temp;
	for (i = 0; i < MaxforSudoku; i++)
	{
		for (j = 0; j < MaxforSudoku; j++)
		{
			fscanf(file_pointer, "%c", &temp);
			if ((int)temp >= '0' && (int)temp <= '9')
				onlyNumbers[i][j] = temp;
			else
				j--;
		}
	}
	return;
}

//Takes a Char array and takes it's index and puts into the int S array.
void charIndextoInt(char Index[][MaxforSudoku], int S[][MaxforSudoku])
{
	int r, c;
	for (r = 0; r < MaxforSudoku; r++)
	{
		for (c = 0; c < MaxforSudoku; c++)
		{
			S[r][c] = (int)Index[r][c] - (int)'0';
		}
	}
	return;
}

//prints Sudoku to the screen.
void printSudoku(int Sudoku[][MaxforSudoku])
{
	int i, j;

	for (i = 0; i < MaxforSudoku; i++)
	{
		for (j = 0; j < MaxforSudoku; j++)
		{
			printf("%d ", Sudoku[i][j]);
		}
		printf("\n");
	}
	return;
}

//User defined Functions end.

//fills the S array with 0.
void init(int S[][MaxforSudoku])
{
	int row, colomn;
	for (row = 0; row < MaxforSudoku; row++)
	{
		for (colomn = 0; colomn < MaxforSudoku; colomn++)
		{
			S[row][colomn] = 0;
		}
	}
	return;
}

//checks if x is legal to put in (r,x) index.
int is_legal(int S[][MaxforSudoku], int r, int c, int x)
{
	int row, colomn,
		errorCounter = 0;
	if (S[r][c] == x ||
		S[r][c] != 0 ||
		x > 9 ||
		x < 0 ||
		r > MaxforSudoku ||
		c > MaxforSudoku ||
		r < 0 ||
		c < 0)
		{
			errorCounter++;
		}

	if (errorCounter == 0)
	{
		for (colomn = 0; colomn < MaxforSudoku && errorCounter == 0; colomn++)
		{
			if (S[r][colomn] == x)
				errorCounter++;
		}
		for (row = 0; row < MaxforSudoku && errorCounter == 0; row++)
		{
			if (S[row][c] == x)
				errorCounter++;
		}
		//Kare Kontrol sistemi ekle
		//0,1,2 - 3,4,5 - 6,7,8	
		for (row = r / 3; (row < (3 * (r/3)) + 3) && errorCounter == 0; row++)
		{
			for (colomn = (c / 3); colomn < (3 * (c/3)) + 3 && errorCounter == 0; colomn++)
			{
				if (S[row][colomn] == x)
					errorCounter++;
			}
		}
	}

	if (errorCounter != 0)
	{
		printf("	####	There is some errors. Check the value.	####\n");
		return 0;
	}
	
	return 1;
}

//Puts x into the (r,c) location.
void place(int S[][MaxforSudoku], int r, int c, int x)
{
	S[r][c] = x;	
	return;
}

//reads sudoku data from file.
void read_from_file(FILE *file_pointer, int S[][MaxforSudoku])
{
	int i, j;
	char IntTochar[MaxforSudoku][MaxforSudoku];
	
	takingIndextoChar(file_pointer, IntTochar);
	charIndextoInt(IntTochar, S);

	printSudoku(S);
	return;
}

//writes updated sudoku data to file.
void write_to_the_file(FILE *file_pointer, int S[][MaxforSudoku])
{
	int row, colomn;
	for (row = 0; row < MaxforSudoku; row++)
	{
		for (colomn = 0; colomn < MaxforSudoku; colomn++)
		{
			fprintf(file_pointer, "%d ", S[row][colomn]);
		}
		fprintf(file_pointer, "\n");
	}
	return;
}


void main()
{
	int S[MaxforSudoku][MaxforSudoku],
		error = 0, errorbefore,
		addresforR, addresforC,
		inputValue;
	FILE *SudokuData, *writingFile;
	SudokuData = fopen("sudoku.txt", "r+");
	writingFile = fopen("SudokuResult.txt", "w");
	init(S);
	//scenario
	read_from_file(SudokuData, S);
	
	//Çözdürmediðim için döngü kurmuyorum hata olduðu anda program bitecek.
	while(error==0)
	{	
		//Sudokuyu çözdürmeyin dendiði için devre dýþý býrakýp sadece input alýyorum.
		
		
		//printf("!!!You have only %d mistake(s) change!!!\n", 3 - error);				
		//printf("!!!Please give me a value and where you want to put it in!!!\n");		
		//printf("		The value: ");		
		scanf("%d", &inputValue);
		
		
		//ayný þekilde burada da sadece deðeri okuyorum.
		
		//printf("			The row value: ");
		scanf("%d", &addresforR);
		
		
		//ayný þekilde burada da sadece deðeri okuyorum.
		
		
		//printf("				The colomn value: ");
		scanf("%d", &addresforC);
		
		
		errorbefore = is_legal(S, addresforR, addresforC, inputValue);
		if (errorbefore == 1)
		{
			place(S, addresforR, addresforC, inputValue);
			printSudoku(S);
		}
		else if (errorbefore == 0)
			error++;
		
	}
	write_to_the_file(writingFile, S);
	return;
}