/***************************************
 * ********������ ��᫠�****************
 * ***ProblemSet5(�++) pset5/speller.c**
 * ************���*********************
 * ** �஢�ઠ ��䮣�䨨**************
 * ************************************/

#ifndef SPELL_H
#define SPELL_H
#include <string>
#include <fstream>
#include <vector>
#include <ctime>

class Spell
{
private:

    double load_time;               // �६� ����㧪�
    double check_time;              // �६� �� �஢���
    double size_time;               // �६� ��� ��।������ ࠧ���
    double unload_time;             // �६� �᢮�������� �����

    int misspelling;                // ������⢮ ��䮣��� �訡��

    int word_in_dictionary;         // ������⢮ �㪢 � ᫮���
    int word_in_text;               // ������⢮ �㪢 � ⥪�

    int dictionary_size;            // ࠧ��� ᫮���� � �����
    int text_size;                  // ࠧ��� ⥪�� � �����

    std::vector <std::string> lib;  // ����� ��� ᫮����
    std::vector <std::string> txt;  // ����� ��� ⥪��

    struct timespec begin;          // ������� ��� ��।������ �����୮�� �६��� ��砫�
    struct timespec finish;         // ������� ��� ��।������ �����୮�� �६��� �����

public:
    Spell();
    ~Spell();
    void Misspell(std::string path,         // �஢�ઠ ��䮣�䨨
                  std::string dict);
    void Report();                          // �⮡ࠦ���� १���� �஢�ન
    void LoadDictionary( std:: string dict);
    void LoadText(std::string path);
    void UnloadDictionary();
    double Total();                         // ��饥 �६� �஢�ન ⥪��
    bool CheckWord(std::string word);       // ᢥઠ ᫮�� � ᫮��६

    double Calculate(struct timespec &beg, // ����� �६���
                     struct timespec &end );

};

#endif // SPELL_H
