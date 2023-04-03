#ifndef DFA_FUNCTIONS_H_INCLUDED
#define DFA_FUNCTIONS_H_INCLUDED

#include <iostream>
#include"State.h"
#include"DFAInt.h"
#include<exception>
#include"Functions.h"
#include<cstring>
#include<string>
#include<fstream>

int valid_data(unsigned&, unsigned&, State&, State *& , int *&, int&, State **&, State *&);
int valid_data_file(unsigned&, unsigned&, State&, State *& , int *&, int&, State **&, State *&,std::ifstream&);
int valid_data_char(unsigned&, unsigned&, State&, State *& , char *&, int&, State **&, State *&);

#endif // DFA_FUNCTIONS_H_INCLUDED
