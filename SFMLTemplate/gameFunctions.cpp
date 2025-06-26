#include "gameFunctions.h"

void saveStatisticsData(std::string path, Stats currentMatch)
{
    ArchivoStatistics arc(path);

    arc.addAndSaveRecentMatch(currentMatch);

    ///descomentar para chequear en la consola
    arc.Read().coutStats(arc.Read());
}

Stats getLastRecordedStats()
{

    ArchivoStatistics arc("path");

    Stats obj(arc.Read());

    return obj;
}