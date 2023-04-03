#include"Functions.h"


int Input_alphabet(unsigned sz, int *& a)
{
        std::string buf;
    for(int i=0;i<sz;i++)
        {
            std::cout<<" Моля въведете символ номер ["<<i+1<<"] ";
            std::cin>>a[i];
            if(!std::cin)
       {
           throw 1;
       }


        }
        return 0;
}

unsigned Input_symbols(unsigned& sz)
{
    std::cout<<"Моля въведете брой символи в азбуката на автомата: ";
    std::cin>>sz;
    if(!std::cin) throw 1;
   return sz;
}

unsigned Input_number_states(unsigned& sz)
{

   std::cout<<"Моля въведете брой състоянията :";
   std::cin>>sz;
   if(!std::cin) throw 1;
   return sz;
}
int reserve_table_memory(int n, int m, State **& arr)
{
    arr=new State*[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=new State[m];
    }
    return 0;
}

bool  if_begin_state_is_in_array(unsigned sz, State * arr, State& bq)
{
    bool flag=true;
    for(int i=0;i<sz;i++)
    {
        if(bq==arr[i])
        {
            flag=false;
            break;
        }
    }

    return flag;//връща false когато открива съвпадение
}

bool  check_end_state(unsigned sz, State * arr, unsigned szeq, State * eq)throw()
{
   bool flag=true;
   for(unsigned i=0;i<szeq;i++)
   {
     for(unsigned j=0;j<sz;j++)
        {
            if(eq[i]==arr[j])
            {
                flag=false;
                break;
            }
        }
   }
   if(flag)
    {
        throw "Имате невалидно крайно състояние!";
    }
    return flag;
}
int input_begin_state(State& bq)
{
   std::cout<<"Моля въведете начално състояние:";
   std::cin>>bq;

   return 0;
}
bool check_states_in_table(State * arr, unsigned sz, State st)
{
   bool flag=false;
   for(int i=0;i<sz;i++)
   {
     if(!(st==arr[i]))//0 true    1 false
     {
         flag=true;
         break;
     }
   }
     return flag;
}
//***********************************
int reserve_state_memory(unsigned& sz, State *& arr)
{
    arr=new State[sz];
    return 0;
}

int input_states(unsigned sz, State *& arr)
{
    for(int i=0;i<sz;i++)
    {
        std::cout<<"Моля въведете състояние номер ["<<i+1<<"] ";
        std::cin>>arr[i];
    }
    return 0;
}
int input_number_symbols(int& s)
{
    std::cout<<"Моля въведете брой символи в азбуката на автомата:";
    std::cin>>s;
    std::cout<<std::endl;
    if(!std::cin) throw 1;

    return 0;
}
int input_alphabet(int sz, int *& arr)
{
    for(int i=0;i<sz;i++)
    {
        std::cout<<"Моля въведете символ номер ["<<i+1<<"] ";
        std::cin>>arr[i];
        if(!std::cin) throw 1;
    }
    return 0;
}
int input_alphabet_char(int sz, char *& arr)
{
    for(int i=0;i<sz;i++)
    {
        std::cout<<"Моля въведете символ номер ["<<i+1<<"] ";
        std::cin>>arr[i];
        if(arr[i]<'a' || arr[i]>'z') throw 1;
    }
    return 0;
}
int reserve_memory_transition_table(unsigned& N, unsigned M, State **& table)
{
    table=new State*[N];
    for(int i=0;i<N;i++)
    {
      table[i]=new State[M];
    }
    return 0;
}
int Transition(unsigned& N, unsigned M, State **& table, State* arr, int * alphabet)
{
    bool flag=true;
    bool isinarr=false;
    while(flag){
            try{
                flag=false;
                for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {


                std::cout<<"Моля въведете ("<<arr[i]<<", "<<alphabet[j]<<")->";//въвеждане на таблицата с преходи
                std::cin>>table[i][j];
                for(int k=0;k<N;k++)
                {
                    if(table[i][j]==arr[k])
                    {
                        isinarr=true;
                        break;

                    }
                    else isinarr=false;
                }


            }
        }
        if(isinarr==false) throw AutomationException();
            }

                catch(AutomationException)
                {
                    std::cout<<"Невалидно крайно състояние! Моля въведете отново:";
                    std::cin.clear();
                    std::cin.ignore();
                    //std::cin>>table[i][j];
                    flag=true;
                }
            }
            return 0;
        }



int Transition_char(unsigned& N, unsigned M, State **& table, State* arr, char * alphabet)
{
    bool flag=true;
    bool isinarr=false;
    while(flag){
            try{
                flag=false;
                for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {


                std::cout<<"Моля въведете ("<<arr[i]<<", "<<alphabet[j]<<")->";//въвеждане на таблицата с преходи
                std::cin>>table[i][j];
                for(int k=0;k<N;k++)
                {
                    if(table[i][j]==arr[k])
                    {
                        isinarr=true;
                        break;

                    }
                    else isinarr=false;
                }


            }
        }
        if(isinarr==false) throw AutomationException();
            }

                catch(AutomationException)
                {
                    std::cout<<"Невалидно крайно състояние! Моля въведете отново:";
                    std::cin.clear();
                    std::cin.ignore();
                    //std::cin>>table[i][j];
                    flag=true;
                }
            }
            return 0;
        }

unsigned input_number_final_states(unsigned& f)
{
  std::cout<<"Моля въведете брой крайни състояния: ";
  std::cin>>f;
  if(!std::cin) throw 1;
  return 0;
}

int input_final_states(unsigned sz, State *& arr)
{
    for(int i=0;i<sz;i++)
    {
      std::cout<<"Моля въведете крайно състояние номер ["<<i+1<<"] ";
      std::cin>>arr[i];
    }
    return 0;
}
int menu_options()
{
    std::cout<<"\nВъзможни опции:\n";
    std::cout<<"1 - Извеждане на начално състояние\n";
    std::cout<<"2 - Промяна на начално състояние\n";
    std::cout<<"3 - Отпечатване на автомата в конзолата\n";
    std::cout<<"4 - Отпечатване на автомата в файл\n";
    std::cout<<"5 - Създайте нов автомат\n";
    std::cout<<"Изберете опция:";
    return 0;
}
