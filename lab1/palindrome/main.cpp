//
// Created by Kuba on 05-03-18.
//

#include "palindrome.h"

int main()
{
    cout<<"Wybierz opcje: [S]prawdz palindrom/[W]yjscie";
    char menu;
    cin>>menu;
    if(menu=='W')
        return 1;
    if(menu=='S')
    {
        string s1;
        cin>>s1;
        cout<<is_palindrome(s1);
    }
    return 0;
}