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

// установить пару ключ значение
 void Node::SetData(string key, int value){
        mKey = key;
        mValue = value;
}

// установить пару указателей
void Node::SetPoint(Node *_prev, Node* _next){
        mPrev =_prev;
        mNext = _next;
}

// сеттер указателя на следующий элемент
void Node::SetNext(Node* next){
        mNext = next ;
}

// сеттер указателя на следующий элемент
void Node::SetPrev(Node* prev){
        mPrev = prev;
}

// геттер ключа
string Node::GetKey(){
        return mKey;
}

// геттер значения
int Node::GetValue(){
        return mValue;
}

// геттер указ. на след. элемент
Node* Node::GetNext(){
        return mNext;
}

// геттер указ. на пред. элемент
Node* Node::GetPrev(){
        return mPrev;
}

// отображения ключа со значением
void Node::Display(){
        cout << "this is key  " << GetKey() << endl;
        cout << "this is value "<<GetValue() << endl;

}
