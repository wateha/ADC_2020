#include "ACDay4.h"

ACDay4::ACDay4(std::string dataFileName) {
    DataFileReader data = DataFileReader(dataFileName, ' ', DataFileReader::DataType::STR);

    const std::vector<std::vector<std::string>> dataVector {data.GetStringData()};
    int dataVectorLength = dataVector.size();

    // Day 4
    for (int i = 0; i < dataVectorLength; i++) {
        if (dataVector[i].size() == 7) {
            result_1++;
            for (int j = 0; j < dataVector[i].size(); j++) {
                if (GetCode(dataVector[i][j], "cid", ':') == 0) {
                    result_1--;
                    break;
                }
            }
            
        }
        if (dataVector[i].size() == 8) {
            result_1++;
        }
    }
}

int ACDay4::GetCode(std::string inputString, std::string code, char separator) {
    std::size_t pos {0};
    pos = inputString.find(separator);
    return code.compare(inputString.substr(0, pos));
}

int ACDay4::GetResult(int resultNumber) {
    switch (resultNumber) {
    case 1: {return result_1; };
    case 2: {return result_2; };
    default: { return 0; }
    }
}
