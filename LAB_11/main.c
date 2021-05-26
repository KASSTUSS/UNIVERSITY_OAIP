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
#include <math.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

#define E 0.01

void scanMatrix( double **MatrixA, double *MatrixB, int N );
void transformationMatrix( double **MatrixA, double *MatrixB, int N );
void printMatrix ( double **Matrix, double *BMatrix, int N );
void Itera( double **MatrixA, double *MatrixB, int N );

double Normalize( double **MatrixA, int N );
double Pogr( double **MatrixA, int N );
int converge(double *k, double *p, double **MatrixA, int N);


int N;

int main()
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

    double *unknownElements = (double *)malloc(amountVar*sizeof(double));

    double **mainMatrix = (double **)malloc(amountVar*sizeof(double *));
    for(int i = 0; i < amountVar; i++) 
    {
        mainMatrix[i] = (double *)malloc((amountVar)*sizeof(double));
    }
    double *BMatrix = (double *)malloc(amountVar*sizeof(double *));
    
    if ( ans == 1 ) {
        scanMatrix(mainMatrix, BMatrix, amountVar);
    } else {
        mainMatrix[0][0] = 0.71;
        mainMatrix[0][1] = 0.1;
        mainMatrix[0][2] = 0.12;
        BMatrix[0] = 0.29;

        mainMatrix[1][0] = 0.1;
        mainMatrix[1][1] = 0.34;
        mainMatrix[1][2] = -0.04;
        BMatrix[1] = 0.32;

        mainMatrix[2][0] = 0.12;
        mainMatrix[2][1] = -0.04;
        mainMatrix[2][2] = 0.1;
        BMatrix[2] = -0.1;
    }

    printf("Расширенная матрица:\n");
    printMatrix(mainMatrix, BMatrix, amountVar);

    transformationMatrix(mainMatrix, BMatrix, amountVar);

    printf("Преображенная матрица:\n");
    printMatrix(mainMatrix, BMatrix, amountVar);

    Itera(mainMatrix, BMatrix, amountVar);
    
    getch();
    return 0;
}

void scanMatrix( double **MatrixA, double *MatrixB, int N )
{
    double number = 0;

    for( int i = 0; i < N; i++ ) 
    {   
        for( int j = 0; j < N; j++ )
        {
            printf("Введите коэфициент a[%d,%d]: ", i+1, j+1);
            scanf("%f", &number);
            MatrixA[i][j] = number;
        }
        printf("Введите коэфициент b[%d]: ", i+1);
        scanf("%f", &number);
        MatrixB[i] = number;
        printf("\n");
    }
}

void printMatrix ( double **MatrixA, double *MatrixB, int N )
{
    for( int i = 0; i < N; i++ ) 
    {
        for( int j = 0; j < N; j++ )
        {
            printf(" %.2f  ", MatrixA[i][j]);
        }
        printf("  %.2f\n", MatrixB[i]);
    }
}

void transformationMatrix( double **MatrixA, double *MatrixB, int N )
{
    double temp = 0;
    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            temp = MatrixA[i][i] * (-1);
            MatrixB[i] /= temp;
            for (int j = 0; j <= N; j++)
            {
                MatrixA[i][j] /= temp;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        MatrixB[i] *= -1;
        for (int j = 0; j < N; j++)
            MatrixA[i][i] = 0;
    }
}
double Normalize( double **MatrixA, int N )
{
    double sum = 0, max = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            sum += fabs(MatrixA[i][j]);
            if (sum > max) max = sum;
        }
        sum = 0;
    }
    return max;
}
double Pogr( double **MatrixA, int N )
{
    double eps = 0;
    double norm = Normalize(MatrixA,N);
    eps = ((1 - norm) / norm)*E;
    return eps;
}
int converge(double *k, double *p, double **MatrixA, int N)
{
    double norm = 0;
    for (int i = 0; i < N; i++)
        norm += (k[i] - p[i])*(k[i] - p[i]);
    if (sqrt(norm) == Pogr(MatrixA,N))
        return 1;
    return 0;
}
void Itera( double **MatrixA, double *MatrixB, int N )
{
    double *x = (double *)malloc(N*sizeof(double));
    double *p = (double *)malloc(N*sizeof(double));

    for (int i = 0; i < N; i++)
    {
        x[i] = MatrixB[i];
        p[i] = 0;
    }
    do
    {
        for (int i = 0; i < N; i++)
            p[i] = x[i];
        for (int i = 0; i < N; i++)
        {
            double var = 0;
            for (int j = 0; j < i; j++)
            {
                var += (MatrixA[i][j] * x[j]);
            }
            for (int j = i + 1; j < N; j++)
                var += (MatrixA[i][j] * p[j]);
            x[i] = (MatrixB[i] - var) / MatrixA[i][i];
        }
    } while (converge(x,p,MatrixA,N));

    for (int i = 0; i < N; i++)
    {
        printf("x[%d] = %.2f ;\n", i+1, x[i]);
    }
}