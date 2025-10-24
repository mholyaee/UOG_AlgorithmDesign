#include <iostream>
using namespace std;
// Function to swap two elements
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
// QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[low];    // Choose the first element as pivot
    int i = low + 1;        // Index of smaller element
    int j = high;           // Index of larger element

    while (i <= j) {
        // Find element greater than pivot
        while (i <= high && arr[i] <= pivot)
            i++;
        // Find element smaller than pivot
        while (arr[j] > pivot)
            j--;
        // If i and j haven't crossed, swap elements
        if (i < j)
            swap(arr[i], arr[j]);
    }
    // Place pivot in its correct position
    swap(arr[low], arr[j]);
        
        
        // Separately sort elements before and after partition
        quickSort(arr, low, j - 1);
        quickSort(arr, j + 1, high);
    }
}

// Utility function to print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    
}

// Example usage
int main() {
    int arr[] = {64, 34, 2,19,75,1,110,25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: ";
    printArray(arr, n);
    
    quickSort(arr, 0, n - 1);
    
    cout << "\nSorted array: ";
    printArray(arr, n);
    
    return 0;
}
