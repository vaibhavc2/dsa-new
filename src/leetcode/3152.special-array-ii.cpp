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
 * @lc app=leetcode id=3152 lang=cpp
 *
 * [3152] Special Array II
 */

// @lc code=start
class Solution {
   public:
    vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries) {}
};
// @lc code=end

//*/*-------------- SOLUTIONS --------------*/*//

// Brute force : using special-array-i Q - TLE (Time Limit Exceeded)
// Time: O(n * q), Space: O(1)
class Solution1 {
   private:
    inline bool isSpecial(vector<int> &nums, int i, int n) {
        int pi, pj;
        if (i == n) return 1;
        pi = pj = -1;

        for (int j = i + 1; j <= n; ++i, ++j) {
            if (pi == -1) pi = nums[i] % 2;
            pj = nums[j] % 2;

            if (pi == pj) return 0;

            pi = pj;
        }

        return 1;
    }

   public:
    vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries) {
        vector<bool> res;

        for (auto &q : queries) {
            res.emplace_back(isSpecial(nums, q[0], q[1]));
        }

        return res;
    }
};

// Prefix Sum - OPTIMAL
// Time: O(n + q), Space: O(n)
class Solution2 {
   public:
    vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries) {
        int n = (int)nums.size();
        vector<int> prefixSum(n, 1);

        for (int i = 1; i < n; i++) {
            if ((nums[i] & 1) != (nums[i - 1] & 1))
                prefixSum[i] += prefixSum[i - 1];
        }

        // vector<bool> res;

        // for (auto &q : queries) {
        //     res.emplace_back(prefixSum[q[1]] >= q[1] - q[0] + 1);
        // }

        // equivalent to the above commented code, but faster for large queries - beats 100% submissions
        vector<bool> res(queries.size());

        for (size_t i = 0; i < queries.size(); i++) {
            res[i] = prefixSum[queries[i][1]] >= queries[i][1] - queries[i][0] + 1;
        }

        return res;
    }
};

// Prefix Sum & Special Count approach - OPTIMAL
// Time: O(n + q), Space: O(n)
class Solution3 {
   public:
    vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries) {
        int n = (int)nums.size();
        vector<int> prefix(n, 0);  // Initialize prefix array with size n

        // Calculate the prefix array
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1];
            if ((nums[i - 1] % 2 == 0 && nums[i] % 2 == 0) || (nums[i - 1] % 2 != 0 && nums[i] % 2 != 0)) {
                prefix[i]++;
            }
        }

        vector<bool> ans;  // Result vector

        // Process the queries
        for (auto &q : queries) {
            int left = q[0], right = q[1];
            int specialCount = prefix[right] - prefix[left];
            ans.emplace_back(specialCount == 0);
        }

        return ans;  // Return the result
    }
};

//*/*-------------- SOLUTIONS --------------*/*//

inline void solve() {
    int n1, n2;

    cin >> n1;
    vector<int> v(n1);
    vector_input(v);

    cin >> n2;
    vector<vector<int>> q(n2, vector<int>(2, 0));
    for (int i = 0; i < n2; i++)
        cin >> q[i][0] >> q[i][1];

    Solution sol;
    auto ans = sol.isArraySpecial(v, q);
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
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