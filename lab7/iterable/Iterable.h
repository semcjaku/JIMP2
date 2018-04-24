//
// Created by Kuba on 23-04-18.
//

#ifndef JIMP_EXERCISES_ITERABLE_H
#define JIMP_EXERCISES_ITERABLE_H


#include <string>
#include <vector>
#include <memory>

namespace utility
{


    class IterableIterator
    {
    public:
        ~IterableIterator()=default;
        virtual std::pair<int, std::string> Dereference() const =0;
        virtual IterableIterator &Next()=0;
        virtual bool NotEquals(const std::unique_ptr<IterableIterator> &other) const =0;
        std::vector<int>::const_iterator left_;
        std::vector<std::string>::const_iterator right_;
    };

    class ZipperIterator : public IterableIterator
    {
    public:
        explicit ZipperIterator(std::vector<int>::const_iterator left, std::vector<std::string>::const_iterator right,
                                std::vector<int>::const_iterator left_end, std::vector<std::string>::const_iterator right_end);
        std::pair<int, std::string> Dereference() const override ;
        IterableIterator &Next() override ;
        bool NotEquals(const std::unique_ptr<IterableIterator> &other) const override ;

    private:
        std::vector<int>::const_iterator left_end_;
        std::vector<std::string>::const_iterator right_end_;
    };

    /*class IterableIteratorWrapper : public IterableIterator
    {
    public:
        IterableIteratorWrapper(std::unique_ptr<IterableIterator> iterator);
        bool operator!=(const IterableIteratorWrapper &other);
        std::pair<int, std::string> operator*();
        IterableIteratorWrapper &operator++();
    private:
        //IterableIterator iter_;
    };

    class Iterable
    {
    public:
        virtual std::unique_ptr<IterableIterator> ConstBegin =0;
        virtual std::unique_ptr<IterableIterator> ConstEnd =0;
        IterableIteratorWrapper cbegin() const;
        IterableIteratorWrapper cend() const;
        //IterableIteratorWrapper begin() const;
        //IterableIteratorWrapper end() const;
    };*/
}


#endif //JIMP_EXERCISES_ITERABLE_H
