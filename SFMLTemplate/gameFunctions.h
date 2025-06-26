#define _CRT_SECURE_NO_WARNINGS

#include "SFML/Graphics.hpp"
#include <string>
#include "clsStats.h"
#include "clsArchStats.h"
#include "clsArchivoStatistics.h"

void saveStatisticsData(std::string, Stats currentMatch);

Stats getLastRecordedStats();

