/*
    ������������ ������ �8( 7 ������� ) �� ��������: 
        "������ �������������� � ����������������(����)".

    ���������� 1: 
        ������ ������ �������� � ������������ � ���������. �������������� ������ �
    ���������� ������� �� ������� ����, ��������� � ���������. � ��������� ����������� ����:
        1) ���� ������� ��������;
        2) ���������� ������� ��������;
        3) ����� � ������� �������� �� ��������� ���������;
        4) ��������� �������� ���������;
        5) �������� ��������� �� �������;
        6) ����� �� ����� ������� ��������;
        7) �����.
        ��������� ������� �����: ������� �.�., ����� �����, ����� �� �����, ���� ����������
���������.


    ����������� � ����������� �������:
        -
    
    ��������: 
        ������� ������ ��-12 ������ �.�.

    07.12.2020
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h> 
#include <locale.h>
#include <time.h>

#define LEN_STR 30
#define LEN_DATE 40

void inputBankClientInfo(void);
void printBankClientInfo(void);
void deleteBankClientInfo(void);
void sortBankClientInfo(void);
void findBankClientInfo(void);
void editBankClientInfo(void);

void printFoundedClientInfo( int n );
void toEmptyString( char *string );
void editDateChange( void ); 

struct bankClient {
    int   id;
    char  surname[LEN_STR];
    char  name[LEN_STR];
    char  patronymic[LEN_STR];
    int   accountNumber;
    float accountAmount;
    char  dateChange[LEN_DATE];
};

struct bankClient *clients;
struct bankClient **pClient;
int s_time;
struct tm *m_time;
char str_t[LEN_DATE] = {};

unsigned int count = 1;

int main(void) 
{
    setlocale(LC_ALL, "Russian");

    int userChoise;
	do
	{
		printf("\n\n%s\n\n\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n",
            "                       ����                        ", 
            "***************************************************",
            "*                                                 *",
            "*     (1) ���� ������� ��������                   *",
			"*     (2) ���������� ������� ��������             *",
			"*     (3) ����� ������� ��������                  *",
			"*     (4) �������������� ������� ��������         *",
			"*     (5) �������� ������� ��������               *",
			"*     (6) �������� ������� ��������               *",
			"*     (0) �����                                   *",
            "*                                                 *",
            "***************************************************"
            );
        printf("���������: ");
		scanf("%d", &userChoise);

		switch(userChoise)
		{
			case 1:
				inputBankClientInfo();
				break;
			case 2:
				sortBankClientInfo();
				break;
			case 3:
				findBankClientInfo();
				break;
			case 4:
				editBankClientInfo();
				break;
			case 5:
				deleteBankClientInfo();
				break;
			case 6:
				printBankClientInfo();
				break;
			case 0:
                free(clients);
                free(pClient);
				userChoise = 0;
				break;
			default: 
				main();
		}

	} while (userChoise != 0);

    getch();

    return 0;
}

void inputBankClientInfo(void)
{
    int repeat = 0;

    printf("\n\n\n\n\n%s\n%s\n%s\n\n\n",
        "      ********************",
        "      *    ���� ������   *",
        "      ********************"
    );

    do {
        repeat = 0;

        if( !(clients = (struct bankClient*)realloc(clients, sizeof(struct bankClient) * (count+2))) ) {
            printf("\n\n\n������ �� ����������!!!\n\n\n");

            getch();
        }

        if( !(pClient = (struct bankClient**)realloc(pClient, sizeof(struct bankClient*) * (count+2))) ) {
            printf("\n\n\n������ �� ����������!!!\n\n\n");

            getch();
        }

        printf("\n\n%s", 
        "  ������� ������� ������� �����: ");
        scanf("%s",(clients+count)->surname);

        printf("%s", 
        "      ������� ��� ������� �����: ");
        scanf("%s",(clients+count)->name);

        printf("%s", 
        " ������� �������� ������� �����: ");
        scanf("%s",(clients+count)->patronymic);
        
        printf("%s", 
        "         ������� ����� �� �����: ");
        scanf("%f", &(clients+count)->accountAmount);

        editDateChange();

        (clients+count)->accountNumber = 34140000 + 7 + count*10;
        (clients+count)->id = count;
        

        printf("\n\n\t*���������� � ������� ����� ��������� � ������ ��������*\n\n\n");
        
        pClient[count] = &clients[count]; 

        count++;

        printf("\n\n������� ��������� ��������? ( 1 - ��, 0 - ��� ): ");
        scanf("%d", &repeat);
    } while( repeat );
}

void printBankClientInfo(void)
{
    printf("\n\n\n\n\n%s\n%s\n%s\n\n\n",
        "      *********************",
        "      *    ����� ������   *",
        "      *********************"
    );

	if ( count == 1 ) {
		printf("\n\n\t*������ �������� ����*\n\n\n\n\n");
	} else {
        for ( int i = 1; i < count; i++ ) {
            printf("\n\n   ������ %d\n\n", pClient[i]->id);
            printf("         ��� ������� �����: %s %s %s\n", pClient[i]->surname, pClient[i]->name, pClient[i]->patronymic);

            printf("               ����� �����: %d\n", pClient[i]->accountNumber);

            printf("            ����� �� �����: %.2f\n", pClient[i]->accountAmount);

            printf(" ���� ���������� ���������: %s\n\n\n", pClient[i]->dateChange);
        }
    }
}

void deleteBankClientInfo(void)
{
    printf("\n\n\n\n\n%s\n%s\n%s\n\n\n",
        "      *********************",
        "      *      ��������     *",
        "      *********************"
    );

	int
        userElement = 0, 
        i = 1;
    short 
        check  = 0,
        repeat = 0;

    do {
        printf("������� ����� ������� ��� �������� ( ID ): ");
	    scanf("%d", &userElement);

	    while ( i <= count && !check ) {
		    if ( userElement == (clients+i)->id ) {
		    	for ( int j = i; j <= count-1; ++j ) {
		    		for ( int k = 0; k < LEN_STR; ++k ) {
		    			(clients+j)->surname[k] = (clients+j+1)->surname[k];
		    		}

		    		for ( int k = 0; k < LEN_STR; ++k ) {
		    			(clients+j)->name[k] = (clients+j+1)->name[k];
		    		}

                    for ( int k = 0; k < LEN_STR; ++k ) {
	    				(clients+j)->patronymic[k] = (clients+j+1)->patronymic[k];
		    		}

	    			for ( int k = 0; k < LEN_DATE; ++k ) {
	    				(clients+j)->dateChange[k] = (clients+j+1)->dateChange[k];
	    			}

	    			(clients+j)->accountNumber = (clients+j+1)->accountNumber;
                    (clients+j)->accountAmount = (clients+j+1)->accountAmount;
	    		}

                int 
                    p      = 1,
                    checkP = 0;

                while( p <= count && !checkP ) {
                    if ( userElement == pClient[p]->id ) {
                        for ( int j = p; j <= count-1; ++j ) {
                            pClient[j] = pClient[j+1];
                        }
                    } 
                    ++p;  
                }

	    		count--;

	    		if( !(clients = (struct bankClient*)realloc(clients, sizeof(struct bankClient) * (count+2))) ) {
                    printf("\n\n\n������ �� ����������!!!\n\n\n");

                    getch();
                }
                if( !(pClient = (struct bankClient**)realloc(pClient, sizeof(struct bankClient*) * (count+2))) ) {
                    printf("\n\n\n������ �� ����������!!!\n\n\n");

                    getch();
                }

	    		printf("\n\n\t*������ � ������� %d ������ �� ������� ��������*\n", userElement);
            
                check = 1;
	    	}
            ++i;
	    }
        if( !check ) {
            printf("\n\n\t*������� � ����� ������� �� �������*\n");
        }
        printf("\n\n������� ��������� ��������? ( 1 - ��, 0 - ��� ): ");
        scanf("%d", &repeat);
        check = 0;
    } while(repeat);
    printf("\n\n\n\n\n");
}

void sortBankClientInfo(void)
{
    printf("\n\n\n\n\n%s\n%s\n%s\n\n\n",
        "      ***********************",
        "      *      ����������     *",
        "      ***********************"
    );

    for(int i = 1 ; i <= count - 1; i++) { 
       for(int j = 1 ; j <= count - i - 1 ; j++) {  
           if((int)(pClient[j]->surname[0]) > (int)(pClient[j+1]->surname[0])) {       
              struct bankClient *temp = pClient[j];
              pClient[j] = pClient[j+1] ;
              pClient[j+1] = temp; 
           }
        }
    }
	printf("\n\n\n\t*������ �������� ������������*\n");
}

void findBankClientInfo(void) 
{
    printf("\n\n\n\n\n%s\n%s\n%s\n\n\n",
        "      ******************",
        "      *      �����     *",
        "      ******************"
    );

	int 
        choise     = 1,
        repeat     = 0,
        check      = 1,
        findInt     = 1;
	char findStr[LEN_STR] = {};

    do {
        toEmptyString(findStr);

        printf("\n\n�������� �������� ������:\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n%s", 
            "(1) ID �������",
            "(2) ������� �������",
            "(3) ��� �������",
            "(4) �������� �������",
            "(5) ����� ����� �������",
            "(6) ����� �� �����",
            "(7) ���� ���������� ���������",
            "������� ��������: "
            );
        scanf("%d", &choise);
        printf("\n\n");
        switch(choise) {

            case 1:

                printf("\n������� ID �������: ");
                scanf("%d", &findInt);

                for ( int i = 1; i <= count; ++i )
                {
                    if ( pClient[i]->id == findInt )
                    {
                        printf("\n\n\t*���������� � ������� �������*\n");
                        printFoundedClientInfo(i);
                        check = 0;
                    }
                }

                if (check) printf("\n\n\t*���������� � ������� �� �������*\n");

                break;


            case 2:

                printf("\n������� ������� �������: ");
                scanf("%s", findStr);

                for (int i = 1; i <= count; ++i)
                {
                    if ( strcmp(findStr, pClient[i]->surname) == 0 )
                    {
                        printf("\n\n\t*���������� � ������� �������*\n");
                        printFoundedClientInfo(i);
                        check = 0;
                    }
                }

                if (check) printf("\n\n\t*���������� � ������� �� �������*\n");

                break;


            case 3:

                printf("\n������� ��� �������: ");
                scanf("%s", findStr);

                for (int i = 1; i <= count; ++i)
                {
                    if ( strcmp(findStr, pClient[i]->name) == 0 )
                    {
                        printf("\n\n\t*���������� � ������� �������*\n");
                        printFoundedClientInfo(i);
                        check = 0;
                    }
                }

                if (check) printf("\n\n\t*���������� � ������� �� �������*\n");

                break;


            case 4:

                printf("\n������� �������� �������: ");
                scanf("%s", findStr);

                for (int i = 1; i <= count; ++i)
                {
                    if ( strcmp(findStr, pClient[i]->patronymic) == 0 )
                    {
                        printf("\n\n\t*���������� � ������� �������*\n");
                        printFoundedClientInfo(i);
                        check = 0;
                    }
                }

                if (check) printf("\n\n\t*���������� � ������� �� �������*\n");

                break;


            case 5:

                printf("\n������� ����� ����� �������: ");
                scanf("%d", &findInt);

                for (int i = 1; i <= count; ++i)
                {
                    if ( pClient[i]->accountNumber == findInt )
                    {
                        printf("\n\n\t*���������� � ������� �������*\n");
                        printFoundedClientInfo(i);
                        check = 0;
                    }
                }

                if (check) printf("\n\n\t*���������� � ������� �� �������*\n");

                break;

            case 6:

                printf("\n������� ����� �� ����� �������: ");
                scanf("%d", &findInt);

                for (int i = 1; i <= count; ++i)
                {
                    if ( pClient[i]->accountAmount == findInt )
                    {
                        printf("\n\n\t*���������� � ������� �������*\n");
                        printFoundedClientInfo(i);
                        check = 0;
                    }
                }

                if (check) printf("\n\n\t*���������� � ������� �� �������*\n");

                break;

            case 7:

                printf("\n������� ���� ���������� ���������: ");
                scanf("%s", &findStr);

                for (int i = 1; i <= count; ++i)
                {
                    if ( strcmp(findStr, pClient[i]->dateChange) == 0 )
                    {
                        printf("\n\n\t*���������� � ������� �������*\n");
                        printFoundedClientInfo(i);
                        check = 0;
                    }
                }

                if (check) printf("\n\n\t*���������� � ������� �� �������*\n");

                break;

            default:
                findBankClientInfo();
	    }
        printf("\n\n������� ��������� ��������? ( 1 - ��, 0 - ��� ): ");
        scanf("%d", &repeat);
    } while( repeat );
    printf("\n\n\n\n\n");
}

void printFoundedClientInfo(int n)
{
	printf("\n\n\n   ������ %d\n\n", pClient[n]->id);
	printf("         ��� ������� �����: %s %s %s\n", pClient[n]->surname, pClient[n]->name, pClient[n]->patronymic);
	printf("               ����� �����: %d\n", pClient[n]->accountNumber);
	printf("            ����� �� �����: %.2f\n", pClient[n]->accountAmount);
    printf(" ���� ���������� ���������: %s\n\n\n", pClient[n]->dateChange);
}


void editBankClientInfo(void) 
{
    printf("\n\n\n\n\n%s\n%s\n%s\n\n\n",
        "      ***************************",
        "      *      ��������������     *",
        "      ***************************"
    );

    int 
        editID = 1,
        choise = 0,
        repeat = 0,
        check = 1,
        editElement = 1;
    char newStr[LEN_STR] = {};

    do {
        editID = 1;
        choise = 0;
        repeat = 0;
        check = 1;
        editElement = 1;

        printf("\n������� ID ������� ��� ��������� ����������: ");
        scanf("%d", &editID);

        for (int i = 1; i <= count; ++i)
        {
            if ( pClient[i]->id == editID ) {
                editElement = i;
                break;
            } else if ( i == count ) {
                printf("\n\n\t*������ � ����� ID �� ������*\n");
                printf("\n\n������� ��������� ��������? ( 1 - ��, 0 - ��� ): ");
                scanf("%d", &repeat);
                repeat == 1 ? editBankClientInfo() : main();
            }
        }

        do {
            toEmptyString(newStr);

            printf("\n\n�������� �������� ������:\n%s\n%s\n%s\n%s\n%s\n%s\n\n%s", 
                "(1) ������� �������",
                "(2) ��� �������",
                "(3) �������� �������",
                "(4) ����� ����� �������",
                "(5) ����� �� �����",
                "(0) �����",
                "������� ��������: "
                );
            scanf("%d", &choise);
            printf("\n\n");

            switch( choise ) {

                case 1:

                    toEmptyString(pClient[editElement]->surname);

                    printf("������� ����� ������� �������: ");
                    scanf("%s", pClient[editElement]->surname);

                    editDateChange(); 

                    printf("\n\n\t*������� ������� ��������*\n");

                    break;


                case 2:

                    toEmptyString(pClient[editElement]->name);

                    printf("������� ����� ��� �������: ");
                    scanf("%s", pClient[editElement]->name);

                    editDateChange(); 

                    printf("\n\n\t*��� ������� ��������*\n");

                    break;


                case 3:

                    toEmptyString(pClient[editElement]->patronymic);

                    printf("������� ����� ������� �������: ");
                    scanf("%s", pClient[editElement]->patronymic);

                    editDateChange(); 

                    printf("\n\n\t*�������� ������� ��������*\n");

                    break;


                case 4:

                    pClient[editElement]->accountNumber = 0;

                    printf("������� ����� ����� ����� �������: ");
                    scanf("%d", pClient[editElement]->accountNumber);

                    editDateChange(); 

                    printf("\n\n\t*����� ����� ������� �������*\n");

                    break;


                case 5:

                    pClient[editElement]->accountAmount = 0;

                    printf("������� ����� ����� �� ����� �������:");
                    scanf("%f", pClient[editElement]->accountAmount);

                    editDateChange(); 

                    printf("\n\n\t*������ ����� �� ����� ������� �������*\n");

                    break;

                case 0:

                    choise = 0;
                    break;

                default:
                    editBankClientInfo();
            }
        } while ( choise != 0 );
    printf("\n\n������� ��������� ��������? ( 1 - ��, 0 - ��� ): ");
    scanf("%d", &repeat);
    } while ( repeat );
}

void toEmptyString( char *string ) {
    for( int i = 0; i < LEN_STR; i++ ) {
        string[i] = '\0';
    }
} 

void editDateChange( void ) 
{
    s_time = time(NULL);
    m_time = localtime(&s_time);
    strftime((clients+count)->dateChange, LEN_DATE, "%d.%m.%Y %H:%M:%S ", m_time);
}