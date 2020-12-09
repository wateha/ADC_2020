#include "ACDay2.h"

ACDay2::ACDay2(std::string dataFileName)
{
    DataFileReader data = DataFileReader(dataFileName, ' ', DataFileReader::DataType::STR);

    const std::vector<std::vector<std::string>> dataVector {data.GetStringData()};

    int dataVectorLength = dataVector.size();
    
    for (int i = 0; i < dataVectorLength; i++) {
        GetBoundaries(dataVector[i][0]);
        GetKey(dataVector[i][1]);
        // Day 2
        int keyCount = CountKeys(dataVector[i][2]);
        if (keyCount >= minValue && keyCount <= maxValue) {
            result_1++;
        }
        // Day 2*
        if (CheckKeys(dataVector[i][2]) == 1) {
            result_2++;
        }
    }
}

void ACDay2::GetBoundaries(std::string inputString)
{
    int pos = inputString.find('-');
    minValue = std::stoi(inputString.substr(0, pos));
    maxValue = std::stoi(inputString.substr(pos + 1, inputString.length() - pos));
}
void ACDay2::GetKey(std::string inputString)
{
    key = inputString.at(0);
}

int ACDay2::CountKeys(std::string inputString)
{
    int count {0};
    for (int i = 0; i < inputString.length(); i++) {
        if (inputString.at(i) == key) {
            count++;
        }
    }
    return count;
}

int ACDay2::CheckKeys(std::string inputString)
{
    int count {0};
    if (inputString.at(minValue-1) == key) {
            count++;
    }
    if (inputString.at(maxValue-1) == key) {
        count++;
    }
    return count;
}

int ACDay2::GetResult(int resultNumber)
{
    switch (resultNumber) {
    case 1: {return result_1; };
    case 2: {return result_2; };
    default: { return 0; }
    }
}