//
// Created by Kuba on 07-04-18.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H

#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>
#include <vector>

namespace pool
{
    class TextPool
    {
    public:
        /*Rule of Five (z usuniętą możliwością kopiowania)
        domyślny konstruktor
        konstruktor z listą inicjalizacyjną*/
        TextPool();
        TextPool(std::vector<std::string> text);
        ~TextPool()=default;
        TextPool(const std::initializer_list<std::string> &elements) : pool_{elements} {RemoveRedundant();}

        TextPool(TextPool &&tp);
        TextPool & operator=(TextPool &&tp);

        void RemoveRedundant();
        std::experimental::string_view Intern(const std::string &str);
        size_t StoredStringCount() const;

    private:
        std::vector<std::string> pool_;
    };
}

#endif //JIMP_EXERCISES_TEXTPOOL_H
