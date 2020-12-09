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

    // Day 4*
    for (int i = 0; i < dataVectorLength; i++) {
        if (dataVector[i].size() == 8) {
            result_2 += ParseCode(dataVector[i]);
        }
        if (dataVector[i].size() == 7) {
            bool cid = false;
            for (int j = 0; j < dataVector[i].size(); j++) {
                if (GetCode(dataVector[i][j], "cid", ':') == 0) {
                    cid = true;
                    break;
                }
            }
            if (!cid) {
                result_2 += ParseCode(dataVector[i]);
            }
        }
    }
}

int ACDay4::GetCode(std::string inputString, std::string code, char separator) {
    std::size_t pos {0};
    pos = inputString.find(separator);
    return code.compare(inputString.substr(0, pos));
}

bool ACDay4::ValidateCode(std::string code, std::string value) {
    switch (codeMap[code]) {
    case BYR:
        return ValidateBYR(value);
    case IYR:
        return ValidateIYR(value);
    case EYR:
        return ValidateEYR(value);
    case HGT:
        return ValidateHGT(value);
    case HCL:
        return ValidateHCL(value);
    case ECL:
        return ValidateECL(value);
    case PID:
        return ValidatePID(value);
    case CID:
        return true;
    default:
        return false;
    }
}

int ACDay4::ParseCode(std::vector<std::string> inputVector) {
    for (int i = 0; i < inputVector.size(); i++) {
        std::size_t pos {0};
        pos = inputVector[i].find(":");
        if (!ValidateCode(inputVector[i].substr(0, pos), inputVector[i].substr(pos + 1, inputVector[i].length()))) {
            return 0;
        }
    }
    return 1;
}

int ACDay4::GetResult(int resultNumber) {
    switch (resultNumber) {
    case 1: {return result_1; };
    case 2: {return result_2; };
    default: { return 0; }
    }
}

bool ACDay4::ValidateBYR(std::string inputString) {
    int value {std::stoi(inputString)};
    return (value >= 1920 && value <= 2002);
}

bool ACDay4::ValidateIYR(std::string inputString) {
    int value {std::stoi(inputString)};
    return (value >= 2010 && value <= 2020);
}

bool ACDay4::ValidateEYR(std::string inputString) {
    int value {std::stoi(inputString)};
    return (value >= 2020 && value <= 2030);
}

bool ACDay4::ValidateHGT(std::string inputString) {
    size_t ending {};
    int value {std::stoi(inputString, &ending)};
    if (inputString.substr(ending).compare("in") == 0) {
        return (value >= 59 && value <= 76);
    }
    if (inputString.substr(ending).compare("cm") == 0) {
        return (value >= 150 && value <= 193);
    }
    return false;
}

bool ACDay4::ValidateHCL(std::string inputString) {
    if ((inputString[0] != '#') || (inputString.size() != 7)) {
        return false;
    }
    for (int i = 1; i < 7; i++) {
        if ((validCharset.count(inputString[i]) == 0) && (validNumset.count(inputString[i]) == 0)) {
            return false;
        }
    }
    return true;
}

bool ACDay4::ValidateECL(std::string inputString) {
    return (validEyeColor.count(inputString) == 1);
}


bool ACDay4::ValidatePID(std::string inputString) {
    if (inputString.size() != 9) {
        return false;
    }
    for (int i = 0; i < 9; i++) {
        if (validNumset.count(inputString[i]) == 0) {
            return false;
        }
    }
    return true;
}
