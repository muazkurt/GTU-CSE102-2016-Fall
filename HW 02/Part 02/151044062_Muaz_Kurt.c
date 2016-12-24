#include <stdio.h>
#include <math.h>




/*

		Sorry for my mistake(s)
			i worked on this for 9 hours
			but there is still some problems in it.
		The program calculates the polynomials and writes their result
			in a .txt document.
		
		I identified one mistake but didnt solved it. In the example date if we take
		the last result 20, polynomial doesnt work. Takes other data "0" and calculates
		the polynomial with it.


*/
void main()
{
	FILE *input, *output;
	int line, degree, coefficients;
	int isPossitive, x, total, degreeCounter = 0, counter;
	input = fopen("updated_polynomial.txt", "r");
	output = fopen("Polynomial_Sonuc.txt", "w");
	isPossitive = fscanf(input, "%ld", &degree);
	degreeCounter = degree + 1;
	if (isPossitive == 0)
		printf("!ERROR!");
	else
	{
		for (line = 0;
			isPossitive == 1 || isPossitive==2;
			line++)
			{
			total = 0;
			fseek(input, 2*(degree+2)  , SEEK_CUR);
			fscanf(input, "%ld", &x);
			fseek(input, -(2*(degree) -3), SEEK_CUR);
			
			if (line > 0)
				fseek(input, -(2*line), SEEK_CUR);			
			
			for (counter = 0; counter <= degree; counter++)
			{
				fscanf(input, " %ld", &coefficients);
				total = total + (coefficients* pow(x, degree - counter));
			}
			isPossitive= fscanf(input, "%d%d", &x, &degree);
			degreeCounter += degree + 1;
			fprintf(output, "Line %d= P(%d) = %d\n", line, x, total);
			}
	}
	return;
}