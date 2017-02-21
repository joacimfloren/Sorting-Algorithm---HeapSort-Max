#pragma once

class BinHeap
{
public:
    BinHeap(void);
    ~BinHeap(void);

    bool isEmpty();
    bool isFull();

    float findMin();
    void deleteMin();
    void makeEmpty();

    int  m_currSize;

    void perculateDown(int ix);


    float m_arr[10000000];
    int numberOfNodes = 10000000;
private:
    
};