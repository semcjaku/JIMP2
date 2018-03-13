//
// Created by semcjaku on 13.03.18.
//

#include "MinimalTimeDifference.h"

unsigned int ToMinutes(std::string time_HH_MM)
{
    std::unsigned int minutes=0;
    std::int separator = time_HH_MM.find(":",);
    std::size_t *pos=*time_HH_MM[separator];
    minutes+=(60*stoi(time_HH_MM,pos,10));
    std::string tmp = time_HH_MM.substr(separator+1);
    pos=*tmp;
    minutes+=stoi(time_HH_MM,pos,10);
    return minutes;
}

unsigned int MinimalTimeDifference(std::vector<std::string> times)
{

}