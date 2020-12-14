#include "NestedBag.h"

NestedBag::NestedBag(const std::string &colour) {
    bagColour = colour;
}

std::string& NestedBag::GetColour() {
    return bagColour;
}
void NestedBag::AddBag(const std::string &colour, int count) {
    innerBags.emplace(colour, count);
};

void NestedBag::AddParent(const std::string &colour) {
   parentBags.push_back(colour);
}

int NestedBag::GetParentCount() {
    return parentBags.size();
}
std::string& NestedBag::GetParent(int index) {
    return parentBags[index];
}

int NestedBag::GetBagNumber(std::string bagName) {
    return innerBags[bagName];
};

int NestedBag::GetInnerBagCount() {
    return innerBags.size();
}

std::unordered_map<std::string, int>& NestedBag::GetInnerBag() {
    return innerBags;
}
