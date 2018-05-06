//
// Created by Kuba on 30-04-18.
//

#include "MovieSubtitles.h"

namespace moviesubs
{

    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int miliseconds, int fps, std::istream *in, std::ostream *out)
    {
        std::string sub;
        size_t beg, end;
        const int delay=miliseconds*fps/1000;
        bool check_if_brace_is_frame;
        int frame;
        while(in->peek()!=EOF)
        {
            getline(*in,sub);
            beg=0;
            end=0;
            do
            {
                beg=sub.find('{',end);
                end=sub.find('}',beg+1);
                check_if_brace_is_frame=true;
                for(int i=beg+1;i<end;i++)
                {
                    if(!isdigit(sub[i]))
                        check_if_brace_is_frame=false;

                }
                if(check_if_brace_is_frame)
                {
                    frame=std::stoi(sub.substr(beg+1,end-beg-1),nullptr,10);
                    frame+=delay;
                    sub.replace(beg+1,end-beg-1,std::to_string(frame));
                }
            } while(beg!=std::string::npos);
            *out<<sub;
            if(in->peek()!=EOF)
                *out<<std::endl;
        }
    }
}