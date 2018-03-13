//
// Created by Kuba on 11-03-18.
//

#include "Polybius.h"

const char polybius_tab[5][5] = {{'A', 'B', 'C', 'D', 'E'},
                           {'F', 'G', 'H', 'I', 'K'},
                           {'L', 'M', 'N', 'O', 'P'},
                           {'Q', 'R', 'S', 'T', 'U'},
                           {'V', 'W', 'X', 'Y', 'Z'}};
string PolybiusCrypt(string message)
{
    string encrypted;
    bool found;
    transform(message.begin(), message.end(),message.begin(), ::toupper);
    replace( message.begin(), message.end(), 'J', 'I');
    for(int i=0; i<message.length(); i++)
    {
        if(message[i] == ' ')
            continue;
        found = false;
        for(int row=0; row<5; row++)
        {
            for(int column=0; column<5; column++)
            {
                if(message[i] == polybius_tab[row][column])
                {
                    encrypted+=to_string(row+1)+to_string(column+1);
                    found = true;
                    break;
                }
            }
            if(found)
                break;
        }
    }
    return encrypted;
}

string PolybiusDecrypt(string crypted)
{
    int row, column;
    string decrypted;
    for(int i=0; i<crypted.length(); i+=2)
    {
        decrypted+=polybius_tab[(int)crypted[i]-48-1][(int)crypted[i+1]-48-1];
    }
    transform(decrypted.begin(), decrypted.end(),decrypted.begin(), ::tolower);
    return decrypted;
}