// GL Self-Education Task 3
//
//
//
//
//
//
#include <pthread.h>
#include <sys/types.h>
#include <dirent.h>

#include <iostream>

#include "FileNameStorage.h"
#include "functional.h"

pthread_mutex_t g_storage_mutex = PTHREAD_MUTEX_INITIALIZER;
FileNameStorage g_storage;
bool            g_verbose = true;

int main(int argc, char *argv[])
{
    pthread_t thread1, thread2;

    if (argc == 1)
    {
        printUsageMessage();
        return 0;
    }

    g_storage.p_currentDir = argv[1];
    g_storage.p_currentDirStream = opendir(argv[1]);

    if (g_storage.p_currentDirStream == NULL)
    {
        std::cout << argv[1] <<" Directory not found.\n";
        return 0;
    }

    while (g_storage.state != PROCESSED_STATE)
    {
        if((pthread_create(&thread1, NULL, &iterateFiles, NULL)))
            return -1;

        if((pthread_create(&thread2, NULL, &printPaths, NULL)))
            return -1;

        pthread_join(thread1, NULL);
        pthread_join(thread2, NULL);
    }

    closedir(g_storage.p_currentDirStream);

    return 0;
}
