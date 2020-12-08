/*
    ЛАБОРАТОРНАЯ РАБОТА №5( 7 вариант ) по предмету: 
        "Основы алгоритмизации и программирования(ОАиП)".

    УПРАЖНЕНИЕ 3: 
        Проверить, есть ли в матрице хотя бы одна строка, содержащая элемент,
    равный нулю, и найти ее номер. Уменьшить все элементы матрицы на значение
    первого элемента найденной строки.

    КОММЕНТАРИИ К ВЫПОЛНЕНОМУ ЗАДАНИЮ:
        В условии не указано, надо ли выводить номера ВСЕХ строк, что содержат
    нулевой элемент, поэтому программа отнимает от всех элементов значение 
    элемента той строки, содержащей нулевой элемент, что была найдена первой. 
    
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

    int 
        matrix[100][100];             // двумерный массив (матрица)

    int 
        i                        = 0, // счетчик цикла
        j                        = 0, // счетцик цикла
        linesMatrix              = 0, // кол-во строк матрицы
        columnsMatrix            = 0, // кол-во столбцов матрицы
        firstElementFoundedLines = 0, // значение первого элемента строки, в которой был найден нулевой элемент
        numberLine               = 0; // номер строки, в которой был найден нулевой элемент

    short 
        checkingLinesMatrix      = 0; // булевая переменная для определения наличия в строке нулевого элемента


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

    printf("\n\n\nДана матрица: \n\n"); // вывод матрицы
    for( i = 0; i < linesMatrix; i++ ) {
        for( j = 0; j < columnsMatrix; j++ ) 
            printf("\t%d", matrix[i][j]);
        printf("\n\n");
    }

    i = 0;
    while( (i < linesMatrix) && (checkingLinesMatrix == 0) ) { // проверка и поиск строки, содержащей нулевой элемент
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
        printf("\n\n\nНомер строки, содержащей хотя бы один нулевой элемент: %d", numberLine);
        printf("\nИтоговая матрица: \n\n");
        for( i = 0; i < linesMatrix; i++ ) {
            for( j = 0; j < columnsMatrix; j++ ) {
                matrix[i][j] -= firstElementFoundedLines;
                printf("\t%d", matrix[i][j]);
            }
            printf("\n\n");
        }
   } else {
       printf("\n\n\nМатрица не содержит элемент, равнй нулю.");
   }
         
    getch();

    return 0;
}