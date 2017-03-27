#ifndef HASHMAP_H
#define HASHMAP_H

#include <string>
#include "Node.h"


// количество букв в алфавите соответствует количеству корзин
const int BUCKET_SIZE = 26;

class HashMap
{
private:
    Node*   table[BUCKET_SIZE];                 // таблица указателей (hash table)
public:
            HashMap();                          // конструктор
            ~HashMap();                         // деструктор

    int     HashFunction(std::string key);       // hash функция

    void    Erase(std::string key);              // удаление элемента по ключу
    void    Insert(std::string key, int value);  // вставка элемента в конец списка
    int     FindElement(std::string key);        // поиск значения по ключу
    Node*   Find(std::string key);               // поиск элемента списка

};

#endif // HASHMAP_H
