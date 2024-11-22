// ---------- CP SETUP ---------- //
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,abm,bmi,bmi2,mmx,avx,avx2,fma")

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
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
   public:
    bool isAnagram(string s, string t) {}
};
// @lc code=end

//*/*-------------- SOLUTIONS --------------*/*//

// method 1 - Sorting
// Time: O(nlogn)
// Space: O(1)
class Solution1 {
   public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};

// method 2 - 2 Hash Tables using unordered_map
// Time: O(n)
// Space: O(1)
class Solution2 {
   public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, int> frqMp1, frqMp2;

        for (auto &ch : s) ++frqMp1[ch];
        for (auto &ch : t) ++frqMp2[ch];

        int l1 = (int)frqMp1.size();
        int l2 = (int)frqMp2.size();

        if (l1 != l2) return false;

        for (int i = 97; i < 122; ++i) {
            if (frqMp1[(char)i] != frqMp2[(char)i]) return false;
        }

        return true;
    }
};

// method 3 - 1 Hash Table using unordered_map
// Time: O(n)
// Space: O(1)
class Solution3 {
   public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> count;

        for (auto &c : s) count[c]++;
        for (auto &c : t) count[c]--;

        for (auto &x : count) {
            if (x.second != 0) return false;
        }

        return true;
    }
};

// method 4 - 1 Hash Table using array - faster than unordered_map - MOST OPTIMAL
// Time: O(n)
// Space: O(1)
class Solution4 {
   public:
    bool isAnagram(string s, string t) {
        int cnt[26] = {0};

        for (char &c : s) cnt[c - 'a']++;
        for (char &c : t) cnt[c - 'a']--;

        for (int &val : cnt) {
            if (val != 0) return false;
        }

        return true;
    }
};

//*/*-------------- SOLUTIONS --------------*/*//

inline void solve() {
    string s, t;
    cin >> s >> t;

    Solution sol;
    auto ans = sol.isAnagram(s, t);
    cout << ans << endl;
}

int32_t main() {
    fastIO();
    DOUBLE();

    int t = 1;
    cin >> t;

    while (t--)
        solve();

    return 0;
}