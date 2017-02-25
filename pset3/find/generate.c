/**
 * generate.c
 * Generates pseudorandom numbers in [0,MAX), one per line.
 * Usage: generate n [s]
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>                                   // библиотека для cs50 IDE
#include <stdio.h>                                  // стандартная библиотека ввода вывода
#include <stdlib.h>                                 // библиотека srand48()  drand48()
#include <time.h>                                   // библиотека для time()


#define LIMIT 1000                                  // Ограничение максимальное значения

int main(int argc, string argv[])
{
    
    if (argc != 2 && argc != 3){                    // если количество элементов не равно двум или трем
        printf("Usage: ./generate n [s]\n");        // инструкция вызова программы   
        return 1;                                   // не корректное завершение
    }
    
    int n = atoi(argv[1]);                          // преобразуем второй аргумент в целочисленную переменную
    
    if (argc == 3)                                  // если у нас имеется третий аргумент 
        srand48((long) atoi(argv[2]));              // он будет задавать зерно для случайных чисел
    else
        srand48((long) time(NULL));                 // иначе значение будет по умолчанию и работает при помощи аргумента времени 
    
    // отображение псевдослучайного числа
    for (int i = 0; i < n; i++)                     // вывести в консоль псевдослучайное число в интервале
        printf("%i\n", (int) (drand48() * LIMIT));  // от 0 < digit < LIMIT           
    
    return 0;
}
