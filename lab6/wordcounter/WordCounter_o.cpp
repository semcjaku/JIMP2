//
// Created by Kuba on 15-04-18.
//

#include "WordCounter.h"

namespace datastructures
{
    /*struct {
        inline bool operator()(std::map<Word,Counts>::iterator a, std::map<Word,Counts>::iterator b) const
        {
            return a->second > b->second;
        }
    } customLess;*/

    bool Cmp(std::map<Word,Counts>::iterator a, std::map<Word,Counts>::iterator b)
    {
        return a->second > b->second;
    }

    Word::Word(string w)
    {
        word_=w;
    }

    Word::Word(const Word& w)
    {
        word_=w.word_;
    }

    Word & Word::operator=(const Word& w)
    {
        if (this == &w) {
            return *this;
        }

        word_=w.word_;
    }

    Word::Word(Word &&w)
    {
        word_.clear();
        std::swap(word_,w.word_);
    }

    Word & Word::operator=(Word &&w)
    {
        if (this == &w)
        {
            return w;
        }

        word_.clear();
        std::swap(word_,w.word_);
    }

    bool Word::operator<(const Word &w) const
    {
        return(word_<w.word_);
    }

    bool Word::operator==(const Word &w) const
    {
        return (word_==w.word_);
    }

    string Word::GetWord() const
    {
        return word_;
    }

//===============================================================

    Counts::Counts()
    {
        number=0;
    }

    Counts::Counts(unsigned int n)
    {
        number=n;
    }

    Counts::Counts(const Counts& c)
    {
        number=c.number;
    }

    Counts & Counts::operator=(const Counts& c)
    {
        if (this == &c) {
            return *this;
        }

        number=c.number;
    }

    Counts::Counts(Counts &&c)
    {
        unsigned int tmp;
        tmp=number;
        number=c.number;
        c.number=tmp;
    }

    Counts & Counts::operator=(Counts &&c)
    {
        if (this == &c)
        {
            return c;
        }

        unsigned int tmp;
        tmp=number;
        number=c.number;
        c.number=tmp;
    }

    Counts Counts::operator++()
    {
        ++number;
        return *this;
    }

    Counts Counts::operator++(int)
    {
        number++;
        return *this;
    }

    bool Counts::operator==(const Counts &c) const
    {
        return (number==c.number);
    }

    bool Counts::operator<(const Counts &c) const
    {
        return (number<c.number);
    }

    bool Counts::operator>(const Counts &c) const
    {
        return (number>c.number);
    }

    void Counts::SetCount(unsigned int x)
    {
        number=x;
    }

    unsigned int Counts::GetCount() const
    {
        return number;
    }

//===============================================================

    Counts WordCounter::operator[](string word)
    {
        Word tmp(word);
        auto map_check=dict.find(tmp);
        if(map_check!=dict.end())
            return dict[tmp];
        Counts x(0);
        return x;
    }

    WordCounter::WordCounter(std::initializer_list<Word> list)
    {
        for(Word n:list)
        {
            auto map_check=dict.find(n);
            dict[n]++;
        }

    }

    void WordCounter::AddWord(string w)
    {
        dict[w]++;
    }

    unsigned int WordCounter::DistinctWords()
    {
        return (unsigned int)dict.size();
    }

    unsigned int WordCounter::TotalWords()
    {
        unsigned int total=0;
        for(auto n:dict)
            total+=(n.second).GetCount();
        return total;
    }

    std::set<Word> WordCounter::Words()
    {
        std::set<Word> words;
        for(auto n:dict)
            words.emplace(n.first);
        return words;
    }

    void WordCounter::Sort()
    {
        std::sort(dict.begin(),dict.end(), std::greater<Counts>());
    }

    std::map<Word,Counts> WordCounter::GetDict()
    {
        return dict;
    };

    WordCounter WordCounter::FromInputStream(std::ifstream in)
    {
        WordCounter result;
        string buf;
        char tmp;
        if(in)
        {
            while(in.peek()!=EOF)
            {
                tmp=in.get();
                if(isalpha(tmp))
                    buf+=tmp;
                else
                {
                    result.AddWord(buf);
                    buf.clear();
                }
            }
        }
        return result;
    }

    //------------------------------------------------------------

    bool operator==(const int &i, const Counts &c)
    {
        return (i==c.GetCount());
    }

    std::ostream& operator<< (std::ostream &out,WordCounter &wc)
    {
        wc.Sort();
        for(auto n:wc.GetDict())
            out<<n.first.GetWord()<<": "<<n.second.GetCount()<<"; ";
        return out;
    }
}