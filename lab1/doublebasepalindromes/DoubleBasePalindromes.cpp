//
// Created by Kuba on 05-03-18.
//

#include "DoubleBasePalindromes.h"

uint64_t DoubleBasePalindromes(int max_vaule_exculsive)
{
    int total=0;
    for(int i=1;i<=max_vaule_exculsive;i+=2)
    {
        int check=0, rev=0, j=i;
        while(j>0)
        {
            rev = rev*10+j%10;
            j/=10;
        }
        if(rev==i)
            check++;
        rev=0;
        j=i;
        while(j>0)
        {
            rev = rev*2+j%2;
            j/=2;
        }
        if(rev==i)
            check++;
        if(check==2)
            total+=i;
    }
    return total;
}