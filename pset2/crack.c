/***************************************
 * ********Аннаев Арслан****************
 * ***ProblemSet2(Ш++) pset2/crack.c****
 * **********Брутфорсе******************
 * ************************************/

/**************************************
 * *****Разбор задания ****************
****1. Получить хеш
****2. Извлечь солт
****3. Брутфорсе
****4. Вывести на экран пароль
**************************************/
/**************************************
 * andi - 50aodB7xwypJE
 * rofl - 50fkUxYHbnXGw
 * Aska - 507tgVQTCDcUQ
 * 
 * 
 * *************************************/
#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>  		// стандартная библиотека ввода вывода
#include <cs50.h>   		// библиотека для cs50 IDE
#include<string.h>			// библиотека функции strcmp()
#include <crypt.h>			// библиотека фунции для crypt()


#define symbol_count 4		// количество символов в пароле

//========================================================================

void brutforce(char* str,int index, int len, char* salt, char* word);		// перебор пароля в цикле
void crack_password(char* password,char* st, char* word );					// функция сравнения хеша
void getSalt(char* str);													// получение солт-а


char* ecrypted_word;														// хеш пароля
char  salt[3];																// солт	пароля


//========================================================================
// точка входа
int main(int argc, char* argv[])
{


// если принимаемых аргументов больше двух
	if (argc != 2)
    {
        printf("Usage: ./crack hash\n");	// инструкция по запуску программы	
        return 1;							// вернуть ошибку
    }

	ecrypted_word = argv[1];				// присваеваем хеш
	getSalt(ecrypted_word);					// извлекаем солт из хеша
	
	char pass[5] = {'A','A','A','A','\0'};	// начальная инициализация
	
	
// crack хеша	
    for (int i = 1; i <= symbol_count+1; i++)
         brutforce(pass, 0, i-1, salt, ecrypted_word);

	return 0;
}
//========================================================================

// извлечение солт-а
void getSalt(char* str)
{
    salt[0] = str[0];		// первый элемент солт-а
    salt[1] = str[1];		// второй элемент солт-а
}


// перебор пароля
void brutforce(char* str,int index, int len, char* st, char* word)
{  
	// если индекс меньше порядкового номера пароля
	if(index < (len-1)) {
        for (char i = 'A'; i <= 'z'; i++) 			// перебор всех символов латинского алфавита
        {	
            str[index] = i;							// изменяем значение в массиве(перебираем)
            brutforce(str, index+1, len,st, word ); // углубляемся в рекурсию до тех пор пока индекс не 
        }											// будет больше или равен порядковому номеру пароля
    }
      else {
        for (char i = 'A'; i <= 'z'; i++)			// иначе если индекс больше или равен 
        {
            str[index] = i;							// перебираем пароль
            crack_password(str,st, word);			// сравниваем с хешом	
        }
    }
}

// сравнения пароля с хеш строкой
void  crack_password(char* password,char* st, char* word )
{
    if(strcmp(word, crypt(password, st)) == 0)		// если при переборе получим совпадение 
    {
        printf("\nPassword: %s", password);			// печатаем пароль
        exit(0);
    }
}
