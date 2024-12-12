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
 * @lc app=leetcode id=2337 lang=cpp
 *
 * [2337] Move Pieces to Obtain a String
 */

// @lc code=start
class Solution {
   public:
    bool canChange(string &s, string &t) {}
};
// @lc code=end

//*/*-------------- SOLUTIONS --------------*/*//

class Solution1 {
   public:
    bool canChange(string s, string t) {
        int i, j, n = (int)s.size();
        int charCnt1, charCnt2;
        charCnt1 = charCnt2 = 0;
        const pair<char, char> p = {'L', 'R'};

        for (i = j = 0; i < n && j < n; ++i, ++j) {
            while (s[i] == '_') ++i;
            while (t[j] == '_') ++j;

            if (s[i] != t[j]) return false;

            if (s[i] == p.first) {
                if (i < j) return false;
            } else if (s[i] == p.second) {
                if (i > j) return false;
            }

            ++charCnt1, ++charCnt2;
        }

        while (i < n) {
            if (s[i++] != '_') ++charCnt1;
        }

        while (j < n) {
            if (t[j++] != '_') ++charCnt2;
        }

        if (charCnt1 != charCnt2) return false;

        return true;
    }
};

class Solution2 {
   public:
    bool canChange(string &s, string &t) {
        int i, j, n = (int)s.size();

        for (i = j = 0; i < n || j < n; ++i, ++j) {
            while (i < n && s[i] == '_') ++i;
            while (j < n && t[j] == '_') ++j;

            // this code works because of the specific behaviour of c++ strings
            // when i == n then, s[i] = '\0' or null character! (same for j and t)

            if (s[i] != t[j] || (s[i] == 'L' && i < j) || (s[i] == 'R' && i > j)) return 0;
        }

        return 1;
    }
};

//*/*-------------- SOLUTIONS --------------*/*//

inline void solve() {
    string s, t;
    cin >> s >> t;

    Solution sol;
    auto ans = sol.canChange(s, t);
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