/*
    ЛАБОРАТОРНАЯ РАБОТА №2( 7 вариант ) по предмету: 
        "Основы алгоритмизации и программирования(ОАиП)".

    УПРАЖНЕНИЕ 3: 
        Составить программу, которая бы выдавала по названию страны
    название столицы этой страны (использовать не менее 6-7 названий)

    КОММЕНТАРИИ К ВЫПОЛНЕНОМУ ЗАДАНИЮ:
        -
    
    ВЫПОЛНИЛ: 
        студент группы МС-12 ЧВАЛОВ К.Р.

    07.12.2020
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <string.h>
#include <locale.h>

int main(void) 
{
    setlocale(LC_ALL, "Russian");  

    char 
        COUNTRY[9][10] = { // массив некоторых стран
            "Belarus",
            "Russia",
            "China",
            "France",
            "Germany",
            "Italy",
            "Japan",
            "USA",
            "Spain",
        };

    char 
        country[10],       // массив символов (строка); входная строка: название страны 
        capital[15];       // массив символов (строка); выходная строка: название столицы страны

    printf("Введите название страны (Беларусь, Россия, Китай, Франция, Германия, Италия, Япония, США), чтобы получить название ее столицы: ");
	
    fgets(country, 10, stdin);
    fflush(stdin); 

    if( country[0] == 'Б' ) {
        strcpy(capital, "Минск");
    } else if( country[0] == 'Р' ) {
        strcpy(capital, "Москва");
    } else if( country[0] == 'К' ) {
        strcpy(capital, "Пекин");
    } else if( country[0] == 'Ф' ) {
        strcpy(capital, "Париж");
    } else if( country[0] == 'Г' ) {
        strcpy(capital, "Берлин");
    } else if( country[0] == 'И' ) {
        strcpy(capital, "Рим");
    } else if( country[0] == 'Я' ) {
        strcpy(capital, "Токио");
    } else if( country[0] == 'С' ) {
        strcpy(capital, "Вашингтон");
    } 

    puts(capital);

	getch();

    return 0;
}