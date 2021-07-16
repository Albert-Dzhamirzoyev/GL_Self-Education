#include <cstdint>
#include <iostream>

uint32_t fibonacci(int number)
{
    if (number <= 0)
        return 0;
    if (number == 1)
        return 1;
    if (number > 47)
        throw "fibonacci_type_overflow";

    return fibonacci(number - 1) + fibonacci(number - 2);
}

void printUsageMessage()
{
    std::cout << "usage: fibo [-v] <fibonacci number>\n\n" <<
                 "Fibonacci numbers in the range from 1 to 47 are allowed.";
}


