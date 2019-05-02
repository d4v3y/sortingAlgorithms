#include <iostream>
#include "merge.h"

#define aType int //  array type

using namespace std;

void Merge(aType a[], int firstLeft, int lastLeft, int firstRight, int lastRight, int size) {

    aType tempArray[size];
    int index = firstLeft;
    int firstSave = firstLeft;

    cout << "Firs_tLeft:  " << firstLeft << endl;
    cout << "Last_Left:   " << lastLeft << endl;
    cout << "Firs_tRight: " << firstRight << endl;
    cout << "Last_Right:  " << lastRight << endl;

    //  Merge segments (array subsets)
    while ((firstLeft <= lastLeft) && (firstRight <= lastRight)) {

        if (a[firstLeft] < a[firstRight]) {
            tempArray[index] = a[firstLeft];
            firstLeft++;
        } else {
            tempArray[index] = a[firstRight];
            firstRight++;
        }

        index++;
    }
    //  Copy remainder of left array into tempArray
    while (firstLeft <= lastLeft) {
        tempArray[index] = a[firstLeft];
        firstLeft++;
        index++;
    }
    //  Copy remainder of right array into tempArray
    while (firstRight <= lastRight) {
        tempArray[index] = a[firstRight];
        firstRight++;
        index++;
    }
    //  Copy back into original array
    for (index = firstSave; index <= lastRight; index++) {
        a[index] = tempArray[index];
    }
}

void Mergesort(aType a[], int first, int last, int size) {

    int middle;

    cout << endl;
    cout << "First: " << first << endl;
    cout << "Last:  " << last << endl;

    if (first < last) {

        middle = (first + last) / 2;

        cout << "Middle:  " << middle << endl;

        Mergesort(a, first, middle, size);
        Mergesort(a, middle + 1, last, size);
        Merge(a, first, middle, middle + 1, last, size);
    }
}

//  Swap:  Swap two items (by reference).
void MergeSwap(aType &v1, aType &v2) {

    aType tmpVal;

    tmpVal = v1;
    v1 = v2;
    v2 = tmpVal;
}

//  PrintArray:  Print contents of an array.
void PrintMergeArray(aType A[], int nElements) {

    cout << "[ ";

    for (int i = 0; i < nElements; i++) {
        
        cout << A[i];
        
        if (i < nElements - 1) {
            cout << ", ";
        }
    }
    
    cout << " ] " << endl;
}