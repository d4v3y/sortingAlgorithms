#include <iostream>
#include "selc.h"

#define aType int

using namespace std;

void SelectionSort(aType A[], int nElements) {

    int iSmallest;
    aType tmp;

    for (int i = 0; i < nElements; i++) {

        cout << " Pass: " << i << endl;
        iSmallest = IndexOfSmallest(A, i, nElements - 1);
        
        //  swap
        if (iSmallest > i) {
            tmp = A[i];
            A[i] = A[iSmallest];
            A[iSmallest] = tmp;
        }

        PrintSelcArray(A, nElements);
    }

    cout << "\nFinished:" << endl;
}

//  IndexOfSmallest:  Find index of smallest value.
int IndexOfSmallest(aType A[], int iStart, int iEnd) {

    int index = -1;
    aType aMin = A[iStart];

    for (int i = iStart; i <= iEnd; i++) {
        if (A[i] < aMin) {
            aMin = A[i];
            index = i;
        }
    }

    cout << "IndexOfSmallest:  " << index << endl;

    return index;
}

//  Print contents of an array.
void PrintSelcArray(aType A[], int nElements) {

    cout << "[ ";

    for (int i = 0; i < nElements; i++) {
        cout << A[i];
        if (i < nElements - 1) {
            cout << ", ";
        }
    }

    cout << " ] " << endl;
}
