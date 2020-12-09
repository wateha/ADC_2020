#pragma once
#include"DataFileReader.h"
#include <string>
#include <vector>

class ACDay4
{
public:
    ACDay4(std::string dataFileName);
    int GetResult(int resultNumber);
private:
    int result_1 {0}, result_2 {};
    const std::vector<std::string> fieldCodes {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid", "cid"};

    int GetCode(std::string inputString, std::string code, char separator);
};
