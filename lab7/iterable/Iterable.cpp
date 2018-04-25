//
// Created by Kuba on 23-04-18.
//

#include "Iterable.h"

namespace utility
{
    IterableIterator::IterableIterator(const IterableIterator &ii)
    {
        left_=ii.left_;
        right_=ii.right_;
    }

    IterableIterator & IterableIterator::operator=(const IterableIterator &ii)
    {
        if (this == &ii) {
            return *this;
        }

        left_=ii.left_;
        right_=ii.right_;
    }

    //-------------------------------------------------------------------------------------------------------------------

    ZipperIterator::ZipperIterator(std::vector<int>::const_iterator left, std::vector<std::string>::const_iterator right,
                                            std::vector<int>::const_iterator left_end, std::vector<std::string>::const_iterator right_end)
    {
        left_=left;
        right_=right;
        left_end_=left_end;
        right_end_=right_end;
    }

    std::pair<int, std::string> ZipperIterator::Dereference() const
    {
        std::pair<int, std::string> values;
        values.first=*left_;
        values.second=*right_;
        return values;
    }

    IterableIterator & ZipperIterator::Next()
    {
        left_++;
        right_++;
        return *this;
    }

    bool ZipperIterator::NotEquals(const std::unique_ptr<IterableIterator> &other) const
    {
        bool logic1=other->left_==left_, logic2=other->right_==right_;
        bool conj=logic1 && logic2;
        return !conj;
    }

    //---------------------------------------------------------------------------------------------------------------------

    IterableIteratorWrapper::IterableIteratorWrapper(std::unique_ptr<IterableIterator> iterator)
    {
        iter_=move(iterator);
    }

    bool IterableIteratorWrapper::operator!=(const IterableIteratorWrapper &other)
    {
        return iter_->NotEquals(other.iter_);
    }

    std::pair<int, std::string> IterableIteratorWrapper::operator*()
    {
        return iter_->Dereference();
    }

    IterableIteratorWrapper & IterableIteratorWrapper::operator++()
    {
        iter_->Next();
        return *this;
    }

    //====================================================================================================================

    IterableIteratorWrapper Iterable::cbegin() const
    {
        IterableIteratorWrapper tmp(move(this->ConstBegin()));
        return tmp;
    }

    IterableIteratorWrapper Iterable::cend() const
    {
        IterableIteratorWrapper tmp(move(this->ConstEnd()));
        return tmp;
    }

    IterableIteratorWrapper Iterable::begin() const
    {
        return this->cbegin();
    }

    IterableIteratorWrapper Iterable::end() const
    {
        return this->cend();
    }

}