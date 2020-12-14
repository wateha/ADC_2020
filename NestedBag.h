#pragma once
#include <string>
#include <vector>
#include <unordered_map>

class NestedBag
{
public:
    NestedBag(const std::string &colour);
    std::string& GetColour();
    void AddBag(const std::string &colour, int count);
    void AddParent(const std::string &colour);
    int GetParentCount();
    std::string& GetParent(int index);
    int GetBagNumber(std::string bagName);
    int GetInnerBagCount();
    std::unordered_map<std::string, int> & GetInnerBag();
private:
    std::string bagColour {};
    std::unordered_map<std::string, int> innerBags {};
    std::vector<std::string> parentBags {};
};

// Red contain 2 Blue and 3 Green
// Green contain 5 Yellow
// Blue contain 3 Yellow and 5 White
// White is empty
// Yellow is empty

// Red: 2 * (3 * (1) + 5 * (1)) + 3 * (5* (1))