#pragma once
#include"DataFileReader.h"
#include <string>
#include <vector>

class ACDay1
{
public:
    ACDay1(std::string dataFileName);
    int GetResult(int resultNumber);
private:
    int result_1 {}, result_2 {};
    int dataVectorLength {};
    int firstNumber {}, secondNumber {};
};

