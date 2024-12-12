// ---------- CP SETUP ---------- //
#ifndef DEBUG
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,abm,bmi,bmi2,mmx,avx,avx2,fma")
#endif

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
/* Prefer 'using ll' in leetcode */
// using ll = long long;
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
 * @lc app=leetcode id=1608 lang=cpp
 *
 * [1608] Special Array With X Elements Greater Than or Equal X
 */

// @lc code=start
class Solution {
   public:
    int specialArray(vector<int> &nums) {}
};
// @lc code=end

//*/*-------------- SOLUTIONS --------------*/*//

class Solution1 {
   public:
    int specialArray(vector<int> &nums) {
        int x = 0, n = (int)nums.size();
        auto it1 = nums.begin(), it2 = nums.end();
        sort(it1, it2);

        while (x <= nums[n - 1]) {
            if (x == nums.end() - lower_bound(it1, it2, x))
                return x;

            ++x;
        }

        return -1;
    }
};

//*/*-------------- SOLUTIONS --------------*/*//

inline void solve() {
    int n;
    input(n);

    vector<int32_t> v(n);
    vector_input(v);

    Solution sol;
    auto ans = sol.specialArray(v);
    cout << ans << endl;
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