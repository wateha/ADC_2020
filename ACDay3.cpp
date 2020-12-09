#include "ACDay3.h"
ACDay3::ACDay3 (std::string dataFileName) {
    DataFileReader data = DataFileReader (dataFileName, ' ', DataFileReader::DataType::STR);
    dataVector = data.GetStringData();

    // Day 3
    result_1 = CalculateTrees(3, 1);

    // Day 3*
    result_2 = CalculateTrees(1, 1) * CalculateTrees(3, 1) * CalculateTrees(5, 1) * CalculateTrees(7, 1) * CalculateTrees(1, 2);
    std::cout << "CalculateTrees(1, 1) = " << CalculateTrees(1, 1) <<
        "; CalculateTrees(3, 1) = " << CalculateTrees(3, 1) <<
        "; CalculateTrees(5, 1) = " << CalculateTrees(5, 1) <<
        "; CalculateTrees(7, 1) = " << CalculateTrees(7, 1) <<
        "; CalculateTrees(1, 2) = " << CalculateTrees(1, 2) <<
        ";" << std::endl;
}

int ACDay3::CalculateTrees(int xOffset, int yOffset) {
    int dataVectorLength = dataVector.size();
    int dataRowLength  = dataVector[0][0].length();
    int currentPosition {0};
    int treeCount {0};
    for (int i = yOffset; i < dataVectorLength; i += yOffset) {
        currentPosition = (currentPosition + xOffset) % dataRowLength;
        if (dataVector[i][0].at(currentPosition) == '#') {
            treeCount++;
        }
    }
    return treeCount;
}

unsigned int ACDay3::GetResult (int resultNumber) {
    switch (resultNumber) {
    case 1: { return result_1; };
    case 2: { return result_2; };
    default: { return 0; }
    }
}
