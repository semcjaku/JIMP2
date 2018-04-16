//
// Created by Kuba on 15-04-18.
//

#include "WordCounter.h"
using ::datastructures::WordCounter;
using ::datastructures::Counts;
using ::datastructures::Word;

int main()
{
    WordCounter counter {Word("z"), Word("p"), Word("z"), Word("z"), Word("hi"), Word("voltage")};
    std::cout<<counter;
    return 0;
}