//file exception.cpp
//Alex Giacobbi and Jalen Tacsiat
//agiacobbi
//date: 11/1/18
//implementation file for exception.cpp

//    data object: a message explaining an exception
//    operations: constructor, what

#include "exception.h"

//creates an exception message
//pre  theMessage passed may be a literal string
//post exception message object is assigned theMessage
//usage throw cexception ("BAD MOVE");
Exception::Exception(string theMessage) 
{
    message = theMessage;
}

//outputs a message exception
//pre message object has been assigned 
//post returns the exception message when exception is thrown
//usage cout << except.what() << endl;
string Exception::what() const
{
    return message;
}
