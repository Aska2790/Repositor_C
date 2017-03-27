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
            ArrayList(){_allocator = 10;}      // ��������� �� 㬮�砭��
            ArrayList(int start_val);          // ��������� � ���樠����樥� ࠧ���
            ~ArrayList();                      // ��������
    int     Size();                            // ⥪�騩 ࠧ��� ���ᨢ�
    int     Capacity();                        // ��騩 ࠧ��� ���ᨢ�
    int     Getdata(int index);                // ����祭�� ���祭�� �� �������
    void    SetData(int index, int data);      // ��⠭���� ���祭�� �� �������
    void    Remove(int index);                 // 㤠����� ����� �� �������
    void    Add(int data);                     // ���������� ����� � �����
    void    DisplayArrayList();                // �⮡ࠦ���� ᯨ᪠
};

#endif // ARRAYLIST_H
