//
// Created by Jakub on 25-03-18.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H

#include <iostream>
#include <string>
#include <unordered_map>

namespace nets
{
    class View
    {
    public:
        View();
        View(std::string sign);
        ~View();

        std::string Render(const std::unordered_map <std::string, std::string> &model) const;

    private:
        std::string text_;
    };
}


#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
