/*
    ЛАБОРАТОРНАЯ РАБОТА №11( 7 вариант ) по предмету: 
        "Основы алгоритмизации и программирования(ОАиП)".
        
    ПРАКТИЧЕСКАЯ ЧАСТЬ: 
        Составить программу на Си по решению системы линейных
    алгебраических уравнений методами простых итераций и Зейделя 
    в согласии вариантами.
    
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
void RowSum( double **MatrixA, double *MatrixB, int r1, int r2, float c, const int columnsCount);
void Zeidel(double *matX, double *matRes, double **MatrixA, double *MatrixB, int N );
void Itera(double *matX, double *matRes, double **MatrixA, double *MatrixB, int N );
void Solve( double **MatrixA, double *MatrixB, int N );


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

    Solve(mainMatrix, BMatrix, amountVar);
    
    free(unknownElements);
    free(mainMatrix);
    free(BMatrix);
    
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

void RowSum(double **MatrixA, double *MatrixB, int r1, int r2, float c, const int columnsCount)
{
    for (int i = 0; i < columnsCount; i++)
        MatrixA[r2][i] += MatrixA[r1][i] * c;
        MatrixB[r2] += MatrixB[r1] * c;
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
    RowSum(MatrixA, MatrixB, 0, 2, -0.17, N);

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
void Solve( double **MatrixA, double *MatrixB, int N )
{
    double *x = (double *)malloc(N*sizeof(double));
    double *p = (double *)malloc(N*sizeof(double));

    printf("%s\n\n%s\n%s\n", "Выберите метод решения СЛАУ:", "(1) Метод простых итераций", "(2) Метод Зейделя");

    int choice = 0;

    do{
        scanf("%d", &choice);
    } while (choice < 1 && choice > 2);

    switch (choice)
    {
        case 1:
            do{
                Itera( x, p, MatrixA, MatrixB, N );
            } while (converge( x, p, MatrixA, N ));
            break;

        case 2:
            do{
                Zeidel( x, p, MatrixA, MatrixB, N );
            } while (converge( x, p, MatrixA, N ));
            break;
        
        default:
            break;
    }

    for (int i = 0; i < N; i++)
    {
        printf("x[%d] = %.2f ;\n", i+1, x[i]);
    }
}

void Itera(double *matX, double *matRes, double **MatrixA, double *MatrixB, int N )
{
    float elementsSum = 0;
    static int iteration;

    if (iteration != 0) 
        for (int i = 0; i < N; i++)
            matX[i] = matRes[i];
    else
        for (int i = 0; i < N; i++)
            matX[i] = MatrixB[i];
        
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            if (i != j) elementsSum += MatrixA[i][j] * matX[j];

        matRes[i] = (MatrixB[i] - elementsSum) / MatrixA[i][i];
        elementsSum = 0;
    }

    iteration++;
}


void Zeidel(double *matX, double *matRes, double **MatrixA, double *MatrixB, int N )
{
    float elementsSum = 0;
    static int iteration;

    if (iteration != 0) 
        for (int i = 0; i < N; i++)
            matX[i] = matRes[i];
    else
        for (int i = 0; i < N; i++)
            matX[i] = MatrixB[i];
        
    for (int i = 0; i < N; i++)
    {
        for (int j = i+1; j < N; j++)
            if (i != j) elementsSum += MatrixA[i][j] * matX[j];

        matRes[i] = (MatrixB[i] - elementsSum) / MatrixA[i][i];
        elementsSum = 0;

        for (int j = 0; j < i; j++)
            if (i != j) elementsSum += MatrixA[i][j] * matRes[j];
        elementsSum /= -MatrixA[i][i];
        
        matRes[i] += elementsSum;
        elementsSum = 0;
    }

    iteration++;
}
