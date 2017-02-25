/**
 * helpers.c
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>                        // библиотека для cs50 IDE
#include "helpers.h"                     // загаловочный файл helpers.c



//Бинарный поиск отсортированного массива
bool search(int value, int values[], int n)
{
    if (n > 0) {                          // если количество элементов в массиве меньше нуля
        
    int low = 0;                          // начало области поиска
    int high = n - 1;                     // конец области поиска
    int middle = 0;                       // среднее значение
        
    while (low <= high) {                 // пока число начальное меньше или равно конечному
        middle = (low + high) / 2;        // нахождение середины
        if(value == values[middle])       // если польз. число равно значение середины
            return true;                  // вернуть True
        else 
            if (value > values[middle])   // если польз. число больше значения середины
                low = middle + 1;         // младшему присвоить 
            else         
                high = middle - 1;     
    }
  } 
    return false;
}

// Cортировка вставкою
void sort(int values[], int n)
{
    int  item;                                      // индекс предыдущего элемента
    int temp;                                       // временная переменная

    for (int i = 1; i < n; i++) {
            temp = values[i];                       // сохраняем текущее значение
            item = i-1;                             // запоминаем индекс предыдущего элемента массива
            
            while(item >= 0 && values[item] > temp) // пока индекс не равен 0 и предыдущий элемент массива больше текущего
            {                                       // перестановка элементов массива 
               values[item + 1] = values[item];     // больший элемент прокидываем вперед 
               values[item] = temp;                 // на его место размещаем меньшее значение
               item--;                      
            }
    }

}






     