//
// Created by Kuba on 17-05-18.
//

#include "Scheduler.h"

int academia::SchedulingItem::CourseId() const
{
    return course_id;
}

int academia::SchedulingItem::TeacherId() const
{
    return teacher_id;
}

int academia::SchedulingItem::RoomId() const
{
    return room_id;
}

int academia::SchedulingItem::TimeSlot() const
{
    return time_slot;
}

int academia::SchedulingItem::Year() const
{
    return year;
}

//======================================================================================================================

academia::Schedule::Schedule(const academia::Schedule &s)
{
    items_=s.items_;
}

academia::Schedule & academia::Schedule::operator=(const academia::Schedule &s)
{
    if (this == &s) {
        return *this;
    }
    items_=s.items_;
}

academia::SchedulingItem academia::Schedule::operator[](int n) const
{
    return items_[n];
}

unsigned long academia::Schedule::Size() const
{
    return items_.size();
}

void academia::Schedule::InsertScheduleItem(academia::SchedulingItem si)
{
    items_.emplace_back(si);
}

academia::Schedule academia::Schedule::OfTeacher(int id) const
{
    academia::Schedule result;
    copy_if(items_.begin(),items_.end(),back_inserter(result.items_),[id](SchedulingItem si){return (si.TeacherId()==id);});
    return result;
}

academia::Schedule academia::Schedule::OfRoom(int id) const
{
    academia::Schedule result;
    copy_if(items_.begin(),items_.end(),back_inserter(result.items_),[id](SchedulingItem si){return (si.RoomId()==id);});
    return result;
}

academia::Schedule academia::Schedule::OfYear(int y) const
{
    academia::Schedule result;
    copy_if(items_.begin(),items_.end(),back_inserter(result.items_),[y](SchedulingItem si){return (si.Year()==y);});
    return result;
}

std::vector<int> academia::Schedule::AvailableTimeSlots(int before_hour)
{
    std::vector<int> result;
    std::vector<int> negative;
    for(int i=1;i<=before_hour;i++)
        result.emplace_back(i);
    if(!items_.empty())
    {
        transform(items_.begin(),items_.end(),back_inserter(negative),[](SchedulingItem i){return i.TimeSlot();});
        auto it=remove_if(result.begin(),result.end(),[negative](int n){return (find(negative.begin(),negative.end(),n)!=negative.end());});
        result.erase(it,result.end());
    }
    return result;
}

academia::Schedule academia::GreedyScheduler::PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                                                 const std::map<int, std::set<int>> &courses_of_year, int n_time_slots)
{
    academia::Schedule schedule;
    bool found;
    if(rooms.empty() || teacher_courses_assignment.empty() || courses_of_year.empty() || n_time_slots==0)
        throw NoViableSolutionFound();
    for(auto teacher : teacher_courses_assignment)
    {
        for(auto course : teacher.second)
        {
            for(auto year : courses_of_year)
            {
                found=false;
                for(auto coy : year.second)
                {
                    if(coy==course)
                    {
                        std::vector<int> time_of_teacher=schedule.OfTeacher(teacher.first).AvailableTimeSlots(n_time_slots);
                        std::vector<int> time_of_year=schedule.OfYear(year.first).AvailableTimeSlots(n_time_slots);
                        for(auto room : rooms)
                        {
                            std::vector<int> time_of_room=schedule.OfRoom(room).AvailableTimeSlots(n_time_slots);
                            if(time_of_year.empty() || time_of_teacher.empty() || time_of_room.empty())
                                throw NoViableSolutionFound();
                            for(auto i : time_of_teacher)
                            {
                                for(auto j : time_of_year)
                                {
                                    for(auto k : time_of_room)
                                    {
                                        if(i==j && j==k)
                                        {
                                            schedule.InsertScheduleItem(SchedulingItem{course, teacher.first, room, i, year.first});
                                            found=true;
                                            break;
                                        }
                                    }
                                    if(found)
                                        break;
                                }
                                if(found)
                                    break;
                            }
                            if(found)
                                break;
                        }
                        if(!found)
                            throw NoViableSolutionFound();
                        else
                            break;
                    }
                }
                if(found)
                    break;
            }
        }
    }
    return schedule;
}