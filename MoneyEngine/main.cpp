#include <iostream>
#include <chrono>
#include <ctime>
#include <thread>
#include <conio.h>

#include <cstdio>
#include <sstream>
#include <string>

#include <unordered_map>

#include "InputManager.h"
#include "OrderBookManager.h"

#include <functional>

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
    OrderBookManager orderBookManager;
    InputManager inputManager(orderBookManager);

    std::cout << "\033[33mENGINE STARTING\033[0m\n\n\n" << std::endl;

    while (!time_range(7, 30, 23, 0)) {
        std::cout << "Not in trading hours, waiting\n";
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }

    while (time_range(7, 30, 23, 0)) {
        std::time_t now = std::time(nullptr);
        std::tm localTime = safeLocalTime(now);
        int hh = localTime.tm_hour;
        int mm = localTime.tm_min;
        std::cout << "Local Time: [" << hh << ":" << mm << "] \n";

        // Check order type, must be valid
        // If NULL string 
        // Prompt again with specifics, again check if valid



        std::string colorPrompt = "\033[34m"; // Blue for prompt
        std::string reset = "\033[0m";       // Reset color
        // Display colored prompt
        std::cout << colorPrompt << "Enter Command (ORDER/INFO/HELP): " << reset;
        // Get user command
        std::string command;
        std::getline(std::cin, command);
        inputManager.CommandInput(command); // nice and clean.
        // idk if this is a bad idea. its basically gunna chain forever in here.



        std::cout << "Processing Trades...\n";
        orderBookManager.matchAllOrders();

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }


    std::cout << "\n\n\n\033[33mENGINE STOPPING\033[0m\n\n\n" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    return 0;
}