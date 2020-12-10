/*
    ������������ ������ �7( 7 ������� ) �� ��������: 
        "������ �������������� � ����������������(����)".

    ���������� 1 (������� ��� �������� ��� �������� � �������): 
        ����� � ������� ������ ������, ��� �������� ������� ����� ����. 

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

void fillingMatrix ( int *matrix, int *lines, int *columns );

int checkLineMatrix ( int *matrix, int *columns, int num, int i );
int searchLine ( int *matrix, int *lines, int *columns );

int main(void) 
{
    setlocale(LC_ALL, "Russian");

    int 
        *matrix;             // �������

    int 
        i               = 0, // ������� �����
        j               = 0, // ������� �����
        linesMatrix     = 0, // ���-�� ����� �������
        columnsMatrix   = 0, // ���-�� �������� �������
        answer          = 0; // ����� ������ �������, ��� �������� ������� �������
 
    printf("������� ���������� ����� �������: "); 
    scanf("%d", &linesMatrix);
    
    printf("\n������� ���������� �������� �������: ");
    scanf("%d", &columnsMatrix);
    printf("\n");

    if( !(matrix = (int*)calloc(((linesMatrix) * (columnsMatrix)), sizeof(int))) ) {
        printf("\n������������ ������.");

        getch();
        return 0;
    }

    fillingMatrix(matrix, &linesMatrix, &columnsMatrix);

    answer = searchLine (matrix, &linesMatrix, &columnsMatrix);
    answer ? printf("\n\n\n����� ������ ������ �������, ��� �������� ������� ����� ����: %d", answer) : printf("\n\n\n������ �������, ��� �������� ������� ����� ����, �� �������.");

    free(matrix); // ����������� ����� ���������� ������� ������

    getch();

    return 0;
}

void fillingMatrix ( int *matrix, int *lines, int *columns ) // ���������� �������
{
    int i = 0;
    int j = 0;
    printf("\n\n");
    for( i = 0; i < (*lines); i++ ) {
        for( j = 0; j < (*columns); j++ ) {
            printf("������� ������� [%d][%d]: ", (i + 1), (j + 1));
            scanf("%d", (matrix + ((i * (*columns)) + j)));
        }
        printf("\n");
    } // ���� ��������� �������
}

int checkLineMatrix ( int *matrix, int *columns, int num, int i ) // �������� ������ �������: ��� �� �������� �������?
{
    int 
        result = 1,
        j      = 0;

    while( result && j < (*columns) ) {
        if( *(matrix + (*columns)*i + j) != num ) {
            result = 0;
        }
        ++j;
    }

    if(result) {
        return 1;
    } else {
        return 0;
    }
}

int searchLine ( int *matrix, int *lines, int *columns ) // ����� ������, ��� �������� ������� �������
{
    int 
        result = 0,
        check  = 0,
        i      = 0;

    while ( !check && (i < *lines) ) {
        if( checkLineMatrix (matrix, columns, 0, i) ) {
            i++;
            check = 1;
            result = i;
        } else {
            i++;
        }   
    }

    return result;
}