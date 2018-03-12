//
// Created by Kuba on 12-03-18.
//

#include "SimpleForwardList.h"

ForwardList *CreateNode(int value)
{
    ForwardList *new_node;
    new_node = (ForwardList *) malloc(sizeof(ForwardList));
    new_node->value = value;
    new_node->next = nullptr;
    return new_node;
}

void DestroyList(ForwardList *list)
{
    ForwardList *k=list->next, *l=list;
    while(l->next!=nullptr)
    {
        while(k->next!=nullptr)
        {
            l=l->next;
            k=k->next;
        }
        l->next=nullptr;
        free(l);
        l=list;
    }
    free(l);
    free(list);
}

ForwardList *PushFront(ForwardList *list, int value)
{
    ForwardList *new_node;
    new_node = (ForwardList *) malloc(sizeof(ForwardList));
    new_node->next=list;
    new_node->value=value;
    return new_node;
}

void Append(ForwardList *list, ForwardList *tail)
{
    while(list!=nullptr)
        list=list->next;
    list->next=tail;
    tail->next=nullptr;
}