//
// Created by Kuba on 17-05-18.
//

#include "Scheduler.h"

int academia::SchedulingItem::CourseId()
{
    return course_id;
}

int academia::SchedulingItem::TeacherId()
{
    return teacher_id;
}

int academia::SchedulingItem::RoomId()
{
    return room_id;
}

int academia::SchedulingItem::TimeSlot()
{
    return time_slot;
}

int academia::SchedulingItem::Year()
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
        remove_if(result.begin(),result.end(),[negative](int n){return (find(negative.begin(),negative.end(),n)!=negative.end());});
        for(int i=1;i<result.size();i++)
            if(result[i]<result[i-1])
            {
                result.erase(result.begin()+i,result.end());
                break;
            }
    }
    return result;
}

