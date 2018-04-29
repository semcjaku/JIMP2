//
// Created by semcjaku on 24.04.18.
//

#include "Pesel.h"
#include <iostream>
using ::academia::Pesel;
using ::academia::InvalidPeselChecksum;
using ::academia::InvalidPeselLength;
using ::academia::InvalidPeselCharacter;
using ::academia::AcademiaDataValidationError;

int main()
{
    try
    {
        Pesel("44051401359");
    }
    catch(InvalidPeselLength &x)
    {
        std::cout<<"dlugosc";
    }
    catch(InvalidPeselChecksum &y)
    {
        std::cout<<"suma";
    }
    catch(InvalidPeselCharacter &z)
    {
        std::cout<<"character";
    }

}
