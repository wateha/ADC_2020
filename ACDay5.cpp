#include "ACDay5.h"

ACDay5::ACDay5(std::string dataFileName)
{
    DataFileReader data = DataFileReader(dataFileName, ' ', DataFileReader::DataType::STR);

    const std::vector<std::vector<std::string>> dataVector {data.GetStringData()};
    int dataVectorLength = dataVector[0].size();

    for (int i = 0; i < dataVectorLength; i++) {
        std::string rowCode {dataVector[0][i].substr(0, 7)};
        std::string colCode {dataVector[0][i].substr(7, 9)};

        InsertSeatID(BinaryToInt(rowCode) * 8 + BinaryToInt(colCode));
    }

    // Day 5
    result_1 = seatIDs.back();
    // Day 5*
    result_2 = FindMissingID();
}

int ACDay5::BinaryToInt(std::string &inputString) {
    for (size_t i = 0; i < inputString.length(); i++) {
        if (inputString[i] == 'F' || inputString[i] == 'L') {
            inputString.replace(i, 1, "0");
        }
        if (inputString[i] == 'B' || inputString[i] == 'R') {
            inputString.replace(i, 1, "1");
        }
    }
    return stoi(inputString, nullptr, 2);
}

void ACDay5::InsertSeatID(int id) {
    if (seatIDs.empty()) {
        seatIDs.push_back(id);
    }
    else {
        for (size_t i = 0; i < seatIDs.size(); i++) {
            if (seatIDs[i] > id) {
                seatIDs.insert(seatIDs.begin()+i, id);
                break;
            }
            if (i == seatIDs.size() - 1) {
                seatIDs.push_back(id);
                break;
            }
        }
    }
}
int ACDay5::FindMissingID() {
    int position {};
    int offset{seatIDs.front()};
    for (size_t i = 1; i < seatIDs.size(); i++) {
        position = seatIDs[i] - offset;
        if (position != i) {
            return seatIDs[i]-1;
        }
        position++;
    }
    return -1;
}

int ACDay5::GetResult(int resultNumber) {
    switch (resultNumber) {
    case 1: {return result_1; };
    case 2: {return result_2; };
    default: { return 0; }
    }
}