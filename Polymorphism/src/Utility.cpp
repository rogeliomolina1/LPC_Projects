/***

 ABOUT THIS FILE
 ---------------

 This code is the implementation (definitions) of all the functions
 listed in utils.h.

 THERE IS NO NEED TO READ ANY OF THIS. If anything is broken, it is my
 fault and I will fix it. You should leave all of this code alone.

***/

#include "Utility.h"
#include <cctype>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define Fail(x) { cerr << x << endl; exit(-1); }

string Utility::ConvertToLowercase(string s)
{
  string result = "";
  for (unsigned int i = 0; i < s.length(); i++)
    {
      result += tolower(s[i]);
    }
  return result;
}

string Utility::ConvertToUppercase(string s)
{
  string result = "";
  for (unsigned int i = 0; i < s.length(); i++)
    {
      result += toupper(s[i]);
    }
  return result;
}

void Utility::PrintWrappedString(string text)
{
  const int MAX_WIDTH = 60;
    string str=text;
    unsigned long pos = 0;
    unsigned long last = 0;
    while ((pos = str.find(" ", pos)) != string::npos)
    {
      if ((pos - last) > MAX_WIDTH)
        {
            str[pos] = '\n';
            last = pos;
        }
        pos++;
    }
    cout << str << endl;
}
