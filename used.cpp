#include "used.h"

string Used::concat(string first, string second)
{
    return first+second;
}

string Used::copy(string str)
{
  return str;
}

string Used::revers(string str)
{
    char temp;
    for(int i=0;i<str.size()/2;i++)
    {
        temp=str[i];
        str[i]=str[str.length()-1-i];
        str[str.length()-1-i]=temp;
    }
    return str;
}
