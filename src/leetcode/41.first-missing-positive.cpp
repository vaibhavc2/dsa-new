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
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

// @lc code=start
class Solution {
   public:
    int firstMissingPositive(vector<int> &nums) {}
};
// @lc code=end

//*/*-------------- SOLUTIONS --------------*/*//

// Complexity requirements of the problem:
// Time Complexity - O(n), Space Complexity - O(n), Auxiliary Space - O(1) (meaning constant extra space other than what is in the algorithm)

// Unpreferred sol'n - using sort - Bad approach - Wrong time complexity, although not TLE
// Time Complexity - O(n logn), Space Complexity - O(n), Auxiliary Space - O(1)
class Solution1 {
   public:
    int firstMissingPositive(vector<int> &nums) {
        sort(nums.begin(), nums.end());

        if (nums.back() <= 0) return 1;
        if (nums[0] > 1) return 1;

        for (size_t i = 1; i < nums.size(); i++) {
            int diff = abs(nums[i - 1] - nums[i]);

            if (diff > 1) {
                if (nums[i] < 0) continue;
                if (nums[i - 1] < 0 && nums[i] >= 2) return 1;
                if (nums[i - 1] >= 0) return (nums[i - 1] + 1);
            }
        }

        return nums.back() + 1;
    }
};

// Unpreferred sol'n - using set - Bad approach - Wrong time complexity, although not TLE
// Time Complexity - O(n logn), Space Complexity - O(n), Auxiliary Space - O(n)
class Solution2 {
   public:
    int firstMissingPositive(vector<int> &nums) {
        // Step 1: Create a set from the input array
        set<int> numSet(nums.begin(), nums.end());

        // Step 2: Iterate through positive integers starting from 1
        for (int i = 0; i < INT_MAX - 1; ++i) {
            // If current integer is not in the set, return it as the missing number
            if (!numSet.count(i + 1)) return i + 1;
        }

        // This is redundant as loop should already return the result
        return 1;
    }
};

// Using boolean array as a lookup table
// Time Complexity - O(n), Space Complexity - O(n), Auxiliary Space - O(n)
class Solution3 {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<bool> seen(n + 1, false);  // Array for lookup

        // Mark the elements from nums in the lookup array
        for (int num : nums) {
            if (num > 0 && num <= n) {
                seen[num] = true;
            }
        }

        // Iterate through integers 1 to n
        // return smallest missing positive integer
        for (int i = 1; i <= n; i++) {
            if (!seen[i]) {
                return i;
            }
        }

        // If seen contains all elements 1 to n
        // the smallest missing positive number is n + 1
        return n + 1;
    }
};

// Using index as a hash key and negative sign as a presence detector
// Time Complexity - O(n), Space Complexity - O(n), Auxiliary Space - O(1)
class Solution4 {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        bool contains1 = false;

        // Replace negative numbers, zeros,
        // and numbers larger than n with 1s.
        // After this nums contains only positive numbers.
        for (int i = 0; i < n; i++) {
            // Check whether 1 is in the original array
            if (nums[i] == 1) {
                contains1 = true;
            }
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = 1;
            }
        }

        if (!contains1) return 1;

        // Mark whether integers 1 to n are in nums
        // Use index as a hash key and negative sign as a presence detector.
        for (int i = 0; i < n; i++) {
            int value = abs(nums[i]);
            if (value == n) {
                nums[0] = -abs(nums[0]);
            } else {
                nums[value] = -abs(nums[value]);
            }
        }

        // First positive in nums is smallest missing positive integer
        for (int i = 1; i < n; i++) {
            if (nums[i] > 0) return i;
        }

        // nums[0] stores whether n is in nums
        if (nums[0] > 0) {
            return n;
        }

        // If nums contained all elements 1 to n
        // the smallest missing positive number is n + 1
        return n + 1;
    }
};

// MOST OPTIMAL SOLUTION
// Using cyclic sort - in place sorting algorithm, which becomes unstable for large n, but works for this problem
// Time Complexity - O(n), Space Complexity - O(n), Auxiliary Space - O(1)
class Solution5 {
   public:
    int firstMissingPositive(vector<int> &nums) {
        int n = (int)nums.size();

        // Step 1: Place each number in its correct position if possible
        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                // Swap nums[i] with the number at its correct position nums[nums[i] - 1]
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Step 2: Find the first missing positive
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        // If all numbers are in the correct positions, the missing number is n + 1
        return n + 1;
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
    auto ans = sol.firstMissingPositive(v);
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