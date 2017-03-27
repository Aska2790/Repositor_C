#ifndef ARRAYLIST_H
#define ARRAYLIST_H

class ArrayList{
private:
    int     _size;
    int     _allocator;
    int*    array;
    void    Resize();
    void    Rewrite(int *old_array);
public:
            ArrayList(){_allocator = 10;}      // конструктор по умолчанию
            ArrayList(int start_val);          // конструктор с инициализацией размера
            ~ArrayList();                      // деструктор
    int     Size();                            // текущий размер массива
    int     Capacity();                        // общий размер массива
    int     Getdata(int index);                // получение значения по индексу
    void    SetData(int index, int data);      // установка значение по индексу
    void    Remove(int index);                 // удаление элемента по индексу
    void    Add(int data);                     // добавление элемента в конец
    void    DisplayArrayList();                // отображение списка
};

#endif // ARRAYLIST_H
