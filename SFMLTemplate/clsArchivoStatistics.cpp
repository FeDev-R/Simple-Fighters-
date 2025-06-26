#define _CRT_SECURE_NO_WARNINGS


#include "clsArchivoStatistics.h"

ArchivoStatistics::ArchivoStatistics(std::string filePath)
{
    _filePath = filePath;
}

bool ArchivoStatistics::Save(Stats statistics)
{
    FILE* p = fopen("statistics.dat", "wb+");
    if (p == NULL) {
        return false;
    }


    bool ok = fwrite(&statistics, sizeof(Stats), 1, p);
    fclose(p);
    return ok;
}

Stats ArchivoStatistics::Read()
{
    FILE* pArchivo = fopen("statistics.dat", "rb");
    if (pArchivo == NULL) {
        return Stats(0, 0, 0, 0, 0, 0, 0, 0, 0);
    }
    Stats statistics;
    fread(&statistics, sizeof(Stats), 1, pArchivo);
    fclose(pArchivo);
    std::cout << "read : ";
    statistics.coutStats(statistics);
    return statistics;
}

void ArchivoStatistics::addAndSaveRecentMatch(Stats statistics)
{
    Stats lastRecord(Read());

    lastRecord += statistics;

    if (Save(lastRecord)) {
        std::cout << "RecentMatch added succesfully" << std::endl;
    }
    std::cout << "lastRecord : ";

    lastRecord.coutStats(lastRecord);


}

