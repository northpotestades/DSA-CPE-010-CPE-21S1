template <typename T>
void quickSortWithMerge(T arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);

        // Use MergeSort on the left sublist
        mergeSort(arr, low, pivot - 1);

        // Use MergeSort on the right sublist
        mergeSort(arr, pivot + 1, high);
    }
}
