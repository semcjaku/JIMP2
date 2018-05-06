//
// Created by Kuba on 30-04-18.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <string>
#include <sstream>

namespace moviesubs
{
    class MovieSubtitles
    {
    public:
        ~MovieSubtitles()=default;
        virtual void ShiftAllSubtitlesBy(int miliseconds, int fps, std::istream *in, std::ostream *out)=0;

    };

    class MicroDvdSubtitles : public MovieSubtitles
    {
    public:
        void ShiftAllSubtitlesBy(int miliseconds, int fps, std::istream *in, std::ostream *out) override;

    };

   /* class SubRipSubtitles : public MovieSubtitles
    {
    public:
        void ShiftAllSubtitlesBy(int miliseconds, int fps, std::istream *in, std::ostream *out) override;
    };

    //--------------------------------------------ERRORS-----------------------------------------------------------------

    class InvalidSubtitleLineFormat : public std::invalid_argument
    {

    };

    class NegativeFrameAfterShift : public InvalidSubtitleLineFormat
    {

    };

    class SubtitleEndBeforeStart : public InvalidSubtitleLineFormat
    {
    public:
        int LineAt() const;
    };

    class MissingTimeSpecification : public InvalidSubtitleLineFormat
    {

    };

    class OutOfOrderFrames : public InvalidSubtitleLineFormat
    {

    };*/
}

#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
