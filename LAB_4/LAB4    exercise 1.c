/*
    ЛАБОРАТОРНАЯ РАБОТА №4( 7 вариант ) по предмету: 
        "Основы алгоритмизации и программирования(ОАиП)".

    УПРАЖНЕНИЕ 1: 
        Сдвинуть элементы массива циклически на n позиций вправо.

    КОММЕНТАРИИ К ВЫПОЛНЕНОМУ ЗАДАНИЮ:
        -
    
    ВЫПОЛНИЛ:
        студент группы МС-12 ЧВАЛОВ К.Р.

    07.12.2020
*/
#include <stdio.h>
#include <conio.h>
#include <locale.h>

int main(void) 
{
    setlocale(LC_ALL, "Russian");  


    int 
        Arr[100];        // входной массив
    
    int 
        lengthArray = 0, // длина массива
        n           = 0, // число на которое нужно сдвинуть элементы массива
        forChanging = 0; // переменная для перестановки элементов массива
    
    printf("Введите длину массива: ");
    scanf("%d", &lengthArray);
    
    printf("\nВведите массив: ");
    for ( int i = 0; i < lengthArray; i++ ) {

        scanf("%d", &Arr[i]);

    }
    
    printf("\nВведите число, на которое необходимо сдрвинуть элементы массива: ");
    scanf("%d", &n);

    for ( int i = 0; i < n; i++ ) { // сдвиг элементов массива
        forChanging = Arr[lengthArray-1];
        for ( int j = lengthArray-1; j > 0; j-- ) {
            Arr[j] = Arr[j-1];
        }
        Arr[0] = forChanging;
        forChanging = 0;
    } 

    printf("\n\nИтоговый массив: ");
    for ( int i = 0; i < lengthArray; i++ ) {

        printf("  %d", Arr[i]);

    } 

    getch();

    return 0;
}