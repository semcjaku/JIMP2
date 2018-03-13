//
// Created by Kuba on 12-03-18.
//

#ifndef JIMP_EXERCISES_SIMPLEFORWARDLIST_H
#define JIMP_EXERCISES_SIMPLEFORWARDLIST_H

#include <iostream>
using namespace std;

typedef struct Forward
{
    struct Forward *next;
    int value;
} ForwardList;

ForwardList *CreateNode(int value);
void DestroyList(ForwardList *list);
ForwardList *PushFront(ForwardList *list, int value);
void Append(ForwardList *list, ForwardList *tail);

#endif //JIMP_EXERCISES_SIMPLEFORWARDLIST_H
