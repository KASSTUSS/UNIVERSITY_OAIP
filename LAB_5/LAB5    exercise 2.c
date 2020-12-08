/*
    ЛАБОРАТОРНАЯ РАБОТА №5( 7 вариант ) по предмету: 
        "Основы алгоритмизации и программирования(ОАиП)".

    УПРАЖНЕНИЕ 2: 
        Дана целочисленная прямоугольная матрица. Определить количество
    столбцов, содержащих хотя бы один нулевой элемент; номер строки, в которой
    находится самая длинная серия одинаковых элементов.

    КОММЕНТАРИИ К ВЫПОЛНЕНОМУ ЗАДАНИЮ:
        -
    
    ВЫПОЛНИЛ: 
        студент группы МС-12 ЧВАЛОВ К.Р.

    07.12.2020
*/
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <locale.h>

int main(void) 
{
    setlocale(LC_ALL, "Russian");   

    int matrix[100][100],            // двумерный массив (матрица)
        checkingMatrix[100];         // массиив кол-ва одинковых элементов серии каждой строки

    int i                       = 0, // счетчик цикла
        j                       = 0, // счетчик цикла
        k                       = 0, // счетчик цикла
        linesMatrix             = 0, // кол-во строк матрицы
        columnsMatrix           = 0, // кол-во столбцов матрицы
        counterZeroColumns      = 0, // счетчик столбцов матрицы, содержащих хотя бы один нулевой элемент
        reserveElement          = 0, // переменная для поиска серии одинаковых эелементов строк матрицы
        numberLine              = 1, // номер строки матрицы, в которой находится самая длинная серия одинаковых элементов
        newElement              = 0, // переменная для сортировки 
        location                = 0, // переменная для сортировки
        counterElements         = 0, // счетчик одинковых элементов какой-либо серии
        maxCount                = 0; // кол-во элементов самой длинной серии этих же элеменотов

    short checkingColumnsMatrix = 0; // булевая переменная для определения нулевых элементов в столбцах матрицы

    printf("Введите количество строк матрицы: "); 
    scanf("%d", &linesMatrix);
    printf("\nВведите количество столбцов матрицы: ");
    scanf("%d", &columnsMatrix);
    printf("\n");

    for( i = 0; i < linesMatrix; i++ ) { // ввод матрицы
        for ( j = 0; j < columnsMatrix; j++ ) {
            printf("Введите элемент матрицы [%d,%d]: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
        printf("\n");
    }

    for( i = 0; i < columnsMatrix; i++ ) { // поиск и подсчет столбцов, которые содержат нулевой элемент
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

    for( i = 0; i < linesMatrix; i++ ) { // поиск строки матрицы, в которой находится самая длинная серия одинаковых элементов
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
 
    for ( i = 1; i < linesMatrix; i++ ) { // сортировка массива checkingMatrix
        newElement = checkingMatrix[i];
        location = i - 1;
        while( location >= 0 && checkingMatrix[location] > newElement )
        {
            checkingMatrix[location+1] = checkingMatrix[location];
            location--;
        }
        checkingMatrix[location+1] = newElement;
    }

    printf("\n\n\nДана матрица: \n\n");
    for( i = 0; i < linesMatrix; i++ ) {
        for( j = 0; j < columnsMatrix; j++ ) 
            printf("\t%d", matrix[i][j]);
        printf("\n\n");
    }

    printf("\n\n\nКоличество столбцов, содержащих хотя бы один нулевой элемент: %d", counterZeroColumns);
    if( checkingMatrix[linesMatrix-1] == 1 ) {
        printf("\n\nВо всех строках матрицы не обнаружено серии одинаковых элементов");
    } else if ( checkingMatrix[linesMatrix-1] == checkingMatrix[linesMatrix-2] ) {
        printf("\n\nВ матрице несколько строк с длинной серией одинаковых элементов.");
    } else {
        printf("\n\nНомер строки матрицы, в которой находится самая длинная серия одинаковых элементов: %d", numberLine);
    }
         
    getch(); 

    return 0;
}