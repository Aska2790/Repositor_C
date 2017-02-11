{"filter":false,"title":"mario_less.c","tooltip":"/pset1/mario_less.c","undoManager":{"mark":3,"position":3,"stack":[[{"start":{"row":0,"column":0},"end":{"row":186,"column":0},"action":"remove","lines":["#include <stdio.h>","#include <cs50.h>","","","","int GetFirstTwoNum(int* array);","int DisplayCard(long long _CardNumber);","int Diapazon(long long _CardNumber );","void ChangeIntToArray(int* arrayOfDigits, long long number, int iter);","bool LunthAlgorithm(int *array,  int el);","int CountDigitsInCard (long long CardNumber );","bool CheckCountDigitsInCard(long long _CardNumber );","long long getCardNumber();","","","int main(void)","{","   long long temp;","   temp = getCardNumber();"," ","   DisplayCard(temp);","}","  ","","","// получение двух первых чисел с карты","int GetFirstTwoNum(int* array)          ","{","    int temp =0;","    temp =  array[0]*10;        ","    temp += array[1];","    return temp;","}","","","int DisplayCard(long long _CardNumber)","{","    "," int temp = CountDigitsInCard (_CardNumber );","  ","  int c =Diapazon(_CardNumber);","   if ((temp == 13 || temp == 16)&&(c==3)) ","        printf( \"VISA\\n\");","   if ( temp == 16 && c ==2)     ","             printf( \"MASTERCARD\\n\");","   if ( temp == 15 && c==1)     ","                printf( \"AMEX\\n\");","   if ( c==4 || _CardNumber ==0 )  ","        printf( \"INVALID\\n\");","        return 0;","}","","int Diapazon(long long _CardNumber )","{","    ","    int CountDigits = CountDigitsInCard(_CardNumber);","    ","    int array[CountDigits];","    ChangeIntToArray(array, _CardNumber,CountDigits);","    int temp = GetFirstTwoNum(array);","    ","    ","    if (temp ==34 || 37== temp){","     ","        return 1;}","    if (temp  >=51 && 55 <= temp){","       ","            return 2;}","   if ( temp > 39 && 50 > temp){","          ","                return 3;    }","   ","        return 4;","}","","// получение массива интов из числа введенного пользователем","void ChangeIntToArray(int* arrayOfDigits, long long number, int iter)","{","    for (int i = iter-1; i >= 0; i--)","    {","        arrayOfDigits[i] = number%10;","        number/=10;","    }","}","","bool LunthAlgorithm(int *array, int counter)","{","    int result =0;","    ","    if (counter%2 == 0) {","        for (int i = 0 ; i < counter; i++){","             if (i%2 == 0)","                {","                    ","                    array[i]*=2;","                    if (array[i] > 9) ","                        array[i] -=9;","                        ","                    result += array[i];","    } else ","            result += array[i];","    }        ","    }","    ","    else  {","        result +=array[0];","             ","        for (int i = 1; i < counter; i++){","            if (i%2 == 0)","                result += array[i];","        else {","                array[i]*=2;","                if (array[i] > 9)","                    array[i] -=9;","                result += array[i];","            }","      }","    }       ","    ","    ","    int c = result;","    result /=10;","    result*=10;","    ","    if (c-result == 0)","        return true;","    else ","        return false;    ","        ","    ","}","","","// Количество символов в числе","int CountDigitsInCard (long long CardNumber )","{","    long long temp = CardNumber;","    int iter=0;","    while (temp !=0) {","        temp /= 10;","        iter++;","    }","    return iter;","}","","","// проверка входных значений","bool CheckCountDigitsInCard(long long _CardNumber )","{","    ","    ","    int CountDigits = CountDigitsInCard (_CardNumber);","    ","    int array[CountDigits];","    ","    ChangeIntToArray(array, _CardNumber, CountDigits);","    ","     if(CountDigits == 13 || CountDigits ==15|| CountDigits ==16)","     {","        if( LunthAlgorithm(array, CountDigits))","            return true;","        ","    }","    return false;","    ","}","","","","","// получения номера карты","long long getCardNumber()","{   ","    ","    long long CardNumber = 0;               // переменная хранящяя высоту лесенки","   ","    printf(\"Number: \");                 // приглашение ввести высоту лесенки","        CardNumber = get_long_long();       // считывание в переменную","    ","    if (CheckCountDigitsInCard(CardNumber ))","        return CardNumber; ","    else {","        printf( \"INVALID\\n\");","        return 0;","    }","}",""],"id":2}],[{"start":{"row":0,"column":0},"end":{"row":79,"column":0},"action":"insert","lines":["#include <stdio.h>","#include <cs50.h>","","","bool checkCorrectValue ( int temp );                   // проверка корректности введенного значения","int  getHeight         ( void );                       // получения высоты лесенки","void drawString        ( char symbol, int counter );   //  вывод символов в строку","void display           ( int height );                 // печать лесенки","","","","","int main (void)","{   ","    int temp_value;             // временная переменная","    ","    temp_value = getHeight();   // получения высоты лесенки","    ","    display(temp_value);        // печать лесенки           ","            ","}","","//=================================================================================================","","// проверка корректности введенного значения","bool checkCorrectValue( int temp)","{","    if (!(temp >=0 && temp <=23)) // если число в нужном интервале ","        return true;        ","    else ","        return false;","}","","//=================================================================================================","// получения высоты лесенки","int getHeight()","{   ","    int height = 0;                     // переменная хранящяя высоту лесенки","  ","    do {","        printf(\"Height: \");             // приглашение ввести высоту лесенки","        height = get_int();             // считывание в переменную","        ","    } while (  checkCorrectValue(height));       // до тех пор пока не получим корректного значения","   ","    return height;                      // возврат корректного значения","}","","//=================================================================================================","// печать лесенки","void display (int height)","{","    int temp = height;                  // временная переменная для манипуляций              "," ","    for (int i =0 ; i < height; i++ ){","        temp--;","        ","        drawString( ' ', temp);         // вывод левой","        drawString( '#', height-temp ); // стороны лесенки","        ","        drawString( ' ', 2);            // зазор между лесенками","        ","        drawString( '#', height-temp ); // вывод правой стороны","     // draw( ' ', temp);               // для симметрии но не проходит проверкуcheck50 ","     ","        printf(\"\\n\");                   // завершение цикла печати","        ","    }    ","}","//=================================================================================================","//  вывод символов в строку","void drawString ( char symbol, int counter )","{","    ","for (int i = 0; i < counter; i++ )","    printf(\"%c\", symbol);","    ","}","",""],"id":3}],[{"start":{"row":60,"column":6},"end":{"row":64,"column":5},"action":"remove","lines":["  drawString( ' ', 2);            // зазор между лесенками","        ","        drawString( '#', height-temp ); // вывод правой стороны","     // draw( ' ', temp);               // для симметрии но не проходит проверкуcheck50 ","     "],"id":4}],[{"start":{"row":61,"column":16},"end":{"row":61,"column":17},"action":"insert","lines":["#"],"id":5}]]},"ace":{"folds":[],"scrolltop":120,"scrollleft":0,"selection":{"start":{"row":22,"column":0},"end":{"row":22,"column":99},"isBackwards":false},"options":{"guessTabSize":true,"useWrapMode":false,"wrapToView":true},"firstLineState":{"row":7,"state":"start","mode":"ace/mode/c_cpp"}},"timestamp":1486846941932,"hash":"74fb6e1dbe3a3ab6a53e0e7793d313efb4e74b46"}