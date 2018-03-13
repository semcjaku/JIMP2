//
// Created by semcjaku on 06.03.18.
//

#include "Array2d.h"

int **NewArray2D(int n_rows, int n_columns)
{
    if(n_rows<1 || n_columns<1)
        return NULL;
    int **tab = new int *[n_rows];
    for(int i=0;i<n_rows;i++)
    {
        tab[i]=new int[n_columns];
    }
    FillArray2D(n_rows, n_columns, tab);
    return tab;
}

void FillArray2D(int n_rows, int n_columns, int *const *tab) {
    int number=1;
    for(int i=0;i<n_rows;i++)
    {
        for(int j=0;j<n_columns;j++)
        {
            tab[i][j]=number;
            number++;
        }
    }
}

void DeleteArray2D(int **array, int n_rows, int n_columns)
{
    for(int i=0;i<n_rows;i++)
    {
        delete array[i];
    }
    delete array;
}