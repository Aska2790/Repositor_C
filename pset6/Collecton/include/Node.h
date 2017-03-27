#ifndef NODE_H
#define NODE_H

#include <string>

using namespace std;

class Node{
private:
    Node*   mNext;                              // указатель на следующий элемент
    Node*   mPrev;                              // указатель на предыдущий элемент
    string  mKey;                               // ключ
    int     mValue;                             // значение
public:
            Node();
           ~Node();

    void    SetData(string key, int value);     // установить пару ключ значение
    void    SetPoint(Node *_prev, Node* _next); // установить пару указателей
    void    SetNext(Node* next);                // сеттер указателя на следующий элемент
    void    SetPrev(Node* prev);                // сеттер указателя на следующий элемент

    string  GetKey();                           // геттер ключа
    int     GetValue();                         // геттер значения
    Node*   GetNext();                          // геттер указ. на след. элемент
    Node*   GetPrev();                          // геттер указ. на пред. элемент

    void    Display();                          // отображения ключа со значением
};

#endif // NODE_H
