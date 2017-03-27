#include "HashMap.h"
#include "Node.h"
#include <string>
#include <iostream>
using namespace std;

char alphabet [26]= {"abcdefghjklmnopqrstuvwxyz"};

// конструктор
HashMap::HashMap()
{
    // инициализаци€ €чеек
    for(int i=0; i < BUCKET_SIZE; i++){
        table[i] = NULL ;
    }
}

HashMap::~HashMap()
{
   delete this->table;
}


// вставка элемента в конец списка
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
 hash функци€ принимает ключ (строку)
 возвращает первый символ ключа
 */
int HashMap::HashFunction(string key){
    for(int i= 0; i< 26; i++)
        if(alphabet[i] == tolower(key[0])){
        return i;
    }
}

// поиск ноды
Node* HashMap::Find(string key){
    int bucket = HashFunction(key);                         // определ€ем в какой корзине находитс€ значение
    if (table[bucket] == NULL){
        cout << "return not create bucket"<< endl;
        return NULL;
    }
    else{
        Node* temp_node = table[bucket];            // временной ноде присваиваем начало корзины

        while(temp_node!=NULL){                     // выполнить до конца списка
            if (temp_node->GetKey() == key){        // если ключ совпадает то
                cout << "return found node" << endl;
                temp_node->Display();
                return temp_node;                   // вернуть ноду с этим ключом
            }

            if(temp_node->GetNext()==NULL)
                return temp_node;

        temp_node = temp_node->GetNext();       // переход на следующую ноду
        }
    }
}

// поиск значени€ по ключу
int  HashMap::FindElement(string key){
    Node* temp_node = Find(key);                // находим ноду по ключу

    if ( temp_node == NULL){                     // если такой ноды нет
        cout << "that element are absent" << endl;
        return -1;
    }
    else
        return temp_node->GetValue();           // иначе возвращем значение
}


// удаление элемента с таблицы
void HashMap::Erase(string key){
     Node* temp_node = Find(key);               // находим ноду по ключу

    if ( temp_node->GetNext() == NULL){                    // если она пуста€
        temp_node->GetPrev()->SetNext(NULL);
        delete temp_node;
        cout << "end of list " << endl;         // то оповещаем пользовател€
    }
    else{// иначе
        Node *prev = temp_node->GetPrev();      // предыдущей ноде присваеваем
        prev->SetNext(temp_node->GetNext());    // ноду следующей после текущей
        delete temp_node;
        cout << "key erase " << endl;
    }
}

