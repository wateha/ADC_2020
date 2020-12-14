#pragma once
#include "DataFileReader.h"
#include "NestedBag.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class ACDay7
{
public:
    ACDay7(std::string dataFileName);
    int GetResult(int resultNumber);
    void AddBagToList(const std::string &colour);
    void ConnectBags(const std::string &parent, const std::string &child, int count);
    void ExtractParent(NestedBag *parent);
    int CountInnerBags(std::string bagName);
private:
    int result_1 {}, result_2 {};
    std::unordered_map<std::string, NestedBag*> bagList {};
    std::unordered_set<std::string> resultSet {};
    void DestroyBags();
};


