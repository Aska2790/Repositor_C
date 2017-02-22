/***************************************
 * ********Аннаев Арслан****************
 * **ProblemSet2(Ш++) pset2/vigenere.c**
 * **Шифрование по алгоритму Viginere***
 * ************************************/

/**************************************
 * *****Разбор задания ****************
****1. Получить ключ
****2. Получить текст
****3. Зашифровать
****4. Вывести на экран зашифрованный текст
***********************************/

#include <stdio.h>  // стандартная библиотека ввода вывода
#include <cs50.h>   // библиотека для cs50 IDE
#include <string.h> // для работы strlen()
#include <ctype.h>  // библиотека функций isaplha(), isupper(), islower() 

//===============================================================================================
const char *ALPHLOW = "abcdefghijklmnopqrstuvwxyz";      // буквы нижнего регистра
const char *ALPHUP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";       // буквы верхнего регистра
const int  NUMBERLETTER = 26;                            // количество букв


int   getSymbolNumber   (char symbol);                    // получение номера символа для смещения
char  getOffsetSymbol   (char userSymbol, char keySymbol);// символ со смещением
char *getPlainText      (void);                           // получение строки от пользователя
void  displayCipherText (char *encryptedline);            // Вывод зашифрованного текста
char *vigenerShifr      (char *userLine, char* keys);     // Шифр Видженера
bool  checkTheKey       (char *keys);                     // проверка ключа 



//===============================================================================================
// точка входа в программу
int main(int argc, string argv[])
{
    if (argc !=2) {                                     // если количество аргументов с командной строки больше одного
        printf("Usage: ./caesar k\n");                  // инструкция по вызозу программы
        return 1;
    }
    
    if (!checkTheKey(argv[1])) {                        // проверка ключа на содержания символов отличных от букв
        printf("Usage: ./caesar k\n");
        return 1;
    }
        
    char *key = argv[1];                                // корректный ключ из командной строки
    char* user_string = getPlainText();                 // строка пользователя
    char* encrypted = vigenerShifr( user_string ,key);  // шифруем сообщение
    
    displayCipherText(encrypted);                       // отображаем результат      
    
    return 0;
}



//===============================================================================================
// получение строки от пользователя
char* getPlainText()
{
    printf("plaintext: ");          // приглашение ввести строку 
    return get_string();            // ввод строки и вернуть в майн    
}

//===============================================================================================
// Вывод зашифрованного текста
void displayCipherText (char* encryptedline)
{
    printf("ciphertext: %s%s", encryptedline, "\n");
}

//===============================================================================================
// получение номера символа для смещения
int getSymbolNumber(char symbol)
{
    int SymbolNumber;                                       // номер символа
    for (int j = 0; j < NUMBERLETTER; j++)                  // проход по массиву
        if ((symbol == ALPHLOW[j])||(symbol== ALPHUP[j]))   // определения номера
            SymbolNumber = j;
    return  SymbolNumber;
}

//===============================================================================================
// символ со смещением
char getOffsetSymbol(char userSymbol, char keySymbol)
{   
    char result;                                            // символ со смещением
    int key = getSymbolNumber(keySymbol);                   // получаем смещение ключа
    
    if(isupper(userSymbol))                                 // для заглавных букв
        result = (userSymbol-'A' + key)%NUMBERLETTER +'A';
    if(islower(userSymbol))                                 // для строчных букв
        result = (userSymbol-'a' + key)%NUMBERLETTER +'a';
        return result;
}

//===============================================================================================
// Шифр Видженера
char* vigenerShifr(char *userLine, char *keys)
{
    int overflowController = 0;                     // для соблюдения длины ключа
    int len = strlen(keys);                         // длина ключа
    
    for(int i = 0; i < strlen(userLine); i++)       // проход по все строке
    {
        if(isalpha(userLine[i]))                    // исполнять только на буквах
        {
            if(overflowController >= len)           // если итератор больше длины строки
                overflowController = 0;             // обнуляем его
            
            // получаем символ со смещением
            userLine[i]= getOffsetSymbol(userLine[i],keys[overflowController]);
            overflowController++;                   // после коррекного завершения инкрементируем
        }
    }
      return userLine;                              // результат строка со смещением по ключу
}


//===============================================================================================
// проверка ключа 
bool checkTheKey (char* keys)
{
    for (int i = 0; i < strlen(keys); i++){
        if (!isalpha(keys[i]))              // если в строке есть не буква))
            return false;                   // то выдаем ошибку
    }
    return true;                            // в противном слоучае все ок
}

//===============================================================================================