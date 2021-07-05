// GL Self-Education Task 1
//
// This is a stack class template implementation based on dynamic array.
// The initial capacity of the stack and memory area size allocated on demand
// is set by const value 'baseCapacity'.
//
// Next methods were implemented in class ArrayStack<T>:
//
// void create(int capacity)
// void push(const T & data)
// T pop()
// int capacity()
// int size()
// voidx resize(int newSize)
//
#include <cassert>
constexpr int baseCapacity = 8;

template <class T>
class ArrayStack
{
private:
    int     m_size;
    int     m_capacity;
    T *     m_data;
public:
    ArrayStack();
    ~ArrayStack();
    ArrayStack(const ArrayStack & copyMe);
    ArrayStack & operator=(const ArrayStack & assignMe);

    void create (int newCapacity);
    void push(const T & data);
    T & pop();
    int capacity();
    int size();
    void resize(int newSize);
};

