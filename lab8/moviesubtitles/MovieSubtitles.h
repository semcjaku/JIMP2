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

    class SubRipSubtitles : public MovieSubtitles
    {
    public:
        void ShiftAllSubtitlesBy(int miliseconds, int fps, std::istream *in, std::ostream *out) override;
    };

    //--------------------------------------------ERRORS-----------------------------------------------------------------

    class SubtitlesException : public std::invalid_argument
    {
    public:
        SubtitlesException(const std::string &line, int nr);
        int LineAt() const;
    private:
        int line_;
    };

    class InvalidSubtitleLineFormat : public SubtitlesException
    {
    public:
        InvalidSubtitleLineFormat(const std::string &message, int nr);
    };

    class NegativeFrameAfterShift : public SubtitlesException
    {
    public:
        NegativeFrameAfterShift(const std::string &message, int nr);
    };

    class SubtitleEndBeforeStart : public SubtitlesException
    {
    public:
        SubtitleEndBeforeStart(const std::string &message, int nr);
    };

    class MissingTimeSpecification : public SubtitlesException
    {
    public: MissingTimeSpecification(const std::string &message, int nr);
    };

    class OutOfOrderFrames : public SubtitlesException
    {
    public:
        OutOfOrderFrames(const std::string &message, int nr);
    };
}

#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
