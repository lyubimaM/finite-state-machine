#ifndef DFACHAR_H_INCLUDED
#define DFACHAR_H_INCLUDED

#include"DFA.h"
#include<iostream>
#include<string>
#include"State.h"
#include"Functions.h"
#include<exception>
#include<iomanip>


class DFAChar : public Automaton
{
  public:
      DFAChar();
      DFAChar(unsigned&, unsigned&, State&, State *& , char *&, int&, State **&, State *&);
      DFAChar(const DFAChar &);
      DFAChar& operator=(const DFAChar &);
      ~DFAChar();

      int setAlphabet(unsigned, char*);
      int setSymbols(int);
      int setTable(unsigned, unsigned, State **&);
      int setArr(unsigned, State *);

      char* getAlphabet()const;
      int getSymbols()const;
      State** getTable()const;
      State* getArr()const;
      virtual std::ostream& ins(std::ostream&)const;
      virtual std::istream& ext(std::istream&);

      int checkword(char[],State**,State,State*,State*,unsigned ,unsigned, char*,int  ) const;
      State** operator&(const DFAChar& a) const;


private:
    char * alphabet;//ab
    int symbols;//брой символи в азбуката
    State ** table;//transition
    State * arr;//състояния
};
std::ostream& operator<<(std::ostream& ,const DFAChar&);

#endif // DFACHAR_H_INCLUDED
