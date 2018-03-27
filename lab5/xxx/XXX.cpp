//
// Created by semcjaku on 27.03.18.
//

#include <cstring>
#include <algorithm>
#include "XXX.h"

XXX::XXX() : name_{new char[1024]} {

}

XXX::~XXX() {
    delete [] name_;
}

XXX::XXX(const XXX& xxx) {
    std::size_t sz = strlen(xxx.name_);
    name_ = new char[sz];
    strcpy(name_, xxx.name_);
}

XXX & XXX::operator=(const XXX& xxx) {

    if (this == &xxx) {
        return *this;
    }

    delete[] name_;

    size_t sz = strlen(xxx.name_);
    name_ = new char[sz];
    strcpy(name_,xxx.name_);
}

XXX::XXX(XXX &&xxx) : name_{nullptr} {
    std::swap(name_, xxx.name_);
}

XXX & XXX::operator=(XXX &&xxx) {
;
    if (this == &xxx) {
        return xxx;
    }

    delete[] name_;

    name_ = nullptr;
    std::swap(name_,xxx.name_);
}