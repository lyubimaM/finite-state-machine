#include"DFAInt.h"

DFAInt::DFAInt(): Automaton(), symbols(0){

       alphabet=nullptr;
       table=nullptr;
       arr=nullptr;
}
DFAInt::DFAInt(unsigned& q, unsigned& f, State& bq, State *& eq, int *& alphabet, int& symbols, State **& table , State *& arr): Automaton(q,f,bq,eq)
{
///Състояния
        Automaton::setQ(q);
        setArr(q,arr);
///Азбука
        setSymbols(symbols);
        setAlphabet(this->symbols,alphabet);
///Таблица с преходи

    this->table=new State*[q];
    for(int i=0;i<q;i++)
    {
        this->table[i]=new State[symbols];
    }

        setTable(q,symbols,table);
        //this->table=nullptr;
///начално състояние
        Automaton::setBq(bq);
///финални състояния
        Automaton::setF(f);
        Automaton::setEq(f,eq);
}

DFAInt::DFAInt(const DFAInt & rhs): Automaton(rhs)
{
   symbols=rhs.symbols;
   if(alphabet!=nullptr)
   {
       delete [] alphabet;
   }
   alphabet=new int[symbols];

   for(int i=0;i<symbols;i++)
   {
       alphabet[i]=rhs.alphabet[i];
   }
}

DFAInt& DFAInt::operator=(const DFAInt & rhs)
{
    if(this!=&rhs)
    {
       Automaton::operator=(rhs);
       symbols=rhs.symbols;
       alphabet=new int[symbols];
       for(int i=0;i<symbols;i++)
       {
           alphabet[i]=rhs.alphabet[i];
       }
    }
    return *this;
}

DFAInt::~DFAInt()
{
    if(alphabet!=nullptr)
    {
        delete [] alphabet;
    }
}
int DFAInt::setAlphabet(unsigned sz, int* arr)
{
   if(this->alphabet!=nullptr)
   {
       delete [] alphabet;
   }
   alphabet=new int[sz];
   for(int i=0;i<sz;i++)
   {
       alphabet[i]=arr[i];
   }
   return 0;
}
int DFAInt::setSymbols(int s)
{
    this->symbols=s;
    return 0;
}
int DFAInt::setTable(unsigned r, unsigned c, State **& t)
{

    if(table!=nullptr)//q symb
    {
        for(int i=0;i<r;i++)
        {
            delete [] table[i];
        }
        delete [] table;
    }

    table = new State*[r];
    for(int i=0;i<r;i++)
    {
        table[i]=new State[c];
    }

    if(t!=nullptr)
    {

        for(int i=0;i<r;i++)
        {

                for(int j=0;j<c;j++)
            {

                table[i][j]=t[i][j];
            //std::cout<<table[i][j];

            }
        }
    }
    return 0;
}
int DFAInt::setArr(unsigned sz, State * a)
{
    if(a!=nullptr)
    {
        arr=new State[sz];
        for(int i=0;i<sz;i++)
        {
            arr[i]=a[i];
        }
    }else
      arr=nullptr;
    return 0;
}

int* DFAInt::getAlphabet()const
{
    return this->alphabet;
}
int DFAInt::getSymbols()const
{
    return this->symbols;
}
State** DFAInt::getTable()const
{
    return this->table;
}
State* DFAInt::getArr()const
{
    return this->arr;
}
DFAInt DFAInt::operator&(const DFAInt& a) const
{

int i;
    State*TEMP=new State[getF()+a.getF()];
    State*eq=Automaton::getEq();
    State*eq1=a.Automaton::getEq();

       for( i=0;i<getF();i++)
       {
           TEMP[i]=eq[i];
       }
       for(int j=0;j<a.getF();j++)
       {
           TEMP[i++]=eq1[j];
       }
     State newbeginq=Automaton::getBq()+a.Automaton::getBq();


    int o=0,h=0,br=0,sz=0,x=0;
    bool isinarr=false;
    State**tmp=new State*[Automaton::getQ()];
    State copytmp[100]{0};
    State copytmp2[100];

    for(int i=0;i<Automaton::getQ();i++)
        tmp[i]=new State[a.Automaton::getQ()];
    State**tmp2=new State*[a.Automaton::getQ()*Automaton::getQ()];
    for(int i=0;i<a.Automaton::getQ()*Automaton::getQ();i++)
        tmp2[i]=new State[symbols];
    State*newarr=new State[a.Automaton::getQ()*Automaton::getQ()];
    for(int i=0;i<Automaton::getQ();i++)
    {
        for(int j=0;j<a.Automaton::getQ();j++)
        {
                        tmp[i][j]=this->arr[i]+a.arr[j];

        }

    }
for(int i=0;i<Automaton::getQ();i++)
{
    for(int j=0;j<a.Automaton::getQ();j++)
    {
        newarr[x]=tmp[i][j];

        x++;
    }
}
    for(int i=0;i<Automaton::getQ();i++)
    {

        for(int j=0;j<a.Automaton::getQ();j++)
        {


             for(int k=0;k<a.Automaton::getQ();k++)
    {

                        if(tmp[i][j]==this->arr[i]+a.arr[k])
                        {
                            for(int m=0;m<symbols;m++)
                            {
                                tmp2[o][h++]=table[i][m]+a.table[k][m];
                            }
                            if(h>symbols-1)
                            {
                                h=0;o++;
                            }
                            break;
                        }
    }


        }

    }


    for(int i=0;i<symbols;i++)
    {
        if(i==0)
            std::cout<<std::setw(9)<<alphabet[i];
        else  std::cout<<std::setw(6)<<alphabet[i];


    }
        std::cout<<std::endl;
o=0,h=0;
    for(int i=0;i<Automaton::getQ()*a.Automaton::getQ();i++)
    {
std::cout<<tmp[o][h++]<<" | ";
if(h>a.Automaton::getQ()-1)
{
    h=0;o++;
}
        for(int j=0;j<symbols;j++)
        {

            std::cout<<tmp2[i][j]<<" ";

        }

std::cout<<std::endl;
    }

for(int i=0;i<Automaton::getQ();i++)
    {
        for(int j=0;j<a.Automaton::getQ();j++)
        {
            if(tmp[i][j]==Automaton::getBq()+a.Automaton::getBq())
                std::cout<<"Begin: "<<tmp[i][j]<<std::endl;

        }

    }
for(int i=0;i<Automaton::getQ();i++)
    {
        for(int j=0;j<a.Automaton::getQ();j++)
        {
            for(int m=0;m<Automaton::getF();m++){
                if(tmp[i][j].check(eq[m]))
                {
                     copytmp[br++]=tmp[i][j];
                }
          }
        }}
        for(int i=0;i<Automaton::getQ();i++)
    {
        for(int j=0;j<a.Automaton::getQ();j++)
        {
            for(int m=0;m<a.Automaton::getF();m++){
                if(tmp[i][j].check(eq1[m]))
                {
                     copytmp[br++]=tmp[i][j];
                }
          }
        }}

        for (int i = 0; i < br; i++) {


		int flag = 1;
		for (int j = i+1; j < br; j++) {
			if (copytmp[j] == copytmp[i]) {
				flag = 0;
				break;
			}
		}
		if(flag)
		{
		    copytmp2[sz++]=copytmp[i];
		}
        }
        for(int i=0;i<sz;i++)
            std::cout<<"End Number["<<i+1<<"] = "<<copytmp2[i]<<std::endl;
unsigned brq=Automaton::getQ()*a.Automaton::getQ();
unsigned brf=sz;
int *newalph=getAlphabet();
int symbols1=symbols;

 //return DFAInt (brq,brf,newbeginq,TEMP,newalph,symbols1,tmp2,newarr);


}
std::ostream& DFAInt::ins(std::ostream& out)const
{
    int rows=Automaton::getQ();
    int cols=getSymbols();
    for(int i=0;i<cols;i++)
    {
        if(i==0)
            std::cout<<std::setw(6)<<alphabet[i];
        else  std::cout<<std::setw(4)<<alphabet[i];


    }
    std::cout<<std::endl;
    for(int i=0;i<rows;i++)
    {
        std::cout<<arr[i]<<" | ";
        for(int j=0;j<cols;j++)
        {
            out<<this->table[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
Automaton::ins(out);

    return out;
}
std::ostream& operator<<(std::ostream&os,const DFAInt& D)
{
    return D.ins(os);
}

int DFAInt::checkword(char word[20],State** transition,State beginQ,State* endQ,State*Arr,unsigned Q,unsigned F, int* alph,int symb ) const
{
    char word1[20];
    std::string buf;
    int current,j,i;
    bool flag,flag1=1,t=true,isinarr;
    int temp;
    State tmp;
while(flag1)
{
t=true;
        current = 0, flag = 0;// current will keep track of the current state
while(t)
{
    try
    {
        t=false;
        isinarr=false;
        std::cout << "\nВъведете дума: ";
        std::cin >> word1;
    for(int i=0;i<strlen(word1);i++)
        {
            for(int j=0;j<symb;j++)
            {
                if(word1[i]-'0'==alph[j])
                                {isinarr=true;break;}
                            else {isinarr=false;}
            }
       if(isinarr==false) throw AutomationException();
        }
    }catch(...)
    {
        std::cout<<"Въвели сте некоректна дума!";
        std::cin.clear();
        //std::cin.ignore();
    getline(std::cin,buf);

        t=true;
    }
}

	if (strcmp(word1,"exit") ==0)
    {
            exit(1);
    }
	for ( i = 0; i < strlen(word1); i++) {
	    // process the string and change the state accordingly
	                temp = word1[i];

	    // getting the index of the input from the alphabet set
	    for ( j = 0; j < symb; j++) {

	        if (alph[j] == temp-'0') {
	            break;
	        }
	    }
	    // storing the value of transition state
            tmp = transition[current][j];

	    // changing the current state to the next state
	    for (int k = 0; k < Q; k++)
	        if (Arr[k]==tmp) {
	             current = k;
	             break;
	         }
	     //loop for checking if a the dfa is in a trap state

	}


	    for (i = 0; i < F; i++){
	        if (Arr[current]==endQ[i]) {
	            std::cout << "Думата е разпозната\n"<<std::endl;
                    flag = true;
                    break;
                }
                else flag=false;
	    }

             if (flag == false)
                std::cout << "Думата не е разпозната!"<<std::endl;
if(flag==true) {word=word1;std::cout<<word;}
                std::cout<<"Искате ли пак да въведете дума (1 за да, 0 за не)"<<std::endl;
std::cin>>flag1;
}


}
int DFAInt::endStates(State*& newEq, State* eq1, State* eq2, State ** tb, unsigned& szNewEq, unsigned szEq1, unsigned szEq2, unsigned szTrow, unsigned szTcol)
{

    for(int i=0;i<szTrow;i++)
    {
        szEq1=szEq2=0;
        for(int j=0;j<szTcol;j++)
        {

            if(tb[i][j].check(eq1[szEq1++]) || tb[i][j].check(eq2[szEq2++]))
            {
               // newEq[szNewEq++]=tb[i][j];
               szNewEq++;
            }
        }
    }

    return 0;
}
std::istream& DFAInt::ext(std::istream& in)
{
     Automaton::ext(in);
    in>> symbols;
    alphabet=new int[symbols];
    //***********************
    for(int i=0;i<symbols;i++)
    {
        in>>alphabet[i];
    }
    //***********************
    arr=new State[Automaton::getQ()];
    for(int i=0;i<Automaton::getQ();i++)
    {
        in>>arr[i];
    }

   //***********************
    table=new State*[Automaton::getQ()];
    for(int i=0;i<Automaton::getQ();i++)
    {
        table[i]=new State[symbols];
    }
    for(int i=0;i<Automaton::getQ();i++)
    {
        for(int j=0;j<symbols;j++)
        {
           in>>table[i][j];
        }
    }

    return in;
}
