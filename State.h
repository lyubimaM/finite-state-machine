#ifndef STATE_H_INCLUDED
#define STATE_H_INCLUDED

#include<iostream>
#include<cstring>

class State
{
public:
    State();
    State(char *);
    State(const State &);
    State& operator=(const State &);
    virtual ~State();

    std::ostream& ins(std::ostream&)const;
    std::istream& ext(std::istream&);

    bool operator==(const State &)const;
    bool operator!=(const State &) const;
    char * getState()const;

    char operator[](unsigned)const;
    State operator+(const State&) const;

    bool check(const State &)const;
private:
    char * name;//q0, q1..
};
std::ostream& operator<<(std::ostream&, const State &);
std::istream& operator>>(std::istream&, State &);


#endif // STATE_H_INCLUDED
