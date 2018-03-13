//
// Created by semcjaku on 13.03.18.
//

#include "MinimalTimeDifference.h"

unsigned int ToMinutes(std::string time_HH_MM)
{
    unsigned int minutes=0;
    int separator = time_HH_MM.find(":",);
    size_t *pos=*time_HH_MM[separator];
    minutes+=(60*stoi(time_HH_MM,pos,10));
    std::string tmp = time_HH_MM.substr(separator+1);
    pos=*tmp;
    minutes+=stoi(time_HH_MM,pos,10);
    return minutes;
}

unsigned int MinimalTimeDifference(std::vector<std::string> times)
{
    unsigned int time1, time2;
    time1=ToMinutes(times[0]);
    time2=ToMinutes(times[1]);
    if(abs(time1-time2)<=12*60)
    {
        time1=abs(time1-time2);
    }
    else
    {
        time1=24*60-abs(time1-time2);
    }
    return time1;
}