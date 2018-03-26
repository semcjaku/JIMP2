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
        std::size_t posbeg, posend, exception;
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
                exception=text_.find("}", posbeg);
                if(exception<posend)                        //sprawdza przypadki typu "{{tekst} tekst {tekst}}"
                {
                    exception=posbeg;
                    posbeg=text_.find("{{", posbeg+1);
                    inserted+=text_.substr(exception, posbeg-(exception+1));
                    posend=text_.find("}}", posbeg+2);
                }
                exception=text_.find("{{{");
                if(exception==posbeg)
                    inserted+=" ";
                while(exception==posbeg)                    //sprawdza przypadki, gdy tekst obłożony więcej niż 2 nawiasami
                {
                    exception=text_.find("{{{");
                    inserted+="{";
                    posbeg++;
                }
                tmp=text_.substr(posbeg+2,posend-(posbeg+2));
                auto map_check=model.find(tmp);
                if(map_check!=model.end())
                    inserted+=map_check->second;
            }
        }
        return inserted;
    }

}