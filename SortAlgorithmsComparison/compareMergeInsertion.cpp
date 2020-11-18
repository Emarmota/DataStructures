#include<iostream>
#include <chrono>
#include <algorithm>


using namespace std;

const int Shortinput = 100, Longinput = 10000;

void merge(int arr[], int star, int middle, int end);
void mergeSort(int arr[], int start, int end);
void insertionSort(int arr[], int n);
void printArray(int A[], int size);

int main()
{
    int shortArray[Shortinput];
    int longArray[Longinput];

    //Real array size 
    int shortArraySize = sizeof(shortArray) / sizeof(shortArray[0]);
    int longArraySize = sizeof(longArray) / sizeof(longArray[0]);

    //Fill the arrays with random numbers
    for (int i = 0; i < Shortinput; i++)
        shortArray[i] = rand() % 100;

    for (int i = 0; i < Longinput; i++)
        longArray[i] = rand() % 100;


    /*The function swaps the value of each element with that of some other randomly picked element.
    When provided, the function gen determines which element is picked in every case.
        Otherwise, the function uses some unspecified source of randomness.*/
    random_shuffle(std::begin(shortArray), std::end(shortArray));

    auto t1 = chrono::high_resolution_clock::now();
    //MergeSort with short array
    mergeSort(shortArray, 0, shortArraySize - 1);
    auto t2 = chrono::high_resolution_clock::now();

    auto durationShortMergeSort = chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

    cout <<"The duration of Merge Sort with a short array is: "<< durationShortMergeSort << " microseconds" << endl;

    random_shuffle(std::begin(longArray), std::end(longArray));

    auto t3 = chrono::high_resolution_clock::now();
    //MergeSort with long array
    mergeSort(longArray, 0, longArraySize - 1);
    auto t4 = chrono::high_resolution_clock::now();

    auto durationLongtMergeSort = chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count();

    cout << "The duration of Merge Sort with a long array is: " << durationLongtMergeSort << " microseconds" <<endl;

  
    random_shuffle(std::begin(shortArray), std::end(shortArray));

    auto t5 = chrono::high_resolution_clock::now();
    //Inserction Sort with short array
    insertionSort(shortArray, shortArraySize);
    auto t6 = chrono::high_resolution_clock::now();

    auto durationShortInsertionSort = chrono::duration_cast<std::chrono::microseconds>(t6 - t5).count();

    cout << "The duration of Insertion Sort with a short array is: " << durationShortInsertionSort << " microseconds";
    cout << endl;

    //Inserction Sort with long array
    random_shuffle(std::begin(longArray), std::end(longArray));

    auto t7 = chrono::high_resolution_clock::now();
    //Inserction Sort with long array
    insertionSort(longArray, longArraySize);
    auto t8 = chrono::high_resolution_clock::now();

    auto durationLongInsertionSort = chrono::duration_cast<std::chrono::microseconds>(t8 - t7).count();

    cout << "The duration of Insertion Sort with a long array is: " << durationLongInsertionSort << " microseconds";
    cout << endl;

    cout << endl;

    return 0;
}

void merge(int arr[], int start, int middle, int end)
{
    int n1 = middle - start + 1;
    int n2 = end - middle;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[start + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];


    int i = 0;

    int j = 0;

    int k = start;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int middle = start + (end - start) / 2;

        mergeSort(arr, start, middle);
        mergeSort(arr, middle + 1, end);

        merge(arr, start, middle, end);
    }
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
}

