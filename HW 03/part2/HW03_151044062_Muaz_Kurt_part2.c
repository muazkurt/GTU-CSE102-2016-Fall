 #include <stdio.h>
#define PI 3.14
//only for part2 . Tek dosya olması gerektiğini son dakika gördüm. CTRL+C, CTRL+V
#include <math.h>
#define waitingMax 15
double power(double powered, int powerer)
{
	if (powerer == 1)
	{
		return powered;
	}
	else if (powerer > 1)
	{
		powered = (powered)* power(powered, (powerer - 1));
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

double sinus(double x, int counter)
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
		totalVariable = totalVariable + xVariable;
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
	printf("Sin(%d) = %f", angleX, sinus(radianX, termsTobeUsed));
	return 0;
}






//' . , e, l, o, g, n, x, (, ), s, i, c, t, a, sayılar, ^, /, - ' işaretleri olması durumuna göre tekrar düzenler.
int duzenleme(char arr[])
{
	int i, count = 0;
	for (i = 0; i < waitingMax; i++)
	{
		if (
			((int)arr[i] <= '9' && (int)arr[i] >= '0')
			|| arr[i] == 'e' || arr[i] == 'E'
			|| arr[i] == '.' || arr[i] == '/'
			|| arr[i] == '(' || arr[i] == ')'
			|| arr[i] == 'l' || arr[i] == 'L'
			|| arr[i] == 'o' || arr[i] == 'O'
			|| arr[i] == 'g' || arr[i] == 'G'
			|| arr[i] == 'n' || arr[i] == 'N'
			|| arr[i] == 'x' || arr[i] == 'X'
			|| arr[i] == 's' || arr[i] == 'S'
			|| arr[i] == 'i' || arr[i] == 'I'
			|| arr[i] == 'c' || arr[i] == 'C'
			|| arr[i] == 't' || arr[i] == 'T'
			|| arr[i] == 'a' || arr[i] == 'A'
			|| arr[i] == '^' || arr[i] == '/'
			|| arr[i] == '-'
			)
		{
			arr[count] = arr[i];
			count++;
		}
		else
			;
	}
	return count;
}

//Sadece katsayıyıyı alan array. Katsayı alınacak array ve bunların yazılacağı array gerekir. Kaç basamaklı olduğu return olur.
int katSayi(char alinan[], char yazilan[])
{
	int i, count = 0;
	for (i = 0; i < waitingMax; i++)
	{
		if ((int)alinan[i] <= '9' && (int)alinan[i] >= '0')
		{
			yazilan[count] = alinan[i];
			count++;
		}
		else if (alinan[i] == '.')
			return count;
	}
	return 0;
}


//Array içine verilen int valueden başlayarak '1' '/' 'x' yazar. Return value 3 tür.
int OIX(char arr[], int i)
{
	arr[i] = '1';
	arr[i+1] = '/';
	arr[i+2] = '(';
	arr[i + 3] = 'x';
	arr[i + 4] = ')';
	return 5;
}

//Verilen array içeriğini int yapar ve o sayıyı return eder. Array ve eleman sayısı gereklidir.
int makingInt(char arr[], int count)
{
	int total = 0, chartoInt, i, negative = 0;
	for (i = 0; i < count; i++)
	{
		if (arr[i] == '-')
		{
			negative = 1;
		}
		else
		{
			chartoInt = (int)(arr[i] - 48);
			total = total + chartoInt*pow(10, count - (i + 1));
		}
	}
	if (negative == 1)
	{
		return -total;
	}
	return total;
}


//Verilen array ekrana basılır. Array ve Eleman sayısı gereklidir.
void printingArray(char arr[], int counter)
{
	int i;
	for (i = 0; i < counter; i++)
		printf("%c ", arr[i]);
	return;
}


//Verilen sayıyı verilen array içerisine yazar. Sayı ve kullanılacak array gereklidir.
void makingArr(int number, char arr[])
{
	int i = 0;
	for (i = 0; number >= 10; i++)
	{
		arr[i] = number % 10;
		number /= 10;
	}
	if (number< 10 && number >= 0)
	{
		arr[i] = (char)(number + 48);
	}
	else if (number < 0)
	{
		arr[i] = '-';
		number = (-number);
		i++;
		for (i = 1; number >= 10; i++)
		{
			arr[i] = number % 10;
			number /= 10;
		}
		if (number < 10)
		{
			arr[i] = (char)(number + 48);
		}
	}
	return;
}


//Array içerisindeki kesirli sayıyı 1 eksiltir.
//	Pay arrayi ve eleman sayısı, payda arrayi ve eleman sayısı gereklidir.
void calcfrac(char first[], int countF, char sec[], int countS)
{
	int up, down;
	up = makingInt(first, countF);
	down = makingInt(sec, countS);
	up -= (down*up);
	makingArr(up, first);
	makingArr(down, sec);
}


//			Array içerisinde olan verileri kontrol ederek neyin türevinin alınacağını belirler.
//						İçerisinde elemanlar olan bir array gereklidir.
//	Constant			=			0
//	Line				=			1
//	power				=			2
//	Square root			=			3
//	Exponental			=			4
//	Ln(x)				=			5
//	loga(x)				=			6
//	sin(x)				=			7
//	cos(x)				=			8
//	tan(x)				=			9
//	sin-1(x)			=			10
//	cos-1(x)			=			11
//	tan-1(x)			=			12
int detectingWhich(char arr[])													//Neyin türevi olacak öğrenmek
{
	int i, xCount = 0;
	for (i = 0; i < waitingMax; i++)
	{
		if (arr[i] == 'x')
			xCount += 1;
	}
	if (xCount != 0)
	{
		for (i = 0; i < waitingMax; i++)
		{
			if (arr[i] == '^')													//üstel durumlar 2, 3, 4.
			{
				for (i += 1; i < waitingMax; i++)
				{
					if ((int)arr[i] >= (int)'0' && (int)arr[i] <= (int)'9')		//üzeri sayıysa
					{
						for (i += 1; i < waitingMax; i++)
						{
							if (arr[i] == '/')									//sayıdan sonra kesir varsa
							{
								return 3;										//	mesela karekök!
							}
						}
						return 2;
					}
					else if (arr[i] == 'x')										//sayı üzeri x olması durumu!
					{
						return 4;
					}
				}
			}
			else if (arr[i] == 'l')												//logaritma kısmı 5, 6.
			{
				for (i += 1; i < waitingMax; i++)
				{
					if (arr[i] == 'n')			//Ln... kısmı
						return 5;
					else if (arr[i] == 'o')		//lo... kısmı
						return 6;
				}
			}
			else if (arr[i] == 's')												//sinüslü şeyler 7, 10
			{
				for (i += 1; i < waitingMax; i++)								//sin^-1(x)
				{
					if (arr[i] == '^')
					{
						return 10;
					}
				}
				return 7;														//sin(x)
			}
			else if (arr[i] == 'c')												//cosinüslü şeyler 8, 11
			{
				for (i += 1; i < waitingMax; i++)								//cos^-1(x) , 11
				{
					if (arr[i] == '^')
					{
						return 11;
					}
				}
				return 8;														//cos(x) , 8
			}
			else if (arr[i] == 't')												//tanjantlı şeyler 9, 12
			{
				for (i += 1; i < waitingMax; i++)								//tan^-1(x) , 12
				{
					if (arr[i] == '^')
					{
						return 12;
					}
				}
				return 9;														//tan(x) , 9
			}
		}
		return 1;																//sadece katsayı olursa
	}
	else if (xCount == 0)														//constant kısmı	0
	{
		return 0;
	}
	return -1;																	//error durumu
}


//X^1 fonksiyon için çalışır. DetectingWitch fonksiyonu değeri 1 dir.
double lineDerivative(char arr[], int varX)												
{
	int i, y = 0, katsayim;
	for (i = 0; arr[i] != 'x'; i++)												//x' in katsayısını bulma
	{
		if ((int)arr[i] >= (int)'0' && (int)arr[i] <= '9')						//bulunan her katsayıyı array 
		{
			arr[y] = arr[i];													//	elemanı olarak sıralama
			y++;
		}
	}
	katsayim = makingInt(arr, y);
	if (y == 0)																	//eğer katsayı yoksa
	{	
		arr[y] = '1';															//	tek eleman olarak 1 atamak
		y++;
	}
	for (i = 0; i < y; i++)												//ekrana basmak
	{
		printf("%c ", arr[i]);
	}
	return katsayim;
}


//X^a fonksiyonları için çalışır. DetectingWitch fonksiyon değeri 2 dir. (a kesirli olmamalı) Türevli hali döner
double powerDerivative(char arr[], int varX)
{
	int i, y = 0, temp, ycount, alt;
	double result;
	char newarray[waitingMax];
	for (i = 0; i < waitingMax; i++)											//içerik kontrolü
	{
		if (arr[i] == '^')														//üst e çıktı hadi hayırlısı
		{
			for (i += 1; i < waitingMax; i++)									// üstte neler var acaba
			{
				if ((int)arr[i] >= '0' && (int)arr[i] <= (int)'9')				//sayılar varsa bi başa alalım
				{
					arr[y] = arr[i];											//başa sayılar
					y++;														// nerde kaldık?
				}
			}
		}
	}
	ycount = y;
	arr[y] = 'x';
	y += 1;
	arr[y] = '^';
	y += 1;
	temp = makingInt(arr, ycount);
	alt = temp;
	temp--;	
	makingArr(temp, newarray);
	ycount = y;
	for (i = 0; i < ycount; i++)
	{
		arr[y] = newarray[i];
		y += 1;
	}
	for (i = 0; i < y; i++)												//ekrana basmak
	{
		printf("%c ", arr[i]);
	}
	result = (alt)*(pow(varX, temp));
	return result;
}


//X^a/b türü fonksiyonlar için çalışır. DetectingWitch fonksiyon değeri 3 tür. (b!=0) Türevli hali döner.
double squareRootDerivative(char arr[], int variableX)
{
	int i,
		y = 0,
		payC = 0, 
		kehkeh = 0,
		q=0, 
		kacSayi,
		katsayisi,
		variables;
	double result,ust, alt;
	
	//klasik sayaaç
	
	char pay[waitingMax], payda[waitingMax], katsayilar[waitingMax];								//Kesirli sayıların tutulacağı pay / payda
	
	variables = duzenleme(arr);
	kacSayi = katSayi(arr, katsayilar);
	katsayisi = makingInt(katsayilar, kacSayi);
	for (i = 0; arr[i] < '^'; i++)
	{
		;														//üst  işareti bulma
	}
	for (i += 1; arr[i] < '/'; i++)													//pay bulma
	{
		if ((int)arr[i] >= (int) '0' && (int)arr[i] <= (int)'9')						//pay
		{
			pay[payC] = arr[i];															//pay arr içine sayıları atma
			payC++;																			//pay counter arttırma
		}
	}
	for (i += 1; i < variables; i++)										//payda bulma
	{
		if ((int)arr[i] >= (int) '0' && (int)arr[i] <= (int)'9')
		{
			payda[kehkeh] = arr[i];														//payda array içine payda yazma
			kehkeh++;
		}
	}
	
	for (i = 0; arr[i-1] < '^'; i++)
	{
		if (i < payC && y <payC)
		{
			arr[i] = pay[i];
			y++;
		}
		if (y >= payC && q<kehkeh)
		{
			arr[i] = payda[q];
			q++;
		}
		else
		{
			arr[i] = 'x';
			i++;
			arr[i] = '^';
		}
	}
	alt = makingInt(pay, payC) / makingInt(payda, kehkeh);
	ust = alt - 1.0;
	q = 0;
	calcfrac(pay, payC, payda, kehkeh);										//yukarıda tanımladığım fonksiyon ile kesirli sayı hesabı
	if (pay[0] == '-')
	{
		for (i += 1; i < payC + 1; i++)											//üst olan payı girmek
		{
			arr[i] = pay[q];
			q++;
		}
	}
	else if (pay[0] != '-')
	{
		for (i += 1; i < payC ; i++)											//üst olan payı girmek
		{
			arr[i] = pay[q];
			q++;
		}
	}
	arr[i] = '/';
	i++;
	q = 0;
	for (i += 1; q < kehkeh; i++)											//üst olan paydayı girmek
	{
		arr[i] = payda[q];
		q++;
	}
	printingArray(arr, i);
	if(kacSayi==0)
		result = (alt)*pow(variableX, ust);
	else if (kacSayi>0)
	{
		result = katsayisi*(alt)*pow(variableX, ust);
	}
	return result;
}


//e^x ya da a^x için çalışır. DetectingWitch fonksiyon değeri 4 tür.
//Sıkıntılar var.
void exponentalDerivative(char arr[])
{
	int i, a, arrayCounter = 0, powerCounter = 0, e = 0;
	char power[waitingMax], kat[waitingMax] ;
	for (i = 0; i < waitingMax; i++)
	{
		if ((int)arr[i] <= '9' && (int)arr[i] >= '0')
		{
			arr[arrayCounter] = arr[i];
			arrayCounter++;
		}
		else if (arr[i] == 'e' || arr[i] == 'E')
		{
			arr[arrayCounter] = arr[i];
			arrayCounter++;
			e = 1;
		}
		else if (arr[i] == '^')
		{

			powerCounter = katSayi(&arr[i + 1], power);
		}
	}
	a = arrayCounter-2;
	if (e == 1 && powerCounter == 0)
	{
		arr[arrayCounter] = '^';
		arrayCounter++;
		arr[arrayCounter] = 'x';
		arrayCounter++;
	}
	if (e == 0 && powerCounter == 0)
	{
		arr[arrayCounter] = 'l';
		arrayCounter++;
		arr[arrayCounter] = 'n';
		arrayCounter++;
		arr[arrayCounter] = '(';
		arrayCounter++;
		for (i = 0; i < a; i++)
		{
			arr[arrayCounter] = arr[i];
		}
	}

	else if (powerCounter > 0)
	{
		makingInt(power, powerCounter);

	}

	printingArray(arr, arrayCounter);
	return;
}


//Ln(x) || a. ln(x) türü fonksiyonlar için çalışır. DetectingWitch fonksiyon değeri 5 tir. Türevli hali döner
double lnDerivative(char arr[], int valueX)
{
	int i = 0, variables = 0, kacSayi = 0, katsayisi;
	double result;
	char katsayiarr[waitingMax];
	variables = duzenleme(arr);
	kacSayi = katSayi(arr, katsayiarr);
	if (kacSayi == 0)
	{
		i += OIX(arr, 0);
		printingArray(arr, i);
		result = 1 / valueX;
		printf("\n%lf", result);
		return result;
	}
	else if (kacSayi > 0)
	{
		for (i = 0; i < kacSayi; i++)
		{
			arr[i] = katsayiarr[i];
		}
		katsayisi = makingInt(katsayiarr, kacSayi);
		arr[kacSayi] = '.';
		kacSayi++;
		kacSayi += OIX(arr, kacSayi);
		printingArray(arr, kacSayi);
		printf("\n");
		result = katsayisi*(1 / valueX);
		return result;
	}
	return 0;
}


//loga(x) türü fonksiyonlar için çalışır. DetectingWitch fonksiyon değeri 6' dır. (a!=1) Türevli hali döner.
double logDerivative(char arr[], int valueX)
{
	int i = 0, c = 0, kacSayi = 0, variables = 0, x = 0, valueLog, katsayisi;
	double result;
	char katsayiarr[waitingMax], alttaKalan[waitingMax];
	variables = duzenleme(arr);
	kacSayi = katSayi(arr, katsayiarr);
	if (kacSayi == 0)
	{	
		for (c = 3; c < variables - 3; c++)
		{
			alttaKalan[x] = arr[c];
			x++;
		}
		valueLog = makingInt(alttaKalan, x);
		i = OIX(arr,0);
		i -= 1;
		arr[i] = '.';
		i++;
		arr[i] = 'l';
		i++;
		arr[i] = 'n';
		i++;
		arr[i] = '(';
		i++;
		for (c = 0 ; c < x; c++)
		{
			arr[i] = alttaKalan[c];
			i++;
		}
		arr[i-1] = ')';
		printingArray(arr, i);
		result = 1 / (valueX*log(valueLog));
		printf("\n%f", result);
		return result;
	}
	else if (kacSayi > 0)
	{
		for (c = kacSayi+4; c < variables - 3; c++)
		{
			alttaKalan[x] = arr[c];
			x++;
		}
		valueLog = makingInt(alttaKalan, c);
		for (i = 0; i < kacSayi; i++)
		{
			arr[i] = katsayiarr[i];
		}
		katsayisi = makingInt(katsayiarr, kacSayi);
		arr[i] = '.';
		i++;
		i += OIX(arr, i);
		i -= 1;
		arr[i] = '.';
		i++;
		arr[i] = 'l';
		i++;
		arr[i] = 'n';
		i++;
		arr[i] = '(';
		i++;
		for (c = 0; c < x; c++)
		{
			arr[i] = alttaKalan[c];
			i++;
		}
		arr[i - 1] = ')';
		printingArray(arr, i);
		result = katsayisi / (valueX*log(valueLog));
		return result;
	}
	return 0;
}



double sinDerivative(char arr[], int varX)
{
	int i = 0,
		c = 0,
		kacSayi = 0,
		variables = 0,
		katsayisi;
	double result;
	char katsayilar[waitingMax];
	
	variables = duzenleme(arr);
	kacSayi = katSayi(arr, katsayilar);
	katsayisi = makingInt(katsayilar, kacSayi);
	if (kacSayi == 0)
	{
		arr[i] = 'c';
		i++;
		arr[i] = 'o';
		i++;
		arr[i] = 's';
		i++;
		arr[i] = '(';
		i++;
		arr[i] = 'x';
		i++;
		arr[i] = ')';
		i++;
		result = cos(varX);
	}
	else if (kacSayi > 0)
	{
		for (i = 0; i < kacSayi; i++)
		{
			arr[i] = katsayilar[i];
		}
		arr[i] = '.';
		i++;
		arr[i] = 'c';
		i++;
		arr[i] = 'o';
		i++;
		arr[i] = 's';
		i++;
		arr[i] = '(';
		i++;
		arr[i] = 'x';
		i++;
		arr[i] = ')';
		i++;
		result = katsayisi*cos(varX);
	}
	printingArray(arr, i);
	return result;
}



double cosDerivative(char arr[], int varX)
{
	int i = 0, 
		c, 
		kacSayi = 0,
		variables = 0,
		katsayisi;
	double result;
	
	char katsayilar[waitingMax];
	
	
	variables = duzenleme(arr);
	kacSayi = katSayi(arr, katsayilar);
	katsayisi = makingInt(katsayilar, kacSayi);
	arr[i] = '-';
	i++;
	if (kacSayi == 0)
	{
		arr[i] = 's';
		i++;
		arr[i] = 'i';
		i++;
		arr[i] = 'n';
		i++;
		arr[i] = '(';
		i++;
		arr[i] = 'x';
		i++;
		arr[i] = ')';
		i++;
		result = -sin(varX);
	}
	else if (kacSayi > 0)
	{
		for (c=0; c < kacSayi; c++)
		{
			arr[i] = katsayilar[c];
			i++;
		}
		arr[i] = '.';
		i++;
		arr[i] = 's';
		i++;
		arr[i] = 'i';
		i++;
		arr[i] = 'n';
		i++;
		arr[i] = '(';
		i++;
		arr[i] = 'x';
		i++;
		arr[i] = ')';
		i++;
		result = katsayisi*(-sin(varX));
	}
	printingArray(arr, i);
	return result;
}


double tanDerivative(char arr[], int varX)
{
		int i = 0,
			c,
			kacSayi = 0,
			variables = 0,
			katsayisi;
		double result;

		char katsayilar[waitingMax];
		
		variables = duzenleme(arr);
		kacSayi = katSayi(arr, katsayilar);
		katsayisi = makingInt(katsayilar, kacSayi);
		if (kacSayi > 0)
		{
			for (c = 0; c < kacSayi; c++)
			{
				arr[i] = katsayilar[c];
				i++;
			}
			arr[i] = '.';
			i++;
			result = katsayisi*pow(1 / cos(varX), 2);
		}
		else if (kacSayi == 0)
			result = pow(1 / cos(varX), 2);
		arr[i] = 's';
		i++;
		arr[i] = 'e';
		i++;
		arr[i] = 'c';
		i++;
		arr[i] = '^';
		i++;
		arr[i] = '2';
		i++;
		arr[i] = '(';
		i++;
		arr[i] = 'x';
		i++;
		arr[i] = ')';
		i++;
		printingArray(arr, i);
	return result;
}



double sinNDerivative(char arr[], int varX)
{
	int i = 0, c, kacSayi = 0, variables = 0, katsayisi;
	double result;
	char katsayilar[waitingMax];
	variables = duzenleme(arr);
	kacSayi = katSayi(arr, katsayilar);
	katsayisi = makingInt(katsayilar, kacSayi);
	if (kacSayi > 0)
	{
		for (c = 0; c < kacSayi; c++)
		{
			arr[i] = katsayilar[c];
			i++;
		}
		arr[i] = '.';
		i++;
		result = katsayisi*(1 / pow((1 - pow(varX, 2)), (1 / 2)));
	}
	else if(kacSayi==0)
		result = 1 / pow((1 - pow(varX, 2)), (1 / 2));
	arr[i] = '1';
	i++;
	arr[i] = '/';
	i++;
	arr[i] = '(';
	i++;
	arr[i] = '1';
	i++;
	arr[i] = '-';
	i++;
	arr[i] = 'x';
	i++;
	arr[i] = '^';
	i++;
	arr[i] = '2';
	i++;
	arr[i] = ')';
	i++;
	arr[i] = '^';
	i++;
	arr[i] = '1';
	i++;
	arr[i] = '/';
	i++;
	arr[i] = '2';
	i++;
	printingArray(arr, i);
	return result;
}



double cosNDerivative(char arr[], int varX)
{
	int i = 0, c, kacSayi = 0, variables = 0, katsayisi;
	double result;
	char katsayilar[waitingMax];
	variables = duzenleme(arr);
	kacSayi = katSayi(arr, katsayilar);
	katsayisi = makingInt(katsayilar, kacSayi);
	arr[i] = '-';
	i++;
	if (kacSayi > 0)
	{
		for (c = 0; c < kacSayi; c++)
		{
			arr[i] = katsayilar[c];
			i++;
		}
		arr[i] = '.';
		i++;
		result = katsayisi*(-(1 / pow(1 - pow(varX, 2), (1 / 2))));
	}
	else if (kacSayi == 0)
		result = -(1 / pow(1 - pow(varX, 2), (1 / 2)));
	arr[i] = '1';
	i++;
	arr[i] = '/';
	i++;
	arr[i] = '(';
	i++;
	arr[i] = '1';
	i++;
	arr[i] = '-';
	i++;
	arr[i] = 'x';
	i++;
	arr[i] = '^';
	i++;
	arr[i] = '2';
	i++;
	arr[i] = ')';
	i++;
	arr[i] = '^';
	i++;
	arr[i] = '1';
	i++;
	arr[i] = '/';
	i++;
	arr[i] = '2';
	i++;
	printingArray(arr, i);
	return result;
}


double tanNDerivative(char arr[], int varX)
{
	int i = 0, c, kacSayi = 0, variables = 0, katsayisi;
	double result;
	char katsayilar[waitingMax];
	variables = duzenleme(arr);
	kacSayi = katSayi(arr, katsayilar);
	katsayisi = makingInt(katsayilar, kacSayi);
	if (kacSayi > 0)
	{
		for (c = 0; c < kacSayi; c++)
		{
			arr[i] = katsayilar[c];
			i++;
		}
		arr[i] = '.';
		i++;
		result = katsayisi * 1 / (1 + pow(varX, 2));
	}
	else if (kacSayi == 0)
		result = 1 / (1 + pow(varX, 2));
	arr[i] = '1';
	i++;
	arr[i] = '/';
	i++;
	arr[i] = '(';
	i++;
	arr[i] = '1';
	i++;
	arr[i] = '+';
	i++;
	arr[i] = 'x';
	i++;
	arr[i] = '^';
	i++;
	arr[i] = '2';
	i++;
	arr[i] = ')';
	i++;
	printingArray(arr, i);
	return result;
}



int main()
{

	part1();



	int counterOfInput,
		control,
		variables,
		elements,
		valueX;
	double result = 0.0;
	char arrayOfSTG[waitingMax], operation;
	printf("\nNumber of the elements is ");
	scanf("\n%d", &elements);
	if (elements > 1)
	{
		printf("\nThe operation: ");
		scanf("\n%c", &operation);
	}
	printf("The x' s value: ");
	scanf("%d", &valueX);
	do{
		printf("\nThe %d. element entered: ", elements);
		scanf("\n");
		for (counterOfInput = 0; counterOfInput < waitingMax; counterOfInput++)
		{
			scanf("%c", &arrayOfSTG[counterOfInput]);
			if (arrayOfSTG[counterOfInput] == '\n')
			{
				counterOfInput = waitingMax;
			}
		}
		
		control = detectingWhich(arrayOfSTG);
		if (operation == '+' || elements<= 1)
		{
			switch (control)
			{
			case 0:
				printf("0");
				break;
			case 1:
				result += lineDerivative(arrayOfSTG, valueX);
				break;
			case 2:
				result += powerDerivative(arrayOfSTG, valueX);
				break;
			case 3:
				result += squareRootDerivative(arrayOfSTG, valueX);
				break;
			case 4:
				//result += exponentalDerivative(arrayOfSTG, valueX);
				break;
			case 5:
				result += lnDerivative(arrayOfSTG, valueX);
				break;
			case 6:
				result += logDerivative(arrayOfSTG, valueX);
				break;
			case 7:
				result += sinDerivative(arrayOfSTG, valueX);
				break;
			case 8:
				result += cosDerivative(arrayOfSTG, valueX);
				break;
			case 9:
				result += tanDerivative(arrayOfSTG, valueX);
				break;
			case 10:
				result += sinNDerivative(arrayOfSTG, valueX);
				break;
			case 11:
				result += cosNDerivative(arrayOfSTG, valueX);
				break;
			case 12:
				result += tanNDerivative(arrayOfSTG, valueX);
				break;
			default:
				break;
			}
		}
		
		elements--;
	} while (elements > 0);


	printf("\n%d", control);


	return 0;
}