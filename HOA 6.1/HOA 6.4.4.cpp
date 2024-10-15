#include <iostream>

int recursiveBinarySearch(int arr[], int low, int high, int key) {
    if (low > high) {
        return -1; // Key not found
    }

    int mid = (low + high) / 2;
    std::cout << "Current Mid: " << mid << ", Value: " << arr[mid] << std::endl;

    if (arr[mid] == key) {
        return mid; // Key found
    } else if (arr[mid] < key) {
        return recursiveBinarySearch(arr, mid + 1, high, key); // Search right half
    } else {
        return recursiveBinarySearch(arr, low, mid - 1, key); // Search left half
    }
}

int main() {
    int arr[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 8;

    int result = recursiveBinarySearch(arr, 0, size - 1, key);
    if (result != -1) {
        std::cout << "Key " << key << " found at index: " << result << std::endl;
    } else {
        std::cout << "Key " << key << " not found." << std::endl;
    }

    return 0;
}

