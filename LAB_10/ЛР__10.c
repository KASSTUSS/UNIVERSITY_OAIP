/*
    ЛАБОРАТОРНАЯ РАБОТА №10( 7 вариант ) по предмету: 
        "Основы алгоритмизации и программирования(ОАиП)".
    ПРАКТИЧЕСКАЯ ЧАСТЬ: 
        Составить программу на Си по решению системы линейных
    алгебрарических уравнений методом Гаусса в согласии вариантами.
    
    КОММЕНТАРИИ К ВЫПОЛНЕНОМУ ЗАДАНИЮ:
         -
    
    ВЫПОЛНИЛ: 
        студент группы МС-12 ЧВАЛОВ К.Р.
    26.04.2021
*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

void printMatrix( float **Matrix, int N );
void normalization( float **Matrix, int N );
void getUnknownElements ( float **Matrix, int N, float *elems );

int main(void) 
{
    setlocale(LC_ALL, "Russian");

    int ans = 0;
    int amountVar = 3;

    printf("Выберите нужный режим работы:\n (<любая цифра>) Автоматическая подстановка и решение СЛАУ из варианта;\n (1) Ввод своей СЛАУ;\nВвод: ");
    scanf("%d", &ans);

    if( ans == 1 ) {
        amountVar = 0;
        printf("Введите количество переменных СЛАУ: ");
        scanf("%d", &amountVar);
    } else {
        amountVar = 3;
    }

    float *unknownElements = (float *)malloc(amountVar*sizeof(float));

    float **mainMatrix = (float **)malloc(amountVar*sizeof(float *));
    for(int i = 0; i < amountVar; i++) 
    {
        mainMatrix[i] = (float *)malloc((amountVar+1)*sizeof(float));
    }
    
    if ( ans == 1 ) {
        printMatrix(mainMatrix, amountVar);
    } else {
        mainMatrix[0][0] = 0.71;
        mainMatrix[0][1] = 0.1;
        mainMatrix[0][2] = 0.12;
        mainMatrix[0][3] = 0.29;

        mainMatrix[1][0] = 0.1;
        mainMatrix[1][1] = 0.34;
        mainMatrix[1][2] = -0.04;
        mainMatrix[1][3] = 0.32;

        mainMatrix[2][0] = 0.12;
        mainMatrix[2][1] = -0.04;
        mainMatrix[2][2] = 0.1;
        mainMatrix[2][3] = -0.1;
    }

    normalization(mainMatrix, amountVar);
    getUnknownElements(mainMatrix, amountVar, unknownElements);

    for ( int i = 0; i < amountVar; i++ )
    {
        printf("Переменная x[%d] = %.2f;\n", i+1, unknownElements[i]);
    }
    
    getch();
    return 0;
}

void printMatrix( float **Matrix, int N )
{

    float number = 0;

    for( int i = 0; i < N; i++ ) 
    {   
        for( int j = 0; j < N; j++ )
        {
            printf("Введите коэфициент a[%d,%d]: ", i+1, j+1);
            scanf("%f", &number);
            Matrix[i][j] = number;
        }
        printf("Введите коэфициент b[%d]: ", i+1);
        scanf("%f", &number);
        Matrix[i][N] = number;
        printf("\n");
    }

}

void normalization( float **Matrix, int N )
{
     
    for( int i = 0 ; i < N; i++ )
    {
        for ( int l = i; l < N; l++) {
            float number = Matrix[l][i];
            for( int j = i; j < N+1; j++ )
            {
                Matrix[l][j] /= number;
            }
        }

        for ( int k = (i+1); k < N; k++ ) 
        { 
            float number = Matrix[k][i];
            for ( int s = i; s < (N+1); s++ ) 
            {
                Matrix[k][s] = Matrix[k][s] - Matrix[i][s]*number;
            }
        }
    }

}

void getUnknownElements ( float **Matrix, int N, float *elems ) 
{
    for ( int i = 1; i <= N; i++ ) 
    {
        elems[N-i] = Matrix[N-i][N];
        for (int j = 0; j < (i-1); j++)
        {
            elems[N-i] -= (elems[N-i+j+1]*Matrix[N-i][N-i+j+1]);
        }
    }
}
