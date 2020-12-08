/*
    ЛАБОРАТОРНАЯ РАБОТА №5( 7 вариант ) по предмету: 
        "Основы алгоритмизации и программирования(ОАиП)".

    УПРАЖНЕНИЕ 1: 
        Проверить, все ли строки матрицы содержат хотя бы один отрицательный
    элемент. Если да, то изменить знаки всех элементов матрицы на обратные.

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

    float 
        matrix[100][100];        // двумерный массив (матрица)

    int 
        i                   = 0, // счетчик цикла
        j                   = 0, // счетцик цикла
        linesMatrix         = 0, // кол-во строк матрицы
        columnsMatrix       = 0; // кол-во столбцов матрицы

    short 
        checkingMatrix      = 1, // булевая переменная для определения наличия отрицателных элементов во всех строках матрицы
        checkingLinesMatrix = 0; // булевая переменная для определения наличия отрицателных элементов в строке

    printf("Введите количество строк матрицы: "); 
    scanf("%d", &linesMatrix);
    printf("\nВведите количество столбцов матрицы: ");
    scanf("%d", &columnsMatrix);
    printf("\n");

    for(i = 0; i < linesMatrix; i++) {
        for (j = 0; j < columnsMatrix; j++) {
            printf("Введите элемент матрицы [%d,%d]: ", i+1, j+1);
            scanf("%f", &matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n\nДана матрица: \n\n");
    for( i = 0; i < linesMatrix; i++ ) {
        for( j = 0; j < columnsMatrix; j++ ) 
            printf("\t%.0f", matrix[i][j]);
        printf("\n\n");
    }

    for( i = 0; i < linesMatrix; i++ ) { // проверка на наличие отрицательных элементов матрицы в каждой строке матрицы
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

        for( i = 0; i < linesMatrix; i++ ) { // изменение знаков всех элементов матрицы на обратные
            for( j = 0; j < columnsMatrix; j++ ) {
                if( matrix[i][j] > 0 ) {
                    matrix[i][j] -= matrix[i][j] * 2; 
                } else if( matrix[i][j] < 0 ) {
                    matrix[i][j] =  matrix[i][j] + (abs(matrix[i][j]) * 2);
                }
            }
        }

        printf("\n\n\nИтоговая матрица: \n\n");
        for( i = 0; i < linesMatrix; i++ ) {
            for( j = 0; j < columnsMatrix; j++ ) 
                printf("\t%.0f", matrix[i][j]);
        printf("\n\n");
        }

     } else {
         printf("Отрицательных элементов не обнаружено, либо они содержатся не во всех строках матрицы.");
     }

    getch();

    return 0;
}