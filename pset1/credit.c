#include <stdio.h>
#include <cs50.h>


int GetFirstTwoNum(int* array);
int DisplayCard(long long _CardNumber);
int RangeFirstDigit(long long _CardNumber );
void ChangeIntToArray(int* arrayOfDigits, long long number, int iter);
bool LunthAlgorithm(int *array,  int el);
int CountDigitsInCard (long long CardNumber );
bool CheckCountDigitsInCard(long long _CardNumber );
long long getCardNumber();


int main(void)
{
    
   long long temp = 0;      // временная переменная
   temp = getCardNumber();  // получения номера карты пользователя
   DisplayCard(temp);       // отображения результат
}
  
//=================================================================================================

// получение двух первых чисел с карты
int GetFirstTwoNum(int* array)          
{
    int temp = 0;           // временная переменная
    temp =  array[0]*10;    // первый элемент переводим в десятки        
    temp += array[1];       // прибавляем второй элемент массива
    return temp;            // тем самым получаем первый два символа в массиве
}

//=================================================================================================
// Вывод 
int DisplayCard(long long _CardNumber)
{
    int CountDigits = CountDigitsInCard ( _CardNumber );   // количество символов в номере карты
    int _range = RangeFirstDigit(_CardNumber);                    // диапазон первых чисел    
    
    if ((CountDigits == 13 || CountDigits == 16)&&(_range==3)) 
        printf( "VISA\n");
    if ( CountDigits == 16 && _range ==2)     
        printf( "MASTERCARD\n");
    if ( CountDigits == 15 && _range==1)     
        printf( "AMEX\n");
    if (_range==4 || _CardNumber ==0 )  
        printf( "INVALID\n");
        
    return 0;
}
//=================================================================================================
// Диапазон значений производителя карты
int RangeFirstDigit(long long _CardNumber )
{
    int CountDigits = CountDigitsInCard ( _CardNumber );    // количество символов в номере карты
    int array[CountDigits];                                 // массив размером с количество символов в карте    
        
    ChangeIntToArray(array, _CardNumber,CountDigits);       // преобразуем номер карты в массив символов      
    int temp = GetFirstTwoNum(array);                       // получаем первые два символа для определения диапазона
        
    if (temp ==34 || 37== temp)                             // диапазон чисел карт от AMEX
        return 1;
    if (temp  > 50 && 55 >= temp)                           // диапазон чисел карт от MASTERCARD
        return 2;
    if ( temp > 39 && 50 > temp)                            // диапазон чисел карт от VISA
        return 3;    
   
    return 4;
}
//=================================================================================================
// получение массива интов из числа введенного пользователем
void ChangeIntToArray(int* arrayOfDigits, long long number, int iter)
{
    for (int i = iter-1; i >= 0; i--)
    {
        arrayOfDigits[i] = number%10;       // заполнение массива с конца
        number/=10;
    }
}
//=================================================================================================
// Алгоритм Луна для праверги карты
bool LunthAlgorithm(int *array, int counter)    
{
    int result =0;
    
    if (counter%2 == 0)                      // если у нас в карточке четное число символов то
    {
        for (int i = 0 ; i < counter; i++) {// проверка начинается с первого символа
             if (i%2 == 0) {                // каждый четный номер в массиве
                array[i]*=2;                // умножаем на два
                
                if (array[i] > 9)           // если он превышает 9-ти то
                    array[i] -=9;           // отнимаем от него 9-ку
                        
                result += array[i];         // и суммируем
    } else 
            result += array[i];             // а каждое нечетное просто суммируем
        } 
    }
    
    else  {
        result +=array[0];                  // если у нас в карточке нечетное число символов то
             
        for (int i = 1; i < counter; i++){  // проверка начинается с второго символа
            if (i%2 == 0)                   // каждый четный номер в массиве
                result += array[i];         //суммируем    
        else {
                array[i]*=2;                // каждый нечетный номер в массиве 
                if (array[i] > 9)           // если превышает 9    
                    array[i] -=9;       
                    
                result += array[i];         //суммируем 
            }
      }
    }       
    
    
    int temp = result;   // временная переменная               
    result /=10;         // преобразуем в единичное значение
    result*=10;         // переводим в десятки
    
    if (temp-result == 0)   // если не равен нулю
        return true;
    else 
        return false;    
}

//=================================================================================================
// Количество символов в числе
int CountDigitsInCard (long long CardNumber )
{
    long long temp = CardNumber;        
    int iter=0;
    while (temp !=0) {
        temp /= 10;
        iter++;
    }
    return iter;
}
//=================================================================================================

// проверка входных значений
bool CheckCountDigitsInCard(long long _CardNumber )
{
    int CountDigits = CountDigitsInCard (_CardNumber);              // количество символов в карте
    int array[CountDigits];                                         // массив для алгоритма Луна
    ChangeIntToArray(array, _CardNumber, CountDigits);              // преобразуем номер карты в массив символов
    
     if(CountDigits == 13 || CountDigits ==15|| CountDigits ==16) { // если количество символов в заданном диапазоне 
        if( LunthAlgorithm(array, CountDigits))                     // и номер прошел проверку по алгоритму Луна 
            return true;
    }
    return false;
}
//=================================================================================================
// получения номера карты
long long getCardNumber()
{   
    
    long long CardNumber = 0;               // переменная хранящяя высоту лесенки
   
    printf("Number: ");                     // приглашение ввести номер карты
    CardNumber = get_long_long();           // считывание в переменную
    
    if (CheckCountDigitsInCard(CardNumber ))// если номер прошел проверку то
        return CardNumber;                  // вернуть номер карты 
    else return 0;                          
}
//=================================================================================================