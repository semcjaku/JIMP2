//
// Created by semcjaku on 29.05.18.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

#include <memory>

namespace tree
{
    template <class T>
    class Tree
    {
    public:
        Tree() : left{nullptr}, right{nullptr}, value(nullptr) {}
        explicit Tree(const T & value): right{nullptr}, left{nullptr}, value{std::make_shared<T>(value)} {}
        void Insert(const T & node);
        bool Find(const T & key);
        size_t Depth();
        size_t Size();
        T Value();


    private:
        std::shared_ptr<T> value;
        std::shared_ptr<Tree<T>> left;
        std::shared_ptr<Tree<T>> right;
    };

    template <class T>
    void Tree<T>::Insert(const T &node)
    {
        if(node < *value)
        {
            if(left==nullptr)
                left=std::make_shared<Tree<T>>(Tree(node));
            else
                left->Insert(node);
        }
        else
        {
            if(right==nullptr)
                right=std::make_shared<Tree<T>>(Tree(node));
            else
                right->Insert(node);
        }
    }

    template <class T>
    bool Tree<T>::Find(const T &key)
    {
        if(*value==key)
            return true;
        if(*value>key)
        {
            if(left==nullptr)
                return false;
            left->Find(key);
        }
        else
        {
            if(right==nullptr)
                return false;
            right->Find(key);
        }
    }

    template <class T>
    size_t Tree<T>::Depth()
    {
        if(left==nullptr && right==nullptr)
            return 1;
        if(left==nullptr)
            return 1+right->Depth();
        if(right==nullptr)
            return 1+left->Depth();
        return 1+std::max(left->Depth(),right->Depth());
    }

    template <class T>
    size_t Tree<T>::Size()
    {
        if(left==nullptr && right==nullptr)
            return 1;
        if(left==nullptr)
            return 1+right->Size();
        if(right==nullptr)
            return 1+left->Size();
        return 1+left->Size()+right->Size();
    }

    template <class T>
    T Tree<T>::Value()
    {
        return *value;
    }
}


#endif //JIMP_EXERCISES_TREE_H
