#include <cstdint>

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
