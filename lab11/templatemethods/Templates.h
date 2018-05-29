//
// Created by semcjaku on 22.05.18.
//

#ifndef JIMP_EXERCISES_TEMPLATES_H
#define JIMP_EXERCISES_TEMPLATES_H


#include <vector>
#include <algorithm>

namespace templates
{
    template<typename T>
    T Add(const T &a, const T &b)
    {
        return a+b;
    }

    template<typename T>
    double Mean(const std::vector<T> &buf)
    {
        double m;
        for(auto elem:buf)
            m+=(double)elem;
        m/=(double)buf.size();
        return m;
    }

    template<typename T>
    auto Value(T pointer)
    {
        return *pointer;
    }
}


#endif //JIMP_EXERCISES_TEMPLATES_H
