//file exception.h
//Alex Giacobbi and Jalen Tacsiat
//agiacobbi
//date: 11/1/18
//specification file for exception.cpp

//    data object: a message explaining an exception
//    operations: constructor, what

#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>
using namespace std;

class Exception
{
public:
   //creates an exception message
   //pre  theMessage passed may be a literal string
   //post exception message object is assigned theMessage
   //usage throw Exception ("BAD MOVE");
   Exception(string theMessage ) ;

   //outputs a message exception
   //pre message object has been assigned 
   //post returns the exception message when exception is thrown
   //usage cout << except.what() << endl;
   string what() const;
private:
    string message;
};
#endif
