#include "ArrayList.h"
#include <iostream>

ArrayList::ArrayList(int start_val){
    array = new int[start_val];
    _allocator = start_val;
    _size =0;
}


ArrayList::~ArrayList(){
    delete [] array;
}


void ArrayList::Add(int data){
    if(_size >= _allocator)
        Resize();

    array[_size] = data;
    _size++;
}


void ArrayList::DisplayArrayList(){
    for(int i=0; i < _size; i++)
    std::cout << "Element # "<< i+1 << " = " <<array[i]<< std::endl;
}


void ArrayList::Resize(){
    int *temp = array;
    _allocator *=2;
    array = new int[_allocator];
    Rewrite(temp);
    delete temp;
}


void ArrayList::Rewrite(int *old_array){
    for (int i= 0;i < _size; i++){
        array[i] = old_array[i];
    }
}


int ArrayList::Size(){
    return _size;
}



int ArrayList::Capacity(){
    return _allocator;
}


void ArrayList::SetData(int index, int data){
    if (index < _size){
        int iter = 0;
        int temp = array[index];
        array[index] = data;

     for(int i =index; i < _size;i++){
         iter = array[i+1];
         array[i+1] = temp;
         temp = iter;
     }

     }
}


int ArrayList::Getdata(int index){
    if(index < _size) {
        return array[index];
        }
}

void ArrayList::Remove(int index){
    if(index < _size)
        for (int i = index-1; i < _size-1; i++)
            array[i] = array[i+1];
    _size--;
}
