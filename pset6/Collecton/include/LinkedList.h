#ifndef LINKEDLIST_H
#define LINKEDLIST_H


class Nodes{
private:
    int     data;
    Nodes*  _prev;
    Nodes*  _next;
public:
            Nodes();                 // �����������
            ~Nodes();                // ����������

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
    Nodes*   _root;                        // ������ ������
    Nodes*   _end;                         // ��������� �� �����
    int     _size;                        // ������
private:
public:
            LinkedList();                  // �����������
            ~LinkedList();                 // ����������

    void    Add(int data);                 // ����������
    void    Remove(int index);             // ��������
    bool    IsEmpty();                     // ������ ��� ���
    int     Size();                        // ������
    int     GetValByIndex(int index);      // ��������� �������� �� �������
    Nodes*  FindNodeByIndex(int index);    // ����� ���� �� �������
    void    Clear();                       // �������� ����� ������
    void    DisplayList();                 // �����������
};


#endif // LINKEDLIST_H
