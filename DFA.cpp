#include"DFA.h"

Automaton::Automaton()
: Q(0), F(0)
{
    beginQ=" ";
    endQ=nullptr;
}

Automaton::Automaton(unsigned Q,unsigned F, State BQ, State * EQ): Q(Q), F(F),beginQ(BQ)
{
   if(EQ!=nullptr)
   {
       endQ=new State[F];
       for(int i=0;i<F;i++)
       {
           endQ[i]=EQ[i];
       }
   }else
      endQ=nullptr;
}

Automaton::Automaton(const Automaton & rhs): Q(rhs.Q),F(rhs.F)
{

    beginQ=rhs.beginQ;
    if(endQ!=nullptr)
    {
        delete [] endQ;
    }
    endQ=new State[F];
    for(int i=0;i<F;i++)
       {
           endQ[i]=rhs.endQ[i];
       }
}

Automaton& Automaton::operator=(const Automaton & rhs)
{
   if(this!=&rhs)
   {
        F=rhs.F;
        Q=rhs.Q;
        beginQ=rhs.beginQ;

        if(endQ!=nullptr)
        {
          delete [] endQ;
        }

        endQ=new State[rhs.F];
        for(int i=0;i<rhs.F;i++)
        {
           endQ[i]=rhs.endQ[i];
        }

   }
   return *this;
}

Automaton::~Automaton()
{
   if(endQ!=nullptr)
   {
       delete [] endQ;
   }
}



std::ostream& Automaton::ins(std::ostream& out)const
{
    out<<"Begin: "<<getBq();
    std::cout<<std::endl;
    for(int i=0;i<getF();i++)
    {
        out<<"End number ["<<i+1<<"] = "<<endQ[i];
        std::cout<<std::endl;
    }
    return out;
}


std::ostream& operator<<(std::ostream& lhs, const Automaton & rhs)
{
    return rhs.ins(lhs);
}
unsigned Automaton::setF(unsigned& f)
{
    this->F=f;
    return 0;
}

unsigned Automaton::getF()const
{
    return this->F;
}

int Automaton::setBq(State& BQ)
{
    beginQ=BQ;
    return 0;
}
State Automaton::getBq()const
{
    return this->beginQ;
}

int Automaton::setEq(unsigned sz, State * eq)
{
    if(endQ!=nullptr)
    {
        delete [] endQ;
    }
    if(eq!=nullptr){
     this->endQ=new State[sz];
     for(int i=0;i<sz;i++)
        {
            endQ[i]=eq[i];
        }
    }else
      endQ=nullptr;
    return 0;
}
int Automaton::setQ(unsigned Q)
{
    this->Q=Q;
    return 0;
}
unsigned Automaton::getQ()const
{
    return this->Q;
}
State* Automaton::getEq()const
{
   return this->endQ;
}
std::istream& Automaton::ext(std::istream& in)
{
  in>>Q>>F>>beginQ;
  if(endQ!=nullptr)
  {
      delete [] endQ;
  }
 endQ=new State[F];
  for(int i=0;i<F;i++)
  {
      in>>endQ[i];
  }
  return in;
}

std::istream& operator>>(std::istream& lhs, Automaton & rhs)
{
    return rhs.ext(lhs);
}
