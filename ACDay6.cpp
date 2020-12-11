#include "ACDay6.h"

ACDay6::ACDay6(std::string dataFileName) {
    DataFileReader data = DataFileReader(dataFileName, ' ', DataFileReader::DataType::STR);
    const std::vector<std::vector<std::string>> dataVector {data.GetStringData()};
    int dataVectorLength = dataVector.size();

    // Day 6
    for (int i = 0; i < dataVectorLength; i++) {
        for (int j = 0; j < dataVector[i].size(); j++) {
            for (int k = 0; k < dataVector[i][j].size(); k++) {
                charSet.insert(dataVector[i][j][k]);
            }
        }
        result_1 += charSet.size();
        charSet.clear();
    }

    // Day 6*
    for (int i = 0; i < dataVectorLength; i++) {
        comparingString = dataVector[i][0];
        for (int j = 0; j < dataVector[i].size(); j++) {
            comparingString = CompareStrings(comparingString, dataVector[i][j]);
        }
        result_2 += comparingString.size();
    }
}

int ACDay6::GetResult(int resultNumber) {
    switch (resultNumber) {
    case 1: {return result_1; };
    case 2: {return result_2; };
    default: { return 0; }
    }
}

std::string ACDay6::CompareStrings(const std::string &firstString, const std::string &secondString) {
    std::string resultString {};
    for (int i = 0; i < firstString.size(); i++) {
        for (int j = 0; j < secondString.size(); j++) {
            if (firstString[i] == secondString[j]) {
                resultString.push_back(firstString[i]);
                break;
            }
        }
    }
    return resultString;
}
