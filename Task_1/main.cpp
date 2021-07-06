// GL Self-Education Task 1
//
#include <iostream>
#include <string>

#include "ArrayStack.h"

void stackReview(ArrayStack<int>&);
//extern constexpr int baseCapacity;

int main(int argc, char *argv[])
{
    ArrayStack<int> stack;
    std::string     command;
    int             arg;

    while(argc == 1)
    {
        std::cout << "\nInput command (push [int number], pop, popall, resize [int size], erase, quit)" << std::endl;
        std::cin >> command;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            std::cout << "Please try again.\n";
            command.clear();
            continue;
        }

        if (command == "quit")
        {
            stackReview(stack);
            return 0;
        }

        if (command == "push")
        {
            std::cin >> arg;
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(32767,'\n');
                std::cout << "Please try again.\n";
                command.clear();
                continue;
            }
            std::cout << "Pushing " << arg << " to Stack.\n";
            stack.push(arg);
            stackReview(stack);
        }

        if (command == "pop")
        {
            if (stack.size() > 0)
                std::cout << "Popping from the Stack: " << stack.pop() << "\n";
            else
                std::cout << "Stack is already empty.\n";

            stackReview(stack);
        }

        if (command == "popall")
        {
            std::cout << "Get out from my Stack!\n";
            std::cout << "Stack: ";
            while(stack.size() > 0)
                std::cout << stack.pop() << " ";

            std::cout << "\nNow stack is empty.\n";
            stackReview(stack);
        }

        if (command == "resize")
        {
            std::cin >> arg;
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(32767,'\n');
                std::cout << "Please try again.\n";
                command.clear();
                continue;
            }
            if (arg < 0)
            {
                std::cout << "Resizing failed! New size must be positive.\n";
                continue;
            }
            std::cout << "Resizing stack...\n";
            stack.resize(arg);
            stackReview(stack);
        }

        if (command == "erase")
        {
            std::cout << "Erasing stack...\n";
            stack.create(baseCapacity);
            stackReview(stack);
        }

        std::cin.ignore(32767,'\n');
        command.clear();

    }
    //Out of while
    return 0;
}

void stackReview(ArrayStack<int>& stack)
{
    std::cout << "\nStack capacity:\t" << stack.capacity() << "\n" <<
                 "Stack size:\t" << stack.size() << "\n";
}
