/*
    ������������ ������ �2( 7 ������� ) �� ��������: 
        "������ �������������� � ����������������(����)".

    ���������� 3: 
        ��������� ���������, ������� �� �������� �� �������� ������
    �������� ������� ���� ������ (������������ �� ����� 6-7 ��������)

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
#include <string.h>
#include <locale.h>

int main(void) 
{
    setlocale(LC_ALL, "Russian");  

    char 
        COUNTRY[9][10] = { // ������ ��������� �����
            "Belarus",
            "Russia",
            "China",
            "France",
            "Germany",
            "Italy",
            "Japan",
            "USA",
            "Spain",
        };

    char 
        country[10],       // ������ �������� (������); ������� ������: �������� ������ 
        capital[15];       // ������ �������� (������); �������� ������: �������� ������� ������

    printf("������� �������� ������ (��������, ������, �����, �������, ��������, ������, ������, ���), ����� �������� �������� �� �������: ");
	
    fgets(country, 10, stdin);
    fflush(stdin); 

    if( country[0] == '�' ) {
        strcpy(capital, "�����");
    } else if( country[0] == '�' ) {
        strcpy(capital, "������");
    } else if( country[0] == '�' ) {
        strcpy(capital, "�����");
    } else if( country[0] == '�' ) {
        strcpy(capital, "�����");
    } else if( country[0] == '�' ) {
        strcpy(capital, "������");
    } else if( country[0] == '�' ) {
        strcpy(capital, "���");
    } else if( country[0] == '�' ) {
        strcpy(capital, "�����");
    } else if( country[0] == '�' ) {
        strcpy(capital, "���������");
    } 

    puts(capital);

	getch();

    return 0;
}