#include "Node.h"
#include <string>
#include <iostream>

using namespace std;


Node::Node()
{

}

Node::~Node()
{
    delete this->mNext;
    delete this->mPrev;
}

// ���������� ���� ���� ��������
 void Node::SetData(string key, int value){
        mKey = key;
        mValue = value;
}

// ���������� ���� ����������
void Node::SetPoint(Node *_prev, Node* _next){
        mPrev =_prev;
        mNext = _next;
}

// ������ ��������� �� ��������� �������
void Node::SetNext(Node* next){
        mNext = next ;
}

// ������ ��������� �� ��������� �������
void Node::SetPrev(Node* prev){
        mPrev = prev;
}

// ������ �����
string Node::GetKey(){
        return mKey;
}

// ������ ��������
int Node::GetValue(){
        return mValue;
}

// ������ ����. �� ����. �������
Node* Node::GetNext(){
        return mNext;
}

// ������ ����. �� ����. �������
Node* Node::GetPrev(){
        return mPrev;
}

// ����������� ����� �� ���������
void Node::Display(){
        cout << "this is key  " << GetKey() << endl;
        cout << "this is value "<<GetValue() << endl;

}
