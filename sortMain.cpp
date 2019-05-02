#include <iostream>
#include <fstream>

#include "merge.h"
#include "quick.h"
#include "selc.h"

const int ARRAY_SIZE = 10; // Changes the size of the array

/******* Prototypes *******/
void generateMagValue(int arr[], int size, int magRange);
void lowToHighArray(int arr[], int size);
void highToLowArray(int arr[], int size);
void printArray(int arr[], int size);

using namespace std;

int main() {

    int MAGNITUDE_RANGE; // Changes the range of the magnitude values

    cout << "Enter range for magnitude values: ";
    cin >> MAGNITUDE_RANGE;
    cout << endl;

    // Main array
    int magArray[ARRAY_SIZE]; 
    // Number of elements in the array
    int nA = sizeof(magArray) / sizeof(aType);

    // Generate random values into array
    generateMagValue(magArray, ARRAY_SIZE, MAGNITUDE_RANGE);

    cout << "---------------------------------------------------------------------------------------------------" << endl;
    cout << "---------------------------------------------------------------------------------------------------" << endl;

/*************** Unordered Array ***************/
    cout << "Original Array:" << endl;
    printArray(magArray, ARRAY_SIZE);
    cout << "----------------------------------------------------------\n" << endl;

    cout << "MERGE SORT:";
    Mergesort(magArray, 0, nA - 1, ARRAY_SIZE);
    cout << "\nFinished:\n";
    PrintMergeArray(magArray, nA);
    cout << "----------------------------------------------------------\n" << endl;

    cout << "SELECTION SORT:\n";
    SelectionSort(magArray, nA);
    PrintSelcArray(magArray, nA);
    cout << "----------------------------------------------------------\n" << endl;

    cout << "Quick Sort:\n";
    Quicksort(magArray, 0, nA - 1);
    PrintQuickArray(magArray, nA);

    cout << "---------------------------------------------------------------------------------------------------" << endl;
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    cout << "\n";

/*************** Ordered from Low to High Array ***************/
    cout << "ORIGINAL ARRAY:" << endl;
    lowToHighArray(magArray, ARRAY_SIZE);
    printArray(magArray, ARRAY_SIZE);
    cout << "----------------------------------------------------------\n" << endl;

    cout << "MERGE SORT:";
    Mergesort(magArray, 0, nA - 1, ARRAY_SIZE);
    cout << "\nFinished:\n";
    PrintMergeArray(magArray, nA);
    cout << "----------------------------------------------------------\n" << endl;

    cout << "SELECTION SORT:\n";
    SelectionSort(magArray, nA);
    PrintSelcArray(magArray, nA);
    cout << "----------------------------------------------------------\n" << endl;

    cout << "QUICK SORT:\n";
    Quicksort(magArray, 0, nA - 1);
    PrintQuickArray(magArray, nA);

    cout << "---------------------------------------------------------------------------------------------------" << endl;
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    cout << "\n";

/*************** Ordered from High to Low Array ***************/
    cout << "ORIGINAL ARRAY:" << endl;
    highToLowArray(magArray, ARRAY_SIZE);
    printArray(magArray, ARRAY_SIZE);
    cout << "----------------------------------------------------------\n" << endl;

    cout << "MERGE SORT:";
    Mergesort(magArray, 0, nA - 1, ARRAY_SIZE);
    cout << "\nFinished:\n";
    PrintMergeArray(magArray, nA);
    cout << "----------------------------------------------------------\n" << endl;

    cout << "SELECTION SORT:\n";
    SelectionSort(magArray, nA);
    PrintSelcArray(magArray, nA);
    cout << "----------------------------------------------------------\n" << endl;

    cout << "QUICK SORT:\n";
    Quicksort(magArray, 0, nA - 1);
    PrintQuickArray(magArray, nA);

    cout << "---------------------------------------------------------------------------------------------------" << endl;
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    cout << "\n";

    return 0;
}

/*************** "Datasets" ***************/
// Generate random values into array
void generateMagValue(int arr[], int size, int magRange) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % magRange;
    }
}

// Order array from Low to High
void lowToHighArray(int arr[], int size) {

    int temp;

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Order array from High to Low
void highToLowArray(int arr[], int size) {

    int temp;

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] < arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Display array contents
void printArray(int arr[], int size) {

    cout << "[ ";

    for (int i = 0; i < size; i++) {

        cout << arr[i];

        if (i < size - 1) {
            cout << ", ";
        }
    }
    
    cout << " ] " << endl;
}
