#include"DFA_Functions.h"

int valid_data(unsigned& q, unsigned& f, State& bq, State *& eq, int *& alphabet, int& symbols, State **& table, State *& arr){
///���������
bool fl2=true;
std::string buf1;
while(fl2)
{
    try{
            Input_number_states(q);
fl2=false;
    }catch(...)
    {
           std::cout<<"������� ��� ��������� ���� ���������. ";
           getline(std::cin,buf1);
    std::cin.clear();
               getline(std::cin,buf1);

    fl2=true;
    }
}
        reserve_state_memory(q,arr);
        input_states(q,arr);//q1 q2 q3
///������
bool fl=true;
std::string buf2;
while(fl)
{
    try{
input_number_symbols(symbols);        fl=false;
//��������� �� ���� ������� � ��������
}catch(...)
{
    std::cout<<"������� ��� ��������� ���� �������!";
    getline(std::cin,buf2);
    std::cin.clear();
    std::cin.ignore();
    fl=true;
}
}

std::string Buf;
        while(symbols<=0)
          {

    std::cout<<"������� ��� ��������� ���� �������.\n";
                   input_number_symbols(symbols);
          }
        alphabet=new int[symbols];//�������� �� ����� �� ������ � ��������
        bool Flag=true;
        while(Flag)
        {
            try
            {
                    input_alphabet(symbols,alphabet);//��������� �� ��������
                    Flag=false;

            }catch(...)
            {
               std::cout<<"������� ��� ��������� ������!\n";
    std::cin.clear();
    getline(std::cin,Buf);

    Flag=true;
            }
        }
///������� � �������
       reserve_memory_transition_table(q,symbols,table);
       Transition(q,symbols,table,arr,alphabet);
//������� ���������
    bool flag= true;
    std::string buf;
    int line=0;
    bool t=true;
   while(flag)
    {
///��������� ���������� �� ��� AutomatonException()
       try
         {
             t=false;
             flag=false;
            input_begin_state(bq); line = __LINE__;

                    for(int i=0;i<q;i++)
                    {
                            if(bq==arr[i])
                                {t=true;break;}
                            else {t=false;}

                    }
                    if(t==false) throw AutomationException();

           // std::cout<<"BUFFF = "<<buf<<std::endl;
           getline(std::cin, buf);
        if(buf != "")
            throw AutomationException();
         }
           catch(AutomationException)
           {
            std::cerr<<"���� ���������� ���������� ��� ������� input_begin_state() �� ��� "<<line<<" !"<<std::endl;
            std::cin.clear();
            //std::cin.ignore();
            flag = true;
           }
    }

///������� ���������
      bool flag1=true;
      bool p=true;
      while(flag1)
      {


      try{
          flag1=false;
                input_number_final_states(f);

/*while(p){

                           try{
                               p=false;

                              input_number_final_states(f);}
                        catch(...)
           {
               std::cerr<<"���� ���������� ���������� ��� ������� input_final_states() �� ��� "<<line<<" !"<<std::endl;
               getline(std::cin,buf1);
                           std::cin.clear();

            std::cin.ignore();
            p = true;
           }
          }*/



if(f<=0 )
       {
           std::cout<<"�� ���������� ������� � "<<f<<" ������� ���������.���� �������� ���� ������� ���������:";
throw AutomationException();
       }
else if(f>q)
{
    std::cout<<"������ ��� ��������� ���� ���������!\n";
throw AutomationException();
}
       else {
          flag1=false;

            bool isinarr=false;
       eq=new State[f];

       input_final_states(f,eq);
       for(int i=0;i<f;i++)
        {
            for(int j=0;j<q;j++)
            {
                if(eq[i]==arr[j])
                                {isinarr=true;break;}
                            else {isinarr=false;}
            }
       if(isinarr==false) throw AutomationException();
        }
       }
      }
      catch(AutomationException)
           {

            std::cerr<<"���� ���������� ���������� ��� ������� input_final_states() �� ��� "<<line<<" !"<<std::endl;

            std::cin.clear();
    getline(std::cin,Buf);

            flag1 = true;
           }
           catch(...)
           {
               std::cerr<<"���� ���������� ���������� ��� ������� input_final_states() �� ��� "<<line<<" !"<<std::endl;
                           std::cin.clear();

                getline(std::cin,Buf);

            flag1 = true;
           }




}
}
int valid_data_file(unsigned& q, unsigned& f, State& bq, State *& eq, int *& alphabet, int& symbols, State **& table, State *& arr, std::ifstream& fst)
{


        //Input_number_states(q);
fst>>q;
//std::cout<<q<<" ";
        /*reserve_state_memory(q,arr);
        for(int i=0;i<q;i++)
            fst>>arr[i];
        //input_states(q,arr);//q1 q2 q3
///������
fst>>symbols;
//input_number_symbols(symbols);
//��������� �� ���� ������� � ��������

        alphabet=new int[symbols];//�������� �� ����� �� ������ � ��������
        for(int i=0;i<symbols;i++)
            fst>>alphabet[i];
        //input_alphabet(symbols,alphabet);//��������� �� ��������



///������� � �������
       reserve_memory_transition_table(q,symbols,table);
       for(int i=0;i<q;i++)
       {
           for(int j=0;j<symbols;j++)
            fst>>table[i][j];
       }
       //Transition(q,symbols,table,arr,alphabet);
//������� ���������
    fst>>bq;
            //input_begin_state(bq);



///������� ���������
      fst>>f;
                //input_number_final_states(f);


for(int i=0;i<f;i++)
    fst>>eq[i];
       //input_final_states(f,eq);*/




}
