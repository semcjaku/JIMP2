//
// Created by Kuba on 17-05-18.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H


#include <vector>
#include <algorithm>
#include <map>
#include <set>

namespace academia
{
    class SchedulingItem
    {
    public:
        SchedulingItem(int cid, int tid, int rid, int ts, int y) : course_id(cid), teacher_id(tid), room_id(rid), time_slot(ts), year(y) {}
        int CourseId() const;
        int TeacherId() const;
        int RoomId() const;
        int TimeSlot() const;
        int Year() const;
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

    class Scheduler
    {
    public:
        virtual Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment, const std::map<int, std::set<int>> &courses_of_year, int n_time_slots)=0;
    };

    class GreedyScheduler : public Scheduler
    {
    public:
        Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment, const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) override;
    };

    class NoViableSolutionFound : public std::exception {};
}

#endif //JIMP_EXERCISES_SCHEDULER_H
