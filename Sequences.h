#pragma once
#include <memory>
#include "DynamicArray.h"
#include "LinkedList.h"

template<typename T>
class Sequence {
public:


    virtual T GetFirst() = 0;

    virtual T GetLast() = 0;

    virtual T& Get(int index) = 0;

    virtual int GetLength() = 0;

    virtual void Append(T item) = 0;

    virtual void Prepend(T item) = 0;

    virtual void InsertAt(T item, int index) = 0;

    virtual void Print() = 0;
};

template<typename T>
class ArraySequence : public Sequence<T> {
public:


    ArraySequence() : data() {}


    ArraySequence(T *item, int count) : data(item, count) {}

    int GetLength() {
        return data.GetSize();
    }

    T& Get(int index) {
        return data.Get(index);
    }

    T GetFirst() {
        return data.Get(0);
    }

    T GetLast() {
        return data.Get(data.GetSize() - 1);
    }

    void Append(T item) {
        data.Append(item);
    }

    void Prepend(T item) {
        data.Prepend(item);
    }

    void InsertAt(T item, int index) {//void Set(int index,T value)
        if (index >= data.GetSize() || index < 0)
            throw "\nInsertAt Message : Index Out Of Range";
        data.Resize(data.GetSize() + 1);
        for (int i = data.GetSize() - 2; i >= index; --i) {
            data.Set(i + 1, data.Get(i));
        }
        data.Set(index, item);
    }

    void Set(T item, int index){
        data.Set(index, item);
    }

    void Print() {
        data.Print();
    }


private:
    DynamicArray<T> data;

};

template<typename T>
class LinkedListSequence : public Sequence<T> {
public:


    LinkedListSequence() : data(){}

    LinkedListSequence(T *items, int count) : data(items,count){}

    LinkedListSequence(int count) : data(count){}


    int GetLength() {
        return data.GetLength();
    }

    T GetFirst() {
        return data.GetFirst();
    }

    T GetLast() {
        return data.GetLast();
    }

    T& Get(int index) {
        return data.Get(index);
    }

    void Append(T item) {
        data.Append(item);
    }

    void Prepend(T item) {
        data.Prepend(item);
    }

    void InsertAt(T item, int index) {
        data.InsertAt(item, index);
    }

    void RemoveAt(int index) {
        data.RemoveAt(index);
    }


    void Print() {
        data.Print();
    }

private:
    LinkedList<T> data;
};
