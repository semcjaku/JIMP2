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
        size_t empty=tree.find("[none]"), pos;
        std::unique_ptr <SmartTree> root, current, newleaf;
        std::string tree_part;
        if(tree.compare("[none]")!=0)
        {
            root=CreateLeaf(stoi(tree,&pos,10));
            current=move(root->left);
            tree_part=tree.substr(pos+1,std::string::npos);
        }
        while(pos<empty)
        {
            newleaf=CreateLeaf(stoi(tree_part,&pos,10));
            current->left=InsertLeftChild(move(current->left),move(newleaf));
            current=move(current->left);
            tree_part=tree.substr(pos+1,std::string::npos);
        }
        /*pos=tree_part.find("[none]");
        if(pos!=empty+7)
        {
            newleaf=CreateLeaf(stoi(tree_part,&pos,10));
            current->right=InsertLeftChild(move(current->right),move(newleaf));
        }*/
        return move(root);
    }
}