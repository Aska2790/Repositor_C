#ifndef HASHMAP_H
#define HASHMAP_H

#include <string>
#include "Node.h"


// ���������� ���� � �������� ������������� ���������� ������
const int BUCKET_SIZE = 26;

class HashMap
{
private:
    Node*   table[BUCKET_SIZE];                 // ������� ���������� (hash table)
public:
            HashMap();                          // �����������
            ~HashMap();                         // ����������

    int     HashFunction(std::string key);       // hash �������

    void    Erase(std::string key);              // �������� �������� �� �����
    void    Insert(std::string key, int value);  // ������� �������� � ����� ������
    int     FindElement(std::string key);        // ����� �������� �� �����
    Node*   Find(std::string key);               // ����� �������� ������

};

#endif // HASHMAP_H
