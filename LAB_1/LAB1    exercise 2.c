/*
    ЛАБОРАТОРНАЯ РАБОТА №1( 7 вариант ) по предмету: 
        "Основы алгоритмизации и программирования(ОАиП)".

    УПРАЖНЕНИЕ 1: 
        -

    КОММЕНТАРИИ К ВЫПОЛНЕНОМУ ЗАДАНИЮ:
        -
    
    ВЫПОЛНИЛ: 
        студент группы МС-12 ЧВАЛОВ К.Р.

    07.12.2020
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <locale.h>

int main(void) 
{
    setlocale(LC_ALL, "Russian");  

	float 
		x = 0, // входная переменная
		y = 0, // входная переменная
		z = 0, // входная переменная
		a = 0, 
		b = 0, 
		c = 0, 
		d = 0, 
		s = 0; // выходная переменная

	printf("Ввведите число x: ");
	scanf("%f", &x);
	printf("\nВвведите число y: ");
	scanf("%f", &y);
	printf("\nВвведите число z: ");
	scanf("%f", &z);

	a = 5 * atanf(x);
	b = acosf(x) / 4;
	c = (x + 3 * fabs(x - y) + x * x);
	d = (z * fabs(x - y) + x * x);

	s = a - b * c / d;

	printf("\n\n\nВы ввели числа x = %f, y = %f, z = %f\n\n Результат: %.3f", x, y, z, s);

	getch();

	return 0;
}
