#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key) {
    if (high >= low) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] > key)
            return binarySearch(arr, low, mid - 1, key);

        return binarySearch(arr, mid + 1, high, key);
    }

    return -1;
}

int main()
{
    int arr[] = { 5, 3, 4, 15, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 15;
    int result = binarySearch(arr, 0, n - 1, x);
    if (result == -1) 
    printf("Element is not present in array");
    else 
    printf("Element is present at index %d", result);
    return 0;
}