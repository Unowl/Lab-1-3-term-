#pragma once
#include <iostream>
#include "Node.h"


template<typename T>
class LinkedList{
public:
    LinkedList();
    LinkedList(int count);
    LinkedList(T* items,int count);
//    LinkedList(std::unique_ptr<Iterator<T>> begin, std::unique_ptr<Iterator<T>> end);
    ~LinkedList();

    int GetLength(){return Size;}
    T GetFirst();
    T GetLast();
    T& Get(int index);

    void Append(T data);
    void Prepend(T data);

    void pop_front();
    void pop_back();

    void Print();

    void InsertAt(T data,int index);
    void RemoveAt(int index);

    T& operator[] (const int index);
 /*
    std::unique_ptr<ListIt<T>> Begin();
    std::unique_ptr<ListIt<T>> End();
 */
private:
    int Size;
     Node<T>* head;
     Node<T>* tail;

};

template<typename T>
LinkedList<T> :: ~LinkedList(){
    while(Size){
        pop_front();
    }
}

template<typename T>
LinkedList<T> :: LinkedList(int count){
    Size = 0;
    head = nullptr;
    for (int i = 0; i < count; ++i) {
        Append(0);
    }
}

template<typename T>
LinkedList<T> :: LinkedList(){
    Size = 0;
    head = nullptr;
}

template<typename T>
LinkedList<T> :: LinkedList(T* items,int count){
    if(items == nullptr){
        Size = 0;
        head = nullptr;
    }
    else{
        Size = 0;
        this->head = nullptr;
        this->tail = nullptr;
        for (int i = 0; i < count; ++i) {
            Append(items[i]);
        }
    }
}

template<typename T>
T& LinkedList<T> ::Get(int index){
    if(index < 0 || index >= Size)
        throw "\nGet Message : Index Out Of Range\n";

    Node<T>* current;

    if(index < Size/2){
        current = head;
        for (int i = 0; i < index; ++i) {
            current = current->pNext;
        }
    }else{
        current = tail;
        for (int i = 0; i < Size-index-1; ++i) {
            current = current->pPrev;
        }
    }
    return current->data;

}

template<typename T>
T LinkedList<T> ::GetFirst() {
    if(Size == 0)
        throw "\nGetFirst Message : Index Out Of Range\n";
    return Get(0);
}

template<typename T>
T LinkedList<T> ::GetLast(){
    if(Size == 0)
        throw "\nGetLast Message : Index Out Of Range\n";
    return Get(Size - 1);
}

template<typename T>
void LinkedList<T> ::Print(){
    if(head != nullptr){
        std::cout << std::endl;
        Node<T>* tmp = this->head;
        if(Size == 1)
            std::cout << head->data<< ' '; //<< "[" << head->number <<"]";
        else{
            while(tmp != nullptr){
                std::cout << tmp->data<< ' '; //<< "[" << tmp->number <<"]";//std::endl;
                tmp = tmp->pNext;
            }
        }
    }
}


template<typename T>
void LinkedList<T>::Append(T data) {
    if (head == nullptr) {
        head = new Node<T>(data);
        this->tail = head;
    } else {
        Node<T> *current = this->tail;
        this->tail = new Node<T>(data, current, current->pNext);
        current->pNext = tail;
    }
    ++Size;
}

template<typename T>
void LinkedList<T> ::Prepend(T data) {
    if(head == nullptr){
        head = new Node<T>(data);
        this->tail = head;
    }
    else{
        Node<T>* one_more = new Node<T>(data,head->pPrev,head);
        head->pPrev = one_more;
        this->head = one_more;
        Node<T>* current = head;
        while(current->pNext != nullptr){
            current = current->pNext;
        }
        this->tail = current;
    }
    Size++;
}

template<typename T>
void LinkedList<T> ::pop_front() {
    if(Size == 1){
        delete [] tail;
        Size--;
    }
    else{
        Node<T>* tmp = head;
        head = head->pNext;
        head->pPrev = nullptr;
        delete [] tmp;
        Size--;
    }

}

template<typename T>
void LinkedList<T> ::pop_back(){
    if(Size != 1){
        Node<T>* tmp = tail;
        tail = tail->pPrev;
        tail->pNext = nullptr;
        delete [] tmp;
    }
    else{
        delete[] tail;
        head = nullptr;
        tail = nullptr;
    }
    Size--;

}

template<typename T>
void LinkedList<T> ::InsertAt(T data, int index) {
    if(index < 0 || index > Size)
        throw "\nInsertAt Message : Index Out Of Range\n";
    Node<T>* previous;
    Node<T>* new_elem;
    Node<T>* tmp;
  // std::cout << "\nInsertAt data = " << data << " index = " << index << "\n";
    if(index == 0 || index == Size)
    {
         if(index == 0)   Prepend(data);
         if(index == Size) Append(data);
    }
    else
    {
    if(index <= Size/2){//идём сначала
        if(index == 0)
            Prepend(data);
        previous = head;
        for (int i = 0; i < index - 1; ++i) {
            previous = previous->pNext;
        }
    }
    else{//идём с конца

        previous = tail;
        for (int i = 0; i < Size - index; ++i) {
            previous = previous->pPrev;
        }
    }
    tmp = previous->pNext;//запоминаем адрес следующего узла
    new_elem = new Node<T>(data,previous,previous->pNext);//создаем новый узел
    previous->pNext = new_elem;//обновляем указатель на следующий узел у предыдущего
    tmp->pPrev = new_elem;//обновляем указатель на предыдущий узел у следующего

    Size++;
    }
}

template<typename T>
void LinkedList<T>::RemoveAt(int index) {
    if(index < 0 || index >= Size)
        throw "removeAt Message : Index Out Of Range\n";
  //  std::cout << "\nremoveAt index = " << index << "\n";
    if(index == 0)
        pop_front();
    else{
        if(index == Size - 1)
            pop_back();
        else{
            Node<T>* previous;
            Node<T>* toDelete;
            if(index <= Size/2){
                previous = head;
                for (int i = 0; i < index - 1; ++i) {
                    previous = previous->pNext;
                }
            }
            else{
                previous = tail;
                for (int i = 0; i < Size - index; ++i) {
                    previous = previous->pPrev;
                }
            }

            toDelete = previous->pNext;
            previous->pNext = toDelete->pNext;
            toDelete->pNext->pPrev = previous;

            delete[] toDelete;
        Size--;
        }
    }
}



template<typename T>
T& LinkedList<T> :: operator[](const int index){

    int counter;
    Node<T>* current;
    if(index <= Size/2){
        counter = 0;
        current = this->head;
        while(current != nullptr){
            if(counter == index){
                return current->data;
            }
            current = current->pNext;
            counter++;
        }
    }
    else{
        counter = Size - 1;
        current = this->tail;
        while(current != nullptr){
            if(counter == index){
                return current->data;
            }
            current = current->pPrev;
            counter--;
        }
    }
}


