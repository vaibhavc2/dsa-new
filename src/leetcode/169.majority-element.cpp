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
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
   public:
    int majorityElement(vector<int> &nums) {}
};
// @lc code=end

//*/*-------------- SOLUTIONS --------------*/*//

// using sorting (Time complexity is inefficient but space complexity is great!)
// Time: O(nlogn)
// Space: O(1)
class Solution1 {
   public:
    int majorityElement(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        return nums[((int)nums.size()) / 2];
    }
};

// using map - hash table (Optimal Time complexity but space complexity is not great!)
// Time: O(n)
// Space: O(n)
class Solution2 {
   public:
    int majorityElement(vector<int> &nums) {
        int n = (int)size(nums);
        if (n < 3) return nums[0];

        unordered_map<int, int> mp;

        for (auto &x : nums) {
            mp[x]++;

            if (mp[x] > n / 2) return x;
        }

        return -1;
    }
};

// Boyer-Moore Voting Algorithm (Optimal Time and Space complexity)
// Time: O(n)
// Space: O(1)
class Solution3 {
   public:
    int majorityElement(vector<int> &nums) {
        int cnt = 0, res = nums[0];

        for (auto &x : nums) {
            if (cnt == 0) res = x;
            if (res == x)
                ++cnt;
            else
                --cnt;
        }

        return res;
    }
};

//*/*-------------- SOLUTIONS --------------*/*//

inline void solve() {
    int n;
    input(n);

    // string s;
    // cin >> s;
    // string_input(s);

    vector<int32_t> v(n);
    vector_input(v);

    // int32_t arr[10000];
    // array_input(arr, n);

    Solution sol;
    auto ans = sol.majorityElement(v);
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