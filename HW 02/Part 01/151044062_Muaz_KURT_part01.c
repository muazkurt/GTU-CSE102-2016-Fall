#include <stdio.h>

int Draw_Triangle(int starting_point, int length, int layer_type, int k)
{
	int i, StartingSpaces, SpacesinTriangle, StarsinTriangle;

	for (i = 0; i < length; i++)//satýr sayýsý
	{
		for (StartingSpaces = 0; StartingSpaces < starting_point; StartingSpaces++)
		{
			printf(" ");// burasý tamamen boþluklar için
		}
		for (SpacesinTriangle = length - (i + 1); SpacesinTriangle > 0; SpacesinTriangle--)
		{
			switch (layer_type)
			{
			case 1:
				printf(" ");
				break;
			case 2:
				printf("  ");
				break;
			default:
				break;
			}
		}
		for (StarsinTriangle = (2 * i) + 1; StarsinTriangle > 0; StarsinTriangle--)
		{
			if ((StarsinTriangle == 1 && k > 0)|| StarsinTriangle == (2 * i) + 1 || i == length - 1)
			{
				switch (layer_type)
				{
				case 1:
					printf("*");
					break;
				case 2:
					printf("**");
					break;
				default:
					break;
				}
			}
			else
			{
				switch (layer_type)
				{
				case 1:
					printf(" ");
					break;
				case 2:
					printf("  ");
					break;
				default:
					break;
				}
			}
		}
		printf("\n");
	}
	return 0;
}

int Draw_Rectangle(int starting_point, int length, int width, int layer_type)
{
	int lineCounter, startingSpaces, widthCounter;
	if (layer_type == 2)
		length *= 2;
	for (lineCounter = 0; lineCounter < length; lineCounter++)
	{
		for (startingSpaces = 0; startingSpaces < starting_point; startingSpaces++)
		{
			printf(" ");
		}
		for (widthCounter = 0; widthCounter < width; widthCounter++)
		{
			if (
				(layer_type == 2 && (
				(lineCounter == 0 || lineCounter == 1) ||
					(lineCounter == (length - 1) || lineCounter == (length - 2))
					)
					)
				||
				(lineCounter == 0 || lineCounter == (length - 1))
				||
				(widthCounter == 0 || widthCounter == (width - 1))
				)
			{
				switch (layer_type)
				{
				case 1:
					printf("*");
					break;
				case 2:
					printf("**");
					break;
				default:
					break;
				}
			}
			else
			{
				switch (layer_type)
				{
				case 1:
					printf(" ");
					break;
				case 2:
					printf("  ");
					break;
				default:
					break;
				}
			}
		}
		printf("\n\a");
	}








	return 0;
}

//			SOME
//		   MISTAKES
int Draw_Circle(int center, int radius, int layer_type)
{
	int temp, lines, spacesTillStar, centerE, spacesInside;
	centerE = center;
	temp = ((center * 2) - 2);

	//			SOME
	//		   MISTAKES



	for (lines = 0; lines < (center * 2) - 1; lines++)
	{
		for (spacesTillStar = 0; spacesTillStar < centerE; spacesTillStar++)
		{
			switch (layer_type)
			{
			case 1:
				printf(" ");
				break;
			case 2:
				printf("  ");
			default:
				break;
			}
		}

		//Tepe yýldýzý
		if (lines == 0)
		{
			switch (layer_type)
			{
			case 1:
				printf("*");
				break;
			case 2:
				printf("**");
			default:
				break;
			}
			centerE -= 1;
		}

		//Ayak yýldýzý
		else if (lines == temp)
		{
			switch (layer_type)
			{
			case 1:
				printf("  ");
				printf("*");
				break;
			case 2:
				printf("    ");
				printf("**");
			default:
				break;
			}
		}

		//1. kat
		if (lines == 1 || lines == (temp - 1))
		{
			switch (layer_type)
			{
			case 1:
				printf("*   *");
				break;
			case 2:
				printf("**     **");
				break;
			default:
				break;
			}
		}

		//2. kat
		if (lines == 2 || lines == (temp - 2))
		{
			switch (layer_type)
			{
			case 1:
				printf("*     *");
				break;
			case 2:
				printf("**         **");
				break;
			default:
				break;
			}
		}

		//Orta kesim
		if (lines == center - 1)
		{
			for (spacesTillStar = 0; spacesTillStar < (center + 2 - lines); spacesTillStar++)
			{
				switch (layer_type)
				{
				case 1:
					printf(" ");
					break;
				case 2:
					printf("  ");
				default:
					break;
				}
			}
			switch (layer_type)
			{
			case 1:
				printf("*");
				for (spacesInside = 0; spacesInside < radius + 3; spacesInside++)
				{
					printf(" ");
				}
				printf("*");
				break;
			case 2:
				printf("**");
				for (spacesInside = 0; spacesInside< radius + 3; spacesInside++)
				{
					printf("  ");
				}
				printf("**");
				break;
			default:
				break;
			}
		}


		if (lines < center - 1)
			centerE -= 1;
		else if (lines >= center - 1 && lines != temp - 1)
			centerE += 1;
		printf("\n");
	}



	return 0;
}
//			SOME
//		   MISTAKES

void printTriangle(int start, int length, int layer, int much)
{
	int i;
	for (i = 0; i < much; ++i)
		Draw_Triangle(start, length, layer, i);
	Draw_Rectangle(start + (length / 2) + 1, much, length / 2, layer);
	return;
}

void main()
{
	int a = 0, b = 0, c = 0;
	printf("Please give me an int number for starting point \n*****Cigdem Hanim*****\n");
	scanf("%d", &a);
	printf("Please an int for length of pine tree\n****Hello Cigdem****\n");
	scanf("%d", &b);
	printf("One more step please. Thank you for waiting...\n\t I need an integer again\n***Have fun Cigdem***\n");
	scanf("%d", &c);
	printTriangle(a, b, 1, c);
	getch();
	return;
}