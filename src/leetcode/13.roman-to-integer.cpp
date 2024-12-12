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
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */
class Solution {
   public:
    int romanToInt(string s) {
    }
};
// @lc code=start

// @lc code=end

//*/*-------------- SOLUTIONS --------------*/*//

// Approach 1 - Brute Force
// Time: O(n)
// Space: O(1)
class Solution1 {
    unordered_map<char, int> mapping = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};

   public:
    int romanToInt(string &s) {
        int result = 0;

        for (auto it = s.begin(); it != s.end(); ++it) {
            if (it == s.end() - 1)
                result += mapping[*it];
            else if (*it == 'I') {
                if (*(it + 1) == 'V') {
                    result += mapping['V'] - mapping['I'];
                    ++it;
                } else if (*(it + 1) == 'X') {
                    result += mapping['X'] - mapping['I'];
                    ++it;
                } else
                    result += mapping[*it];
            } else if (*it == 'X') {
                if (*(it + 1) == 'L') {
                    result += mapping['L'] - mapping['X'];
                    ++it;
                } else if (*(it + 1) == 'C') {
                    result += mapping['C'] - mapping['X'];
                    ++it;
                } else
                    result += mapping[*it];
            } else if (*it == 'C') {
                if (*(it + 1) == 'D') {
                    result += mapping['D'] - mapping['C'];
                    ++it;
                } else if (*(it + 1) == 'M') {
                    result += mapping['M'] - mapping['C'];
                    ++it;
                } else
                    result += mapping[*it];
            } else
                result += mapping[*it];
        }

        return result;
    }
};

// Approach 2 - Brute Force Optimized
// Time: O(n)
// Space: O(1)
class Solution2 {
   public:
    int romanToInt(string s) {
        unordered_map<char, int> mapping = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}};
        int result = 0, n = (int)s.size();

        for (int i = 0; i < n; i++) {
            if (i < n - 1 && mapping[s[i]] < mapping[s[i + 1]])
                result -= mapping[s[i]];
            else
                result += mapping[s[i]];
        }

        return result;
    }
};

//*/*-------------- SOLUTIONS --------------*/*//

inline void solve() {
    // int n;
    // input(n);

    string s;
    cin >> s;

    // vector<int32_t> v(n);
    // array_input(v);

    // vector<string> vs(n);
    // string_array_input(vs);

    Solution sol;
    auto ans = sol.romanToInt(s);
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