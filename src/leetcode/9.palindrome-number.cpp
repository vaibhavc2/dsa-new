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
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
   public:
    bool isPalindrome(int x) {}
};
// @lc code=end

//*/*-------------- SOLUTIONS --------------*/*//

// Approach 1: Reverse the number and compare
// Time: O(log10(n))
// Space: O(1)
class Solution1 {
   public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        else if (x < 10)
            return true;
        else {
            int reverse = 0, n = x;
            while (x) {
                if (reverse > INT_MAX / 10) return false;
                reverse = x % 10 + reverse * 10;
                x /= 10;
            }
            if (reverse == n) return true;
        }

        return false;
    }
};

// Approach 2: Compare the first and last digits
// Time: O(log10(n))
// Space: O(1)
class Solution2 {
   public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindromes
        if (x < 0) return false;

        // Calculate the divisor to extract the leading digit
        int divisor = 1;
        while (x / divisor >= 10) {
            divisor *= 10;
        }

        while (x != 0) {
            int leading = x / divisor;  // Extract the leading digit
            int trailing = x % 10;      // Extract the trailing digit

            // If the leading and trailing digits are not the same, it's not a palindrome
            if (leading != trailing) return false;

            // Remove the leading and trailing digits
            x = (x % divisor) / 10;

            // Adjust the divisor
            divisor /= 100;
        }

        return true;
    }
};

// Approach 3: Convert to string and compare
// Time: O(log10(n))
// Space: O(log10(n))
class Solution3 {
   public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        string s = to_string(x);
        int n = (int)s.size();
        int i = 0, j = n - 1;

        while (i < j) {
            if (s[i++] != s[j--])
                return false;
        }

        return true;
    }
};

// Approach 4: MOST OPTIMIZED - Reverse half of the number, compare with the other half
// Time: O(log10(n))
// Space: O(1)
class Solution {
   public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;

        int rev = 0;
        while (x > rev) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        // compare half of the number
        return x == rev || x == rev / 10;
    }
};

//*/*-------------- SOLUTIONS --------------*/*//

inline void solve() {
    int n;
    input(n);

    // string s;
    // string_input(s);

    // vector<int32_t> v(n);
    // array_input(v);

    // vector<string> vs(n);
    // string_array_input(vs);

    Solution sol;
    auto ans = sol.isPalindrome(n);
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