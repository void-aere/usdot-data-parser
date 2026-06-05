#include "rapidcsv.hpp"
#include <vector>
#include <string>
#include <map>
#include <iostream>

// Calculates the number of days in a given year
short daysInYear(short year) {
    // If this is a leap year, return 366. Otherwise return 365.
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ? 366 : 365;
}

int main() {
    std::cout << "Reading data... " << std::flush;
    rapidcsv::Document t2("data/T_SCHEDULE_T2.csv");   // open the T2 data file
    
    // Load data columns from the table
    std::vector<short> years = t2.GetColumn<short>("YEAR");
    std::vector<std::string> hours = t2.GetColumn<std::string>("HOURS_AIRBORNE_650");
    std::vector<std::string> days  = t2.GetColumn<std::string>("AIR_DAYS_EQUIP_810");
    std::cout << "done." << std::endl; // done reading data


    // Data structure to store data in. Maps year to <days, hours>
    typedef std::map<short, std::pair<double, double>> flightRecorder;
    flightRecorder data; // data is a flightRecorder (map)


    // Iterate through table rows and collect relevant information
    for (size_t i = 0; i < years.size(); ++i) {
        short year = years[i];
        if (days[i]  != "") data[year].first  += std::stod(days[i]);
        if (hours[i] != "") data[year].second += std::stod(hours[i]);
    }


    // Iterate through map keys (data years), calculate airborne hours and return
    std::cout << "\n\nAVERAGE ANNUAL AIRCRAFT AIRBORNE HOURS PER YEAR:\n\n";
    std::cout << "YEAR\tAVERAGE AIRCRAFT AIRBORNE HOURS\n";
    for (flightRecorder::iterator it = data.begin(); it != data.end(); ++it) {
        short  year = it->first;
        double acDays = it->second.first;                        // unit: aircraft * day
        double airHrs = it->second.second;                       // unit: flight hour
        double annualHours = daysInYear(year) * airHrs / acDays; // unit: flight hour / aircraft / year
        std::cout << year << '\t' << annualHours << '\n';
    }
}
