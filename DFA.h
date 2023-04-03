#ifndef DFA_H_INCLUDED
#define DFA_H_INCLUDED

#include<iostream>
#include<cstring>
#include"State.h"

class Automaton
{
public:
    Automaton();
    Automaton(unsigned,unsigned, State, State *);
    Automaton(const Automaton &);
    Automaton& operator=(const Automaton &);
    virtual~Automaton();
   // virtual int Transition (unsigned& , unsigned, State **&, State*, int *) =0;

    unsigned getQ()const;
    State getBq()const;
    State* getEq()const;
    unsigned getF()const;

    unsigned setF(unsigned&);
    int setEq(unsigned, State *);
    int setBq(State&);
    int setQ(unsigned);

    virtual std::ostream& ins(std::ostream&)const;
    virtual std::istream& ext(std::istream&);

   private:
      unsigned Q;//Брой състояния
      unsigned F;//Брой финални състояния
      State beginQ;//НАЧАЛНО СЪСТОЯНИЕ
      State * endQ;//финални състояния
};
std::ostream& operator<<(std::ostream&, const Automaton &);
std::istream& operator>>(std::istream&, Automaton &);

#endif // DFA_H_INCLUDED
