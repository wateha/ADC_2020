#include "AdventMain.h"

int main(std::string* args, int argc)
{
    ACDay1 day1 = ACDay1("inputModule_01");
    std::cout << "Day 1 result: " << day1.GetResult(1) << ";" << std::endl;
    std::cout << "Day 1* result: " << day1.GetResult(2) << ";" << std::endl << std::endl;

    ACDay2 day2 = ACDay2("inputModule_02");
    std::cout << "Day 2 result: " << day2.GetResult(1) << ";" << std::endl;
    std::cout << "Day 2* result: " << day2.GetResult(2) << ";" << std::endl << std::endl;

    ACDay3 day3 = ACDay3("inputModule_03");
    std::cout << "Day 3 result: " << day3.GetResult(1) << ";" << std::endl;
    std::cout << "Day 3* result: " << day3.GetResult(2) << ";" << std::endl << std::endl;

    ACDay4 day4 = ACDay4("inputModule_04");
    std::cout << "Day 4 result: " << day4.GetResult(1) << ";" << std::endl;
    std::cout << "Day 4* result: " << day4.GetResult(2) << ";" << std::endl << std::endl;

    return 0;
}