//
// Created by semcjaku on 24.04.18.
//

#include "Pesel.h"

namespace academia
{
    Pesel::Pesel() {}

    Pesel::Pesel(const char* nr) : numer_(nr)
    {
        const char* iter=nr;
        while(nr!='\0')
        {
            if(!isnum(*nr))
                throw InvalidPeselCharacter("Uzyto niedozwolonego znaku.");
        }
    }

    AcademiaDataValidationError::AcademiaDataValidationError(const std::string &massage)
            : invalid_argument(massage) {}

    InvalidPeselCharacter::InvalidPeselCharacter(const std::string &massage) : AcademiaDataValidationError(massage) {}
}

//InvalidPeselLength : AcademiaDataValidationError : invalid_argument