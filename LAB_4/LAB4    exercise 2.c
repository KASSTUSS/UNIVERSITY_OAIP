
/*
    ������������ ������ �4( 7 ������� ) �� ��������: 
        "������ �������������� � ����������������(����)".

    ���������� 2: 
        ����� ������ �� k �������� ���������� ��������. ������� �� ����� � 
    ���������� ������� ��� �������, ������� ������ � ���� ������ �� ������ ����.

    ����������� � ����������� �������:
        -
    
    ��������: 
        ������� ������ ��-12 ������ �.�.

    07.12.2020
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <assert.h>
#include <locale.h>

int main(void) 
{
    setlocale(LC_ALL, "Russian");  

    int 
        lengthArray   = 0,         // ����� �������
        counterArray  = 1,         // ������� �������� ������� ��������
        i             = 0,         // ������� �����
        j             = 1;         // ������� �����

    short 
        checkingArray = 1;         // ��� �������� �������
        
    unsigned char 
        inputArrayOfSymbols[100],  // ������� ������ �������� (������)
        outputArrayOfSymbols[100], // �������� ������ �������� (������)
        toSort;                    // ��� ����������

    
    printf("������� ����� ������� ��������: ");
    scanf("%d", &lengthArray);

    lengthArray++;
    
    printf("\n������� ������ �������� (������): ");
    for ( int i = 0; i < lengthArray; i++ ) {
        scanf("%c", &inputArrayOfSymbols[i]);
    } 

    for( i = 1; i < lengthArray; i++ ) { // ������ ���� �������� �������� � ����� ����������
        for( j = i; j > 0; j-- ) 
            if( (int)inputArrayOfSymbols[i] == (int)outputArrayOfSymbols[j] ) {
                checkingArray = 0;
                break;
            } else {
                checkingArray = 1;
            }
        if( checkingArray == 1 ) 
            outputArrayOfSymbols[counterArray++] = inputArrayOfSymbols[i];
    }

    for ( i = 1; i < counterArray; i++ ) { // ���������� ������� outputArrayOfSymbols
        toSort = outputArrayOfSymbols[i];    
        for ( j = i - 1; ( j > 0 ) && ( (int)outputArrayOfSymbols[j] > (int)toSort ); j-- ) 
            outputArrayOfSymbols[j+1] = outputArrayOfSymbols[j]; 
        outputArrayOfSymbols[j+1] = toSort;
    }

    printf("\n\n��� ������� � ���������� �������, ������� ���������� � ������� �������� ���� ���: ");
    for( i = 1; i < counterArray; i++ ) {
        printf("%c", outputArrayOfSymbols[i]);
    } 

    getch();

    return 0;
}