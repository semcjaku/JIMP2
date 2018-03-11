//
// Created by Kuba on 11-03-18.
//

#include "XorCypherBreaker.h"

string XorCypherBreaker(const vector<char> &cryptogram, int key_length, const vector<string> &dictionary)
{
    int word_count=0;
    string key, best("");
    //int cnt=TryDecrypt(cryptogram, dictionary, key); cout<<cnt; int a; cin>>a;
   for(int i='a'; i<='z'; i++)
    {
        for(char j='a'; j<='z'; j++)
        {
            for(char k='a'; k<='z'; k++)
            {
                key.clear();
                key.push_back(i);
                key.push_back(j);
                key.push_back(k);
                int cnt=TryDecrypt(cryptogram, dictionary, key);
                if(cnt > word_count)
                {
                    word_count = cnt;
                    best = key;
                }

            }
        }
    }
    return best;
}

int TryDecrypt(const vector<char> &cryptogram, const vector<string> &dictionary, string key)
{
    int idx = 0, count=0;
    string tmp, tmp2;
    for(int i=0; i<cryptogram.size(); i++)
    {
        tmp+= cryptogram[i]^key[idx++];
        if(idx>=3)
            idx = 0;
    }

    if(tmp.size()<cryptogram.size()*9/10)
        return -1;

    size_t pos, pos2;
    pos = 0;
    pos2 = tmp.find(" ");

    do
    {
        pos2 = tmp.find(" ",pos);
        tmp2 = tmp.substr(pos, pos2!=string::npos ? (pos2-pos):(string::npos));

        if (find(dictionary.begin(),dictionary.end(),tmp2) != dictionary.end())
        {
            count++;
        }

        if(pos2!=string::npos)
        {
            pos = pos2+1;
        }
    } while(pos2!=string::npos);

    return count;
}