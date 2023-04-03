#ifndef AUTOMATIONEXCEPTION_H_INCLUDED
#define AUTOMATIONEXCEPTION_H_INCLUDED

#include<iostream>
#include"State.h"
#include<exception>
#include <string>

class AutomationException: public std::exception
{
private:
    std::string msg;
   public:
   AutomationException():exception()
   {
       std::cout<<"AutomationException!\n";
   }

   virtual const char* what() const throw() {
        return "AutomationException";
   }

};

#endif // AUTOMATIONEXCEPTION_H_INCLUDED
