#include "DataFileReader.h"

DataFileReader::DataFileReader(std::string fileName, char delimiter, DataType dataType, bool clean) {
    // Read data file
    DataFileInput(fileName);
    if (clean) {
        CleanupData(" ");
    }
    // Parse data streams as selected data type with delimiter
    switch (dataType) {
    case DataType::INT:
        IntDataInput(delimiter);
        break;
    case DataType::STR:
        StrDataInput(delimiter);
        break;
    case DataType::FLOAT:
        FloatDataInput(delimiter);
        break;
    default:
        break;
    }
}

// Read input file and load to vector
void DataFileReader::DataFileInput(std::string fileName) {

    // Read file input
    std::ifstream inputDataFile {};
    // Get data input
    inputDataFile.open(fileName);
    if (!inputDataFile) {
        std::cout << "Can't open file \"" << fileName << "\"" << std::endl;
    }
    else {
        std::string data {};
        while(std::getline(inputDataFile, data)) {
            dataInputVector.push_back(data);
        }
    }
}

// Split input data to integers
void DataFileReader::IntDataInput(char delimiter) {
    for (size_t dataStringCounter = 0; dataStringCounter < dataInputVector.size(); dataStringCounter++) {
        size_t pos = 0;
        std::vector <int> dataVector;
        while ((pos = dataInputVector[dataStringCounter].find(delimiter)) != std::string::npos) {
            int data = std::stoi(dataInputVector[dataStringCounter].substr(0, pos));
            dataVector.push_back(data);
            dataInputVector[dataStringCounter].erase(0, pos + 1);
        }
        integerDataVector.push_back(dataVector);
    }
}

// Split input data to strings
void DataFileReader::StrDataInput(char delimiter) {
    for (size_t dataStringCounter = 0; dataStringCounter < dataInputVector.size(); dataStringCounter++) {
        size_t pos = 0;
        std::vector <std::string> dataVector;
        while (true) {
            pos = dataInputVector[dataStringCounter].find(delimiter);
            std::string data = dataInputVector[dataStringCounter].substr(0, pos);
            dataVector.push_back(data);
            dataInputVector[dataStringCounter].erase(0, pos + 1);
            if (pos == std::string::npos) {
                break;
            }
        }
        stringDataVector.push_back(dataVector);
    }
}

// Split input data to floats
void DataFileReader::FloatDataInput(char delimiter) {
    for (size_t dataStringCounter = 0; dataStringCounter < dataInputVector.size(); dataStringCounter++) {
        size_t pos = 0;
        std::vector <float> dataVector;
        while ((pos = dataInputVector[dataStringCounter].find(delimiter)) != std::string::npos) {
            float data = std::stof(dataInputVector[dataStringCounter].substr(0, pos));
            dataVector.push_back(data);
            dataInputVector[dataStringCounter].erase(0, pos + 1);
        }
        floatDataVector.push_back(dataVector);
    }
}

// Integer data access
const std::vector <std::vector <int>>& DataFileReader::GetIntegerData() {
    return integerDataVector;
}

// String data access
const std::vector <std::vector <std::string>>& DataFileReader::GetStringData() {
    return stringDataVector;
}

// Float data access
const std::vector <std::vector <float>>& DataFileReader::GetFloatData() {
    return floatDataVector;
}

// Cleanup data lines
void DataFileReader::CleanupData(std::string delimiter) {
    for (int i = dataInputVector.size() - 1; i > 0; i--) {
        if (dataInputVector[i - 1].empty()) {
            dataInputVector.erase(dataInputVector.begin() + i - 1);
            i--;
        }
        else {
            //dataInputVector[i - 1].pop_back();
            dataInputVector[i - 1].append(delimiter).append(dataInputVector[i]);
            dataInputVector.erase(dataInputVector.begin() + i);
        }
    }
}