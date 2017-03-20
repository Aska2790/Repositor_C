#include "spell.h"
#include <ctime>            // работа с процессорным временем
#include <sys/types.h>      // работа с процессорным временем
#include <errno.h>          // работа с процессорным временем
#include <string>           // строковой класс
#include <cstring>          // манипуляция с символами
#include <iostream>         // стандартная библиотека ввода вывода в консоль
#include <fstream>          // стандартная библиотека файлового ввода вывода

#define NS_IN_S  1E9        // константный делитель наносекунд

//конструктор по умолчанию
Spell::Spell()
{
    load_time =0;
    check_time =0;
    unload_time=0;
    size_time=0;

    misspelling = 0;

    word_in_dictionary = 0;
    word_in_text = 0;

    dictionary_size = 0;
    text_size =0;
}
// деструктор
Spell::~Spell()
{
    std::cout << "\nI am destructor" << std::endl;
}
// проверка орфографии
void Spell::Misspell(std::string path, std::string dict){
    LoadDictionary(dict);                                   // загружаем словарть
    LoadText(path);                                         // загружаем текст

    for (int i=0;i<word_in_text; i++){                      // сверяем со словарем
        if(!CheckWord(txt[i])){
            misspelling++;                                  // если вышла ошибка
           std:: cout << "# " << i << " - "
                      << txt [i] << std::endl;              // выводим ошибку
        }
    }
}
// загрузка словаря из файла
void Spell::LoadDictionary(std::string dict){

    std::ifstream dictionary;                   // обьект файлового потока
    dictionary.open(dict);                      // открываем файлл
    if(!dictionary.is_open()){                  // если не вышло
        std::cout << "Dictionary couldn`t open" << std::endl;
        exit(1);                                // завершаем
    }

    dictionary.seekg(0,dictionary.end);         // указатель в файле перемещаем на конец
    dictionary_size = dictionary.tellg();       // определяем длину файла
    dictionary.seekg(0,dictionary.beg);         // возвращаем указатель в начало

    std::string temp;
                                                // начинаем замерять время
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin);
    while(getline(dictionary,temp)){            // так как в словаре слова идут отдельно в каждой строке
       temp[0] = tolower(temp[0]);              // если вдруг первый символ будет заглавным
        lib.push_back(temp);                    // помещаем в наше хранилище словаря
    }                                           // конец отсчета
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &finish);

    load_time = Calculate(begin, finish);       // подсчет времени потраченное на операцию загрузку

                                                 // начинаем замерять время
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin);
    word_in_dictionary = lib.size();            // определяем количество слов в словаре словаря
                                                // конец отсчета
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &finish);
    size_time =  Calculate(begin, finish);      // подсчет времени потраченное на операцию

    dictionary.close();                         // закрываем обьект файлового потока
}
// загрузка текста для проверки
void Spell::LoadText(std::string path){
    std::ifstream text;                         // обьект файлового потока
    text.open(path);                            // открываем файлл
    if(!text.is_open()){                        // если не вышло
        std::cout << "Text couldn`t open" << std::endl;
        exit(1);                                // завершаем
    }
    text.seekg(0,text.end);                     // указатель в файле перемещаем на конец
    text_size = text.tellg();                   // определяем длину файла
    text.seekg(0,text.beg);                     // возвращаем указатель в начало

    std::string temp;

    while(!text.eof()){                         // пока не достигнем конца файла
        getline(text,temp,' ');                 // считываем слово до пробела
        temp[0] = tolower(temp[0]);             // смена регистра первого символа
        txt.push_back(temp);                    // помещаем во временое хранилище
    }

    word_in_text = txt.size();                  // размер нашего файла
    text.close();                               // закрываем файл
}
// Общее время потраченое на проверку
double Spell::Total(){
    return load_time + check_time+ unload_time + size_time;}
// отображение результата
void Spell:: Report(){
    std::cout << "\n\nWORDS MISSPELLED: "<< misspelling << std::endl;
    std::cout << "WORDS IN DICTIONARY: "<< word_in_dictionary<< std::endl;
    std::cout << "WORDS IN TEXT:  "<< word_in_text << std::endl;
    std::cout << "Dictionary size in byte: "<< dictionary_size << std::endl;
    std::cout << "Text size in bytes: "<< text_size << std::endl;
    std::cout << "Time in load: "<< load_time << std::endl;
    std::cout << "Time in check: "<< check_time << std::endl;
    std::cout << "Time in Size: "<< size_time << std::endl;
    std::cout << "Time in unload: "<< unload_time << std::endl;
    std::cout << "Time in total: "<< Total() << std::endl;
}
// освобождение памяти
void Spell::UnloadDictionary(){
   clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin);     // начало замера времени
   txt.clear();                                         // освобождаем хранилище
   if(txt.size()!=0)                                    // проверка
       std::cout << "Memory is not freed" << std:: endl;

   clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &finish);    // конец замера времени
   unload_time =  Calculate(begin, finish);             // время затраченное на операцию

}
// проверка слова
bool Spell::CheckWord(std:: string word){
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin);     // начало замера времени
    int iter = lib.size();                               // пройтись по всему хранилищу
    int len = word.length();                            // длина слова которое проверяем

     if(!isalpha(word[0])){                             // если в слове есть знаки пунктуации (  (,),.)
         word.erase(0,1);                               // удаляем

     }
     if(!isalpha(word[len-1]) ){                        // если в конце есть знаки
            word.erase(len-1, 1);                       // удаляем
     }

    for(int i =0; i < iter; i++){                       // сверка со словарем
        if(word == lib[i])                              // если есть такое слово
            return true;
    }

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &finish);   // конец замера времени
    check_time +=  Calculate(begin, finish);            // время затраченное на операцию
    return false;

}
// подсчет времени
double Spell::Calculate(struct timespec &beg,struct timespec &end ){
    struct timespec duration;                               // промежуточная переменная
    if ((end.tv_nsec - beg.tv_nsec) < 0) {                  // реализация предусматриваем
           duration.tv_sec = end.tv_sec - beg.tv_sec - 1;
           duration.tv_nsec = NS_IN_S + end.tv_nsec - beg.tv_nsec;
       }
    else{
        duration.tv_sec = end.tv_sec - beg.tv_sec;
        duration.tv_nsec = end.tv_nsec - beg.tv_nsec;
    }

    double result = duration.tv_sec + duration.tv_nsec / NS_IN_S;// результат в секундах
    return result;
}

//=========================================
