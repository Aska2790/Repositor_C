/***************************************
 * ********Аннаев Арслан****************
 * ***ProblemSet4(Ш++) pset5/speller.c**
 * ************ООП*********************
 * ** Проверка орфографии**************
 * ************************************/
#include <iostream>
#include "spell.h"

using namespace std;

int main()
{
    string path =  "G:\\1.txt";                         // проверяемый текст
    string dict =  "D:\\Program_listings\\speller\\dictionaries\\large.txt"; // словарь
    Spell *object = new Spell();                        // обьект класса проверки
    object->Misspell(path, dict);                       // проверяем
    object->Report();                                   // результат
    return 0;
}
