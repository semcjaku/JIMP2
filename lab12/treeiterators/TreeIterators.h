//
// Created by Kuba on 04-06-18.
//

#ifndef JIMP_EXERCISES_TREEITERATORS_H
#define JIMP_EXERCISES_TREEITERATORS_H

#include <vector>
#include "../tree/Tree.h"

namespace tree
{
    template <typename T>
    class PreOrderTreeIterator
    {
    public:
        explicit PreOrderTreeIterator(std::shared_ptr<Tree<T>> root)
        {
            FillOrder(root);
            idx = 0;
        }

        void FillOrder(std::shared_ptr<Tree<T>> tree)
        {
            order.push_back(tree);
            if (tree->left!=nullptr)
                FillOrder(tree->left);
            if (tree->right!=nullptr)
                FillOrder(tree->right);
        }

        PreOrderTreeIterator<T> End()
        {
            idx = (int)order.size();
            return *this;
        }

        PreOrderTreeIterator<T> operator++()
        {
            idx++;
            return *this;
        }

        T operator*()
        {
            return order[idx]->Value();

        }

        bool operator!=(const PreOrderTreeIterator &other) const
        {
            return idx!=other.idx;
        }


    private:
        std::vector<std::shared_ptr<Tree<T>>> order;
        int idx;
    };

    template<typename T>
    class PreOrderTreeView
    {
    public:
        explicit PreOrderTreeView(Tree<T> *tree) : root{std::make_shared<Tree<T>>(*tree)} {};

        PreOrderTreeIterator<T> begin()
        {
            return PreOrderTreeIterator<T>(root);
        }

        PreOrderTreeIterator<T> end()
        {
            return PreOrderTreeIterator<T>(root).End();
        }

    private:
        std::shared_ptr<Tree<T>> root;
    };

    template<typename T>
    PreOrderTreeView<T> PreOrder(Tree<T> *tree)
    {
        return PreOrderTreeView<T>(tree);
    }

    //==================================================================================================================

    template <typename T>
    class PostOrderTreeIterator
    {
    public:
        explicit PostOrderTreeIterator(std::shared_ptr<Tree<T>> root)
        {
            FillOrder(root);
            idx = 0;
        }

        void FillOrder(std::shared_ptr<Tree<T>> tree)
        {
            if (tree->left!=nullptr)
                FillOrder(tree->left);
            if (tree->right!=nullptr)
                FillOrder(tree->right);
            order.push_back(tree);
        }

        PostOrderTreeIterator<T> End()
        {
            idx = (int)order.size();
            return *this;
        }

        PostOrderTreeIterator<T> operator++()
        {
            idx++;
            return *this;
        }

        T operator*()
        {
            return order[idx]->Value();

        }

        bool operator!=(const PostOrderTreeIterator &other) const
        {
            return idx!=other.idx;
        }


    private:
        std::vector<std::shared_ptr<Tree<T>>> order;
        int idx;
    };

    template<typename T>
    class PostOrderTreeView
    {
    public:
        explicit PostOrderTreeView(Tree<T> *tree) : root{std::make_shared<Tree<T>>(*tree)} {};

        PostOrderTreeIterator<T> begin()
        {
            return PostOrderTreeIterator<T>(root);
        }

        PostOrderTreeIterator<T> end()
        {
            return PostOrderTreeIterator<T>(root).End();
        }

    private:
        std::shared_ptr<Tree<T>> root;
    };

    template<typename T>
    PostOrderTreeView<T> PostOrder(Tree<T> *tree)
    {
        return PostOrderTreeView<T>(tree);
    }
    
    //==================================================================================================================

    template <typename T>
    class InOrderTreeIterator
    {
    public:
        explicit InOrderTreeIterator(std::shared_ptr<Tree<T>> root)
        {
            FillOrder(root);
            idx = 0;
        }

        void FillOrder(std::shared_ptr<Tree<T>> tree)
        {
            if (tree->left!=nullptr)
                FillOrder(tree->left);
            order.push_back(tree);
            if (tree->right!=nullptr)
                FillOrder(tree->right);
        }

        InOrderTreeIterator<T> End()
        {
            idx = (int)order.size();
            return *this;
        }

        InOrderTreeIterator<T> operator++()
        {
            idx++;
            return *this;
        }

        T operator*()
        {
            return order[idx]->Value();

        }

        bool operator!=(const InOrderTreeIterator &other) const
        {
            return idx!=other.idx;
        }


    private:
        std::vector<std::shared_ptr<Tree<T>>> order;
        int idx;
    };

    template<typename T>
    class InOrderTreeView
    {
    public:
        explicit InOrderTreeView(Tree<T> *tree) : root{std::make_shared<Tree<T>>(*tree)} {};

        InOrderTreeIterator<T> begin()
        {
            return InOrderTreeIterator<T>(root);
        }

        InOrderTreeIterator<T> end()
        {
            return InOrderTreeIterator<T>(root).End();
        }

    private:
        std::shared_ptr<Tree<T>> root;
    };

    template<typename T>
    InOrderTreeView<T> InOrder(Tree<T> *tree)
    {
        return InOrderTreeView<T>(tree);
    }  
}


#endif //JIMP_EXERCISES_TREEITERATORS_H
