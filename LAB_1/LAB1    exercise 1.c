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
		s = 0; // �������� ����������

	printf("�������� ����� x: ");
	scanf("%f", &x);

	s = 64 * powf(x, 4);

	printf("%.3f\n", s);

	getch();

	return 0;
}
