#include "ACDay6.h"

ACDay6::ACDay6(std::string dataFileName) {
    DataFileReader data = DataFileReader(dataFileName, ' ', DataFileReader::DataType::STR);
    const std::vector<std::vector<std::string>> dataVector {data.GetStringData()};
    int dataVectorLength = dataVector.size();

    for (int i = 0; i < dataVectorLength; i++) {
        for (int j = 0; j < dataVector[i].size(); j++) {

        }
    }
    
}

int ACDay6::GetResult(int resultNumber) {
    switch (resultNumber) {
    case 1: {return result_1; };
    case 2: {return result_2; };
    default: { return 0; }
    }
}
