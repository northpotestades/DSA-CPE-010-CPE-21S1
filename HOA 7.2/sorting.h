template <typename T>
void shellSort(T arr[], size_t size){
	for(int i = size/2; i > 0; i /= 2){
		for(int j = i; j < size; j += 1){
			int temp = arr[j];
			int k;
			for(k = j; k >= i && arr[k - i] > temp; k -= i){
				arr[k] = arr[k - i];
			};
			arr[k] = temp;
		}
	}
}

template <typename T>
void merge(T arr[], int left, int middle, int right){
	int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;
    int* L = new int[n1];
    int* R = new int[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
}

template <typename T>
void mergeSort(T arr[], int left, int right){
	if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

template <typename T>
int partition(T arr[], int low, int high){
	int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

template <typename T>
void quickSort(T arr[], int low, int high){
	if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

template <typename T>
void quickSortWithMerge(T arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        mergeSort(arr, low, pivot - 1);
        mergeSort(arr, pivot + 1, high);
    }
}
