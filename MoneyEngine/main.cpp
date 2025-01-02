#include <iostream>
#include <chrono>
#include <ctime>
#include <thread>
#include "OrderBookManager.h"

// Compiler does not like localtime
std::tm safeLocalTime(std::time_t time) {
    std::tm result;

    // Convert to local time here
    errno_t err = localtime_s(&result, &time);
    if (err != 0) {
        std::cerr << "Can't convert to local\n";
        std::memset(&result, 0, sizeof(result));
    }



    return result;
}


bool time_range(int start_hour, int start_minute, int end_hour, int end_minute) {
    std::time_t now = std::time(nullptr);
    std::tm localTime = safeLocalTime(now);

    //errno_t err = localtime_s(&localTime, &now);
    //if (err) {
    //    std::cerr << "localtime_s failed!\n";
    //    return 0;
    //}



    int hh = localTime.tm_hour;
    int mm = localTime.tm_min;

    // check if in trading bounds
    bool after_start = (hh > start_hour) || (hh == start_hour && mm >= start_minute);
    bool before_end = (hh < end_hour) || (hh == end_hour && mm < end_minute);

    return (after_start && before_end);

}

int main()
{
    while (!time_range(7, 30, 16, 0)) {
        std::cout << "Not in trading hours, waiting\n";
        std::this_thread::sleep_for(std::chrono::minutes(1));

    }




    std::cout << "MARKET OPEN\n";
    OrderBookManager orderBookManager;


    //std::cout << "--7:30 AM--\n\n";
    while (time_range(7, 30, 16, 0)) {
        std::time_t now = std::time(nullptr);
        std::tm localTime = safeLocalTime(now);

        int hh = localTime.tm_hour;
        int mm = localTime.tm_min;

        std::cout << "Engine running. Time is:[" << hh << ":" << mm << "]\n";


        std::cout << "\nPLTR" << std::endl;
        orderBookManager.addOrder("PLTR", 100.0, 10, true);
        orderBookManager.addOrder("PLTR", 99.5, 5, false);
        orderBookManager.addOrder("PLTR", 98.0, 2, false);
        orderBookManager.addOrder("PLTR", 101.0, 10, true);

        std::cout << "\nTSLA" << std::endl;
        orderBookManager.addOrder("TSLA", 200.0, 3, true);
        orderBookManager.addOrder("TSLA", 199.0, 5, false);
        orderBookManager.addOrder("TSLA", 202.0, 1, false);
        orderBookManager.addOrder("TSLA", 210.0, 4, false);
        orderBookManager.addOrder("TSLA", 205.0, 2, true);
        std::cin.get();

    }





    std::cout << "\n\n--4:00 PM--\n\n";
    std::cout << "MARKET CLOSED\n";

    std::cin.get();
    return 0;

}