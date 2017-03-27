#include "LinkedList.h"
#include <iostream>
#include <string>


Nodes::Nodes(){
    this->_next = NULL;
    this->_prev = NULL;
}

Nodes::~Nodes(){
    delete this->_prev;
    delete this->_next;
}

//
int  Nodes:: GetData(){
    return data;
}
//
void Nodes:: SetData(int data){
    this->data =data;
}

//
void Nodes:: DisplayData(){
    std::cout << "That node`s have information :"<< this->GetData()<< std::endl;
}

void Nodes::SetNextNull(){
    this->_next= NULL;
}

void Nodes::SetPrevPoint(Nodes* prev){
    this->_prev= prev;
}

void Nodes::SetNextPoint(Nodes* next){
    this->_next = next;
}

Nodes* Nodes::GetNextPoint(){
    return _next;
}

Nodes* Nodes::GetPrevPoint(){
    return _prev;
}
//====================================================================


LinkedList::LinkedList(){
    _root = NULL;
    _end = NULL;
    _size = 0;
}

LinkedList::~LinkedList(){
    this->Clear();
    delete _root;
    delete _end;
}


//
int LinkedList:: Size(){
    return _size;
}


//
void LinkedList:: Add(int data){
    Nodes *temp = new Nodes;
    temp->SetData(data);
    temp->SetNextNull();

    if(_root == NULL)    {
        _root = temp;
        _end  = temp;

    }
    else {
        temp->SetPrevPoint( _end);
        _end->SetNextPoint( temp );
        _end = temp;
     }
    this->_size++;
}


//
void LinkedList:: Remove(int index){
    Nodes *temp = FindNodeByIndex(index);
    if(temp !=NULL){
    temp->GetPrevPoint()->SetNextPoint(temp->GetNextPoint());
    temp->GetNextPoint()->SetPrevPoint(temp->GetPrevPoint());
    delete temp;
     _size--;
    }
}


//
void LinkedList:: DisplayList(){
    Nodes *temp = _root;
    if(temp!=NULL){
    while(temp !=NULL){
        std::cout << temp->GetData() << std::endl;
        temp = temp->GetNextPoint();
    }
    }else
     std::cout << "List is empty"<< std::endl;
}

//
 Nodes* LinkedList::FindNodeByIndex(int index){
     Nodes *temp =_root;
        for (int i=1; i < index; i++){
            temp = temp->GetNextPoint();
        }
    return temp;
 }


//
 bool LinkedList::IsEmpty(){
     if(_size == 0)
         return true;
     else
         return false;

 }

 int LinkedList::GetValByIndex(int index){
     Nodes *temp;
     temp = FindNodeByIndex(index);
     return temp->GetData();
 }
 void LinkedList::Clear(){

    while(_end!= NULL){
        Nodes* temp = _end;
       _end = temp->GetPrevPoint();
        delete temp;
       _size--;
    }
    _root =NULL;
 }
