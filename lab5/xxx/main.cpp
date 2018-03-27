//
// Created by semcjaku on 27.03.18.
//
#include "XXX.h"
#include <algorithm>

int main()
{
    XXX x,y;
    y=x;
    XXX z{std::move(x)};
    return 0;
};