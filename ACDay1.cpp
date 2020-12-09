#include "ACDay1.h"

ACDay1::ACDay1(std::string dataFileName)
{
    DataFileReader data = DataFileReader(dataFileName, ',', DataFileReader::DataType::INT);

    const std::vector<std::vector<int>> dataVector {data.GetIntegerData()};

    dataVectorLength = dataVector[0].size();
    // Day 1
    for (int i = 0; i < dataVectorLength - 1; i++) {
        for (int j = i + 1; j < dataVectorLength; j++) {
            if (dataVector[0][i] + dataVector[0][j] == 2020) {
                result_1 = dataVector[0][i] * dataVector[0][j];
                break;
            }
        }
    }
    // Day 1*
    for (int i = 0; i < dataVectorLength - 2; i++) {
        for (int j = i + 1; j < dataVectorLength - 1; j++) {
            for (int k = j + 1; k < dataVectorLength; k++) {
                if (dataVector[0][i] + dataVector[0][j] + dataVector[0][k] == 2020) {
                    result_2 = dataVector[0][i] * dataVector[0][j] * dataVector[0][k];
                    break;
                }
            }
        }
    }
}

int ACDay1::GetResult(int resultNumber)
{
    switch (resultNumber) {
        case 1: {return result_1; };
        case 2: {return result_2; };
        default: { return 0; }
    }
}