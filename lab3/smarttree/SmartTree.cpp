//
// Created by Jakub on 19-03-18.
//

#include "SmartTree.h"

namespace datastructures
{
    std::unique_ptr <SmartTree> CreateLeaf(int value)
    {
        std::unique_ptr<SmartTree> leaf = std::make_unique<SmartTree>();
        leaf->value=value;
        leaf->left=nullptr;
        leaf->right=nullptr;
        return move(leaf);
    }

    std::unique_ptr <SmartTree> InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree)
    {
        tree->left=move(left_subtree);
        return move(tree);
    }

    std::unique_ptr <SmartTree> InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree)
    {
        tree->right=move(right_subtree);
        return move(tree);
    }

    void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out)
    {
        if(unique_ptr!=nullptr)
        {
            if(unique_ptr->left)
                PrintTreeInOrder(unique_ptr->left, out);
            *out<<unique_ptr->value<<", ";
            if(unique_ptr->right)
                PrintTreeInOrder(unique_ptr->right, out);
        }
    }

    void Dump (const std::unique_ptr<SmartTree> &tree, std::string &dump)
    {
        if(tree!=nullptr)
        {
            dump+="["+std::to_string(tree->value)+" ";
            Dump(tree->left, dump);
            dump+=" ";
            Dump(tree->right, dump);
            dump+="]";
        }
        else
        {
            dump+="[none]";
        }
    }

    std::string DumpTree(const std::unique_ptr<SmartTree> &tree)
    {
        std::string dump;
        dump.clear();
        Dump(tree, dump);
        return dump;
    }

    std::unique_ptr <SmartTree> RestoreTree(const std::string &tree)
    {

    }
}