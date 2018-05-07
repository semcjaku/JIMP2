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
            throw InvalidSubtitleLineFormat("FPS lower than or equal to zero.",0);
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

    /*void SubRipSubtitles::ShiftAllSubtitlesBy(int miliseconds, int fps, std::istream *in, std::ostream *out)
    {
        if(fps<=0)
            throw InvalidSubtitleLineFormat("FPS lower than or equal to zero.",0);
        const std::regex scheme("\d\n\d\d:\d\d:\d\d,\d\d\d\s-->\s\d\d:\d\d:\d\d,\d\d\d\n\w+\n\n");
    }*/

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