//
// Created by Kuba on 15-04-18.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <string>
#include <iostream>
#include <map>
#include <set>

using std::string;

namespace datastructures
{
    class Word
    {
    public:
        Word()=default;
        Word(string);
        ~Word()=default;

        Word(const Word& w);
        Word & operator=(const Word& w);

        Word(Word &&w);
        Word & operator=(Word &&w);

        bool operator<(const Word&) const;
        bool operator==(const Word&) const;

    private:
        string word_;
    };

    class Counts
    {
    public:
        Counts();
        Counts(unsigned int);
        ~Counts()=default;

        Counts(const Counts& c);
        Counts & operator=(const Counts& c);

        Counts(Counts &&c);
        Counts & operator=(Counts &&c);

        Counts operator++();
        Counts operator++(int);
        bool operator==(const Counts&) const;
        bool operator<(const Counts&) const;
        bool operator>(const Counts&) const;

        void SetCount(unsigned int);
        unsigned int GetCount() const;

    private:
        unsigned int number;
    };

    class WordCounter
    {
    public:
        WordCounter()=default;
        ~WordCounter()=default;

        Counts operator[](string word);
        //const Counts & operator[](string word) const;

        WordCounter(std::initializer_list<Word> list);

        //static WordCounter FromInputStream(std::ifstream);
        unsigned int DistinctWords();
        unsigned int TotalWords();
        std::set<Word> Words();

    private:
        std::map<Word,Counts> dict;
    };

    bool operator==(const int &i, const Counts &c);
}

#endif //JIMP_EXERCISES_WORDCOUNTER_H
