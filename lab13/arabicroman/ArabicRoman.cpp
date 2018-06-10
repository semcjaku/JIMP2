//
// Created by semcjaku on 05.06.18.
//

#include <stdexcept>
#include <vector>
#include <algorithm>
#include "ArabicRoman.h"

std::string ArabicToRoman(int x)
{
    if(x>3999 || x<=0)
        throw std::runtime_error("error");
    std::vector<int> arabic {1000,500,100,50,10,5,1};
    std::vector<std::string> roman {"M","D","C","L","X","V","I"};
    std::string result;
    int idx=0;
    while(x!=0 && idx<7)
    {
        if(x>=arabic[idx])
        {
            x-=arabic[idx];
            result+=roman[idx];
        }
        else if(idx%2==0 && idx<5 && x>=arabic[idx]-arabic[idx+2])
        {
            x-=arabic[idx]-arabic[idx+2];
            result+=roman[idx+2]+roman[idx];
            idx++;
        }
        else if(idx%2==1 && idx<6 && x>=arabic[idx]-arabic[idx+1])
        {
            x-=arabic[idx]-arabic[idx+1];
            result+=roman[idx+1]+roman[idx];
            idx++;
        }
        else
            idx++;
    }
    return result;
}

int RomanToArabic(std::string r)
{
    std::vector<int> arabic {1000,500,100,50,10,5,1};
    std::vector<char> roman {'M','D','C','L','X','V','I'};

    for(auto i : r)
        if(std::find(roman.begin(),roman.end(),i)==roman.end())
            throw std::runtime_error("error");

    int result=0, map_idx=0, str_idx=0;

    while(str_idx<r.length() && map_idx<7)
    {
        if(r[str_idx]==roman[map_idx])
        {
            result+=arabic[map_idx];
            str_idx++;
        }
        else if(map_idx%2==0 && map_idx<5 && str_idx<r.length()-1 && r[str_idx]==roman[map_idx+2] && r[str_idx+1]==roman[map_idx])
        {
            result+=arabic[map_idx]-arabic[map_idx+2];
            str_idx+=2;
            map_idx++;
        }
        else if(map_idx%2==1 && map_idx<6 && str_idx<r.length()-1 && r[str_idx]==roman[map_idx+1] && r[str_idx+1]==roman[map_idx])
        {
            result+=arabic[map_idx]-arabic[map_idx+1];
            str_idx+=2;
            map_idx++;
        }
        else
            map_idx++;
    }
    return result;
}
