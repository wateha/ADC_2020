#pragma once
#include "DataFileReader.h"
#include <string>
#include <vector>

class ACDay7
{
public:
    ACDay7(std::string dataFileName);
    int GetResult(int resultNumber);

private:
    int result_1 {}, result_2 {};
};

