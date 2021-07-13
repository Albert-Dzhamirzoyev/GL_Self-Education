// GL Self-Education Task 2
//
//
//
//
//
//
//

#include <iostream>
#include <stdlib.h>

#include "functional.h"


int main(int argc, char * argv[])
{
    uint64_t  sum = 0;
    uint32_t fibo = 0;
    char* p_number = nullptr;
    int n;
    int i;
    bool verbose = false;

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
                verbose = true;
            else
            {
                printUsageMessage();
                return 0;
            }

            p_number = argv[2];
        }
        else
            p_number = argv[1];
    }

    n = atoi(p_number);
    if ((n <= 0))
    {
        std::cout << "Input not allowed.\n";
        printUsageMessage();
        return 0;
    }

try
    {
        for (i = 0; i <= n; i++)
        {
             fibo = fibonacci(i);
             sum += fibo;

             if (verbose == false)
                 continue;
             std::cout << "Fibonacci(" << i << ") = " << fibo <<
                      ";\t\t Sum(Fibonacci(" << i << ")) = " << sum << ";\n";
        }
    }
catch(const char * exc)
    {
        std::cout << "An Exception Occured: " << exc <<
                     "\nNumber is too big.\n";
        std::cout << "The sum of first " << (i - 1) << " Fibonacci number(s) equals " << sum << "\n";
        return -1;
    }

    std::cout << "The sum of first " << n << " Fibonacci numbers equals " << sum << "\n";

    return 0;
}
