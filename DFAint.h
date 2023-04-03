#ifndef DFAINT_H_INCLUDED
#define DFAINT_H_INCLUDED

#include"DFA.h"
#include<iostream>
#include<string>
#include"State.h"
#include"Functions.h"
#include<exception>
#include<iomanip>

class DFAInt : public Automaton
{
  public:
      DFAInt();
      DFAInt(unsigned&, unsigned&, State&, State *& , int *&, int&, State **&, State *&);
      DFAInt(const DFAInt &);
      DFAInt& operator=(const DFAInt &);
      ~DFAInt();

      int setAlphabet(unsigned, int*);
      int setSymbols(int);
      int setTable(unsigned, unsigned, State **&);
      int setArr(unsigned, State *);

      int* getAlphabet()const;
      int getSymbols()const;
      State** getTable()const;
      State* getArr()const;
      virtual std::ostream& ins(std::ostream&)const;
      virtual std::istream& ext(std::istream&);
      DFAInt operator&(const DFAInt&)const;
      int checkword(char[],State**,State,State*,State*,unsigned ,unsigned, int*,int) const;
      int endStates(State*&, State*, State*, State **, unsigned&, unsigned, unsigned, unsigned, unsigned);
      State* operator+(State*&) const;


private:
    int * alphabet;//01
    int symbols;//брой символи в азбуката
    State ** table;//transition
    State * arr;//състояния
    //ArrState arrSt;//
};
std::ostream& operator<<(std::ostream& os,const DFAInt&D) ;
//State**operator&(const DFAInt&,const DFAInt&)const;

#endif // DFAINT_H_INCLUDED
