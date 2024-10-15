#include <iostream>

int binarySearch(int arr[], int size, int key) {
    int low = 0;
    int high = size - 1;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        std::cout << "Current Mid: " << mid << ", Value: " << arr[mid] << std::endl;

        if (arr[mid] == key) {
            return mid; // Key found
        } else if (arr[mid] < key) {
            low = mid + 1; // Adjust the low index
        } else {
            high = mid - 1; // Adjust the high index
        }
    }
    return -1; // Key not found
}

int main() {
    int arr[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 8;

    int result = binarySearch(arr, size, key);
    if (result != -1) {
        std::cout << "Key " << key << " found at index: " << result << std::endl;
    } else {
        std::cout << "Key " << key << " not found." << std::endl;
    }

    return 0;
}
