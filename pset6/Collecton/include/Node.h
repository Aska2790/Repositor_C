#ifndef NODE_H
#define NODE_H

#include <string>

using namespace std;

class Node{
private:
    Node*   mNext;                              // ��������� �� ��������� �������
    Node*   mPrev;                              // ��������� �� ���������� �������
    string  mKey;                               // ����
    int     mValue;                             // ��������
public:
            Node();
           ~Node();

    void    SetData(string key, int value);     // ���������� ���� ���� ��������
    void    SetPoint(Node *_prev, Node* _next); // ���������� ���� ����������
    void    SetNext(Node* next);                // ������ ��������� �� ��������� �������
    void    SetPrev(Node* prev);                // ������ ��������� �� ��������� �������

    string  GetKey();                           // ������ �����
    int     GetValue();                         // ������ ��������
    Node*   GetNext();                          // ������ ����. �� ����. �������
    Node*   GetPrev();                          // ������ ����. �� ����. �������

    void    Display();                          // ����������� ����� �� ���������
};

#endif // NODE_H
