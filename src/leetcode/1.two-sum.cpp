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
void _print(T x) { cout << x; }

template <class T, class V>
void _print(pair<T, V> p) {
    cout << "{";
    _print(p.first);
    cout << ",";
    _print(p.second);
    cout << "}";
}

template <class T>
void _print(vector<T> v) {
    cout << "[ ";
    for (T i : v) {
        _print(i);
        cout << " ";
    }
    cout << "]";
}

template <class T>
void _print(set<T> v) {
    cout << "[ ";
    for (T i : v) {
        _print(i);
        cout << " ";
    }
    cout << "]";
}

template <class T>
void _print(multiset<T> v) {
    cout << "[ ";
    for (T i : v) {
        _print(i);
        cout << " ";
    }
    cout << "]";
}

template <class T, class V>
void _print(map<T, V> v) {
    cout << "[ ";
    for (auto i : v) {
        _print(i);
        cout << " ";
    }
    cout << "]";
}

template <class T, class V>
void _print(unordered_map<T, V> v) {
    cout << "[ ";
    for (auto i : v) {
        _print(i);
        cout << " ";
    }
    cout << "]";
}

inline void input(int &n) {
    cin >> n;
}

inline void string_input(string &s) {
    getline(cin, s);
}

inline void array_input(vector<int32_t> &v) {
    for (int32_t i = 0; i < static_cast<int32_t>(v.size()); i++)
        cin >> v[i];
}

inline void string_array_input(vector<string> &v) {
    for (int32_t i = 0; i < static_cast<int32_t>(v.size()); i++)
        getline(cin, v[i]);
}
//*/*-------------- SOLUTION --------------*/*//
// !! xxxxxxxx !! START FROM HERE !! xxxxxxxx !!
/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    }
};
// @lc code=end

//*/*-------------- SOLUTIONS --------------*/*//

// Brute Force
// Time Complexity: O(n^2)
// Space Complexity: O(1)
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {}; // No solution found
    }
};

// Binary Search - Unique approach
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2);
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        int i = 0;
        int start = i + 1;
        int end = sorted_nums.size() - 1;
        int mid = start - (start - end) / 2;
        int diff = target - sorted_nums[i];
        bool is_found = false;
        for(; i < sorted_nums.size() && !is_found; i++)
        {
            start = i + 1;
            end = sorted_nums.size() - 1;
            mid = start - (start - end) / 2;
            diff = target - sorted_nums[i];
            while (start <= end)
            {
                if(sorted_nums[mid] == diff)
                {
                    ans[0] = sorted_nums[i];
                    ans[1] = sorted_nums[mid];
                    is_found = true;
                    break;
                }
                else if (sorted_nums[mid] < diff)
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
                mid = start - (start - end) / 2;
            }
        }
        if (ans[0] == ans[1])
        {
            ans = solveRepeat(nums, ans[0]);
        }
        else
        {
            ans[0] = search(nums, ans[0]);
            ans[1] = search(nums, ans[1]);
        }
        return ans;
    }

    int search(vector<int> nums, int& x)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == x)
            {
                return i;
            }
        }
        return -1;
    }

    vector<int> solveRepeat(vector<int> nums, int& x)
    {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == x)
                res.push_back(i);
        }
        return res;
    }
};

// Hash Table - Two-pass
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution3 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        int n = nums.size();

        // Build the hash table
        for (int i = 0; i < n; i++) {
            numMap[nums[i]] = i;
        }

        // Find the complement
        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (numMap.count(complement) && numMap[complement] != i) {
                return {i, numMap[complement]};
            }
        }

        return {}; // No solution found
    }
};

// Hash Table - One-pass - Most Optimal
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution3 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        int n = (int) nums.size();

        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (numMap.count(complement)) {
                return {numMap[complement], i};
            }
            numMap[nums[i]] = i;
        }

        return {};
    }
};

//*/*-------------- SOLUTIONS --------------*/*//

inline void solve() {
    int n, k;
    input(n);

    // string s;
    // string_input(s);

    vector<int32_t> v(n);
    array_input(v);
    input(k);

    // vector<string> vs(n);
    // string_array_input(vs);

    Solution sol;
    auto ans = sol.twoSum(v, k);
    _print(ans);
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