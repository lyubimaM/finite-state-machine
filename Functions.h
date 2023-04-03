#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include<iostream>
#include<cstring>
#include"State.h"
#include"AutomationException.h"

int Input_alphabet(unsigned, int *&);

unsigned Input_symbols(unsigned&);

unsigned Input_number_states(unsigned&);

int reserve_table_memory(int, int, State **&);

bool  if_begin_state_is_in_array(unsigned , State* ,State&);

bool  check_end_state(unsigned, State *,unsigned, State *)throw();

int input_begin_state(State&);

bool check_states_in_table(State*, unsigned, State);
//**********************************************
int reserve_state_memory(unsigned& , State *&);

int input_states(unsigned, State *&);

int input_number_symbols(int&);

int input_alphabet(int, int *&);
int input_alphabet_char(int, char *&);


int reserve_memory_transition_table(unsigned& , unsigned, State **&);

int Transition(unsigned& , unsigned, State **&, State*, int *);
int Transition_char(unsigned& , unsigned, State **&, State*, char *);

unsigned input_number_final_states(unsigned&);

int input_final_states(unsigned, State *&);

int menu_options();

#endif // FUNCTIONS_H_INCLUDED
