#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include <functional>
using namespace std;

// Bubble Sort
template <typename T, typename Comp = less<T>>
void bubbleSort(T arr[], int n, Comp cmp = Comp()) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (cmp(arr[j + 1], arr[j]))
                swap(arr[j], arr[j + 1]);
        }
    }
}

// Selection Sort
template <typename T, typename Comp = less<T>>
void selectionSort(T arr[], int n, Comp cmp = Comp()) {
    for (int i = 0; i < n - 1; i++) {
        int best = i;

        for (int j = i + 1; j < n; j++) {
            if (cmp(arr[j], arr[best]))
                best = j;
        }

        swap(arr[i], arr[best]);
    }
}

// Insertion Sort
template <typename T, typename Comp = less<T>>
void insertionSort(T arr[], int n, Comp cmp = Comp()) {
    for (int i = 1; i < n; i++) {
        T key = arr[i];
        int j = i - 1;

        while (j >= 0 && cmp(key, arr[j])) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Heapify
template <typename T, typename Comp>
void heapify(T arr[], int n, int i, Comp cmp) {
    int best = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;

    if (left < n && cmp(arr[best], arr[left]))
        best = left;

    if (right < n && cmp(arr[best], arr[right]))
        best = right;

    if (best != i) {
        swap(arr[i], arr[best]);
        heapify(arr, n, best, cmp);
    }
}

// Heap Sort
template <typename T, typename Comp = less<T>>
void heapSort(T arr[], int n, Comp cmp = Comp()) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, cmp);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, cmp);
    }
}

// Partition
template <typename T, typename Comp>
int partition(T arr[], int lo, int hi, Comp cmp) {
    T pivot = arr[hi];
    int i = lo - 1;

    for (int j = lo; j < hi; j++) {
        if (cmp(arr[j], pivot)) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[hi]);
    return i + 1;
}

// Quick Sort
template <typename T, typename Comp = less<T>>
void quickSort(T arr[], int lo, int hi, Comp cmp = Comp()) {
    if (lo < hi) {
        int p = partition(arr, lo, hi, cmp);

        quickSort(arr, lo, p - 1, cmp);
        quickSort(arr, p + 1, hi, cmp);
    }
}

// Merge helper
template <typename T, typename Comp>
void merge(T arr[], int left, int mid, int right, Comp cmp) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    T* L = new T[n1];
    T* R = new T[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (!cmp(R[j], L[i]))
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

// Merge Sort helper
template <typename T, typename Comp>
void mergeSortHelper(T arr[], int left, int right, Comp cmp) {
    if (left >= right)
        return;

    int mid = (left + right) / 2;

    mergeSortHelper(arr, left, mid, cmp);
    mergeSortHelper(arr, mid + 1, right, cmp);

    merge(arr, left, mid, right, cmp);
}

// Merge Sort
template <typename T, typename Comp = less<T>>
void mergeSort(T arr[], int n, Comp cmp = Comp()) {
    mergeSortHelper(arr, 0, n - 1, cmp);
}

// Linear Search
template <typename T>
int linearSearch(T arr[], int n, const T& key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }

    return -1;
}

// Binary Search
template <typename T>
int binarySearch(T arr[], int n, const T& key) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

#endif
