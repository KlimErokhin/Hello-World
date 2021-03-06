#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <process.h>
#define Pi 3.1415926
#define CRT_SECURE_NO_WARNINGS

double func_s_by_value(int n, double x)
{
 int k, i;
 double s, rez;
 s = 0;
 for (k = 0; k <= n; k++)
 {
  rez = 1;
  for (i = 1; i <= k; i++)
   rez *= i;
  s += (cos(k*Pi / 4) / rez)* pow(x, k);
 }
 return s;
}

double func_y_by_value(double x)
{
 return  exp(x*cos(Pi / 4))* cos(x*sin(Pi / 4));
}

double func_y_by_pointer(double *x)
{
 return  exp(*x*cos(Pi / 4))* cos(*x*sin(Pi / 4));
}

double func_y_by_reference(double &x)
{
 return  exp(x*cos(Pi / 4))* cos(x*sin(Pi / 4));
}

void main()
{
 /*
 double x;
 x = 0.5;

 double *p_x;
 p_x = &x;

 printf("\n %.2lf    |   %d   |  %.2lf    |\n", x, p_x, *p_x);
 */

 double a, b, h, x, rez, y_value, y_pointer, y_reference, s, delta;
 int n, i, k;

 system("cls"); fflush(stdin);
 printf("enter a :");
 scanf_s("%lf", &a);
 printf("enter b :");
 scanf_s("%lf", &b);
 printf("enter h :");
 scanf_s("%lf", &h);
 printf("enter n : ");
 scanf_s("%d", &n);
 printf("\n");
 puts("|    x   |  Y(x)value  |  Y(x)pointer  | Y(x)reference |     S(x)     |     Y(x) - S(x)   |");
 puts("|---------------------------------------------------------|");

 x = a;
 while (x <= b)
 {
  s = func_s_by_value(n,x);
  y_value = func_y_by_value(x);
  y_pointer = func_y_by_pointer(&x);
  y_reference = func_y_by_reference(x);

  delta = fabs(y_value - s);

  printf("\n %.2lf    |   %.5lf   |   %.5lf   |   %.5lf   |   %.5lf|      %.5lf      | \n", x, y_value, y_pointer, y_reference, s, delta);
  x += h;
 }
 _getch();
}