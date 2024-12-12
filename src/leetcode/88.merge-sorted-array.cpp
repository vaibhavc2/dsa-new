// ---------- CP SETUP ---------- //
#ifndef DEBUG
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,abm,bmi,bmi2,mmx,avx,avx2,fma")
#endif

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
// #define int long long
#define fastIO()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

// const int MOD = 1e9+7;
// const int _MOD = 998244353;
// const double EPS = 1e-9;
// const long long INF = 2e18;
// const int mxN = 2e5+5;
// const double PI = 4 * atan(1);

#define db_precision numeric_limits<double>::digits10 + 1
#define DOUBLE()                  \
    cout.precision(db_precision); \
    cout << fixed

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T, class V>
void _print(unordered_map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <typename T>
void _print(T x);

// function implementations
template <typename T>
void _print(T x) { cerr << x; }

template <class T, class V>
void _print(pair<T, V> p) {
    cerr << "{";
    _print(p.first);
    cerr << ",";
    _print(p.second);
    cerr << "}";
}

template <class T>
void _print(vector<T> v) {
    cerr << "[ ";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

template <class T>
void _print(set<T> v) {
    cerr << "[ ";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

template <class T>
void _print(multiset<T> v) {
    cerr << "[ ";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

template <class T, class V>
void _print(map<T, V> v) {
    cerr << "[ ";
    for (auto i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

template <class T, class V>
void _print(unordered_map<T, V> v) {
    cerr << "[ ";
    for (auto i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

inline void input(int &n) {
    cin >> n;
}

inline void string_input(string &s) {
    getline(cin, s);
}

inline void vector_input(vector<int32_t> &v) {
    for (int32_t i = 0; i < static_cast<int32_t>(v.size()); i++)
        cin >> v[i];
}

inline void string_vector_input(vector<string> &v) {
    for (int32_t i = 0; i < static_cast<int32_t>(v.size()); i++)
        getline(cin, v[i]);
}

inline void array_input(int32_t arr[], int32_t n) {
    for (int32_t i = 0; i < n; i++)
        cin >> arr[i];
}

inline void string_array_input(string arr[], int32_t n) {
    for (int32_t i = 0; i < n; i++)
        getline(cin, arr[i]);
}

inline void char_array_input(char arr[], int32_t n) {
    for (int32_t i = 0; i < n; i++)
        cin >> arr[i];
}

//*/*-------------- SOLUTION --------------*/*//
// !! xxxxxxxx !! START FROM HERE !! xxxxxxxx !!
/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
class Solution {
   public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {}
};
// @lc code=end

//*/*-------------- SOLUTIONS --------------*/*//

// approach 1 - Two Pointers using extra space
// Time - O(m+n), Space - O(m+n)
class Solution1 {
   public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        vector<int> copy1 = nums1;
        int i = 0, j = 0, k = 0;

        for (; i < m && j < n; k++) {
            if (copy1[i] < nums2[j])
                nums1[k] = copy1[i++];
            else
                nums1[k] = nums2[j++];
        }

        while (k < m + n && i < m) {
            nums1[k] = copy1[i++];
            k++;
        }

        while (k < m + n && j < n) {
            nums1[k] = nums2[j++];
            k++;
        }
    }
};

// approach 2 - Two Pointers without using extra space - OPTIMAL
// Time - O(m+n), Space - O(1)
class Solution2 {
   public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int i = m - 1;      // last element of nums1
        int j = n - 1;      // last element of nums2
        int k = m + n - 1;  // last index of nums1

        // we will start from the end of both arrays and keep on comparing the elements, and put the greater element at the end of nums1, & decrement the respective pointers, & keep on doing this till we reach the start of nums2
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                // this automatically handles the case when i < 0, and there are elements left in nums2, so all the remaining elements of nums2 will be copied to nums1
                nums1[k--] = nums2[j--];
            }
        }
    }
};

//*/*-------------- SOLUTIONS --------------*/*//

inline void solve() {
    int n1, n2;
    cin >> n1 >> n2;

    vector<int32_t> v1(n1 + n2);
    for (int i = 0; i < n1; i++) cin >> v1[i];
    vector<int32_t> v2(n2);
    vector_input(v2);

    Solution sol;
    sol.merge(v1, n1, v2, n2);
    for (auto &i : v1) {
        cout << i << " ";
    }
    cout << endl;
}

int32_t main() {
#ifndef DEBUG
    fastIO();
    DOUBLE();
#endif

    int t = 1;
    cin >> t;

    while (t--)
        solve();

    return 0;
}