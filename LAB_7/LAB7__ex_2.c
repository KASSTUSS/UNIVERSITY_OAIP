/*
    ������������ ������ �7( 7 ������� ) �� ��������: 
        "������ �������������� � ����������������(����)".

    ���������� 2 (������� ��� �������� ��� �������� � �������): 
        ������ 2 ������. ��������� � ������� ������ ������� ������� �� 2 ���
    ������ ������� ����������� � 1-�� �� 0.

    ����������� � ����������� �������:
        -
    
    ��������: 
        ������� ������ ��-12 ������ �.�.

    10.12.2020
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h> 
#include <locale.h>

#define MAX_LENTH_STRING 102              // ������������ ����� ������

void changingString( char *firstString, char *secondString );
void changingChar( char *charSecString );

int main(void) 
{
    setlocale(LC_ALL, "Russian");

    unsigned char 
        firstString[MAX_LENTH_STRING],    // ������ ������� ������
        secondString[MAX_LENTH_STRING];   // ������ ������� ������
 
    printf("������� ������ ������ �� �������� (�� ����� %d ��������): ", MAX_LENTH_STRING - 2);
	fgets(firstString, MAX_LENTH_STRING, stdin);
    fflush(stdin); 
    printf("\n������� ������ ������ �� �������� (�� ����� %d ��������): ", MAX_LENTH_STRING - 2);
	fgets(secondString, MAX_LENTH_STRING, stdin);
    fflush(stdin);

    changingString(firstString, secondString);

    printf("�������� ������: %s", secondString);

    getch();

    return 0;
}

void changingString( char *firstString, char *secondString )
{
    int 
        i     = 0, // ������� �����
        j     = 0, // ������� �����
        check = 0; // ������� ���������� ��� �������� ��������� �������� ������ � ������ ������

    while( i < MAX_LENTH_STRING && secondString[i] != '\0' && secondString[i] != '\n') {
        j = 0;
        do {
            if( secondString[i] == firstString[j] ) {
                changingChar( secondString + i );
                check = 1;
            } else {
                ++j;
            }
        } while( j < MAX_LENTH_STRING && firstString[j] != '\0' && !check && firstString[i] != '\n');
        ++i;
        check = 0;
    }
}

void changingChar( char *charSecString )
{
    *charSecString = '0';
}