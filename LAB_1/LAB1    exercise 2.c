/*
    ������������ ������ �1( 7 ������� ) �� ��������: 
        "������ �������������� � ����������������(����)".

    ���������� 1: 
        -

    ����������� � ����������� �������:
        -
    
    ��������: 
        ������� ������ ��-12 ������ �.�.

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
		x = 0, // ������� ����������
		y = 0, // ������� ����������
		z = 0, // ������� ����������
		a = 0, 
		b = 0, 
		c = 0, 
		d = 0, 
		s = 0; // �������� ����������

	printf("�������� ����� x: ");
	scanf("%f", &x);
	printf("\n�������� ����� y: ");
	scanf("%f", &y);
	printf("\n�������� ����� z: ");
	scanf("%f", &z);

	a = 5*atanf(x);
	b = acosf(x)/4;
	c = (x+3*fabs(x-y)+x*x);
	d = (z*fabs(x-y)+x*x);

	s = a - b * c / d;

	printf("\n\n\n�� ����� ����� x = %f, y = %f, z = %f\n\n ���������: %.3f", x, y, z, s);

	getch();

	return 0;
}
