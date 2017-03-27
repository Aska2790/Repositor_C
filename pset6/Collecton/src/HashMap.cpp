#include "HashMap.h"
#include "Node.h"
#include <string>
#include <iostream>
using namespace std;

char alphabet [26]= {"abcdefghjklmnopqrstuvwxyz"};

// �����������
HashMap::HashMap()
{
    // ������������� �����
    for(int i=0; i < BUCKET_SIZE; i++){
        table[i] = NULL ;
    }
}

HashMap::~HashMap()
{
   delete this->table;
}


// ������� �������� � ����� ������
void HashMap::Insert(string key, int value){
    int bucket = HashFunction(key);

    if(table[bucket]==NULL){

        table[bucket] = new Node();
        table[bucket]->SetData(key,value);
        table[bucket] ->SetPoint(NULL,NULL);
        cout << "New bucket" << endl<< endl;
        table[bucket]->Display();

    }
    else {
        Node* temp_node = Find(key);

        if (temp_node == NULL){
            Node* new_node = new Node();
            new_node->SetData(key, value);
            new_node->SetPoint(temp_node, NULL);
        }
        else {
            temp_node->SetData(key, value);
            cout << "Update data" <<endl;
        }
    }


}

/*
 hash ������� ��������� ���� (������)
 ���������� ������ ������ �����
 */
int HashMap::HashFunction(string key){
    for(int i= 0; i< 26; i++)
        if(alphabet[i] == tolower(key[0])){
        return i;
    }
}

// ����� ����
Node* HashMap::Find(string key){
    int bucket = HashFunction(key);                         // ���������� � ����� ������� ��������� ��������
    if (table[bucket] == NULL){
        cout << "return not create bucket"<< endl;
        return NULL;
    }
    else{
        Node* temp_node = table[bucket];            // ��������� ���� ����������� ������ �������

        while(temp_node!=NULL){                     // ��������� �� ����� ������
            if (temp_node->GetKey() == key){        // ���� ���� ��������� ��
                cout << "return found node" << endl;
                temp_node->Display();
                return temp_node;                   // ������� ���� � ���� ������
            }

            if(temp_node->GetNext()==NULL)
                return temp_node;

        temp_node = temp_node->GetNext();       // ������� �� ��������� ����
        }
    }
}

// ����� �������� �� �����
int  HashMap::FindElement(string key){
    Node* temp_node = Find(key);                // ������� ���� �� �����

    if ( temp_node == NULL){                     // ���� ����� ���� ���
        cout << "that element are absent" << endl;
        return -1;
    }
    else
        return temp_node->GetValue();           // ����� ��������� ��������
}


// �������� �������� � �������
void HashMap::Erase(string key){
     Node* temp_node = Find(key);               // ������� ���� �� �����

    if ( temp_node->GetNext() == NULL){                    // ���� ��� ������
        temp_node->GetPrev()->SetNext(NULL);
        delete temp_node;
        cout << "end of list " << endl;         // �� ��������� ������������
    }
    else{// �����
        Node *prev = temp_node->GetPrev();      // ���������� ���� �����������
        prev->SetNext(temp_node->GetNext());    // ���� ��������� ����� �������
        delete temp_node;
        cout << "key erase " << endl;
    }
}

