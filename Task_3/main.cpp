// GL Self-Education Task 3
//
// Program uses global mutual storage (struct FileNameStorage g_storage) for
// keeping inserted path-string (char* p_currentDir), storage state (enum StorageStates),
// container with counted file names (vector files) and inserted directory stream object (DIR).
//
// Two threads (thread1, thread2 with functions iterateFiles() and printPaths())
// use this storage alternately with mutex protection (g_storage_mutex).
//
// Thread 1 reads a file name from inserted directory and saves it to storage.
// Thread 2 extracts a file name from storage and prints its full path.
// Both threads run periodically until storage will processed (vector files becomes empty).
//
#include <pthread.h>
#include <sys/types.h>
#include <dirent.h>

#include <iostream>

#include "FileNameStorage.h"
#include "functional.h"

pthread_mutex_t g_storage_mutex = PTHREAD_MUTEX_INITIALIZER;
FileNameStorage g_storage;
bool            g_verbose = false;

int main(int argc, char *argv[])
{
    pthread_t thread1, thread2;
    char * p_pathArgument = nullptr;

    if (argc == 1)
    {
        printUsageMessage();
        return 0;
    }
    if (argc > 1)
    {
        if(argv[1][0] == '-')
        {
            if(argv[1][1] == 'v')
            {
                g_verbose = true;
                p_pathArgument = argv[2];
            }
            else
            {
                printUsageMessage();
                return 0;
            }
        }
        else
            p_pathArgument = argv[1];
    }

    g_storage.p_currentDir = p_pathArgument;
    g_storage.p_currentDirStream = opendir(p_pathArgument);

    if (g_storage.p_currentDirStream == NULL)
    {
        std::cout << argv[1] <<"\n Said directory not found.\n";
        return 0;
    }

    std::cout << "Files\\directories found:\n";

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
