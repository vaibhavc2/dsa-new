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
 * @lc app=leetcode id=1047 lang=cpp
 *
 * [1047] Remove All Adjacent Duplicates In String
 */

// @lc code=start
class Solution {
   public:
    string removeDuplicates(string s) {}
};
// @lc code=end

//*/*-------------- SOLUTIONS --------------*/*//

// Brute force Optimized approach
// Time complexity: O(n)
// Space complexity: O(n)
class Solution1 {
    inline int checkDuplicates(string &s) {
        for (int i = 0; i < (int)(size(s)) - 1; ++i) {
            if (s[i] == s[i + 1]) return i;
        }
        return -1;
    }

   public:
    string removeDuplicates(string s) {
        if (size(s) < 2) return s;

        int i = checkDuplicates(s);
        while (i != -1) {
            do {
                s.erase(i, 2);

                if (i > 0) --i;

            } while (s[i] == s[i + 1]);

            i = checkDuplicates(s);
        }

        return s;
    }
};

// Stack approach
// Time complexity: O(n)
// Space complexity: O(n)
class Solution2 {
   public:
    string removeDuplicates(string s) {
        stack<char> st;
        string res;

        for (auto &c : s) {
            if (!st.empty() && st.top() == c) {
                st.pop();
            } else {
                st.push(c);
            }
        }

        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};

// Stack approach - Optimized - Use string as a stack
// Time complexity: O(n)
// Space complexity: O(n)
class Solution3 {
   public:
    string removeDuplicates(string s) {
        string result;
        for (char &c : s) {
            if (!result.empty() && result.back() == c) {
                result.pop_back();
            } else {
                result.push_back(c);
            }
        }
        return result;
    }
};

// Two pointers approach
// Time complexity: O(n)
// Space complexity: O(n)
class Solution4 {
   public:
    string removeDuplicates(string s) {
        int i = 0, n = (int)s.length();
        for (int j = 0; j < n; ++j, ++i) {
            s[i] = s[j];  // this helps copying the next chars after duplicates at the beginning of the string
            if (i > 0 && s[i - 1] == s[i])
                i -= 2;  // adjacent duplicates found
        }
        return s.substr(0, i);
    }
};

//*/*-------------- SOLUTIONS --------------*/*//

inline void solve() {
    string s;
    cin >> s;

    // vector<int32_t> v(n);
    // array_input(v);

    // vector<string> vs(n);
    // string_array_input(vs);

    Solution sol;
    auto ans = sol.removeDuplicates(s);
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