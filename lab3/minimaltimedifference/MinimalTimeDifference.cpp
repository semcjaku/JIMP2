//
// Created by semcjaku on 13.03.18.
//

#include "MinimalTimeDifference.h"

namespace minimaltimedifference
{
    unsigned int ToMinutes(std::string time_HH_MM)
    {
        unsigned int minutes=0;
        size_t pos;
        minutes+=(60*stoi(time_HH_MM,&pos,10));
        std::string time_MM = time_HH_MM.substr(pos+1,std::string::npos);
        minutes+=(stoi(time_MM,nullptr,10));
        return minutes;
    }

    unsigned int MinimalTimeDifference(std::vector<std::string> times)
    {
        unsigned int tmp1, tmp2, minimal=1440;
        for(int i=0; i<times.size()-1; i++)
        {
            tmp1=ToMinutes(times[i]);
            for(int j=i+1; j<times.size(); j++)
            {
                tmp2=ToMinutes(times[j]);
                if(abs(tmp1-tmp2)<=12*60)
                {
                    tmp2=abs(tmp1-tmp2);
                }
                else
                {
                    tmp2=24*60-abs(tmp1-tmp2);
                }
                if(tmp2<minimal)
                    minimal=tmp2;
            }
        }
        return minimal;
    }
}
