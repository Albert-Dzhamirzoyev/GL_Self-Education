// GL Self-Education Task 1
//
// This is a stack class template implementation based on a dynamic array.
// The initial capacity of the stack and memory area size allocated on demand
// is set by const value 'baseCapacity'.
//
// The ArrayStack class automatically allocates memomy when there's no place to
// perform regular push() operation.
//

#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <cassert>

constexpr int c_baseCapacity = 4;

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
    ArrayStack(const ArrayStack& copyMe);
    ArrayStack & operator=(const ArrayStack& assignMe);

    void create (int newCapacity = c_baseCapacity);
    void push(const T & data);
    T pop();
    int capacity() const {return m_capacity;}
    int size() const {return m_size;}
    void resize(int newCapacity);
};

// Creates an empty stack with zero size and capacity
// (memory isn't allocated)
template <class T>
ArrayStack<T>::ArrayStack():
    m_size(0), m_capacity(0), m_data(nullptr) {}

// Deleting and releasing memory (destructor)
template <class T>
ArrayStack<T>::~ArrayStack()
{
    delete [] m_data;
}

// Deep copying constructor
template<class T>
ArrayStack<T>::ArrayStack(const ArrayStack& copyMe)
{
    m_size = copyMe.m_size;
    m_capacity = copyMe.m_capacity;
    if (copyMe.m_data)
    {
        m_data = new T [m_capacity];

        for (int i = 0; i < m_size; i++)
            m_data[i] = copyMe.m_data[i];
    }
    else
        m_data = nullptr;
}

// Overloaded operator '=' for deep copying
template <class T>
ArrayStack<T>& ArrayStack<T>::operator=(const ArrayStack& assignMe)
{
    if (this == &assignMe)
        return *this;

    delete [] m_data;

    m_size = assignMe.m_size;
    m_capacity = assignMe.m_capacity;
    if (assignMe.m_data)
    {
        m_data = new T [m_capacity];

        for (int i = 0; i < m_size; i++)
            m_data[i] = assignMe.m_data[i];
    }
    else
        m_data = nullptr;

    return *this;
}

//Creates a new stack with capacity = newCapacity.
// If the stack wasn't  originally empty all content is deleted and
// memory is reallocated on a new one
template <class T>
void ArrayStack<T>::create(int newCapacity)
{
    if (m_data)
        delete [] m_data;

    m_size = 0;


    if (newCapacity > 0)
    {
        m_capacity = newCapacity;
        m_data = new T [m_capacity];
    }
    else
    {
        m_capacity = 0;
        m_data = nullptr;
    }
}

// Pushing element to the stack
// If the stack capacity is not enough for pushing regular element
// it increases its capacity with method resize()
template <class T>
void ArrayStack<T>::push(const T& data)
{
    if (m_capacity - m_size < 1)
        resize(m_capacity + c_baseCapacity);

    m_data[m_size] = data;
    m_size++;
}

// Popping element from the stack
// Assertion failed if the stack is already empty
template <class T>
T ArrayStack<T>::pop()
{
    assert(m_size > 0 && "Popping failed! Stack is already empty.");

    m_size--;
    return m_data[m_size];
}

// Increasing-decreasing capacity of the stack
// in accordance to the value 'newCapacity'. If
// newCapacity is lower than current size the stack deletes older elements
// the "freshest" remain
template <class T>
void ArrayStack<T>::resize(int newCapacity)
{
    if (newCapacity <= 0)
    {
        create(0);
        return;
    }

    T *newData = new T [newCapacity];
    if (m_size <= newCapacity)
    {
        for (int i = 0; i < m_size; i++)
            newData[i] = m_data[i];
    }
    else
    {
        int offset = m_size - newCapacity;
        for (int i = offset; i < m_size; i++)
            newData[i - offset] = m_data[i];

        m_size = newCapacity;
    }
    m_capacity = newCapacity;
    delete [] m_data;
    m_data = newData;
}
#endif // ARRAYSTACK_H
