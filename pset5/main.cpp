/***************************************
 * ********������ ��᫠�****************
 * ***ProblemSet4(�++) pset5/speller.c**
 * ************���*********************
 * ** �஢�ઠ ��䮣�䨨**************
 * ************************************/
#include <iostream>
#include "spell.h"

using namespace std;

int main()
{
    string path =  "G:\\1.txt";                         // �஢��塞� ⥪��
    string dict =  "D:\\Program_listings\\speller\\dictionaries\\large.txt"; // ᫮����
    Spell *object = new Spell();                        // ��쥪� ����� �஢�ન
    object->Misspell(path, dict);                       // �஢��塞
    object->Report();                                   // १����
    return 0;
}
