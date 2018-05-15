//
// Created by semcjaku on 15.05.18.
//

#include <set>
#include <vector>
#include "Algo.h"

namespace algo
{

    void CopyInto(const std::vector<int> &v, int n_elements, std::vector<int> *out)
    {
        copy_n(v.begin(),n_elements,std::back_inserter(*out));
    }

    bool Contains(const std::vector<int> &v, int element)
    {
        return(find(v.begin(),v.end(),element)!=v.end());
    }

    std::vector<std::string> MapToString(const std::vector<double> &v)
    {
        std::vector<std::string> result;
        transform(v.begin(),v.end(),back_inserter(result),[](double v){return std::to_string(v);});
        return result;
    }

    void InitializeWith(int initial_value, std::vector<int> *v)
    {
        fill(v->begin(),v->end(),initial_value);
    }

    std::vector<int> InitializedVectorOfLength(int length, int initial_value)
    {
        std::vector<int> result;
        fill_n(back_inserter(result),length,initial_value);
        return result;
    }

    std::set<std::string> Keys(const std::map<std::string, int> &m)
    {
        std::set<std::string> result;
        transform(m.begin(),m.end(),inserter(result,result.begin()),[](std::pair<std::string,int> m){return m.first;});
        return result;
    }

    std::vector<int> Values(const std::map<std::string, int> &m)
    {
        std::vector<int> result;
        transform(m.begin(),m.end(),back_inserter(result),[](std::pair<std::string,int> m){return m.second;});
        return result;
    }

    bool ContainsKey(const std::map<std::string, int> &v, const std::string &key)
    {
        std::set<std::string> result=Keys(v);
        return(find(result.begin(),result.end(),key)!=result.end());
    }

    bool ContainsValue(const std::map<std::string, int> &v, int value)
    {
        std::vector<int> result=Values(v);
        return(find(result.begin(),result.end(),value)!=result.end());
    }

    std::map<std::string, int> DivisableBy(const std::map<std::string, int> &m, int divisor)
    {
        std::map<std::string, int> result;
        transform(m.begin(),m.end(),back_inserter(result),[divisor](std::pair<std::string,int> m){if (m.second%divisor==0)return m.second;});
        return result;
    }

}