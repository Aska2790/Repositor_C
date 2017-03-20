/***************************************
 * ********Аннаев Арслан****************
 * ***ProblemSet5(Ш++) pset5/speller.c**
 * ************ООП*********************
 * ** Проверка орфографии**************
 * ************************************/

#ifndef SPELL_H
#define SPELL_H
#include <string>
#include <fstream>
#include <vector>
#include <ctime>

class Spell
{
private:

    double load_time;               // время загрузки
    double check_time;              // время на проверку
    double size_time;               // время для определения размера
    double unload_time;             // время освобождения памяти

    int misspelling;                // количество орфография ошибок

    int word_in_dictionary;         // количество букв в словаре
    int word_in_text;               // количество букв в тексе

    int dictionary_size;            // размер словаря в байтах
    int text_size;                  // размер текста в байтах

    std::vector <std::string> lib;  // вектор для словаря
    std::vector <std::string> txt;  // вектор для текста

    struct timespec begin;          // структура для определения процессорного времени начало
    struct timespec finish;         // структура для определения процессорного времени конец

public:
    Spell();
    ~Spell();
    void Misspell(std::string path,         // проверка орфографии
                  std::string dict);
    void Report();                          // отображение результата проверки
    void LoadDictionary( std:: string dict);
    void LoadText(std::string path);
    void UnloadDictionary();
    double Total();                         // общее время проверки текста
    bool CheckWord(std::string word);       // сверка слова с словарем

    double Calculate(struct timespec &beg, // посчет времени
                     struct timespec &end );

};

#endif // SPELL_H
