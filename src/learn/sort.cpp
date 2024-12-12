#include <bits/stdc++.h>
using namespace std;

inline void inputArray(int*& arr, int* tmp, const int& n) {
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        tmp[i] = arr[i];
    }
}

inline void printArray(int*& arr, const int& n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

inline void resetArray(int*& arr, const int* tmp, const int& n) {
    for (int i = 0; i < n; i++)
        arr[i] = tmp[i];
}

inline void inputVector(vector<int>& arr, vector<int>& tmp, const int& n) {
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        tmp[i] = arr[i];
    }
}

inline void printVector(vector<int>& arr, const int& n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Stable sorting algorithms maintain the relative order of equal elements.
// Adaptive sorting algorithms take advantage of existing order in its input.
// In-place sorting algorithms use only a small, constant amount of extra space.
// Unstable sorting algorithms may change the relative order of equal elements.
class Sort {
   private:
    // merge sort implementation
    static void mergeArrays(int*& arr, int low, int mid, int high) {
        int i1 = low, i2 = mid + 1;

        int n = high - low + 1;
        int* tmp = new int[n];
        int i = 0;

        while (i1 <= mid && i2 <= high && i < n) {
            if (arr[i1] <= arr[i2]) {
                tmp[i++] = arr[i1++];
            } else {
                tmp[i++] = arr[i2++];
            }
        }

        while (i < n && i1 <= mid) {
            tmp[i++] = arr[i1++];
        }

        while (i < n && i2 <= high) {
            tmp[i++] = arr[i2++];
        }

        for (int j = low, k = 0; j <= high && k < n; j++, k++) arr[j] = tmp[k];

        delete[] tmp;
    }
    static void mergeSort(int*& arr, int low, int high) {
        if (low >= high) return;
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        mergeArrays(arr, low, mid, high);
    }
    static void mergeVectors(vector<int>& arr, int low, int mid, int high) {
        int i1 = low, i2 = mid + 1;

        int n = high - low + 1;
        vector<int> tmp(n);
        int i = 0;

        while (i1 <= mid && i2 <= high && i < n) {
            if (arr[i1] <= arr[i2]) {
                tmp[i++] = arr[i1++];
            } else {
                tmp[i++] = arr[i2++];
            }
        }

        while (i < n && i1 <= mid) {
            tmp[i++] = arr[i1++];
        }

        while (i < n && i2 <= high) {
            tmp[i++] = arr[i2++];
        }

        for (int j = low, k = 0; j <= high && k < n; j++, k++) arr[j] = tmp[k];
    }
    static void mergeSort(vector<int>& arr, int low, int high) {
        if (low >= high) return;
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        mergeVectors(arr, low, mid, high);
    }

    // quick sort implementation
    static int findPivotAndRearrange(int*& arr, int low, int high) {
        int i = low, j = high, pivot = low;
        while (i < j) {
            while (i <= high && arr[i] <= arr[pivot]) ++i;
            while (j >= low && arr[j] > arr[pivot]) --j;

            if (i < j) swap(arr[i], arr[j]);
        }

        swap(arr[pivot], arr[j]);
        return j;
    }
    static void quickSort(int*& arr, int low, int high) {
        if (low >= high) return;
        int pivot = findPivotAndRearrange(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
    static int findPivotAndRearrange(vector<int>& arr, int low, int high) {
        int i = low, j = high, pivot = low;

        while (i < j) {
            while (i <= high && arr[i] <= arr[pivot]) i++;
            while (j >= low && arr[j] > arr[pivot]) j--;

            if (i < j) swap(arr[i], arr[j]);
        }

        swap(arr[pivot], arr[j]);
        return j;
    }
    static void quickSort(vector<int>& arr, int low, int high) {
        if (low >= high) return;
        int pivot = findPivotAndRearrange(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }

   public:
    // Worst Case Complexities - Time: O(n^2), Space: O(1)
    // No best case scenario - Time: O(n^2)
    // In-place sorting algorithm - Unstable - Non-adaptive
    // Use-case: When the number of elements is small
    static void selection(int*& arr, const int& n) {
        for (int i = 0; i < n - 1; i++) {
            int imin = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[imin]) imin = j;
            }
            if (imin != i) swap(arr[i], arr[imin]);
        }
    };
    static void selection(vector<int>& arr, const int& n) {
        for (int i = 0; i < n - 1; i++) {
            int imin = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[imin]) imin = j;
            }
            if (imin != i) swap(arr[i], arr[imin]);
        }
    };

    // Worst Case Complexities - Time: O(n^2), Space: O(1)
    // Best case - When the array is already sorted - Time: O(n)
    // In-place sorting algorithm - Stable - Adaptive
    // Use-case: When the number of elements is small
    static void bubble(int*& arr, const int& n) {
        for (int i = 0; i < n - 1; i++) {
            bool swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) break;
        }
    };
    static void bubble(vector<int>& arr, const int& n) {
        for (int i = 0; i < n - 1; i++) {
            bool swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) break;
        }
    };

    // Worst Case Complexities - Time: O(n^2), Space: O(1)
    // Best case - When the array is already sorted - Time: O(n)
    // In-place sorting algorithm - Stable - Adaptive
    // Less number of comparisons than bubble sort
    // Use-case: When the number of elements is small
    static void insertion(int*& arr, const int& n) {
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    };
    static void insertion(vector<int>& arr, const int& n) {
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    };

    // Divide and Conquer algorithm OR Divide and Merge algorithm
    // Worst Case Complexities - Time: O(n logn), Space: O(n)
    // Best Case - When the array is already sorted - Time: O(n logn)
    // Not an In-place sorting algorithm - Stable - Non-adaptive
    // Use-case: When the number of elements is large (or unknown) - Works well with linked lists, and gives consistent performance in terms of complexity for any number of elements
    static void merge(int*& arr, const int& n) {
        Sort::mergeSort(arr, 0, n - 1);
    };
    static void merge(vector<int>& arr, const int& n) {
        Sort::mergeSort(arr, 0, n - 1);
    };

    static void quick(int*& arr, const int& n) {
        quickSort(arr, 0, n - 1);
    };
    static void quick(vector<int>& arr, const int& n) {
        quickSort(arr, 0, n - 1);
    };

    // Counting Sort - Only works for non-negative integers - Best for large datasets with a small range of values.
    // Worst Case Complexities - Time: O(n + k), Space: O(n + k) [k - range of elements in array]
    // Best Case - When the range of input data is not significantly greater than the number of items - Time: O(n + k)
    // Not an In-place sorting algorithm - Stable - Non-adaptive
    // Use-case: When the range of input data is not significantly greater than the number of items
    static void counting(int*& arr, const int& n) {
        int max = *max_element(arr, arr + n);
        int min = *min_element(arr, arr + n);
        int range = max - min + 1;

        int* count = new int[range]();
        int* output = new int[n];

        for (int i = 0; i < n; i++) count[arr[i] - min]++;

        for (int i = 1; i < range; i++) count[i] += count[i - 1];

        for (int i = n - 1; i >= 0; i--) {
            output[count[arr[i] - min] - 1] = arr[i];
            count[arr[i] - min]--;
        }

        for (int i = 0; i < n; i++) arr[i] = output[i];

        delete[] count;
        delete[] output;
    };
    static void counting(vector<int>& arr, const int& n) {
        int max = *max_element(arr.begin(), arr.end());
        int min = *min_element(arr.begin(), arr.end());
        int range = max - min + 1;

        vector<int> count(range), output(n);

        for (int i = 0; i < n; i++) count[arr[i] - min]++;

        for (int i = 1; i < range; i++) count[i] += count[i - 1];

        for (int i = n - 1; i >= 0; i--) {
            output[count[arr[i] - min] - 1] = arr[i];
            count[arr[i] - min]--;
        }

        for (int i = 0; i < n; i++) arr[i] = output[i];
    };

    static void cyclic(int*& arr, const int& n) {};
    static void cyclic(vector<int>& arr, const int& n) {};

    static void heap(int*& arr, const int& n) {};
    static void heap(vector<int>& arr, const int& n) {};

    static void radix(int*& arr, const int& n) {};
    static void radix(vector<int>& arr, const int& n) {};

    static void bucket(int*& arr, const int& n) {};
    static void bucket(vector<int>& arr, const int& n) {};

    static void shell(int*& arr, const int& n) {};
    static void shell(vector<int>& arr, const int& n) {};
};

int a[10001], tmp[10001];
void solveUsingArray() {
    int n;
    cin >> n;

    int* arr = a;  // pointer because the array decays to a pointer, so array can't be passed as a reference!

    inputArray(arr, tmp, n);

    Sort::selection(arr, n);
    printArray(arr, n);

    resetArray(arr, tmp, n);

    Sort::bubble(arr, n);
    printArray(arr, n);

    resetArray(arr, tmp, n);

    Sort::insertion(arr, n);
    printArray(arr, n);

    resetArray(arr, tmp, n);

    Sort::merge(arr, n);
    printArray(arr, n);

    resetArray(arr, tmp, n);

    Sort::quick(arr, n);
    printArray(arr, n);

    resetArray(arr, tmp, n);

    Sort::counting(arr, n);
    printArray(arr, n);
}

void solveUsingVector() {
    int n;
    cin >> n;

    vector<int> arr(n), tmp(n);
    inputVector(arr, tmp, n);

    Sort::selection(arr, n);
    printVector(arr, n);

    arr = tmp;

    Sort::bubble(arr, n);
    printVector(arr, n);

    arr = tmp;

    Sort::insertion(arr, n);
    printVector(arr, n);

    arr = tmp;

    Sort::merge(arr, n);
    printVector(arr, n);

    arr = tmp;

    Sort::quick(arr, n);
    printVector(arr, n);

    arr = tmp;

    Sort::counting(arr, n);
    printVector(arr, n);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solveUsingArray();
        // solveUsingVector();
    }

    return 0;
}