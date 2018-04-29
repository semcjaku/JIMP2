//
// Created by semcjaku on 24.04.18.
//

#include "Pesel.h"

namespace academia
{
    Pesel::Pesel() {}

    Pesel::Pesel(const char* nr) : numer_(nr)
    {
        int length=0, checksum=0, factor;
        char* iter=(char*)nr;
        std::string pesel;
        for(iter; *iter!='\0'; iter++)
            pesel+=*iter;
        iter=(char*)nr;
        while(*iter!='\0')
        {
            if(!isdigit(*iter))
                throw InvalidPeselCharacter(pesel);
            length++;
            switch (length%4)
            {
                case 0:
                    factor=1;
                    break;
                case 1:
                    factor=9;
                    break;
                case 2:
                    factor=7;
                    break;
                case 3:
                    factor=3;
                    break;
            }
            checksum+=((*iter)-'0')*factor;
            iter++;
        }
        if(length!=11)
            throw InvalidPeselLength(pesel, length);
        iter=(char*)numer_+10;
        if((checksum-((*iter)-'0')*3)%10!=*iter-'0')
            throw InvalidPeselChecksum(pesel, (checksum-((*iter)-'0')*3)%10);
    }

    AcademiaDataValidationError::AcademiaDataValidationError(const std::string &message)
            : invalid_argument(message) {}

    InvalidPeselCharacter::InvalidPeselCharacter(const std::string &message) : AcademiaDataValidationError("Invalid PESEL("+message+") character set") {}

    InvalidPeselLength::InvalidPeselLength(const std::string &message, int len) : AcademiaDataValidationError("Invalid PESEL("+message+") length: "+std::to_string(len)) {}

    InvalidPeselChecksum::InvalidPeselChecksum(const std::string &message, int sum) : AcademiaDataValidationError("Invalid PESEL("+message+") checksum: "+std::to_string(sum)) {}
}
