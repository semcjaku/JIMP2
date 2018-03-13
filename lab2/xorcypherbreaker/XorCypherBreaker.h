//
// Created by Kuba on 11-03-18.
//

#ifndef JIMP_EXERCISES_XORCYPHERBREAKER_H
#define JIMP_EXERCISES_XORCYPHERBREAKER_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string XorCypherBreaker(const vector<char> &cryptogram, int key_length, const vector<string> &dictionary);
int TryDecrypt(const vector<char> &cryptogram, const vector<string> &dictionary, string key);

#endif //JIMP_EXERCISES_XORCYPHERBREAKER_H
