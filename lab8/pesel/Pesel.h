//
// Created by semcjaku on 24.04.18.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H

#include <stdexcept>

namespace academia
{
    class Pesel {
    public:

        Pesel();
        Pesel(const char*);

        void ValidatePesel(const char*);

    private:
        const char* numer_;
    };

    class AcademiaDataValidationError : public std::invalid_argument
    {
    public:
        AcademiaDataValidationError(const std::string &massage);
    };

    class InvalidPeselCharacter : public AcademiaDataValidationError
    {
    public:
        InvalidPeselCharacter(const std::string &massage);
    };

}



#endif //JIMP_EXERCISES_PESEL_H
