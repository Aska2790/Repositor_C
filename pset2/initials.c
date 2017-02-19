
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


char * getUserName();
void PrintUserInitials(string str);



int main(void)
{
   char * ptr;
   ptr = getUserName();
   PrintUserInitials(ptr);
}


//=============================================================================
// получение полного имени 
char * getUserName()
{
    char * UserName;
    do {
    UserName = (char *)get_string() ;
    }while ( UserName == NULL);
    
    return UserName;
}


//=============================================================================
// отображение инициалов
void PrintUserInitials(char* cptr)
{
    char * ptr = strtok (cptr," ,.-");  // разбиение на лексемы
   
    while (ptr != NULL) {               
    printf("%c",toupper( ptr[0]));
    ptr = strtok (NULL, " ,.-");        // для цикла
    }
    printf("\n");
}