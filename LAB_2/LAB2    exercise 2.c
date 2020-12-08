/*
    ������������ ������ �2( 7 ������� ) �� ��������: 
        "������ �������������� � ����������������(����)".

    ���������� 2: 
        ���� ��� ����� a, b � �. ��������� ��������, ������������
    ������� �������������� ���� �����, ���� ��� ��� ������� �� ����,
    � ������� �������������� � ��������� ������.

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
        a      = 0, // ������� ����������
        b      = 0, // ������� ����������
        c      = 0, // ������� ����������
        answer = 0; // �������� ����������

    printf("�������� ����� a: ");
	scanf("%f", &a);
	printf("\n�������� ����� b: ");
	scanf("%f", &b);
	printf("\n�������� ����� c: ");
	scanf("%f", &c);

    if( a > 0 && b > 0 && c > 0 ) {
        answer = sqrtf( a * b * c );
        printf("\n\n\n������� �������������� ����� a, b, c: %g", answer); 
    } else {
        answer = ( a + b + c ) / 3;
        printf("\n\n\n������� �������������� ����� a, b, c: %g", answer); 
    }

	getch();

    return 0;
}