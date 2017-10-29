#include <conio.h>
#include <stdio.h>
#include <math.h>

void main ()
{
	double a, a1, b, z1, z2; 
	printf("Enter value of corner a:");
	scanf_s("%lf", &a);
	a1 = sin(2*a) + sin(5*a) - sin(3*a);
	b = (cos(a) + 1) - 2* pow(sin(a*2),2);
	z1 = a1/ b;
	z2 = sin(a)*2;
	printf("\n result is: z1= %lf, z2= %lf", z1, z2);
	getch();

}
