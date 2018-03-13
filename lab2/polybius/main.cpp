//
// Created by Kuba on 11-03-18.
//

#include "Polybius.h"

int main()
{
    string word, code;
    cin>>word;
    code=PolybiusCrypt(word);
    cout<<code<<endl;
    word=PolybiusDecrypt(code);
    cout<<word
    return 0;
}