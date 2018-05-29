//
// Created by semcjaku on 29.05.18.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

namespace tree
{
    template <class T>
    class Tree
    {
    public:
        explicit Tree(const T  & t);
        void Insert(const T & node);
        bool Find(const T & key);

    private:
        std::unique_ptr<Tree> left;
        std::unique_ptr<Tree> right;
        T value;
        size_t depth;
        size_t size;
    };

    template <class T>
    Tree::Tree(const T  & t)
    {
        left=std::make_unique<Tree>(nullptr);
        right=std::make_unique<Tree>(nullptr);
        value=t;
        depth=1;
        size=1;
    }

    template <class T>
    void Tree<T>::Insert(const T &node)    //dorobic poziomy i rozmiar
    {
        if(this->value == nullptr)
            this->value=node;
        if(node < this->value)
            this->left->Insert(node);
        else
            this->right->Insert(node);
    }

    template <class T>
    bool Tree<T>::Find(const T &key)
    {
        Tree *tmp=this;
        while(tmp!=nullptr)
        {
            if(tmp->value==key)
                return true;
            if(tmp->value>key)
                tmp=&(this->left);
            else
                tmp=&(this->right);
        }
        return false;
    }
}


#endif //JIMP_EXERCISES_TREE_H
