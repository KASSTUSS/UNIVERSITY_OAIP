/*
    ������������ ������ �12( 7 ������� ) �� ��������: 
        "������ �������������� � ����������������(����)".

    ������������ �����: 
        ������� ���-������� �� ��������� ����� � ����� � ��� 
    ����� �����, ����������� ������������ �������� �����.
    
    ����������� � ����������� �������:
        � ������� �� ���������� ����������� ������, ������� 
    ���-�������� ����� ��������� ������ ������. 
        � ���� ���������� �������, � ����� ��������� (�������)
    ������� ����� ������������ � ����� �, � ������ ���� �����
    ������, �� ����� ���������� ������. ����� ������� � ��������
    ����� ����� ������������ ������� � ����� �� ���� ������������
    �� ��������. 
        ����� ������������� �������� ����� ������������ �� 
    ��������� ������ � �������. ������������ �������� ����� ��������
    �������� �������.
    
    ��������: 
        ������� ������ ��-12 ������ �.�.
    01.06.2021
*/
#include <stdio.h>
#include <stdlib.h> 
#include <malloc.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

#define N 10
#define F 0.6180339887

struct Bucket
{
    int    value;
    short  info;
    struct Bucket* pointer;
    struct Bucket* next;
};

struct Bucket data[N];
struct Bucket HashTable[N];

void setup( struct Bucket *str );
void addElementToTable( int key, struct Bucket *data, struct Bucket *str, int iteration );
void addNewElementToEmptyPlace( int index, int key, struct Bucket *data, struct Bucket *str, int iteration );
void addNewLinkListItem( int index, int key, struct Bucket *data, struct Bucket *str, int iteration );

int getRandomNumber( int a, int b );
int findIndexMaxElement( struct Bucket *str );
int HF( int key );

int main( void )
{
    setlocale( LC_ALL, "Russian" );

    setup(HashTable);

    

    for( int i = 0; i < N; i++ )
        addElementToTable( getRandomNumber(0,N*10), data, HashTable, i );
    
    printf("\n\n<���-�������>\n\n\n");
    for(int i = 0; i < N; i++) {
        if(HashTable[i].info != 0) {
            printf("{������[%d]: %d}", i+1, HashTable[i].value);
            int check = 0;
            if(HashTable[i].next == 0) {
                printf(";\n\n");
            } else {
                printf(" -> {������[%d]: %d}", i+1, (HashTable[i].next)->value);
                int check = 0;
                do {
                    struct Bucket* pointer = (HashTable[i].next)->next;
                    if( pointer != 0 ) {
                        check = 1;
                        printf(" -> {������[%d]: %d}", i+1, pointer->value);
                    } else {
                        check = 0;
                        printf(";\n\n");
                    }
                } while( check );
            }
        } else {
            printf("{������[%d]: ������};\n\n", i+1);
        }
    }
    
    printf("\n---------------------------------------------\n����� ����� � ������������ ��������� �����: %d", findIndexMaxElement(HashTable));

    

    getch();
    return 0;
}

void setup( struct Bucket *str )
{
	for ( int i = 0; i < N; i++ )
	{
		data[i].info = 0;
		data[i].next = NULL;
        data[i].pointer = (data+i);

        (str+i)->info = 0;
        (str+i)->value = 0;
        (str+i)->next = NULL;
	}
}

int HF( int key )
{
    int x = N;
    double y = 0.618033;

    int h = x*fmod( key*y, 1 );

    

    return h;
}

void addElementToTable( int key, struct Bucket *data, struct Bucket *str, int iteration )
{
    int temp = HF(key);

    if( (str+temp)->info == 0 ) {
        addNewElementToEmptyPlace( temp, key, data, str, iteration );
    } else {
        addNewLinkListItem( temp, key, data, str, iteration );
    }
}

void addNewElementToEmptyPlace( int index, int key, struct Bucket *data, struct Bucket *str, int iteration )
{
    data[iteration].info = 1;
    data[iteration].value = key;
    str[index].info = data[iteration].info;
    str[index].value = data[iteration].value;
    str[index].next = data[iteration].next;
    str[index].pointer = data[iteration].pointer;
}

void addNewLinkListItem( int index, int key, struct Bucket *data, struct Bucket *str, int iteration )
{
    
    data[iteration].info = 1;
    data[iteration].value = key;

    if( key > str[index].value ) {
        data[iteration].next = str[index].pointer;
        str[index].info = data[iteration].info;
        str[index].value = data[iteration].value;
        str[index].next = data[iteration].next;
        str[index].pointer = data[iteration].pointer;
    } else {
        data[iteration].next = str[index].next;
        str[index].info = data[iteration].info;
        str[index].value = data[iteration].value;
        str[index].next = data[iteration].pointer;
    }
    
}

int getRandomNumber( int a, int b ) 
{
    return a + rand() % b;
}

int findIndexMaxElement( struct Bucket *str )
{
    int indexMax = 0;
    int max = str[indexMax].value;

    

    for( int i = 1; i < N; i++ )
        if( max < str[i].value )
        {
            indexMax = i;
            max = str[indexMax].value;
        }

    return indexMax+1;
}