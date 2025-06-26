#pragma once
#include "clsArchStats.h"
#include <string>
#include <iostream>

class ArchivoStatistics
{

public:
    ArchivoStatistics(std::string filePath);
    bool Save(Stats statistics);
    Stats Read();

    void addAndSaveRecentMatch(Stats statistics);



private:
    std::string _filePath;
};