#pragma once
#include"DataFileReader.h"
#include <string>
#include <vector>

class ACDay2
{
public:
    ACDay2(std::string dataFileName);
    int GetResult(int resultNumber);
private:
    int result_1 {0}, result_2 {};
    int minValue {}, maxValue {};
    char key {};
    std::string password {};

    void GetBoundaries(std::string inputString);
    void GetKey(std::string inputString);
    int CountKeys(std::string inputString);
    int CheckKeys(std::string inputString);
};

