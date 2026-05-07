#pragma once
#include <string>
#include <iostream>

class GEntry
{
private:
    std::string name[10];
    int score[10];
    int numberOfEntries = 0;
    const int maxEntries = 10;
public:
    void addEntry(std::string newName, int newScore);
    void removeEntry(int i);
    bool isEmpty();
    void display();
};

