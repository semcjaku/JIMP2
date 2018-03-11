//
// Created by Kuba on 11-03-18.
//

#ifndef JIMP_EXERCISES_POLYBIUS_H
#define JIMP_EXERCISES_POLYBIUS_H

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string PolybiusCrypt(string message);
string PolybiusDecrypt(string crypted);

extern const char polybius_tab[5][5];

#endif //JIMP_EXERCISES_POLYBIUS_H
