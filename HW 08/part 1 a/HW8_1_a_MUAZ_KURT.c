#include <stdio.h>
int binMaker(int toint)
{
	int total = 0, temp = toint % 2;
	if (toint == 1 || toint == 0)
		total = toint;
	else if (toint > 1) 
		total = 10 * binMaker(toint / 2) + (toint % 2);
	return total;
}
void main()
{
	int value;
	do
	{
		scanf("%d", &value);
		if (value >= 0)
			printf("The binary representation of \"%d\" is %d.\n", value, binMaker(value));
		else
			;
	} while (value >= 0);
	return;
}