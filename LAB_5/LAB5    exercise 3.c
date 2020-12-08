/*
    ������������ ������ �5( 7 ������� ) �� ��������: 
        "������ �������������� � ����������������(����)".

    ���������� 3: 
        ���������, ���� �� � ������� ���� �� ���� ������, ���������� �������,
    ������ ����, � ����� �� �����. ��������� ��� �������� ������� �� ��������
    ������� �������� ��������� ������.

    ����������� � ����������� �������:
        � ������� �� �������, ���� �� �������� ������ ���� �����, ��� ��������
    ������� �������, ������� ��������� �������� �� ���� ��������� �������� 
    �������� ��� ������, ���������� ������� �������, ��� ���� ������� ������. 
    
    ��������: 
        ������� ������ ��-12 ������ �.�.

    07.12.2020
*/
#include <stdio.h>
#include <math.h>
#include <conio.h> 
#include <locale.h>

int main(void) 
{
    setlocale(LC_ALL, "Russian");   

    int 
        matrix[100][100];             // ��������� ������ (�������)

    int 
        i                        = 0, // ������� �����
        j                        = 0, // ������� �����
        linesMatrix              = 0, // ���-�� ����� �������
        columnsMatrix            = 0, // ���-�� �������� �������
        firstElementFoundedLines = 0, // �������� ������� �������� ������, � ������� ��� ������ ������� �������
        numberLine               = 0; // ����� ������, � ������� ��� ������ ������� �������

    short 
        checkingLinesMatrix      = 0; // ������� ���������� ��� ����������� ������� � ������ �������� ��������


    printf("������� ���������� ����� �������: "); 
    scanf("%d", &linesMatrix);
    printf("\n������� ���������� �������� �������: ");
    scanf("%d", &columnsMatrix);
    printf("\n");

    for( i = 0; i < linesMatrix; i++ ) { // ���� �������
        for ( j = 0; j < columnsMatrix; j++ ) {
            printf("������� ������� ������� [%d,%d]: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n\n\n���� �������: \n\n"); // ����� �������
    for( i = 0; i < linesMatrix; i++ ) {
        for( j = 0; j < columnsMatrix; j++ ) 
            printf("\t%d", matrix[i][j]);
        printf("\n\n");
    }

    i = 0;
    while( (i < linesMatrix) && (checkingLinesMatrix == 0) ) { // �������� � ����� ������, ���������� ������� �������
        for ( j = 0; j < columnsMatrix; j++ ) {
            if( matrix[i][j] == 0 ) {
                firstElementFoundedLines = matrix[i][0];
                checkingLinesMatrix = 1;
                numberLine = i+1;
                break;
            }
        }
        i++;
    }

   if( checkingLinesMatrix == 1 ) {
        printf("\n\n\n����� ������, ���������� ���� �� ���� ������� �������: %d", numberLine);
        printf("\n�������� �������: \n\n");
        for( i = 0; i < linesMatrix; i++ ) {
            for( j = 0; j < columnsMatrix; j++ ) {
                matrix[i][j] -= firstElementFoundedLines;
                printf("\t%d", matrix[i][j]);
            }
            printf("\n\n");
        }
   } else {
       printf("\n\n\n������� �� �������� �������, ����� ����.");
   }
         
    getch();

    return 0;
}