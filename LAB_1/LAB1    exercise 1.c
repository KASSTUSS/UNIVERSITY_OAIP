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
		s = 0; // выходная переменная

	printf("Ввведите число x: ");
	scanf("%f", &x);

	s = 64 * powf(x, 4);

	printf("%.3f\n", s);

	getch();

	return 0;
}
