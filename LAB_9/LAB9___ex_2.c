/*
    ЛАБОРАТОРНАЯ РАБОТА №9( 7 вариант ) по предмету: 
        "Основы алгоритмизации и программирования(ОАиП)".

    УПРАЖНЕНИЕ 2: 
        Сформировать бинарный файл из элементов, заданной в варианте структуры, распечатать
	его содержимое, выполнить добавление элементов в соответствии со своим вариантом и поиск по
	одному из параметров (например, по фамилии, по государственному номеру, по году рождения и
	т.д.). Формирование, печать, добавление, поиск элементов оформить и выбор желаемого действия
	оформить в виде функций. Предусмотреть сообщения об ошибках при открытии файла и
	выполнении операций ввода/вывода.
		Структура «Студент»: ФИО; домашний адрес; группа; рейтинг.


    КОММЕНТАРИИ К ВЫПОЛНЕНОМУ ЗАДАНИЮ:
        Я работаю на Windows 10, поэтому часто возникают нестандартные проблемы. Например
    здесь. Чтобы я не сделал, fopen всегда возвращает NULL. То же самое происходит с примерами
    из методички. 
    
    ВЫПОЛНИЛ: 
        студент группы МС-12 ЧВАЛОВ К.Р.

    26.12.2020
*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <locale.h>

void inputInfo(void);
int save(char*);
int printInfo(char*);
int findInfo(char*);

#define LEN_STR 50

struct student {
	int  id;
    char name[3][LEN_STR];
	char homeAdress[2][LEN_STR];
	char group[LEN_STR];
	int  rating;
};

struct student *students;
int studentsCounter = 1;

int main(void) 
{
    char *filename = "students.bin";
    int userChoise = 0;
    
    setlocale(LC_ALL, "Russian");

    do {
        printf("\n\n%s\n\n\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n",
            "                       МЕНЮ                        ", 
            "***************************************************",
            "*                                                 *",
            "*     (1) Ввод массива структур                   *",
			"*     (2) Поиск массива структур                  *",
			"*     (3) Просмотр массива структур               *",
			"*     (4) Запись структуры в бинарный файл        *",
			"*     (0) Выход                                   *",
            "*                                                 *",
            "***************************************************"
            );
        printf("Выполнить: ");
		scanf("%d", &userChoise);

		switch(userChoise)
		{
			case 1:
				inputInfo();
				break;

			case 2:
				findInfo(filename);
				break;

			case 3:
				printInfo(filename);
				break;

			case 4:
				save(filename);
				break;

			case 0:
				userChoise = 0;
				break;

			default: 
				menu();
		}

	} while (userChoise != 0);
    

    getch();

    return 0;
}

void inputInfo(void)
{
	;

    if( !(students = (struct student*)realloc(students, sizeof(struct student)*(studentsCounter+1))) ) {
        printf("\n\n\nПамять не выделилась!!!\n\n\n");

        getch();
    }


	printf("%s", "Введите ФИО:");
	scanf("%s%s%s", (students+studentsCounter)->name[0],
					  (students+studentsCounter)->name[1],
					  (students+studentsCounter)->name[2]);

	printf("%s", "Введите адрес (Улица, дом/квартира):");
	scanf("%s%s", (students+studentsCounter)->homeAdress[0],
				  (students+studentsCounter)->homeAdress[1]);
						 

	printf("%s", "Введите группу студента:");
	scanf("%s", (students+studentsCounter)->group);

	printf("%s", "Введите рейтинг студента:");
	scanf("%d", (students+studentsCounter)->rating);

	studentsCounter++;
}

int save(char *filename)
{
    FILE *structFile;
    char *c;
    int size = studentsCounter * sizeof(struct student);
 
    if ((structFile = fopen(filename, "w")) == NULL)
    {
        perror("Error occured while opening file");
        return 1;
    }
    
    c = (char*)&studentsCounter;
    for (int i = 0; i < sizeof(int); i++)
    {
        putc(*c++, structFile);
    }

    c = (char *)students;
    for (int i = 0; i < size; i++)
    {
        putc(*c, structFile);
        c++;
    }

    fclose(structFile);
    printf("Структура записана в бинарный файл\n");
    return 0;
}

void printFindInfo(int k, struct student *info)
{
	 printf("\nФИО: %s %s %s \nАдрес: %s%s \nГруппа: %s \nРейтинг: %d\n\n", (info + k)->name[0],
        					 											  (info + k)->name[1], 
        					 									    	  (info + k)->name[2],
        																  (info + k)->homeAdress[0],
                                                                          (info + k)->homeAdress[1],
        			    												  (info + k)->group,
        	 															  (info + k)->rating);
}

int printInfo(char *filename)
{
    FILE * structFile;
    char *c;
    int m = sizeof(int);
    int n, l;
 
    int *saveStruct = (int*)malloc(m);
 
    if ((structFile = fopen(filename, "r")) == NULL)
    {
        perror("Error occured while opening file");
        return 1;
    }

    c = (char *)saveStruct;
    while (m > 0)
    {
        l = getc(structFile);
        if (l == EOF) break;
        *c = l;
        c++;
        m--;
    }
   
    n = *saveStruct;
 
    struct student *info = (struct student*)malloc(n*sizeof(struct student));
    c = (char *)info;
  
    while ((l= getc(structFile))!=EOF)
    {
        *c = l;
        c++;
    }
 
    for (int k = 0; k < n; k++)
    {
    	printFindInfo(k, info);
    }
 
    free(saveStruct);
    free(info);
    fclose(structFile);
    return 0;
}

int findInfo(char *filename)
{
    FILE *structFile;
    char *c;
    int m = sizeof(int);
    int n, l;
 
    int *saveStruct = (int*)malloc(m);
 
    if ((structFile = fopen(filename, "r")) == NULL)
    {
        perror("Error occured while opening file");
        return 1;
    }

    c = (char *)saveStruct;
    while (m > 0)
    {
        l = getc(structFile);
        if (l == EOF) break;
        *c = l;
        c++;
        m--;
    }
   
    n = *saveStruct;
 
    struct student *info = (struct student*)malloc(n*sizeof(struct student));
    c = (char *)info;
  
    while ((l= getc(structFile))!=EOF)
    {
        *c = l;
        c++;
    }

    int choise;
	int helpCount = 0;
	int check = 1;
	char findName[3][LEN_STR];
	char findHomeAdress[2][LEN_STR];
	char findGroup[LEN_STR];
	int  findRating = 0;

	printf("Выберете параметр поиска:\n%s\n%s\n%s\n%s\n\n", "(1) ФИО",
															"(2) Адрес",
														   	"(3) Группа",
															"(4) Рейтинг");
	scanf("%d", &choise);
	switch(choise)
	{

		case 1:

			printf("Введите ФИО:\n");

			for (int i = 0; i < 3; ++i)
			{
				scanf("%s", findName[i]);
			}

			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < 3; ++j)
				{
					if (strcmp((info+i)->name[j], findName[j]) == 0) helpCount++;
				}

				if(helpCount == 3) 
				{
					printf("Информация найдена\n");
					printFindInfo(i, info);
					helpCount = 0;
					check = 0;
				}

				helpCount = 0;
			}

			if (check) printf("Информация не найдена\n");

			break;


		case 2:

			printf("Введите адрес:\n");
			for (int i = 0; i < LEN_STR; ++i)
			{
				scanf("%s", findHomeAdress[i]);
			}

			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < 2; ++j)
				{
					if (strcmp((info+i)->homeAdress[j], findHomeAdress[j]) == 0) helpCount++;
				}
				if(helpCount == 2) 
				{
					printf("Информация найдена\n");
					printFindInfo(i, info);
					helpCount = 0;
					check = 0;
				}

				helpCount = 0;
			}

			if (check) printf("Информация не найдена\n");

			break;


		case 3:

			printf("Введите группу студента:\n");
			scanf("%s", findGroup);

			for (int i = 0; i < n; ++i)
			{
				if (strcmp((info+i)->group, findGroup) == 0) {
                    printf("Информация найдена\n");
					printFindInfo(i, info);
					check = 0;
                }
			}

			if (check) printf("Информация не найдена\n");

			break;


		case 4:

			printf("Введите рейтинг студента:\n");
			scanf("%d", &findRating);

			for (int i = 0; i < n; ++i)
			{
				if ( (info+i)->rating == findRating )
				{
					printf("Информация найдена\n");
					printFindInfo(i, info);
					check = 0;
				}
			}

			if (check) printf("Информация не найдена\n");

			break;

		default:
			findInfo(filename);
	}
 
    free(saveStruct);
    free(info);
    fclose(structFile);
    return 0;
} 
