#include "key.h"
#include <iostream>
using namespace std;

int main()
{
   Key a, b, c;
   cin >> a >> b >> c;
   cout << a << b << c << endl;
   if (a < b) cout << “less” << endl;
   a = b = c;
   cout << a << b << c << endl;
   if (a == b) cout << “same” << endl;
   return 0;
}