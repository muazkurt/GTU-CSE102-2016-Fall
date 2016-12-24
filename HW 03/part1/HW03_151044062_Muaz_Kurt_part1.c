#include <stdio.h>
#define PI 3.14
double power(double powered, int powerer)
{
	if (powerer == 1)
	{
		return powered;
	}
	else if (powerer > 1)
	{
		powered = (powered) * power(powered, (powerer - 1));
		return powered;
	}
	return -1;
}
int factorial(int num)
{
	if (num == 0 || num == 1)
	{
		return 1;
	}
	else if (num > 1)
	{
		num = num * factorial(num - 1);
		return num;
	}
	return -1;
}


int trueValue(int angle)
{
	if (angle < 0)
	{
		angle = trueValue(angle + 360);
		angle = angle + 360;
		return angle;
	}
	else if (angle >= 0 && angle < 360)
	{
		return angle;
	}
	else if (angle >= 360)
	{
		angle = trueValue(angle - 360);
		return angle;
	}
	return -1;
}


double angletoRadian(int angle)
{
	double radian;
	radian = (trueValue(angle)*PI) / 180;
	return radian;
}

double sin(double x, int counter)
{
	int i;
	double xVariable, totalVariable = 0;
	for (i = 0; i < counter; i++)
	{
		xVariable = (power(x, ((i * 2) + 1)) / factorial((i * 2) + 1));
		if (i % 2 == 0)
			xVariable = xVariable;
		else
			xVariable = -xVariable;
		totalVariable = totalVariable + xVariable ;
	}
	return totalVariable;
}

int part1(void)
{
	int angleX, termsTobeUsed, a, b;
	double radianX;
	printf("Give me the angle: ");
	a = scanf("%d", &angleX);
	if (a != 1)
		return -1;
	radianX = angletoRadian(angleX);
	printf("Give me the terma: ");
	b = scanf("%d", &termsTobeUsed);
	if (b != 1)
		return -1;
	printf("Sin(%d) = %f", angleX, sin(radianX, termsTobeUsed));
	return 0;
}







void main()
{
	part1();
	return;
}