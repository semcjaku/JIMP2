//
// Created by Kuba on 04-03-18.
//

#include "ReverseString.h"

string reverse(string s, int l)
{
    if(l==1)
    {
        return s;
    }
    else
    {
        char tmp = s[0];
        string s2;
        s2.push_back(tmp);
        s.erase(0,1);
        s.insert(l-2,s2);
        s2.clear();
        l--;
        return reverse(s,l);
    }
}