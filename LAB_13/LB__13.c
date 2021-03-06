/*
    ЛАБОРАТОРНАЯ РАБОТА №13( 7 вариант ) по предмету: 
        "Основы алгоритмизации и программирования(ОАиП)".

    ПРАКТИЧЕСКАЯ ЧАСТЬ: 
        Даны две последовательности a1<=a2<=...<=an и b1<=b2<=...<=bm. 
    Образовать из них новую последовательность чисел так, чтобы она тоже 
    была неубывающей. Дополнительный массив не использовать.
    
    КОММЕНТАРИИ К ВЫПОЛНЕНОМУ ЗАДАНИЮ:
        Так как использование дополнительного массива запрещено, будем
    использовать только данные массивы и сортировку производить в них,
    как в одном массиве (также будет выводиться отсортированный массив).
        Так как два исходных массива уже будут отсортированны, то идеально
    подойдет метод сортировки слиянием, но он требует дополнительного массива.
    Поэтому сортировка будет производится более медленным, но не меннее 
    производительным методом сортировки In-Place Merge Sort, который не требует 
    дополнительного массива.
        Так как оба массива по услувию уже являются отсортированными, то нам
    остается лишь выбрать шаг и, путем сравнения и замены местами значений элементов
    массивов, отсортировать два данных массива. 
    
    ВЫПОЛНИЛ: 
        студент группы МС-12 ЧВАЛОВ К.Р.
    01.06.2021
*/
#include <stdio.h>
#include <stdlib.h> 
#include <malloc.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

#define LIM_MAX 100 // Лимит на максимальный размер массивов
#define LIM_MIN 1 // // Лимит на минимальный размер массивов

void swap( int *x, int *y ); // Функции замены значений переменных
void printArray ( int *Arr, int len ); // Функция выводы в консоль массива
void scanArray ( int *Arr, int len ); // Функция ввода массива
void setUp ( int *A, int *B ); // Функция задания стандартных значений
void scanWithChecking ( int *x, int min, int max, char *text ); // Функция ввода переменной с проверкой введенного значения на попадание в числовой интервал
void scanWithIncreasingChecking ( int *x, int *y, int i ); // Функция ввода переменной с проверкой введенного значения x на то, что оно больше, чем y

void InPlaceMergeSort ( int *A, int *B, int N, int M ); // Собственно функция сортировки слиянием на месте (т.е. без дополнительной памяти)

int min( int x, int y ); // Возвращает минимальный элемент из x и y
int *getValueFromINdex( int i, int *A, int *B, int N ); // Возвращает значение элемента массивов A или B, в зависимости от индекса массива, полученного мысленным примыканием массива B к массиву A

int main( void )
{
    setlocale( LC_ALL, "Russian" );

    int N = 0;
    int M = 0;

    int *A, *B;

    int ans = 0;
    printf("Выберите нужный режим работы:\n\n (<любая цифра>) Автоматическая подстановка готовых последовательностей и их сортировка;\n (1) Ввод своих последовательностей;\n\nВвод: ");
    scanf("%d", &ans);

    if( ans == 1 ) {
        scanWithChecking ( &N, LIM_MIN, LIM_MAX, "\nВведите количество элемента первой последовательности" );
        scanWithChecking ( &M, LIM_MIN, LIM_MAX, "\nВведите количество элемента второй последовательности" );
        
        A = (int *)malloc(N*sizeof(int));
        B = (int *)malloc(M*sizeof(int));
        
        printf("Ввод первого массива A:\n-----------------\n");
        scanArray ( A, N );
        printf("\n\n\nВвод первого массива B:\n-----------------\n");
        scanArray ( B, M );
    } else {
        N = 3;
        M = 5;
        A = (int *)malloc(N * sizeof(int));
        B = (int *)malloc(M * sizeof(int));
        setUp( A, B );
    }

    printf("\n\n\n\n\n Даны две последовательности:\n ----------------------------\n\n");
    printf("Последовательность A: ");
    printArray(A, N);
    printf("\nПоследовательность B: ");
    printArray(B, M);

    InPlaceMergeSort( A, B, N, M );

    printf("\n\n\n\n\n Получаем отсортированную последовательность:\n -------------------------------------\n\n");
    for( int i = 0; i < (N + M-1); i++ )
        printf(" %d,", *getValueFromINdex(i,A,B,N));
    printf(" %d;", *getValueFromINdex((N+M-1),A,B,N));


    getch();
    return 0;
}

void swap( int *x, int *y )
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void printArray ( int *Arr, int len )
{
    for( int i = 0; i < len-1; i++ )
        printf("%d, ", Arr[i]);
    printf("%d;", Arr[len-1]);
}

void scanArray ( int *Arr, int len )
{
    for( int i = 0; i < len; i++ )
    {
        scanWithIncreasingChecking ( (Arr+i), (Arr+i-1), i );
    }
}

void setUp ( int *A, int *B )
{
    A[0] = 10;
    A[1] = 16;
    A[2] = 21;
    B[0] = 1;
    B[1] = 9;
    B[2] = 13;
    B[3] = 19;
    B[4] = 44;
}

void scanWithChecking ( int *x, int min, int max, char *text ) 
{
    int check = 0;

    do {
        printf("%s[%d..%d]: ", text, min, max);
        scanf("%d", x);
        if( *x < min || *x > max ) {
            printf("ОШИБКА! Введено некорректное значение!");
            check = 1;
        } else {
            check = 0;
        }
    } while ( check );
}

void scanWithIncreasingChecking ( int *x, int *y, int i ) 
{
    int check = 0;

    do {
        printf("Введите %d-й элемент массива: ", i+1);
        scanf("%d", x);
        if( *x < *y ) {
            printf("ОШИБКА! Введите значение не меньше предыдущего!\n\n");
            check = 1;
        } else {
            check = 0;
        }
    } while ( check );
}

void InPlaceMergeSort ( int *A, int *B, int N, int M )
{
    int step = min(N, M);

    while ( step >= 1 ) {
        for( int i = 0; i < (N+M-step); i++ )
            if ( *getValueFromINdex(i,A,B,N) > *getValueFromINdex ((i+step),A,B,N) )
                swap( getValueFromINdex(i,A,B,N), getValueFromINdex ((i+step),A,B,N) );
        step--;
    }
}

int min( int x, int y )
{
    if ( x > y ) {
        return y;
    } else {
        return x;
    }
}

int *getValueFromINdex ( int i, int *A, int *B, int N )
{
    if( i < N ) {
        return (A+i);
    } else {
        return (B+i-N);
    }
}
