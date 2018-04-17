//
// Created by semcjaku on 17.04.18.
//

#include "ArrayFill.h"

namespace arrays
{
    void FillArray(size_t size, const ArrayFill &filler, std::vector<int> *v) {
        v->clear();
        v->reserve(size);
        for (size_t i = 0; i < size; i++) {
            v->emplace_back(filler.Value(i));
        }
    }

    int UniformFill::Value(int index) const {
        return value_;
    }

    int IncrementalFill::Value(int index) const {
        if(!index)
            return begin_;
        return begin_+index*step_;
    }
}