#pragma once
#include <tuple>

template<typename T>
class Node{
public:

    Node* pNext;
    Node* pPrev;
    T* ptr_;
    T data;
    int number;

    Node(T* ptr) : ptr_(ptr){number = ptr_;};

    Node(T data = T(),Node* pPrev = nullptr,Node* pNext = nullptr,int number = 0){
        this->data = data;
        this->pPrev = pPrev;
        this->pNext = pNext;
        this->number = number;
    }

    T& operator *(){
        return data;
    }
};

template<typename T>
bool operator != (Node<T>& lhs,Node<T>& rhs){
    return std::make_tuple(lhs.pNext,lhs.pPrev,lhs.data) != std::make_tuple(nullptr, nullptr,0);
}

template<typename T>
std::ostream& operator << (std::ostream& output, const Node<T>& node){
    return output << node.data;
}

template<typename T>
bool operator <=(Node<T>& lhs,Node<T>& rhs){
    return lhs.data <= rhs.data;
}
