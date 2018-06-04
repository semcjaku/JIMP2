//
// Created by Kuba on 04-06-18.
//

#ifndef JIMP_EXERCISES_TEACHERHASH_H
#define JIMP_EXERCISES_TEACHERHASH_H


#include <string>

namespace academia
{
    class TeacherId
    {
    public:
        explicit TeacherId(int x) : id(x) {}
        int Id() const;
        bool operator ==(const TeacherId &other) const;
        bool operator !=(const TeacherId &other) const;
        operator int () const;
    private:
        int id;
    };

    class Teacher
    {
    public:
        Teacher(TeacherId x, std::string tname, std::string tdpt) : id(x), name(tname), dpt(tdpt) {}
        TeacherId Id() const;
        std::string Name() const;
        std::string Department() const;
        bool operator ==(const Teacher &other) const;
        bool operator !=(const Teacher &other) const;
    private:
        TeacherId id;
        std::string name;
        std::string dpt;
    };

    class TeacherHash
    {
    public:
        int operator()(const Teacher &teacher) const;
    };
}


#endif //JIMP_EXERCISES_TEACHERHASH_H
