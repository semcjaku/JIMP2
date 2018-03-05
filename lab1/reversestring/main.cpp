//
// Created by Kuba on 04-03-18.
//

#include "reverseString.h"

int main()
{
    string s1;
    cin>>s1;
    int l1 = s1.length()+1;
    cout<<endl<<reverse(s1, l1);
    return 0;
}