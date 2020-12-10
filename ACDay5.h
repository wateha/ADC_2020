#pragma once
#include "DataFileReader.h"
#include <string>
#include <vector>


class ACDay5
{
public:
    ACDay5(std::string dataFileName);
    int GetResult(int resultNumber);

private:
    int result_1 {}, result_2 {};
    std::vector<int> seatIDs {};
    int BinaryToInt(std::string &inputString);
    void InsertSeatID(int id);
    int FindMissingID();
};
