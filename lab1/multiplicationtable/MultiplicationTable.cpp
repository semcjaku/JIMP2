//
// Created by Kuba on 05-03-18.
//

#include "MultiplicationTable.h"

void MultiplicationTable(int tab[][10])
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
            tab[i][j]=(i+1)*(j+1);
    }
}

void PrintTable(int tab[][10])
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if (tab[i][j] < 10)
                cout << " ";
            cout << tab[i][j] << " ";
        }
        cout<<endl;
    }
}