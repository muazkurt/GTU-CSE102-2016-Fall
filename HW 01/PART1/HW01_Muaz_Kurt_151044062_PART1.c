	#include <stdio.h>

/*	This program is taking your grades and 
	
	gives your latter grade. If you give me 
	
	-1 the program stops and returns you the
	
	average number and letter grade.		 */
	
	#define stopNum -1
void letterGradeDetecter(int numGrade)		//This function checks if the grade is A, B, C, D, E or F
{
	if (numGrade >= 90 && numGrade <= 100)	//If the grade is between 90 and 100 its A
		printf("A\n");
	else if (numGrade >= 80)				//If the grade is not A but its bigger than 80 its B
		printf("B\n");
	else if (numGrade >= 70)				//If the grade is not B but its bigger than 70 its C
		printf("C\n");
	else if (numGrade >= 60)				//If the grade is not C but its bigger than 60 its D
		printf("D\n");
	else									//If the grade is not D its F now, Becouse we are 
		printf("F\n");							//not expect any number less than that
	return ;
}
int main()
{
	int numGrade, totalPoint = 0, counter = 0;
	scanf("%d", &numGrade);					//Taking the first input for starting the program
	if (numGrade == -1)							//checking the First value for if its -1
		;												//if it is.
	else												//if its Not
	{
		while (numGrade != stopNum)								//Starting the loop for taking other inputs
		{
			letterGradeDetecter(numGrade);							//detecting the letter grade with early defined function
			totalPoint += numGrade;									//total point adding
			counter++;												//counter adding
			scanf("%d", &numGrade);									//taking the next value
		}
		totalPoint = totalPoint / counter;						//Averaging the total grade with counter
	}
	printf("%d ", totalPoint);					//Printing Average Grade 
	letterGradeDetecter(totalPoint);			//Printing Letter grade of average grade with early defined function
	return 0;
}