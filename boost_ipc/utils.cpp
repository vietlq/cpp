#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#include "utils.h"

std::string create_mmap_name()
{
    const char PREFIX[] = "NeoMMapFile";
    const size_t BUFF_SZ = 1024;
    char buff[BUFF_SZ];
    char buffTime[BUFF_SZ];
    time_t oTime;
    struct tm oTm;
    
    time(&oTime);
    localtime_r(&oTime, &oTm);
    strftime(buffTime, BUFF_SZ, "%Y%m%d", &oTm);
    snprintf(buff, BUFF_SZ, "%s_%s.dat", PREFIX, buffTime);
    
    std::cout << buff << std::endl;
    
    return buff;
}
