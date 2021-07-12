#include <iostream>
#include <stdlib.h>

#include "functional.h"

#define DEBUG

int main(int argc, char * argv[])
{
    uint64_t  sum = 0;
    uint32_t fibo = 0;
    int n = atoi(argv[1]);
    int i;

    if ((n <= 0) || (argc < 2))
    {
        std::cout << "Please try again.\n";
        return 0;
    }

    try
    {
        for (i = 0; i <= n; i++)
        {
             fibo = fibonacci(i);
             sum += fibo;
#ifdef DEBUG
          std::cout << "Fibonacci(" << i << ") = " << fibo <<
                      ";\t\t Sum(Fibonacci(" << i << ") = " << sum << ";\n";
#endif
        }
    }
catch(const char * exc)
    {
        std::cout << "An Exception Occured: " << exc <<
                     "\nNumber is too big.\n";
        std::cout << "The sum of first " << (i - 1) << " Fibonacci numbers equals " << sum << "\n";
        return -1;
    }

    std::cout << "The sum of first " << n << " Fibonacci numbers equals " << sum << "\n";

    return 0;
}
