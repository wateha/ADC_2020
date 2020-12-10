#pragma once
#include "DataFileReader.h"
#include <string>
#include <vector>


class ACDay6
{
public:
    ACDay6(std::string dataFileName);
    int GetResult(int resultNumber);

private:
    int result_1 {}, result_2 {};
};

