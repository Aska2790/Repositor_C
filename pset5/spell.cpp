#include "spell.h"
#include <ctime>            // ࠡ�� � ������� �६����
#include <sys/types.h>      // ࠡ�� � ������� �६����
#include <errno.h>          // ࠡ�� � ������� �६����
#include <string>           // ��ப���� �����
#include <cstring>          // ��������� � ᨬ������
#include <iostream>         // �⠭���⭠� ������⥪� ����� �뢮�� � ���᮫�
#include <fstream>          // �⠭���⭠� ������⥪� 䠩������ ����� �뢮��

#define NS_IN_S  1E9        // ����⠭�� ����⥫� ����ᥪ㭤

//��������� �� 㬮�砭��
Spell::Spell()
{
    load_time =0;
    check_time =0;
    unload_time=0;
    size_time=0;

    misspelling = 0;

    word_in_dictionary = 0;
    word_in_text = 0;

    dictionary_size = 0;
    text_size =0;
}
// ��������
Spell::~Spell()
{
    std::cout << "\nI am destructor" << std::endl;
}
// �஢�ઠ ��䮣�䨨
void Spell::Misspell(std::string path, std::string dict){
    LoadDictionary(dict);                                   // ����㦠�� ᫮�����
    LoadText(path);                                         // ����㦠�� ⥪��

    for (int i=0;i<word_in_text; i++){                      // ᢥ�塞 � ᫮��६
        if(!CheckWord(txt[i])){
            misspelling++;                                  // �᫨ ��諠 �訡��
           std:: cout << "# " << i << " - "
                      << txt [i] << std::endl;              // �뢮��� �訡��
        }
    }
}
// ����㧪� ᫮���� �� 䠩��
void Spell::LoadDictionary(std::string dict){

    std::ifstream dictionary;                   // ��쥪� 䠩������ ��⮪�
    dictionary.open(dict);                      // ���뢠�� 䠩��
    if(!dictionary.is_open()){                  // �᫨ �� ��諮
        std::cout << "Dictionary couldn`t open" << std::endl;
        exit(1);                                // �����蠥�
    }

    dictionary.seekg(0,dictionary.end);         // 㪠��⥫� � 䠩�� ��६�頥� �� �����
    dictionary_size = dictionary.tellg();       // ��।��塞 ����� 䠩��
    dictionary.seekg(0,dictionary.beg);         // �����頥� 㪠��⥫� � ��砫�

    std::string temp;
                                                // ��稭��� �������� �६�
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin);
    while(getline(dictionary,temp)){            // ⠪ ��� � ᫮��� ᫮�� ���� �⤥�쭮 � ������ ��ப�
       temp[0] = tolower(temp[0]);              // �᫨ ���� ���� ᨬ��� �㤥� ��������
        lib.push_back(temp);                    // ����頥� � ��� �࠭���� ᫮����
    }                                           // ����� �����
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &finish);

    load_time = Calculate(begin, finish);       // ������ �६��� ����祭��� �� ������ ����㧪�

                                                 // ��稭��� �������� �६�
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin);
    word_in_dictionary = lib.size();            // ��।��塞 ������⢮ ᫮� � ᫮��� ᫮����
                                                // ����� �����
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &finish);
    size_time =  Calculate(begin, finish);      // ������ �६��� ����祭��� �� ������

    dictionary.close();                         // ����뢠�� ��쥪� 䠩������ ��⮪�
}
// ����㧪� ⥪�� ��� �஢�ન
void Spell::LoadText(std::string path){
    std::ifstream text;                         // ��쥪� 䠩������ ��⮪�
    text.open(path);                            // ���뢠�� 䠩��
    if(!text.is_open()){                        // �᫨ �� ��諮
        std::cout << "Text couldn`t open" << std::endl;
        exit(1);                                // �����蠥�
    }
    text.seekg(0,text.end);                     // 㪠��⥫� � 䠩�� ��६�頥� �� �����
    text_size = text.tellg();                   // ��।��塞 ����� 䠩��
    text.seekg(0,text.beg);                     // �����頥� 㪠��⥫� � ��砫�

    std::string temp;

    while(!text.eof()){                         // ���� �� ���⨣��� ���� 䠩��
        getline(text,temp,' ');                 // ���뢠�� ᫮�� �� �஡���
        temp[0] = tolower(temp[0]);             // ᬥ�� ॣ���� ��ࢮ�� ᨬ����
        txt.push_back(temp);                    // ����頥� �� �६���� �࠭����
    }

    word_in_text = txt.size();                  // ࠧ��� ��襣� 䠩��
    text.close();                               // ����뢠�� 䠩�
}
// ��饥 �६� ����祭�� �� �஢���
double Spell::Total(){
    return load_time + check_time+ unload_time + size_time;}
// �⮡ࠦ���� १����
void Spell:: Report(){
    std::cout << "\n\nWORDS MISSPELLED: "<< misspelling << std::endl;
    std::cout << "WORDS IN DICTIONARY: "<< word_in_dictionary<< std::endl;
    std::cout << "WORDS IN TEXT:  "<< word_in_text << std::endl;
    std::cout << "Dictionary size in byte: "<< dictionary_size << std::endl;
    std::cout << "Text size in bytes: "<< text_size << std::endl;
    std::cout << "Time in load: "<< load_time << std::endl;
    std::cout << "Time in check: "<< check_time << std::endl;
    std::cout << "Time in Size: "<< size_time << std::endl;
    std::cout << "Time in unload: "<< unload_time << std::endl;
    std::cout << "Time in total: "<< Total() << std::endl;
}
// �᢮�������� �����
void Spell::UnloadDictionary(){
   clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin);     // ��砫� ����� �६���
   txt.clear();                                         // �᢮������� �࠭����
   if(txt.size()!=0)                                    // �஢�ઠ
       std::cout << "Memory is not freed" << std:: endl;

   clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &finish);    // ����� ����� �६���
   unload_time =  Calculate(begin, finish);             // �६� ����祭��� �� ������

}
// �஢�ઠ ᫮��
bool Spell::CheckWord(std:: string word){
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin);     // ��砫� ����� �६���
    int iter = lib.size();                               // �ன��� �� �ᥬ� �࠭�����
    int len = word.length();                            // ����� ᫮�� ���஥ �஢��塞

     if(!isalpha(word[0])){                             // �᫨ � ᫮�� ���� ����� �㭪��樨 (  (,),.)
         word.erase(0,1);                               // 㤠�塞

     }
     if(!isalpha(word[len-1]) ){                        // �᫨ � ���� ���� �����
            word.erase(len-1, 1);                       // 㤠�塞
     }

    for(int i =0; i < iter; i++){                       // ᢥઠ � ᫮��६
        if(word == lib[i])                              // �᫨ ���� ⠪�� ᫮��
            return true;
    }

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &finish);   // ����� ����� �६���
    check_time +=  Calculate(begin, finish);            // �६� ����祭��� �� ������
    return false;

}
// ������ �६���
double Spell::Calculate(struct timespec &beg,struct timespec &end ){
    struct timespec duration;                               // �஬����筠� ��६�����
    if ((end.tv_nsec - beg.tv_nsec) < 0) {                  // ॠ������ �।�ᬠ�ਢ���
           duration.tv_sec = end.tv_sec - beg.tv_sec - 1;
           duration.tv_nsec = NS_IN_S + end.tv_nsec - beg.tv_nsec;
       }
    else{
        duration.tv_sec = end.tv_sec - beg.tv_sec;
        duration.tv_nsec = end.tv_nsec - beg.tv_nsec;
    }

    double result = duration.tv_sec + duration.tv_nsec / NS_IN_S;// १���� � ᥪ㭤��
    return result;
}

//=========================================
