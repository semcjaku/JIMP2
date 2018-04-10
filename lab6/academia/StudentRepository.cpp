//
// Created by semcjaku on 10.04.18.
//

#include "StudentRepository.h"

namespace academia
{
    StudyYear::StudyYear()
    {
        year=0;
    }

    StudyYear::StudyYear(int y)
    {
        year=y;
    }

    StudyYear::StudyYear(const StudyYear& sy) {
        year=sy.year;
    }

    StudyYear & StudyYear::operator=(const StudyYear& sy) {

        if (this == &sy) {
            return *this;
        }

        year=sy.year;
    }

    StudyYear StudyYear::operator++()
    {
        ++year;
        return *this;
    }
    StudyYear StudyYear::operator++(int)
    {
        year++;
        return *this;
    }

    StudyYear StudyYear::operator--()
    {
        --year;
        return *this;
    }
    StudyYear StudyYear::operator--(int)
    {
        year--;
        return *this;
    }

    bool StudyYear::operator==(const StudyYear &y) const
    {
        return(year==y.year);
    }

    bool StudyYear::operator==(const int &y) const
    {
        return (year==y);
    }

    bool StudyYear::operator<(const StudyYear &y) const
    {
        return(year<y.year);
    }

    Student::Student(string i, string fn, string ln, string p, StudyYear y)
    {
        id=i;
        first_name=fn;
        last_name=ln;
        program=p;
        year=y;
    }

}