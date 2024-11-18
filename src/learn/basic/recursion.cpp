#include <bits/stdc++.h>
using namespace std;

void printMultipleTimes(string str, int n) {
    if (n == 0) {
        return;
    }
    cout << str << endl;
    printMultipleTimes(str, n - 1);
}

void printNTo1(int n) {
    if (n == 0) {
        return;
    }
    cout << n << endl;
    printNTo1(n - 1);
}

void print1ToN(int n) {
    if (n == 0) {
        return;
    }
    print1ToN(n - 1);
    cout << n << endl;
}

int sumTillN(int n) {
    if (n == 0) return 0;

    return n + sumTillN(n - 1);
}

int factorial(int n) {
    if (n == 0) return 1;

    return n * factorial(n - 1);
}

vector<int> reverseArray(vector<int> arr) {
    if (arr.size() == 0) return arr;

    int last = arr.back();
    arr.pop_back();

    arr = reverseArray(arr);
    arr.insert(arr.begin(), last);
    return arr;
}

void reverseArr(int arr[], int start, int end) {
    if (start >= end) return;

    swap(arr[start], arr[end]);
    reverseArr(arr, start + 1, end - 1);
}

void reverseArrayOptimized(int arr[], int n) {
    int j = n - 1;

    for (int i = 0; i < n; ++i) {
        swap(arr[i], arr[j]);
        --j;
    }
}

int main() {
    printMultipleTimes("Hello", 3);
    printNTo1(5);
    print1ToN(5);
    cout << sumTillN(6) << endl;
    cout << factorial(5) << endl;
    cout << factorial(10) << endl;
    vector<int> arr = {1, 2, 3, 4, 5};
    arr = reverseArray(arr);
    for (auto x : arr) cout << x << endl;

    int arr2[5] = {1, 2, 3, 4, 5};
    reverseArr(arr2, 0, 4);
    for (auto x : arr2) cout << x << endl;

    int arr3[5] = {1, 2, 3, 4, 5};
    reverseArrayOptimized(arr2, 5);
    for (auto x : arr2) cout << x << endl;

    return 0;
}