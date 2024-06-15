#include <iostream>
#include <cstdlib>

class smart_array
{
public:
    smart_array(size_t size) : m_size(size), m_data(new int[size])
    {
        if (!m_data)
        {
            throw std::runtime_error("error");
        }
    }

    ~smart_array()
    {
        delete[] m_data;
    }

    void add_element(int value)
    {
        if (m_current_size < m_size)
        {
            m_data[m_current_size++] = value;
        }
        else
        {
            throw std::length_error("Array is full");
        }
    }

    int get_element(size_t index) const
    {
        if (index >= m_current_size)
        {
            throw std::out_of_range("Index out of range");
        }
        return m_data[index];
    }

private:
    size_t m_size;
    size_t m_current_size = 0;
    int* m_data;
};

int main()
{
    try
    {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);
        std::cout << arr.get_element(1) << std::endl;
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}