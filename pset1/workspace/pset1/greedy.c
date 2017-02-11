#include <stdio.h>
#include <cs50.h>
#include <math.h>



bool checkCorrect (float interval);     // проверка корректности 
float greeting    ( void);              // получения значения от пользователя
void DisplayValue ( float changies);    // отображения результата
float roundValue  ( float roundMoney);  // Округление для точности 




int main(void)
{
   
   float temp = 0;
   temp = greeting();
   temp = roundValue(temp);
   DisplayValue(temp);
}






//* проверка корректности 
bool checkCorrect(float interval)
{
    if (!(interval >0 && interval < 100))
    return true;
    else
    return false;
}


// *получения значения от пользователя
float greeting()
{
    printf("O hai! How much change is owed?\n");
    
    float gettinMoney = 0 ;
    do {
        printf("How much change is owed?\n");
        gettinMoney = get_float(); 
        
    } while (checkCorrect(gettinMoney) );
    
    return gettinMoney;
}



// отображения результата
void DisplayValue(float changies)
{
    int counts =0;
    while (changies >= 25) {
        changies -=25;
        counts ++;
    }
    
     while (changies >=10) {
        changies -=10;
        counts ++;
    }  
    
    while (changies >=5) {
        changies -=5;
        counts ++;
    }  
    
    while (changies > 0) {
        changies -=1;
        counts ++;
    }
   printf("%d%s", counts, "\n");  
}



//* Округление для точности 
float roundValue(float roundMoney)
{
    roundMoney *=100;
    roundMoney = round(roundMoney);
    return roundMoney;
}
