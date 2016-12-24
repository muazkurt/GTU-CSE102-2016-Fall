#include <stdio.h>
//This program is for a calculator

void main()
{
	int firstNum, secNum=0;							//Defining the variables, first is taking the first value anyway, secound takes the value in the loop 'if it can get in'
	char Operator;									//Defining the char whitch takes the calculation operators from user.
	scanf("%d%c", &firstNum, &Operator);			//Taking the first value to first variable and taking the first operator.
	while (Operator != '=')							//Designing and defining the while loop according to Operator character is not equal to =
	{
		scanf("%d", &secNum);							//Taking the secound value in the loop
		switch (Operator)								//Switching the statement according to Operator. Possibiltys are " +, -, *, /"
		{
		case '+':											//In the situation of '+'
			firstNum = firstNum + secNum;						//Summing first value and secound value, and casting it to first value. Becouse its not change any more
			break;
		case '-':					
			firstNum = firstNum - secNum;						
			break;
		case '*':
			firstNum = firstNum*secNum;
			break;
		case '/':
			firstNum = firstNum / secNum;
		default:
			break;
		}
		scanf("%c", &Operator);							//Taking other Operator to make possible cancelling the loop and making other calculations
	}
	printf("%d\n", firstNum);						//Printing the result
}