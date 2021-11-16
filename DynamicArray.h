#include <iostream>
#include "Node.h"
template <class T>
class DynamicArray{
private:
    T* m_data;
    int m_size;
    int m_capacity;
public:
    ~DynamicArray(){
        delete[] m_data;
    }

    DynamicArray(){
        m_data = nullptr;
        m_size = 0;
        m_capacity = 0;
    }


    DynamicArray(int size){
        m_size = size;
        m_capacity = size;
        m_data = new T[size];
    }

    DynamicArray(T* items,int count){
        if(items == nullptr){
            m_data = nullptr;
            m_size = 0;
            m_capacity = 0;
        }
        else{
            m_size = count;
            m_capacity = count;
            m_data = new T[count];
            for (int i = 0; i < count; ++i)
            {
                m_data[i] = items[i];
            }
        }
    }


    void Resize(int newSize){
        if(newSize > m_capacity){
            int new_capacity = std::max(2 * m_size, newSize);
            T* new_data = new T[new_capacity];
            for (int i = 0; i < m_size; ++i)
            {
                new_data[i] = m_data[i];
            }
            delete[] m_data;
            m_data = new_data;
            m_capacity = new_capacity;
        }
        m_size = newSize;
    }

    T& Get(int index){
        return m_data[index];
    }

    void Set(int index,T value){
        m_data[index] = value;
    }

    int GetSize() const{
        return m_size;
    }

    void Append(T val){
        Resize(m_size + 1);
        m_data[m_size - 1] = val;
    }

    void Prepend(T val){
        Resize(m_size + 1);
        for (int i = m_size - 2; i >= 0; --i)
        {
            m_data[i + 1] = m_data[i];
        }
        m_data[0] = val;
    }
    void Print(){
        for (int i = 0; i < m_size; ++i) {
            std::cout << m_data[i] << ' ';
        }
        std::cout << std::endl;
    }
    T & operator [] (int i){
        return m_data[i];
    }

};

template <typename T>
std::ostream & operator << (std::ostream & out, DynamicArray<T> a){
    for(int i = 0; i < a.GetSize();++i){
        out << a[i] << " ";
    }
    return out;
}
