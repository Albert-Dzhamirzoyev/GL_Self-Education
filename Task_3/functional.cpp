#include <iostream>

#include <pthread.h>
#include <sys/types.h>
#include <dirent.h>

#include "FileNameStorage.h"

extern pthread_mutex_t  g_storage_mutex;
extern FileNameStorage  g_storage;
extern bool             g_verbose;

void printUsageMessage()
{
    std::cout << "usage: dircont [-v] <path>\n\n" <<
                 "Program shows paths to every file in <path> directory.\n" <<
                 "Use option -v to see details of threads operation.";
}

void * iterateFiles(void * p_arg)
{
    pthread_mutex_lock(&g_storage_mutex);

    if (g_verbose == true)
        std::cout << "Thread 1:\n";

    struct dirent * p_fileEntry;

    if ((p_fileEntry = readdir(g_storage.p_currentDirStream)) != NULL)
    {
        g_storage.state = IS_FILLING_STATE;
        g_storage.files.push_back(std::string(p_fileEntry->d_name));

        if (g_verbose == true)
            std::cout << "\t\tFile entry read: " << p_fileEntry->d_name << "\n";
    }
    else
    {
        g_storage.state = FILLED_STATE;
        if (g_verbose == true)
            std::cout << "\t\tAll file entries read.\n";
    }

    pthread_mutex_unlock(&g_storage_mutex);
}

void * printPaths(void * p_arg)
{
    pthread_mutex_lock(&g_storage_mutex);

    if (g_verbose == true)
        std::cout << "Thread 2:\n";

    if ((g_storage.files.size() == 0) &&
        (g_storage.state != NOT_INVOLVED_STATE))
    {
        if (g_verbose == true)
            std::cout << "\t\tAll file entries wrote.\n";

        g_storage.state = PROCESSED_STATE;
    }

    if (((g_storage.files.size()) > 0) &&
        (g_storage.state != NOT_INVOLVED_STATE))
    {
        std::cout << "\t\t" << g_storage.p_currentDir << "/" << g_storage.files.back() << "\n";
        g_storage.files.pop_back();
    }

    if ((g_storage.state == NOT_INVOLVED_STATE) &&
        (g_verbose == true))
        std::cout << "\t\tWoke up too early, sorry!\n";


    pthread_mutex_unlock(&g_storage_mutex);
}
