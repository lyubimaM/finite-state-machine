#include"State.h"

State::State(){
  name=new char[13];
  strcpy(name, "NoState");
}

State::State(char * n)
{
    if(n!=nullptr)
  {
    name=new char[strlen(n)+1];
    strcpy(name,n);
  }else
  {
      name=new char[13];
      strcpy(name, "NoState");
  }
}

State::State(const State & rhs)
{
    if(rhs.name!=nullptr){
        name=new char[strlen(rhs.name)+1];
       strcpy(name, rhs.name);
    }else
    {
      name=new char[13];
      strcpy(name, "NoState");
    }
}

State& State::operator=(const State & rhs)
{
    if(this!=&rhs)
    {
        if(name!=nullptr)
        {
            delete [] name;
        }
        if(rhs.name!=nullptr){
        name=new char[strlen(rhs.name)+1];
        strcpy(name,rhs.name);
        }else
        {
          name=new char[13];
         strcpy(name, "NoState");
        }
    }
    return *this;
}
State::~State()
{
    if(name!=nullptr)
    {
        delete [] name;
    }
}
 std::ostream& State::ins(std::ostream& out)const
 {
     out<<name;
    return out;
 }
std::istream& State::ext(std::istream& in)
{
    in>>name;
    return in;
}

bool State::operator==(const State & rhs)const
{
  bool res = strcmp(this->name, rhs.name);//q1 q10
  return !res;
}
bool State::operator!=(const State&rhs) const
{
      int res = strcmp(this->name, rhs.name);//q1 q10
if(res!=0) return true;
else return false;

}
std::ostream& operator<<(std::ostream& lhs, const State & rhs)
{
    return rhs.ins(lhs);
}

std::istream& operator>>(std::istream& lhs, State & rhs)
{
    return rhs.ext(lhs);
}
char * State::getState()const
{
    return name;
}
char State::operator[](unsigned i)const
{
    return name[i];
}
State State::operator+(const State& a) const
{
    int len1=strlen(name);
    int len2=strlen(a.name);
    int br=len1;
char*tmp=new char[len1+len2+1];
//strcpy(tmp,this->name);
for(int i=0;i<len1;i++)
{

    tmp[i]=name[i];
}
for(int i=0;i<len2;i++)
{
    tmp[br++]=a.name[i];

}
tmp[len1+len2]='\0';
return State(tmp);


}
bool State::check(const State& second)const
{
  if(strstr(this->name, second.name)!=nullptr)return true;
  return false;
}
