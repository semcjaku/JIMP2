//
// Created by Jakub on 25-03-18.
//

#include "SimpleTemplateEngine.h"

namespace nets
{
    View::View()
    {
        text_.clear();
    }

    View::View(std::string sign)
    {
        text_=sign;
    }

    View::~View(){}

    std::string View::Render(const std::unordered_map <std::string, std::string> &model) const
    {
        std::size_t posbeg, posend;
        std::string inserted, tmp;
        inserted.clear();
        posbeg=text_.length()+1;
        posend=std::string::npos;
        while(posbeg!=std::string::npos)
        {
            posbeg=text_.find("{{", posbeg==text_.length()+1 ? 0 : posend+2);
            inserted+=text_.substr(posend==std::string::npos ? 0 : posend+2, posbeg-(posend==std::string::npos ? 0 : posend+2));
            if(posbeg!=std::string::npos)
            {

                posend=text_.find("}}", posbeg+2);
                tmp=text_.substr(posbeg+2,posend-(posbeg+2));
                auto map_check=model.find(tmp);
                if(map_check!=model.end())
                    inserted+=map_check->second;
            }
        }
        return inserted;
    }

}