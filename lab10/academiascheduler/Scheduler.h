//
// Created by Kuba on 17-05-18.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H


#include <vector>
#include <algorithm>

namespace academia
{
    class SchedulingItem
    {
    public:
        SchedulingItem(int cid, int tid, int rid, int ts, int y) : course_id(cid), teacher_id(tid), room_id(rid), time_slot(ts), year(y) {}
        int CourseId();
        int TeacherId();
        int RoomId();
        int TimeSlot();
        int Year();
    private:
        int course_id;
        int teacher_id;
        int room_id;
        int time_slot;
        int year;
    };

    class Schedule
    {
    public:
        Schedule()=default;
        Schedule(const Schedule& s);
        Schedule & operator=(const Schedule& s);
        SchedulingItem operator[](int n) const;

        unsigned long Size() const;
        void InsertScheduleItem(SchedulingItem si);
        Schedule OfTeacher(int id) const;
        Schedule OfRoom(int id) const;
        Schedule OfYear(int y) const;
        std::vector<int> AvailableTimeSlots(int before_hour);
    private:
        std::vector<SchedulingItem> items_;
    };
}

#endif //JIMP_EXERCISES_SCHEDULER_H
