/*
    ЛАБОРАТОРНАЯ РАБОТА №7( 7 вариант ) по предмету: 
        "Основы алгоритмизации и программирования(ОАиП)".

    УПРАЖНЕНИЕ 2 (сделать все операции над строками в функции): 
        Ввести 2 строки. Выполнить в функции замену каждого символа из 2 –ой
    строки который встречается в 1-ой на 0.

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

#define MAX_LENTH_STRING 102              // максимальная длина строки

void changingString( char *firstString, char *secondString );
void changingChar( char *charSecString );

int main(void) 
{
    setlocale(LC_ALL, "Russian");

    unsigned char 
        firstString[MAX_LENTH_STRING],    // первая входная строка
        secondString[MAX_LENTH_STRING];   // вторая входная строка
 
    printf("Введите первую строку на латинице (не более %d символов): ", MAX_LENTH_STRING - 2);
	fgets(firstString, MAX_LENTH_STRING, stdin);
    fflush(stdin); 
    printf("\nВведите вторую строку на латинице (не более %d символов): ", MAX_LENTH_STRING - 2);
	fgets(secondString, MAX_LENTH_STRING, stdin);
    fflush(stdin);

    changingString(firstString, secondString);

    printf("Итоговая строка: %s", secondString);

    getch();

    return 0;
}

void changingString( char *firstString, char *secondString )
{
    int 
        i     = 0, // счетчик цикла
        j     = 0, // счетчик цикла
        check = 0; // булевая переменная для проверки ревенства символов первой и второй строки

    while( i < MAX_LENTH_STRING && secondString[i] != '\0' && secondString[i] != '\n') {
        j = 0;
        do {
            if( secondString[i] == firstString[j] ) {
                changingChar( secondString + i );
                check = 1;
            } else {
                ++j;
            }
        } while( j < MAX_LENTH_STRING && firstString[j] != '\0' && !check && firstString[i] != '\n');
        ++i;
        check = 0;
    }
}

void changingChar( char *charSecString )
{
    *charSecString = '0';
}
