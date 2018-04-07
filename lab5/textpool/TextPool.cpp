//
// Created by Kuba on 07-04-18.
//

#include <cstring>
#include "TextPool.h"

namespace pool
{
    TextPool::TextPool()
    {
        pool_.clear();
    }

    TextPool::TextPool(std::vector<std::string> text)
    {
        for(auto n:text)
        {
            bool exists = false;
            for(auto m:pool_)
            {
                if(n==m)
                    exists=true;
            }
            if(!exists)
                pool_.push_back(n);
        }
    }

    TextPool::TextPool(TextPool &&tp)
    {
        pool_.clear();
        swap(pool_,tp.pool_);
    }

    TextPool & TextPool::operator=(TextPool &&tp)
    {

        if (this == &tp)
        {
            return tp;
        }

        pool_.clear();
        swap(pool_,tp.pool_);
    }

    std::experimental::string_view TextPool::Intern(const std::string &str)
    {
        for (auto n:pool_)
        {
            if(n==str)
            {
                std::experimental::string_view new_element(&n[0],n.size());
                return new_element;
            }
        }
        pool_.push_back(str);
        std::experimental::string_view new_element(&str[0],str.size());
        return new_element;
    }

    size_t TextPool::StoredStringCount() const
    {
        return pool_.size();
    }

    void TextPool::RemoveRedundant()
    {
        std::vector<std::string> cmpr;
        cmpr=pool_;
        pool_.clear();
        for(auto n:cmpr)
        {
            bool exists = false;
            for(auto m:pool_)
            {
                if(n==m)
                    exists=true;
            }
            if(!exists)
                pool_.push_back(n);
        }
    }
}