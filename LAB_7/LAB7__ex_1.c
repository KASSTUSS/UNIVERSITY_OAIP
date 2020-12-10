/*
    ЛАБОРАТОРНАЯ РАБОТА №7( 7 вариант ) по предмету: 
        "Основы алгоритмизации и программирования(ОАиП)".

    УПРАЖНЕНИЕ 1 (сделать все операции над матрицей в функции): 
        Найти в матрице первую строку, все элементы которой равны нулю. 

    КОММЕНТАРИИ К ВЫПОЛНЕНОМУ ЗАДАНИЮ:
        -
    
    ВЫПОЛНИЛ: 
        студент группы МС-12 ЧВАЛОВ К.Р.

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
        *matrix;             // матрица

    int 
        i               = 0, // счетчик цикла
        j               = 0, // счетчик цикла
        linesMatrix     = 0, // кол-во строк матрицы
        columnsMatrix   = 0, // кол-во столбцов матрицы
        answer          = 0; // номер строки матрицы, все элементы которой нулевые
 
    printf("Введите количество строк матрицы: "); 
    scanf("%d", &linesMatrix);
    
    printf("\nВведите количество столбцов матрицы: ");
    scanf("%d", &columnsMatrix);
    printf("\n");

    if( !(matrix = (int*)calloc(((linesMatrix) * (columnsMatrix)), sizeof(int))) ) {
        printf("\nНедостаточно памяти.");

        getch();
        return 0;
    }

    fillingMatrix(matrix, &linesMatrix, &columnsMatrix);

    answer = searchLine (matrix, &linesMatrix, &columnsMatrix);
    answer ? printf("\n\n\nНомер первой строки матрицы, все элементы которой равны нулю: %d", answer) : printf("\n\n\nСтроки матрицы, все элементы которой равны нулю, не найдено.");

    free(matrix); // освобождаем ренее выделенную область памяти

    getch();

    return 0;
}

void fillingMatrix ( int *matrix, int *lines, int *columns ) // заполнение матрицы
{
    int i = 0;
    int j = 0;
    printf("\n\n");
    for( i = 0; i < (*lines); i++ ) {
        for( j = 0; j < (*columns); j++ ) {
            printf("Введите элемент [%d][%d]: ", (i + 1), (j + 1));
            scanf("%d", (matrix + ((i * (*columns)) + j)));
        }
        printf("\n");
    } // ввод элементов массива
}

int checkLineMatrix ( int *matrix, int *columns, int num, int i ) // проверка строки матрицы: все ли элементы нулевые?
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

int searchLine ( int *matrix, int *lines, int *columns ) // поиск строки, все элементы которой нулевые
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
