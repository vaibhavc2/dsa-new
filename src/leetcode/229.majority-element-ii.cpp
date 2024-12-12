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
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 */

// @lc code=start
class Solution {
   public:
    vector<int> majorityElement(vector<int> &nums) {
    }
};
// @lc code=end

//*/*-------------- SOLUTIONS --------------*/*//

// Method - 1 - Using Hash Map
// Time - O(n), Space - O(n)
class Solution1 {
   public:
    vector<int> majorityElement(vector<int> &nums) {
        int n = (int)nums.size();
        vector<int> res;
        unordered_map<int, int> mp, checked;

        for (auto &x : nums) {
            mp[x]++;
            if ((mp[x] > (n / 3)) && !checked[x]) {
                res.emplace_back(x);
                checked[x] = 1;
            }
        }

        return res;
    }
};

// Method - 2 - Boyer-Moore Voting Algorithm
// Time - O(n), Space - O(1)
// MAIN OBSERVATION - There can only be at most 2 different elements that can occur more than n / 3 times!
class Solution2 {
   public:
    vector<int> majorityElement(vector<int> &nums) {
        int n = (int)nums.size();
        int count1 = 0, count2 = 0;          // Counters for the potential majority elements
        int candidate1 = 0, candidate2 = 0;  // Potential majority element candidates

        // First pass to find potential majority elements.
        for (int i = 0; i < n; i++) {
            // If count1 is 0 and the current number is not equal to candidate2, update candidate1.
            if (count1 == 0 && nums[i] != candidate2) {
                count1 = 1;
                candidate1 = nums[i];
            }
            // If count2 is 0 and the current number is not equal to candidate1, update candidate2.
            else if (count2 == 0 && nums[i] != candidate1) {
                count2 = 1;
                candidate2 = nums[i];
            }
            // Update counts for candidate1 and candidate2.
            else if (candidate1 == nums[i]) {
                count1++;
            } else if (candidate2 == nums[i]) {
                count2++;
            }
            // If the current number is different from both candidates, decrement their counts.
            else {
                count1--;
                count2--;
            }
        }

        vector<int> result;
        int threshold = n / 3;  // Threshold for majority element

        // Second pass to count occurrences of the potential majority elements.
        count1 = 0, count2 = 0;
        for (int i = 0; i < n; i++) {
            if (candidate1 == nums[i]) {
                count1++;
            } else if (candidate2 == nums[i]) {
                count2++;
            }
        }

        // Check if the counts of potential majority elements are greater than n/3 and add them to the result.
        if (count1 > threshold) {
            result.push_back(candidate1);
        }
        if (count2 > threshold) {
            result.push_back(candidate2);
        }

        return result;
    }
};

//*/*-------------- SOLUTIONS --------------*/*//

inline void solve() {
    int n;
    input(n);

    vector<int32_t> v(n);
    vector_input(v);

    Solution sol;
    auto ans = sol.majorityElement(v);
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i] << ' ';
    }
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