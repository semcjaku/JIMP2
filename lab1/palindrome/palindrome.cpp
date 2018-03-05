//
// Created by Kuba on 05-03-18.
//

#include "palindrome.h"

bool is_palindrome(string s)
{
    int k=0, l=s.length();
    for(int i=0;i<l/2+1;i++)
    {
        if(s[i]!=s[l-1-i])
        {
            k++;
        }
    }
    if(k)
        return false;
    return true;
}
