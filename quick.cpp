#include <iostream>
#include "quick.h"

#define aType int

using namespace std;

void Quicksort(aType a[], int first, int last) {

    int pivot;

    if (first < last) {

        pivot = Pivot(a, first, last);
        
        Quicksort(a, first, pivot - 1);
        Quicksort(a, pivot + 1, last);
    }
}

//  Pivot:  Find and return the index of pivot element.
int Pivot(aType a[], int first, int last) {

    int p = first;
    aType pivot = a[first];

    for (int i = first + 1; i <= last; i++) {
        if (a[i] <= pivot) {
            p++;
            QuickSwap(a[i], a[p]);
        }
    }

    QuickSwap(a[p], a[first]);

    return p;
}

//  Swap:  Swap two item (by reference).
void QuickSwap(aType &v1, aType &v2) {

    aType tmpVal;

    tmpVal = v1;
    v1 = v2;
    v2 = tmpVal;
}

//  PrintArray:  Print contents of an array.
void PrintQuickArray(aType A[], int nElements) {

    cout << "[ ";

    for (int i = 0; i < nElements; i++) {
        
        cout << A[i];

        if (i < nElements - 1) {
            cout << ", ";
        }
    }

    cout << " ] " << endl;
}
