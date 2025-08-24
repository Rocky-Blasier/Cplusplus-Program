#pragma once
#ifndef ITEMTRACKER_H
#define ITEMTRACKER_H

#include <string>
#include <map>

class ItemTracker {
private:
    std::map<std::string, int> itemFrequency;

public:
    void LoadData(const std::string& filename);
    void WriteBackup(const std::string& filename);
    int GetItemFrequency(const std::string& item);
    void PrintAllFrequencies();
    void PrintHistogram();
};

#endif
