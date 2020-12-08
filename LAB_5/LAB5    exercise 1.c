/*
    ������������ ������ �5( 7 ������� ) �� ��������: 
        "������ �������������� � ����������������(����)".

    ���������� 1: 
        ���������, ��� �� ������ ������� �������� ���� �� ���� �������������
    �������. ���� ��, �� �������� ����� ���� ��������� ������� �� ��������.

    ����������� � ����������� �������:
        -
    
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

    float 
        matrix[100][100];        // ��������� ������ (�������)

    int 
        i                   = 0, // ������� �����
        j                   = 0, // ������� �����
        linesMatrix         = 0, // ���-�� ����� �������
        columnsMatrix       = 0; // ���-�� �������� �������

    short 
        checkingMatrix      = 1, // ������� ���������� ��� ����������� ������� ������������ ��������� �� ���� ������� �������
        checkingLinesMatrix = 0; // ������� ���������� ��� ����������� ������� ������������ ��������� � ������

    printf("������� ���������� ����� �������: "); 
    scanf("%d", &linesMatrix);
    printf("\n������� ���������� �������� �������: ");
    scanf("%d", &columnsMatrix);
    printf("\n");

    for(i = 0; i < linesMatrix; i++) {
        for (j = 0; j < columnsMatrix; j++) {
            printf("������� ������� ������� [%d,%d]: ", i+1, j+1);
            scanf("%f", &matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n\n���� �������: \n\n");
    for( i = 0; i < linesMatrix; i++ ) {
        for( j = 0; j < columnsMatrix; j++ ) 
            printf("\t%.0f", matrix[i][j]);
        printf("\n\n");
    }

    for( i = 0; i < linesMatrix; i++ ) { // �������� �� ������� ������������� ��������� ������� � ������ ������ �������
        for ( j = 0; j < columnsMatrix; j++ ) {
            if( matrix[i][j] < 0 ) {
                checkingLinesMatrix = 1;
                break;
            } else {
                checkingLinesMatrix = 0;
            }
        }
        if ( checkingLinesMatrix == 0 ) {
            checkingMatrix = 0;
            break;
        } else {
            checkingMatrix = 1;
        }
    }

     if( checkingMatrix == 1 ) {

        for( i = 0; i < linesMatrix; i++ ) { // ��������� ������ ���� ��������� ������� �� ��������
            for( j = 0; j < columnsMatrix; j++ ) {
                if( matrix[i][j] > 0 ) {
                    matrix[i][j] -= matrix[i][j] * 2; 
                } else if( matrix[i][j] < 0 ) {
                    matrix[i][j] =  matrix[i][j] + (abs(matrix[i][j]) * 2);
                }
            }
        }

        printf("\n\n\n�������� �������: \n\n");
        for( i = 0; i < linesMatrix; i++ ) {
            for( j = 0; j < columnsMatrix; j++ ) 
                printf("\t%.0f", matrix[i][j]);
        printf("\n\n");
        }

     } else {
         printf("������������� ��������� �� ����������, ���� ��� ���������� �� �� ���� ������� �������.");
     }

    getch();

    return 0;
}