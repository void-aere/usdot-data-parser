#include "rapidcsv.hpp"
#include <vector>

int main() {
    // sum 2020 airtime for american, delta, united

    rapidcsv::Document t2("data/T2/2020.csv");
    std::vector<std::string> carrier  = t2.GetColumn<std::string>("UNIQUE_CARRIER");
    std::vector<std::string> airHours = t2.GetColumn<std::string>("HOURS_AIRBORNE_650");
    std::vector<std::string> acDays   = t2.GetColumn<std::string>("AIR_DAYS_EQUIP_810");

    rapidcsv::Document t100("data/T100/2020.csv");
    std::vector<std::string> carrier100 = t100.GetColumn<std::string>("UNIQUE_CARRIER");
    std::vector<std::string> minutes100 = t100.GetColumn<std::string>("AIR_TIME");

    double sumHours = 0.0;
    double sumACDays = 0.0;
    for (size_t i = 0; i < carrier.size(); ++i) {
        //if (carrier[i] == "AA" || carrier[i] == "DL" || carrier[i] == "UA") {
        if (1) {
            if (airHours[i] != "") sumHours  += std::stod(airHours[i]);
            if (acDays[i]   != "") sumACDays += std::stod(acDays[i]);
        }
    }

    double sumMinutes = 0.0;
    for (size_t i = 0; i < carrier100.size(); ++i) {
        //if (carrier100[i] == "AA" || carrier100[i] == "DL" || carrier100[i] == "UA") {
        if (1) {
            sumMinutes += std::stod(minutes100[i]);
        }
    }

    printf("total aircraft airborne hours:  %f\n", sumHours);
    printf("total operating fleet:          %f\n", sumACDays / 366);
    printf("daily airborne hours of fleet:  %f\n", sumHours / sumACDays);
    printf("annual airborne hours of fleet: %f\n", 366 * sumHours / sumACDays);
    printf("total airborne hours (T100):    %f\n", sumMinutes / 60);
    printf("avg. plane hours (T100):        %f\n", 366 * (sumMinutes / 60) / sumACDays);
}
