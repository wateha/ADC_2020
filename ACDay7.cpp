#include "ACDay7.h"

ACDay7::ACDay7(std::string dataFileName) {
    DataFileReader data = DataFileReader(dataFileName, ' ', DataFileReader::DataType::STR, false);
    const std::vector<std::vector<std::string>> dataVector {data.GetStringData()};
    int dataVectorLength = dataVector.size();
    for (int i = 0; i < dataVectorLength; i++) {
        std::string newBag = dataVector[i][0];
        newBag.append(dataVector[i][1]);
        if (bagList.find(newBag) == bagList.end()) {
            AddBagToList(newBag);
        }
        for (int j = 4; j < dataVector[i].size(); j += 4) {
            if (dataVector[i][j].compare("no") != 0) {
                std::string child = dataVector[i][j+1];
                child.append(dataVector[i][j + 2]);
                if(bagList.find(child) == bagList.end()){
                    AddBagToList(child);
                }
                ConnectBags(newBag, child, std::stoi(dataVector[i][j]));
            }
        }
    }

    // Day 7
    ExtractParent(bagList["shinygold"]);
    result_1 = resultSet.size();
    // Day 7*
    result_2 = CountInnerBags("shinygold") - 1;
    DestroyBags();
}

void ACDay7::ExtractParent(NestedBag *parent) {
    for (int i = 0; i < parent->GetParentCount(); i++) {
        std::string nextParent = parent->GetParent(i);
        resultSet.insert(nextParent);
        ExtractParent(bagList[nextParent]);
    }
}

void ACDay7::AddBagToList(const std::string &colour) {
    NestedBag *bag = new NestedBag(colour);
    std::pair<std::string, NestedBag*> pair (colour, bag);
    bagList.insert(pair);
}

void ACDay7::ConnectBags(const std::string &parent, const std::string &child, int count) {
    bagList[parent]->AddBag(child, count);
    bagList[child]->AddParent(parent);
}

int ACDay7::CountInnerBags(std::string bagName) {
    NestedBag *currentBag = bagList[bagName];
    int innerCount = currentBag->GetInnerBagCount();
    if (innerCount == 0) {
        return 1;
    }
    int sum {1};
    for (auto &bag : currentBag -> GetInnerBag()) {
        sum += (bag.second) * CountInnerBags(bag.first);
    }
    return sum;
}

int ACDay7::GetResult(int resultNumber) {
    switch (resultNumber) {
    case 1: {return result_1; };
    case 2: {return result_2; };
    default: { return 0; }
    }
}

void ACDay7::DestroyBags() {
    for (auto i = bagList.begin(); i != bagList.end(); i++) {
        delete i->second;
    }
}