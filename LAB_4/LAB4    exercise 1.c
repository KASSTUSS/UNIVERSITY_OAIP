/*
    ЋјЅќ–ј“ќ–Ќјя –јЅќ“ј є4( 7 вариант ) по предмету: 
        "ќсновы алгоритмизации и программировани¤(ќјиѕ)".

    ”ѕ–ј∆Ќ≈Ќ»≈ 1: 
        —двинуть элементы массива циклически на n позиций вправо.

     ќћћ≈Ќ“ј–»»   ¬џѕќЋЌ≈Ќќћ” «јƒјЌ»ё:
        -
    
    ¬џѕќЋЌ»Ћ:
        студент группы ћ—-12 „¬јЋќ¬  .–.

    07.12.2020
*/
#include <stdio.h>
#include <conio.h>
#include <locale.h>

int main(void) 
{
    setlocale(LC_ALL, "Russian");  


    int 
        Arr[100];        // входной массив
    
    int 
        lengthArray = 0, // длина массива
        n           = 0, // число на которое нужно сдвинуть элементы массива
        forChanging = 0; // переменна¤ дл¤ перестановки элементов массива
    
    printf("¬ведите длину массива: ");
    scanf("%d", &lengthArray);
    
    printf("\n¬ведите массив: ");
    for ( int i = 0; i < lengthArray; i++ ) {

        scanf("%d", &Arr[i]);

    }
    
    printf("\n¬ведите число, на которое необходимо сдрвинуть элементы массива: ");
    scanf("%d", &n);

    for ( int i = 0; i < n; i++ ) { // сдвиг элементов массива
        forChanging = Arr[lengthArray-1];
        for ( int j = lengthArray-1; j > 0; j-- ) {
            Arr[j] = Arr[j-1];
        }
        Arr[0] = forChanging;
        forChanging = 0;
    } 

    printf("\n\n»тоговый массив: ");
    for ( int i = 0; i < lengthArray; i++ ) {

        printf("  %d", Arr[i]);

    } 

    getch();

    return 0;
}
