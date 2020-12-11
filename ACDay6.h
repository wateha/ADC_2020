#pragma once
#include "DataFileReader.h"
#include <string>
#include <vector>
#include <unordered_set>


class ACDay6
{
public:
    ACDay6(std::string dataFileName);
    int GetResult(int resultNumber);

private:
    int result_1 {}, result_2 {};
    std::unordered_set<char> charSet {};
    std::string comparingString {};
    std::string CompareStrings(const std::string &firstString, const std::string &secondString);
};

