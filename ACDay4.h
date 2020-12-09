#pragma once
#include"DataFileReader.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <set>

class ACDay4
{
public:
    enum PassportCode
    {
        BYR,
        IYR,
        EYR,
        HGT,
        HCL,
        ECL,
        PID,
        CID
    };

    std::unordered_map<std::string, ACDay4::PassportCode> codeMap {{"byr", BYR}, {"iyr", IYR}, {"eyr", EYR}, {"hgt", HGT}, {"hcl", HCL}, {"ecl", ECL}, {"pid", PID}, {"cid", CID}};

    ACDay4(std::string dataFileName);
    int GetResult(int resultNumber);

private:
    int result_1 {0}, result_2 {};
    std::set<char> validCharset {'a', 'b', 'c', 'd', 'e', 'f'};
    std::set<char> validNumset {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
    std::set<std::string> validEyeColor {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
    const std::vector<std::string> fieldCodes {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid", "cid"};
    int GetCode(std::string inputString, std::string code, char separator);
    
    bool ValidateBYR(std::string inputString);
    bool ValidateIYR(std::string inputString);
    bool ValidateEYR(std::string inputString);
    bool ValidateHGT(std::string inputString);
    bool ValidateHCL(std::string inputString);
    bool ValidateECL(std::string inputString);
    bool ValidatePID(std::string inputString);

    bool ValidateCode(std::string code, std::string value);

    int ParseCode(std::vector<std::string> inputVector);
};
