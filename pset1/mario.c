#include <stdio.h>
#include <cs50.h>


bool checkCorrectValue ( int temp );                   // проверка корректности введенного значения
int  getHeight         ( void );                       // получения высоты лесенки
void drawString        ( char symbol, int counter );   //  вывод символов в строку
void display           ( int height );                 // печать лесенки




int main (void)
{   
    int temp_value;             // временная переменная
    
    temp_value = getHeight();   // получения высоты лесенки
    
    display(temp_value);        // печать лесенки           
            
}

//=================================================================================================

// проверка корректности введенного значения
bool checkCorrectValue( int temp)
{
    if (!(temp >=0 && temp <=23)) // если число в нужном интервале 
        return true;        
    else 
        return false;
}

//=================================================================================================
// получения высоты лесенки
int getHeight()
{   
    int height = 0;                     // переменная хранящяя высоту лесенки
  
    do {
        printf("Height: ");             // приглашение ввести высоту лесенки
        height = get_int();             // считывание в переменную
        
    } while (  checkCorrectValue(height));       // до тех пор пока не получим корректного значения
   
    return height;                      // возврат корректного значения
}

//=================================================================================================
// печать лесенки
void display (int height)
{
    int temp = height;                  // временная переменная для манипуляций              
 
    for (int i =0 ; i < height; i++ ){
        temp--;
        
        drawString( ' ', temp);         // вывод левой
        drawString( '#', height-temp ); // стороны лесенки
        
        drawString( ' ', 2);            // зазор между лесенками
        
        drawString( '#', height-temp ); // вывод правой стороны
     // draw( ' ', temp);               // для симметрии но не проходит проверкуcheck50 
     
        printf("\n");                   // завершение цикла печати
        
    }    
}
//=================================================================================================
//  вывод символов в строку
void drawString ( char symbol, int counter )
{
    
for (int i = 0; i < counter; i++ )
    printf("%c", symbol);
    
}

