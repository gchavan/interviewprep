#pragma once

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class IHeap
{
protected:
    IHeap();
    int* data;
    int size;
    int tempSize;

public:
    virtual void BuildHeap(int* arr, int n) = 0;
    void Print();
    virtual void Sort();

private:
    virtual void Heapify(int curr, int max) = 0;
};

class MinHeap : public IHeap
{
public:
    void BuildHeap(int* arr, int n);
    void Sort();

private:
    void Heapify(int curr, int max);    
};

class MaxHeap : public IHeap
{
public:
    void BuildHeap(int* arr, int n);
    void Sort();

private:
    void Heapify(int curr, int max);
};