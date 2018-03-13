//
// Created by Kuba on 12-03-18.
//

#include "GreatestProduct.h"

int GreatestProduct(const vector<int> &numbers, int k)
{
    vector<int> greatest;
    for(int i=0; i<k; i++)
        greatest.push_back(0);
    int product=1, j,index;
    bool change;
    for(int v : numbers)
    {
        j=0;
        index=0;
        change=false;
        for(int w : greatest)
        {
            if(v>w)
            {
                change=true;
                if(greatest[j]<greatest[index])
                    index=j;
            }
            j++;
        }
        if(change)
            greatest[index]=v;
    }
    for(int v : greatest)
        product*=v;
    return product;
}
