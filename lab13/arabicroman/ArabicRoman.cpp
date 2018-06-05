//
// Created by semcjaku on 05.06.18.
//

#include <stdexcept>
#include <map>
#include "ArabicRoman.h"

std::string ArabicToRoman(int x)
{
    if(x>3999 || x<=0)
        throw std::runtime_error("error");
    std::map<std::string,int> convtable;
    convtable["I"]=1;
    convtable["V"]=5;
    convtable["X"]=10;
    convtable["L"]=50;
    convtable["C"]=100;
    convtable["D"]=500;
    convtable["M"]=1000;
    std::string result, tmp;
    tmp=std::to_string(x);
    if(tmp.length()==4)
        for(int i=0;i</*std::stoi(tmp,0,10)*/;i++)
            result+="M";
    if(tmp.length()>=3)
        if()
    return result;
}