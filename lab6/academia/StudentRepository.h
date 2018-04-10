//
// Created by semcjaku on 10.04.18.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORY_H
#define JIMP_EXERCISES_STUDENTREPOSITORY_H

#include <string>
#include <vector>
using std::string;

namespace academia
{
    class StudyYear
    {
    public:
        StudyYear();
        StudyYear(int y);
        ~StudyYear()=default;

        StudyYear operator++();
        StudyYear operator++(int);
        StudyYear operator--();
        StudyYear operator--(int);
        bool operator==(const StudyYear &y) const;
        bool operator==(const int &y) const;
        bool operator<(const StudyYear &y) const;

        StudyYear(const StudyYear& sy);
        StudyYear & operator=(const StudyYear& sy);

    private:
        int year;
    };

    class Student
    {
    public:
        Student()=default;
        Student(string i, string fn, string ln, string p, StudyYear y);
        ~Student()=default;
    private:
        string id;
        string first_name;
        string last_name;
        string program;
        StudyYear year;

    };

    class StudentRepository
    {
    public:

    private:
        std::vector<Student> students;
    };
}

#endif //JIMP_EXERCISES_STUDENTREPOSITORY_H
