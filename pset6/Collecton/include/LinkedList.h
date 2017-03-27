#ifndef LINKEDLIST_H
#define LINKEDLIST_H


class Nodes{
private:
    int     data;
    Nodes*  _prev;
    Nodes*  _next;
public:
            Nodes();                 // конструктор
            ~Nodes();                // деструктор

    Nodes*  GetPrevPoint();
    Nodes*  GetNextPoint();
    int     GetData();

    void    SetData(int data);
    void    SetNextNull();
    void    SetPrevPoint(Nodes *prev);
    void    SetNextPoint(Nodes *next);

    void    DisplayData();
};



class LinkedList{
    Nodes*   _root;                        // голова списка
    Nodes*   _end;                         // указатель на конец
    int     _size;                        // размер
private:
public:
            LinkedList();                  // конструктор
            ~LinkedList();                 // деструктор

    void    Add(int data);                 // добавление
    void    Remove(int index);             // удаление
    bool    IsEmpty();                     // пустой или нет
    int     Size();                        // размер 
    int     GetValByIndex(int index);      // получение элемента по индексу
    Nodes*  FindNodeByIndex(int index);    // поиск узла по индексу
    void    Clear();                       // удаление всего списка
    void    DisplayList();                 // отображение
};


#endif // LINKEDLIST_H
