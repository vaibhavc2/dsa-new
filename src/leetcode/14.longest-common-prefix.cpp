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

inline void string_vector_input_cin(vector<string> &v) {
    for (int32_t i = 0; i < static_cast<int32_t>(v.size()); i++)
        cin >> v[i];
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
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution {
   public:
    string longestCommonPrefix(vector<string> &strs) {
        string res = strs[0];

        for (int i = 1; i < (int)strs.size(); i++) {
            int j = 0;

            while (j < (int)res.size() && j < (int)strs[i].size() && res[j] == strs[i][j]) j++;

            res = res.substr(0, j);
        }

        return res;
    }
};
// @lc code=end

//*/*-------------- SOLUTIONS --------------*/*//

//*/*-------------- SOLUTIONS --------------*/*//

inline void solve() {
    int n;
    input(n);

    vector<string> v(n);
    string_vector_input_cin(v);

    Solution sol;
    auto ans = sol.longestCommonPrefix(v);
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