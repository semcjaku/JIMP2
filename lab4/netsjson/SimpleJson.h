//
// Created by Jakub on 25-03-18.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H

#include <experimental/optional>
#include <string>

namespace nets
{
    class JsonValue
    {
    public:
        JsonValue();
        ~JsonValue();

        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;
        std::string ToString() const;
    private:

    };
}


#endif //JIMP_EXERCISES_SIMPLEJSON_H
