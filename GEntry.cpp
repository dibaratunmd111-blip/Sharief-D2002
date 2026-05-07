#include "GEntry.h"

bool GEntry::isEmpty() {
    if (numberOfEntries == 0) {
        return true;
    }
    else {
        return false;
    }
}

void GEntry::addEntry(std::string newName, int newScore) {
    std::string nn = newName;
    int ns = newScore;

    if (isEmpty()) {
        name[0] = nn;
        score[0] = ns;
        numberOfEntries++;
        return;
    }
    if (numberOfEntries == maxEntries) {
        if (ns < score[maxEntries - 1]) {
            std::cout << "Not High Enough to enter the entry" << std::endl;
            return;
        }
    }
    else
        numberOfEntries++;

    int i = numberOfEntries - 2;
    while (i >= 0 && ns > score[i]) {
        name[i + 1] = name[i];
        score[i + 1] = score[i];
        i--;
    }
    name[i + 1] = nn;
    score[i + 1] = ns;

}

void GEntry::removeEntry(int i) {
    if ((i < 0) || (i > numberOfEntries - 1)) {
        std::cout << "Invalid Entry Index" << std::endl;
    }
    std::string tn = name[i];
    int ts = score[i];
    for (int j = i + 1; j < numberOfEntries; j++) {
        name[j - 1] = name[j];
        score[j - 1] = score[j];
    }
    numberOfEntries--;

    std::cout << "Successfully removed entry: " << tn << "  " << ts << std::endl;
    std::cout << "\n";
}

void GEntry::display() {
    std::cout << "Name \t Score" << std::endl;
    for (int i = 0; i < numberOfEntries; i++) {
        std::cout << name[i] << "\t " << score[i] << std::endl;
    }
    std::cout << std::endl;
}