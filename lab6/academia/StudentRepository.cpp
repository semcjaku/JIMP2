//
// Created by semcjaku on 10.04.18.
//

#include "StudentRepository.h"

namespace academia
{
    StudyYear::StudyYear()
    {
        year=1;
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

    bool StudyYear::operator<(const StudyYear &y) const
    {
        return(year<y.year);
    }

    StudyYear::operator int()
    {
        return year;
    }

    int StudyYear::GetYear() const
    {
        return year;
    }

    void StudyYear::SetYear(int y)
    {
        year=y;
    }

    bool operator==(const int &i, const StudyYear &sy)
    {
        return (i==sy.GetYear());
    }

    bool StudyYear::operator!=(const StudyYear &sy) const
    {
        return (year!=sy.year);
    }

    std::ostream& operator<< (std::ostream &out,StudyYear const &sy)
    {
        out<<sy.GetYear();
        return out;
    }

    std::istream& operator>> (std::istream &in,StudyYear &sy)
    {
        int tmp;
        in>>tmp;
        sy.SetYear(tmp);
        return in;
    }

 //=======================================================================================================

    Student::Student(string i, string fn, string ln, string p, StudyYear y)
    {
        id=i;
        first_name=fn;
        last_name=ln;
        program=p;
        year=y;
    }

    bool Student::operator==(const Student &s) const
    {
        return (id==s.id && first_name==s.first_name && last_name==s.last_name && program==s.program && year==s.year);
    }

    bool Student::operator!=(const Student &s) const
    {
        return (id!=s.id || first_name!=s.first_name || last_name!=s.last_name || program!=s.program || year!=s.year);
    }

    string Student::Id()
    {
        return id;
    }

    string Student::FirstName()
    {
        return first_name;
    }

    string Student::LastName()
    {
        return last_name;
    }

    string Student::Program()
    {
        return program;
    }

    StudyYear Student::Year()
    {
        return year;
    }

    void Student::ChangeLastName(string new_ln)
    {
        last_name=new_ln;
    }
    void Student::ChangeId(string new_id)
    {
        id=new_id;
    }

    void Student::ChangeFirstName(string new_fn)
    {
        first_name=new_fn;
    }

    void Student::ChangeProgram(string new_p)
    {
        program=new_p;
    }

    void Student::ChangeYear(int y)
    {
        year.SetYear(y);
    }

    std::ostream& operator<< (std::ostream &out,Student &s)
    {
        out<<"Student {id: "<<s.Id()<<", first_name: "<<s.FirstName()<<", last_name: "<<s.LastName()<<", program: "<<s.Program()<<", year:"<<s.Year()<<"}";
        return out;
    }

    std::istream& operator>> (std::istream &in,Student &s)
    {
        string tmp;
        size_t p=0,k=0;
        in>>tmp;
        p=tmp.find('"', 0);
        k=tmp.find('"', p);
        s.ChangeId(tmp.substr(p+1,k-p-1));
        p=tmp.find('"', k);
        k=tmp.find('"', p);
        s.ChangeFirstName(tmp.substr(p+1,k-p-1));
        p=tmp.find('"', k);
        k=tmp.find('"', p);
        s.ChangeLastName(tmp.substr(p+1,k-p-1));
        p=tmp.find('"', k);
        k=tmp.find('"', p);
        s.ChangeProgram(tmp.substr(p+1,k-p-1));
        p=tmp.find(": ",k);
        k=tmp.find('}',p);
        s.ChangeYear(std::stoi(tmp.substr(p+1,k-p-1),nullptr,10));
        return in;
    }

    //=======================================================================================================

    StudentRepository::StudentRepository()
    {
        students.clear();
    }

    bool StudentRepository::operator==(const StudentRepository &sr) const
    {
        bool isin;
        size_t count=0;
        for(Student n:students)
        {
            isin=false;
            for(Student m:sr.students)
            {
                if(n==m)
                    isin=true;
            }
            if(isin)
                count++;
        }
        if(count==students.size())
            return true;
        return false;
    }

    Student & StudentRepository::operator[](string id)
    {
        for(Student &n:students)
        {
            if(n.Id()==id)
                return n;
        }
    }

    const Student & StudentRepository::operator[](string id) const
    {
        for(Student n:students)
        {
            if(n.Id()==id)
                return n;
        }
    }

    int StudentRepository::StudentCount()
    {
        return (int)students.size();
    }

    std::vector<Student> StudentRepository::Students()
    {
        return students;
    }

    std::ostream& operator<< (std::ostream &out,StudentRepository &sr)
    {
        out<<'[';
        for(Student n:sr.Students())
        {
            out<<n;
            if (n!=sr.Students()[sr.Students().size()-1])
                out<<", ";
        }
        out<<']';
        return out;
    }

    std::istream& operator>> (std::istream &in,StudentRepository &sr)
    {
        for(Student &n:sr.Students())
            in>>n;
        return in;
    }
}