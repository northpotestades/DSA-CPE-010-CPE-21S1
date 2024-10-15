#include <iostream>

int countOccurrencesArray(int arr[], int size, int key) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key) {
            count++;
        }
    }
    return count;
}

int main() {
    int arr[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 18;

    int count = countOccurrencesArray(arr, size, key);
    std::cout << "Occurrences of " << key << " in array: " << count << std::endl;

    return 0;
}
