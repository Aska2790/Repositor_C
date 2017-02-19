/***************************************
 * ********Аннаев Арслан****************
 * ***ProblemSet2(Ш++) pset2/crack.c****
****Программка для тестирования crack.c
 * ************************************/


#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>  								// стандартная библиотека ввода вывода
#include <cs50.h>   								// библиотека для cs50 IDE
#include <crypt.h>									// библиотека фунции для crypt()


string crypting(string str1, string str2);			// Шифрование пароля
void testing (string prog, string pass);			// тестируем

int main()
{
	
   string programs_name = "crack";
   printf("Plese enter the password(4 symbol)\n");  // приглашение ввести пароль
   string password = get_string();                  // ввод пароля
   printf("Plese enter the salt\n");                // приглашение ввести солт
   string salt = get_string();                      // ввод пароля
   
   string encrypted_password = crypting(password, salt); 
   
   printf("%s", encrypted_password );                // отображение полученного результата
   
   testing(programs_name, encrypted_password );		 // тестируем	
   
  
}


// Шифрование пароля
string crypting(string str1, string str2)
{
	string temp = crypt(str1, str2);				// преобразование пароля в хешстроку  
	return temp;
}

// тестируем
void  testing (string prog, string pass)
{
   printf("\nTest our password(please wait)\n" ); 	// Тестируем пароль
    execl(prog," ",pass,  NULL);                	// Вызов программы crack.c
	
}

