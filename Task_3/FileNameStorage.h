#ifndef FILENAMESTORAGE_H
#define FILENAMESTORAGE_H

#include <string>
#include <vector>

#include <sys/types.h>
#include <dirent.h>

enum StorageStates
{
    NOT_INVOLVED_STATE,
    IS_FILLING_STATE,
    FILLED_STATE,
    PROCESSED_STATE
};

struct FileNameStorage
{
    DIR * p_currentDirStream = NULL;
    char * p_currentDir = nullptr;
    std::vector<std::string> files;
    int filesCount = 0;
    StorageStates state = NOT_INVOLVED_STATE;
};

#endif
