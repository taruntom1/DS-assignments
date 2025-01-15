// This program creates a 6x7 matrix and stores the calender in it, then it prints it out.

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

int main()
{
    // Initialize a 6x7 matrix to represent the calendar (6 weeks, 7 days each)
    std::vector<std::vector<int>> calendar(6, std::vector<int>(7, 0));

    // August 2014 starts on a Friday
    int start_day = 5; // 0 for Sunday, so Friday is 5
    int days_in_month = 31;

    int day = 1; // Start from the 1st of August

    // Fill the calendar with the days of August 2014
    for (int index = start_day; index < start_day + days_in_month; ++index)
    {
        int week = index / 7;
        int day_of_week = index % 7;
        calendar[week][day_of_week] = day;
        ++day;
    }

    // Weekday labels
    std::vector<std::string> weekdays = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

    // Print the calendar
    std::cout << "Calendar of August 2014:" << std::endl;
    for (const auto &weekday : weekdays)
    {
        std::cout << weekday << "\t";
    }
    std::cout << std::endl;

    for (const auto &row : calendar)
    {
        for (const auto &col : row)
        {
            if (col != 0)
            {
                std::cout << std::setw(3) << col << "\t";
            }
            else
            {
                std::cout << "   \t";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
