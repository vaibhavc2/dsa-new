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
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
    }
};
// @lc code=end

//*/*-------------- SOLUTIONS --------------*/*//

// approach 1 - Merge and Sort - NOT OPTIMAL
// Time - O((m+n)log(m+n)), Space - O(1)
class Solution1 {
   private:
    int i = 0, j = 0, idx = 0;
    bool first = true, success = false;
    double med;
    pair<int, int> medIdx = {-1, -1}, res = {-1, -1};

    inline void traverse(vector<int> &nums1, vector<int> &nums2, int &m, int &n) {
        if (first) {
            if (i >= m && j < n)
                res.first = nums2[j++];
            else if (j >= n && i < m)
                res.first = nums1[i++];
            else if (i < m && j < n) {
                if (nums1[i] < nums2[j])
                    res.first = nums1[i++];
                else
                    res.first = nums2[j++];
            }

            if (idx == medIdx.first) {
                if (medIdx.second == -1) {
                    med = static_cast<double>(res.first);
                    success = true;
                    return;
                } else
                    first = false;
            }
        } else {
            if (i >= m && j < n)
                res.second = nums2[j++];
            else if (j >= n && i < m)
                res.second = nums1[i++];
            else if (i < m && j < n) {
                if (nums1[i] < nums2[j])
                    res.second = nums1[i++];
                else
                    res.second = nums2[j++];
            }

            if (idx == medIdx.second) {
                med = static_cast<double>(res.first + res.second) / 2;
                success = true;
            }
        }
    }

   public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int m = (int)nums1.size();
        int n = (int)nums2.size();

        if ((m + n) % 2 == 0) {
            medIdx.first = (m + n) / 2 - 1;
            medIdx.second = (m + n) / 2;
        } else
            medIdx.first = (m + n) / 2;

        for (; idx <= (m + n) / 2 && !success; idx++) {
            traverse(nums1, nums2, m, n);
        }

        return med;
    }
};

//*/*-------------- SOLUTIONS --------------*/*//

inline void solve() {
    int n1, n2;
    input(n1);

    vector<int32_t> v1(n1);
    vector_input(v1);
    input(n2);
    vector<int32_t> v2(n2);
    vector_input(v2);

    Solution sol;
    auto ans = sol.findMedianSortedArrays(v1, v2);
    cout << ans << endl;
}

int32_t main() {
#ifndef DEBUG
    fastIO();
#endif
    DOUBLE();

    int t = 1;
    cin >> t;

    while (t--)
        solve();

    return 0;
}