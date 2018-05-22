//
// Created by semcjaku on 22.05.18.
//

#include <iostream>
#include <complex.h>
#include <bits/shared_ptr.h>
#include "Templates.h"
#include <string>
using templates::Add;
using templates::Mean;
using templates::Value;

int main()
{
    //------Test Add--------------------------------
//    int a=1,b=3;
//    double c=1.0,d=3.5;
//    std::complex<double> e(2.0,3.0),f(1.0,5.0);
//    std::cout<<Add(a,b)<<std::endl;
//    std::cout<<Add(c,d)<<std::endl;
//    std::cout<<Add(e,f)<<std::endl;

    //------Test Mean-------------------------------
//    std::vector<int> x{1,3,3,4,5};
//    std::vector<double> y{1.0,3.0,3.0,4.0,5.0};
//    std::cout<<Mean(x)<<std::endl;
//    std::cout<<Mean(y)<<std::endl;

    //------Test Value-------------------------------
    int *p = new int(73);
    int z=Value(p);
    std::shared_ptr<double> p2 =std::make_shared<double>(3.7);
    double q=Value(p2);
    std::vector<std::string> vs{"abc"};
    std::string str=Value(vs.begin());
    std::cout<<z<<std::endl;
    std::cout<<q<<std::endl;
    std::cout<<str<<std::endl;


    return 0;
}