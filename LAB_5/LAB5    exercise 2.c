/*
    ������������ ������ �5( 7 ������� ) �� ��������: 
        "������ �������������� � ����������������(����)".

    ���������� 2: 
        ���� ������������� ������������� �������. ���������� ����������
    ��������, ���������� ���� �� ���� ������� �������; ����� ������, � �������
    ��������� ����� ������� ����� ���������� ���������.

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

    int matrix[100][100],            // ��������� ������ (�������)
        checkingMatrix[100];         // ������� ���-�� ��������� ��������� ����� ������ ������

    int i                       = 0, // ������� �����
        j                       = 0, // ������� �����
        k                       = 0, // ������� �����
        linesMatrix             = 0, // ���-�� ����� �������
        columnsMatrix           = 0, // ���-�� �������� �������
        counterZeroColumns      = 0, // ������� �������� �������, ���������� ���� �� ���� ������� �������
        reserveElement          = 0, // ���������� ��� ������ ����� ���������� ���������� ����� �������
        numberLine              = 1, // ����� ������ �������, � ������� ��������� ����� ������� ����� ���������� ���������
        newElement              = 0, // ���������� ��� ���������� 
        location                = 0, // ���������� ��� ����������
        counterElements         = 0, // ������� ��������� ��������� �����-���� �����
        maxCount                = 0; // ���-�� ��������� ����� ������� ����� ���� �� ����������

    short checkingColumnsMatrix = 0; // ������� ���������� ��� ����������� ������� ��������� � �������� �������

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

    for( i = 0; i < columnsMatrix; i++ ) { // ����� � ������� ��������, ������� �������� ������� �������
        for ( j = 0; j < linesMatrix; j++ ) {
            if( matrix[j][i] == 0 ) {
                checkingColumnsMatrix = 1;
                break;
            } else {
                checkingColumnsMatrix = 0;
            }
        }
        if ( checkingColumnsMatrix == 1 ) { 
            counterZeroColumns++; 
        }
    }

    for( i = 0; i < linesMatrix; i++ ) { // ����� ������ �������, � ������� ��������� ����� ������� ����� ���������� ���������
        checkingMatrix[i] = 0;
        counterElements = 0;
        reserveElement = matrix[i][0];
        for( j = 0; j < columnsMatrix; j++ ) {
            if( matrix[i][j] == reserveElement ) {  
                checkingMatrix[i]++;
                counterElements++;
            } else {
                reserveElement = matrix[i][j];
            }
        }
        if ( counterElements > maxCount )
        {
            numberLine = i+1;
            maxCount = counterElements;
        }
    }
 
    for ( i = 1; i < linesMatrix; i++ ) { // ���������� ������� checkingMatrix
        newElement = checkingMatrix[i];
        location = i - 1;
        while( location >= 0 && checkingMatrix[location] > newElement )
        {
            checkingMatrix[location+1] = checkingMatrix[location];
            location--;
        }
        checkingMatrix[location+1] = newElement;
    }

    printf("\n\n\n���� �������: \n\n");
    for( i = 0; i < linesMatrix; i++ ) {
        for( j = 0; j < columnsMatrix; j++ ) 
            printf("\t%d", matrix[i][j]);
        printf("\n\n");
    }

    printf("\n\n\n���������� ��������, ���������� ���� �� ���� ������� �������: %d", counterZeroColumns);
    if( checkingMatrix[linesMatrix-1] == 1 ) {
        printf("\n\n�� ���� ������� ������� �� ���������� ����� ���������� ���������");
    } else if ( checkingMatrix[linesMatrix-1] == checkingMatrix[linesMatrix-2] ) {
        printf("\n\n� ������� ��������� ����� � ������� ������ ���������� ���������.");
    } else {
        printf("\n\n����� ������ �������, � ������� ��������� ����� ������� ����� ���������� ���������: %d", numberLine);
    }
         
    getch(); 

    return 0;
}