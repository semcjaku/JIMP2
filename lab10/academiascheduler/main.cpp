//
// Created by Kuba on 17-05-18.
//

#include <iostream>
#include "Scheduler.h"
using academia::Schedule;
using academia::SchedulingItem;

int main()
{
    Schedule schedule;
    schedule.InsertScheduleItem(SchedulingItem {100, 10, 1000, 1, 1});
    schedule.InsertScheduleItem(SchedulingItem {100, 10, 1000, 2, 1});
    std::vector<int> time_of_year=schedule.OfYear(1).AvailableTimeSlots(2);
    if(time_of_year.empty())
        std::cout<<"nic";
//    for(auto n:time_of_year)
//        std::cout<<n<<std::endl;
    return 0;
}