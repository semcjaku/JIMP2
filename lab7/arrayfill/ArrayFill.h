//
// Created by semcjaku on 17.04.18.
//

#ifndef JIMP_EXERCISES_ARRAYFILL_H
#define JIMP_EXERCISES_ARRAYFILL_H

#include <cstdio>
#include <vector>
#include <random>
using ::std::default_random_engine;
using ::std::uniform_int_distribution;

namespace arrays
{
    class ArrayFill {
    public:
        virtual int Value(int index) const =0;
    };

    void FillArray(size_t size, const ArrayFill &filler, std::vector<int> *v);

    class UniformFill : public ArrayFill {
    public:
        UniformFill(int value = 0) : value_{value} {}
        virtual int Value(int index) const override;
    private:
        int value_;
    };

    class IncrementalFill : public ArrayFill
    {
    public:
        IncrementalFill(int begin = 0, int step = 1) : begin_{begin}, step_{step} {}
        virtual int Value(int index) const override;
    private:
        int begin_;
        int step_;
    };

    class RandomFill : public ArrayFill
    {
    public:
        RandomFill(std::unique_ptr<default_random_engine> generator, std::unique_ptr<uniform_int_distribution<int>> distribution) :
    private:

    };
}

#endif //JIMP_EXERCISES_ARRAYFILL_H
