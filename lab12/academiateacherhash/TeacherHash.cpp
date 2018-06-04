//
// Created by Kuba on 04-06-18.
//

#include "TeacherHash.h"

namespace academia
{

    int TeacherId::Id() const
    {
        return id;
    }

    bool TeacherId::operator==(const TeacherId &other) const
    {
        return id==other.id;
    }

    bool TeacherId::operator!=(const TeacherId &other) const
    {
        return id!=other.id;
    }

    TeacherId::operator int() const
    {
        return id;
    }

    TeacherId Teacher::Id() const
    {
        return id;
    }

    std::string Teacher::Name() const
    {
        return name;
    }

    std::string Teacher::Department() const
    {
        return dpt;
    }

    bool Teacher::operator==(const Teacher &other) const
    {
        return (id==other.id && name==other.name && dpt==other.dpt);
    }

    bool Teacher::operator!=(const Teacher &other) const
    {
        return !(id==other.id && name==other.name && dpt==other.dpt);
    }

    int TeacherHash::operator()(const Teacher &teacher) const
    {
        int hash = std::hash<int>()((int)teacher.Id());
        hash+=std::hash<std::string>()(teacher.Name());
        hash+=std::hash<std::string>()(teacher.Department());
        return hash;
    }
}
