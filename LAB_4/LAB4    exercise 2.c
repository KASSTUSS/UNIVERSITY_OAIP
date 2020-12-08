
/*
    ЛАБОРАТОРНАЯ РАБОТА №4( 7 вариант ) по предмету: 
        "Основы алгоритмизации и программирования(ОАиП)".

    УПРАЖНЕНИЕ 2: 
        Задан массив из k символов латинского алфавита. Вывести на экран в 
    алфавитном порядке все символы, которые входят в этот массив по одному разу.

    КОММЕНТАРИИ К ВЫПОЛНЕНОМУ ЗАДАНИЮ:
        -
    
    ВЫПОЛНИЛ: 
        студент группы МС-12 ЧВАЛОВ К.Р.

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
        lengthArray   = 0,         // длина массива
        counterArray  = 1,         // счетчик символов массива символов
        i             = 0,         // счетчик цикла
        j             = 1;         // счетчик цикла

    short 
        checkingArray = 1;         // для проверки массива
        
    unsigned char 
        inputArrayOfSymbols[100],  // входной массив символов (строка)
        outputArrayOfSymbols[100], // выходной массив символов (строка)
        toSort;                    // для сортировки

    
    printf("Введите длину массива символов: ");
    scanf("%d", &lengthArray);

    lengthArray++;
    
    printf("\nВведите массив символов (строку): ");
    for ( int i = 0; i < lengthArray; i++ ) {
        scanf("%c", &inputArrayOfSymbols[i]);
    } 

    for( i = 1; i < lengthArray; i++ ) { // запись всех символов масссива в одном экземпляре
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

    for ( i = 1; i < counterArray; i++ ) { // сортировка массива outputArrayOfSymbols
        toSort = outputArrayOfSymbols[i];    
        for ( j = i - 1; ( j > 0 ) && ( (int)outputArrayOfSymbols[j] > (int)toSort ); j-- ) 
            outputArrayOfSymbols[j+1] = outputArrayOfSymbols[j]; 
        outputArrayOfSymbols[j+1] = toSort;
    }

    printf("\n\nВсе символы в алфавитном порядке, которые появляются в массиве символов один раз: ");
    for( i = 1; i < counterArray; i++ ) {
        printf("%c", outputArrayOfSymbols[i]);
    } 

    getch();

    return 0;
}