#include "StdAfx.h"
#include "BinHeap.h"
#include "assert.h"
#include <limits>
#include <iostream>
#include "Windows.h" 
#include "time.h"
using namespace std;

BinHeap::BinHeap(void)
{
    m_currSize = 0;
    m_arr[0] = -2147483647; INT_MIN; //  /-INT_MIN;-2147483648;
}

BinHeap::~BinHeap(void)
{
}

bool BinHeap::isEmpty()
{
    return m_currSize == 0;
}

bool BinHeap::isFull()
{
    int maxsize = (sizeof(m_arr) / sizeof(m_arr[0])) - 1;
    return (m_currSize >= maxsize);
}

float BinHeap::findMin()
{
    return m_arr[1];
}

/**************************************
ANROP:    heap.deleteMin( );
UPPGIFT:  Tar bort top värdet
***************************************/
void BinHeap::deleteMin()
{
    assert(!isEmpty());
    swap(m_arr[1], m_arr[m_currSize]);
    m_currSize--;
    perculateDown(1);   //trycker ner det som ligger på plats 1.
}

void BinHeap::makeEmpty()
{
    m_currSize = 0;
}

void BinHeap::perculateDown(int ix)
{
    float firstValue = m_arr[ix];

    while (ix * 2 <= m_currSize) {
        int theChild = ix * 2;

        if (theChild != m_currSize && m_arr[theChild] < m_arr[theChild + 1])
            ++theChild;

        if (m_arr[theChild] <= firstValue)
            break;

        m_arr[ix] = m_arr[theChild];
        ix = theChild;
    }

    m_arr[ix] = firstValue;
}

void main()
{
    srand(time(NULL));
    BinHeap * ny = new BinHeap();

    cout << "--------- Unsorted array ---------" << endl;
    for (int i = 1; i < ny->numberOfNodes; i++) {
        ny->m_arr[i] = (float)rand()/((float)RAND_MAX / 50);
        ny->m_currSize++;
    }
    
    int time = GetTickCount();

    for (int i = ny->m_currSize/2; i > 0; i--)
        ny->perculateDown(i);

    for (int i = ny->m_currSize; i > 0 ; i--)
        ny->deleteMin();

    time = GetTickCount() - time;
    delete ny;

    /*TESTKOD*/
    for (int i = 1; i < 10000000; i++)
        if (!(i > i - 1))
            cout << "Error" << endl;

    cout << "--------- Max Heap built ---------" << endl;
    cout << "--------- Array is sorted ---------" << endl;

    cout << "Det tog: " << time << " ms att bygga en MaxHeap och sedan sortera via HeapSort." << endl;
    cin.get();
}