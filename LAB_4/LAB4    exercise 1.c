/*
    ������������ ������ �4( 7 ������� ) �� ��������: 
        "������ �������������� � ����������������(����)".

    ���������� 1: 
        �������� �������� ������� ���������� �� n ������� ������.

    ����������� � ����������� �������:
        -
    
    ��������:
        ������� ������ ��-12 ������ �.�.

    07.12.2020
*/
#include <stdio.h>
#include <conio.h>
#include <locale.h>

int main(void) 
{
    setlocale(LC_ALL, "Russian");  


    int 
        Arr[100];        // ������� ������
    
    int 
        lengthArray = 0, // ����� �������
        n           = 0, // ����� �� ������� ����� �������� �������� �������
        forChanging = 0; // ���������� ��� ������������ ��������� �������
    
    printf("������� ����� �������: ");
    scanf("%d", &lengthArray);
    
    printf("\n������� ������: ");
    for ( int i = 0; i < lengthArray; i++ ) {

        scanf("%d", &Arr[i]);

    }
    
    printf("\n������� �����, �� ������� ���������� ��������� �������� �������: ");
    scanf("%d", &n);

    for ( int i = 0; i < n; i++ ) { // ����� ��������� �������
        forChanging = Arr[lengthArray-1];
        for ( int j = lengthArray-1; j > 0; j-- ) {
            Arr[j] = Arr[j-1];
        }
        Arr[0] = forChanging;
        forChanging = 0;
    } 

    printf("\n\n�������� ������: ");
    for ( int i = 0; i < lengthArray; i++ ) {

        printf("  %d", Arr[i]);

    } 

    getch();

    return 0;
}