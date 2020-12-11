#include "ACDay7.h"

ACDay7::ACDay7(std::string dataFileName) {
    DataFileReader data = DataFileReader(dataFileName, ' ', DataFileReader::DataType::STR);
    const std::vector<std::vector<std::string>> dataVector {data.GetStringData()};
    int dataVectorLength = dataVector[0].size();
}