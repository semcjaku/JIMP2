//
// Created by Kuba on 04-06-18.
//

#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H

#include <chrono>
#include <utility>

namespace profiling
{
    template <typename T>
    auto TimeRecorder(T object)
    {
        auto begin = std::chrono::high_resolution_clock::now();
        auto result = object();
        auto end = std::chrono::high_resolution_clock::now();

        auto time = std::chrono::duration<double,std::milli>(end-begin).count();
        return std::make_pair(result,time);
    }
}


#endif //JIMP_EXERCISES_TIMERECORDER_H
