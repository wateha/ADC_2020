#pragma once
#include"DataFileReader.h"
#include <string>
#include <vector>

class ACDay3
{
public:
    ACDay3(std::string dataFileName);
    unsigned int GetResult(int resultNumber);
private:
    std::vector<std::vector<std::string>> dataVector {};
    unsigned int result_1 {0}, result_2 {0};
    int CalculateTrees(int xOffset, int yOffset);
};