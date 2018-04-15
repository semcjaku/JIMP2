//
// Created by semcjaku on 10.04.18.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORY_H
#define JIMP_EXERCISES_STUDENTREPOSITORY_H

#include <string>
#include <vector>
#include <iostream>
#include <initializer_list>

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
        bool operator!=(const StudyYear &sy) const;
        bool operator<(const StudyYear &y) const;
        operator int();

        StudyYear(const StudyYear& sy);
        StudyYear & operator=(const StudyYear& sy);

        int GetYear() const;
        void SetYear(int y);

    private:
        int year;
    };

    bool operator==(const int &i, const StudyYear &sy);
    std::ostream& operator<< (std::ostream&,StudyYear const&);
    std::istream& operator>> (std::istream&,StudyYear&);

    class Student
    {
    public:
        Student()=default;
        Student(string i, string fn, string ln, string p, StudyYear y);
        ~Student()=default;

        bool operator==(const Student &s) const;
        bool operator!=(const Student &s) const;

        string Id();
        string FirstName();
        string LastName();
        string Program();
        StudyYear Year();
        void ChangeLastName(string new_ln);
        void ChangeId(string new_id);
        void ChangeFirstName(string new_fn);
        void ChangeProgram(string new_p);
        void ChangeYear(int y);

    private:
        string id;
        string first_name;
        string last_name;
        string program;
        StudyYear year;

    };

    std::ostream& operator<< (std::ostream&,Student&);
    std::istream& operator>> (std::istream&,Student&);

    class StudentRepository
    {
    public:
        StudentRepository();
        StudentRepository(std::initializer_list<Student> list) : students{list} {}
        ~StudentRepository()=default;

        bool operator==(const StudentRepository &sr) const;
        Student & operator[](string id);
        const Student & operator[](string id) const;

        int StudentCount();
        std::vector<Student> Students();

    private:
        std::vector<Student> students;
    };

    std::ostream& operator<< (std::ostream&,StudentRepository&);
    std::istream& operator>> (std::istream&,StudentRepository&);
}

#endif //JIMP_EXERCISES_STUDENTREPOSITORY_H
