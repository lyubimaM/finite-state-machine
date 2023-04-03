#include <iostream>
#include"DFA.h"
#include"State.h"
#include"DFAInt.h"
#include<exception>
#include<locale.h>
#include<windows.h>
#include"Functions.h"
#include<cstring>
#include<string>
#include"DFA_Functions.h"
#include<fstream>
#include"DFAChar.h"

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);


        ifstream fin("file.txt");
        if(!fin)
        {
            cerr<<"файлът не може да бъде отворен!";
            return 1;
        }
        ifstream finchar("file1.txt");
        if(!finchar)
        {
            cerr<<"файлът не може да бъде отворен!";
            return 2;
        }

        unsigned Q=0;//Брой състояния
        unsigned F=0;//Брой финални състояния
        State beginQ("q0");//НАЧАЛНО СЪСТОЯНИЕ
        State * endQ=nullptr;
        int * alphabet=nullptr;//01
        char*alphabet2=nullptr;//ab
        int symbols=0;//брой символи в азбуката
         State ** table=nullptr;//transition
        State * arr=nullptr;//състояния
        char word[20];


       valid_data(Q,F,beginQ,endQ,alphabet,symbols,table,arr);
       DFAInt dff(Q,F,beginQ,endQ,alphabet,symbols,table,arr);
       cout<<dff;

    return 0;
}
