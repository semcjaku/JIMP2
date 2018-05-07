//
// Created by Kuba on 30-04-18.
//

#include <regex>
#include "MovieSubtitles.h"

namespace moviesubs
{

    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int miliseconds, int fps, std::istream *in, std::ostream *out)
    {
        if(fps<=0)
            throw std::invalid_argument("FPS lower than or equal to zero.");
        std::string sub, original;
        size_t beg, end;
        const int delay=miliseconds*fps/1000;
        int frame, lastframe=0, secbutlast=0, line=0, framecounter;
        while(in->peek()!=EOF)
        {
            getline(*in,sub);
            original=sub;
            line++;
            beg=0;
            end=0;
            framecounter=1;
            do
            {
                beg=sub.find('{',end);
                if(beg!=std::string::npos)
                {
                    if(sub[beg+2]==':')
                    {
                        end=sub.find('}',beg+1);
                        continue;
                    }
                    end=sub.find('}',beg+1);
                    if(beg+1==end)
                        throw InvalidSubtitleLineFormat(sub,line);
                    for(size_t i=beg+1;i<end;i++)
                    {
                        if(!isdigit(sub[i]))
                            throw InvalidSubtitleLineFormat(original,line);
                    }
                    frame=std::stoi(sub.substr(beg+1,end-beg-1),nullptr,10);
                    frame+=delay;
                    if(frame<0)
                        throw NegativeFrameAfterShift(original,line);
                    if(framecounter%2==0)
                    {
                        if(lastframe>frame)
                            throw SubtitleEndBeforeStart(original,line);
                    }
                    else
                    {
                        if(secbutlast>frame)
                            throw OutOfOrderFrames(original,line);
                    }
                    secbutlast=lastframe;
                    lastframe=frame;
                    sub.replace(beg+1,end-beg-1,std::to_string(frame));
                    framecounter++;
                }
            } while(beg!=std::string::npos);
            if(framecounter!=3)
                throw InvalidSubtitleLineFormat(original,line);
            *out<<sub;
            if(in->peek()!=EOF)
                *out<<std::endl;
        }
    }

    //-------------------------------------------------------------------------------------------------------------------

    void SubRipSubtitles::ShiftAllSubtitlesBy(int miliseconds, int fps, std::istream *in, std::ostream *out)
    {
        if(fps<=0)
            throw std::invalid_argument("FPS lower than or equal to zero.");
        std::string sub, current;
        int line=0;
        unsigned long start, stop;
        size_t delim=0, prevdelim=0;
        char tmp[40];
        const std::regex scheme("[0-9]\n[0-9][0-9]:[0-9][0-9]:[0-9][0-9],[0-9][0-9][0-9]\\s-->\\s[0-9][0-9]:[0-9][0-9]:[0-9][0-9],[0-9][0-9][0-9]\n\\w+\n\n");

        getline(*in,sub,'\0');
        while(delim!=std::string::npos)
        {
            prevdelim=delim;
            delim=sub.find("\n\n",delim+2);
            if(delim!=std::string::npos)
            {
                current=sub.substr(prevdelim ? prevdelim+2 : 0,prevdelim ? delim-prevdelim : delim-prevdelim+1);
                /*if(!std::regex_match(current,scheme))
                    throw InvalidSubtitleLineFormat(current,line);*/
                start=std::stoul(current.substr(11,3),nullptr,10)+std::stoul(current.substr(8,2),nullptr,10)*1000+std::stoul(current.substr(5,2),nullptr,10)*60000+std::stoul(current.substr(2,2),nullptr,10)*3600000;
                stop=std::stoul(current.substr(28,3),nullptr,10)+std::stoul(current.substr(25,2),nullptr,10)*1000+std::stoul(current.substr(22,2),nullptr,10)*60000+std::stoul(current.substr(19,2),nullptr,10)*3600000;
                start+=miliseconds;
                stop+=miliseconds;
                sprintf(tmp,"%02d:%02d:%02d,%03d", (int)(start/3600000), (int)((start%3600000)/60000), (int)(((start%3600000)%60000)/1000), (int)(((start%3600000)%60000)%1000));
                std::string shift1(tmp);
                sprintf(tmp," --> %02d:%02d:%02d,%03d", (int)(stop/3600000), (int)((stop%3600000)/60000), (int)(((stop%3600000)%60000)/1000), (int)(((stop%3600000)%60000)%1000));
                std::string shift2(tmp);
                current.replace(2,29,shift1+shift2);
                sub.replace(prevdelim ? prevdelim+2 : 0,prevdelim ? delim-prevdelim : delim-prevdelim+1,current);
            }
            line++;
        }
        for(int i=0;i<sub.length();i++)
        {
            if(sub[i]=='\n')
                *out<<std::endl;
            else
                *out<<sub[i];
        }
    }

    //---------------------------------------ERRORS----------------------------------------------------------------------

    SubtitlesException::SubtitlesException(const std::string &line, int nr) : invalid_argument("At line "+std::to_string(nr)+": "+line) {line_=nr;}

    int SubtitlesException::LineAt() const
    {
        return line_;
    }

    InvalidSubtitleLineFormat::InvalidSubtitleLineFormat(const std::string &message, int nr) : SubtitlesException(message,nr) {}

    NegativeFrameAfterShift::NegativeFrameAfterShift(const std::string &message, int nr) : SubtitlesException(message,nr) {}

    SubtitleEndBeforeStart::SubtitleEndBeforeStart(const std::string &message, int nr) : SubtitlesException(message,nr) {}

    OutOfOrderFrames::OutOfOrderFrames(const std::string &message, int nr) : SubtitlesException(message, nr) {}

    MissingTimeSpecification::MissingTimeSpecification(const std::string &message, int nr) : SubtitlesException(message, nr) {}
}