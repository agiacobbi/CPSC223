// client program of class Key
// following Homework

#include "key.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(){
   Key a, b, c, file;
   fstream fin, fout;
	
   cin >> a >> b >> c;
   cout << a << " " <<  b << " " <<  c << endl;
   if (a ==b) cout << "same" << endl;
   else cout << "not same" << endl;
   
   a = b = c;
   cout << a << ' ' << b << ' ' << c << endl;
   
   a = a;
   cout << a << endl;
   
   cout << a.convertToInteger() << endl;
   
   fin.open("in.dat");
   fout.open("out.dat");

   fin >> file;
   fout << file;
   cout << file << endl;

   fin.close();
   
   return 0;
}
	
