/*
    ЛАБОРАТОРНАЯ РАБОТА №9( 7 вариант ) по предмету: 
        "Основы алгоритмизации и программирования(ОАиП)".

    УПРАЖНЕНИЕ 1: 
        Создать текстовый файл F1 не менее, чем из 10 строк и записать в него информацию.
    Скопировать из файла F1 в файл F2 строки, начиная с К до К+5.

    КОММЕНТАРИИ К ВЫПОЛНЕНОМУ ЗАДАНИЮ:
        Я работаю на Windows 10, поэтому часто возникают нестандартные проблемы. Например
    здесь. Чтобы я не сделал fopen всегда возвращает NULL. То же самое происходит в примерами
    из методички. 
        В файл F1 записывается последовательность Фибоначчи.
    
    ВЫПОЛНИЛ: 
        студент группы МС-12 ЧВАЛОВ К.Р.

    24.12.2020
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 
#include <locale.h>

int main(void) 
{
    setlocale(LC_ALL, "Russian");

    int *Arr;
    
    int 
        K            = 0,
        m            = 0,
        n            = 1,
        amountString = 0;

    FILE *firstFile;
    FILE *secondFile;

    firstFile = fopen("F1.txt", "w+");
    secondFile = fopen("F2.txt", "w");
    
    if( firstFile == NULL && secondFile == NULL ) {
        printf("\n\nНе удалось создать файл!\n\n");
        getch();
        return 0;
    }

    printf("\nВведите количество строк файла F1(не менее 10): ");
    scanf("%d", &amountString);

    for( int i = 0; i < amountString; i++ ) {
        n += m;
        m = n - m;
        fprintf(firstFile, "%d\n", n);
    }

    printf("\nВведите число K(не более %d): ", amountString-5);
    scanf("%d", &K);

    if( !(Arr = (int*)calloc(K+6, sizeof(int))) ) {
        printf("Память не выделилась!");
    }

    for( int i = 0; i < K+5; i++ ) {
        fscanf(firstFile, "%d\n", (Arr+i));
    }

    for( int i = K; i <  K+5; i++ ) {
        fprintf(secondFile, "%d\n", *(Arr+i));
    }

    fclose(firstFile);
    fclose(secondFile);

    getch();

    return 0;
}
