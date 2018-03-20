//
// Created by semcjaku on 20.03.18.
//

#include "Square.h"

int main()
{
    geometry::Point punkt1(1,1), punkt2(3,3);
    std::cout<<punkt1.Distance(punkt2);
    punkt1.ToString(&std::cout);
    return 0;
}