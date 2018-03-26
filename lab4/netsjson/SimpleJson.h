//
// Created by Jakub on 25-03-18.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H

#include <experimental/optional>
#include <string>
#include <vector>
#include <map>

namespace nets
{
    class JsonValue
    {
    public:
        int i_value, type;
        double d_value;
        bool b_value;
        std::string s_value;
        std::vector<JsonValue> v_value;
        std::map<std::string, JsonValue> m_value;
        JsonValue();
        JsonValue(int a) : i_value(a) {type=1;}
        JsonValue(double a) : d_value(a) {type=2;}
        JsonValue(bool a) : b_value(a) {type=3;}
        JsonValue(std::string a) : s_value(a) {type=4;}
        JsonValue(std::vector<JsonValue> a) : v_value(a) {type=5;}
        JsonValue(std::map<std::string, JsonValue> a) : m_value(a) {type=6;}

        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;
        std::string ToString() const;

    };
}


#endif //JIMP_EXERCISES_SIMPLEJSON_H
