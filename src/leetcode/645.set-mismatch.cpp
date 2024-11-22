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
 * @lc app=leetcode id=645 lang=cpp
 *
 * [645] Set Mismatch
 */

// @lc code=start
class Solution {
   public:
    vector<int> findErrorNums(vector<int> &nums) {}
};
// @lc code=end

//*/*-------------- SOLUTIONS --------------*/*//

// using unordered_map
// Time: O(n)
// Space: O(n)
class Solution1 {
   public:
    vector<int> findErrorNums(vector<int> &nums) {
        unordered_map<int, int> mp;
        vector<int> res(2, 0);

        for (auto &num : nums) {
            mp[num]++;
            if (mp[num] == 2) res[0] = num;
        }

        for (int i = 1; i <= (int)(size(nums)); ++i) {
            if (mp[i] == 0) {
                res[1] = i;
                break;
            }
        }

        return res;
    }
};

// using unordered_set
// Time: O(n)
// Space: O(n)
class Solution2 {
   public:
    vector<int> findErrorNums(vector<int> &nums) {
        unordered_set<int> uniqueNums;
        vector<int> res;

        for (auto &num : nums) {
            if (uniqueNums.count(num)) {
                res.push_back(num);
            }
            uniqueNums.insert(num);
        }

        for (int num = 1; num <= nums.size(); num++) {
            if (!uniqueNums.count(num)) res.push_back(num);
        }

        return res;
    }
};

// using frequency array - OPTIMIZED (except for space complexity)
// Time: O(n)
// Space: O(n)
class Solution3 {
   public:
    vector<int> findErrorNums(vector<int> &nums) {
        int n = (int)(size(nums));
        vector<int> res(2, 0), freq(n + 1);

        for (auto &num : nums) {
            freq[num]++;
            if (freq[num] == 2) res[0] = num;
        }

        for (int i = 1; i <= n; ++i) {
            if (freq[i] == 0) {
                res[1] = i;
                break;
            }
        }

        return res;
    }
};

// using XOR
// Time: O(n)
// Space: O(1)
class Solution4 {
   public:
    vector<int> findErrorNums(vector<int> &nums) {
        int n = nums.size();
        int xorAll = 0;
        int xorArray = 0;

        for (int i = 1; i <= n; i++) {
            xorAll ^= i;
        }

        for (int num : nums) {
            xorArray ^= num;
        }

        int xorResult = xorArray ^ xorAll;

        int rightmostSetBit = xorResult & -xorResult;

        int xorSet = 0;
        int xorNotSet = 0;

        for (int i = 1; i <= n; i++) {
            if (i & rightmostSetBit) {
                xorSet ^= i;
            } else {
                xorNotSet ^= i;
            }
        }

        for (int num : nums) {
            if (num & rightmostSetBit) {
                xorSet ^= num;
            } else {
                xorNotSet ^= num;
            }
        }

        for (int num : nums) {
            if (num == xorSet) {
                return {xorSet, xorNotSet};
            }
        }

        return {xorNotSet, xorSet};
    }
};

// using sum to find duplicate and missing - with set
// Time: O(n)
// Space: O(n)
class Solution5 {
   public:
    vector<int> findErrorNums(vector<int> &nums) {
        int n = nums.size();  // Number of elements in the array

        // Calculate actual sum
        int actual_sum = accumulate(nums.begin(), nums.end(), 0);

        // Calculate unique sum
        unordered_set<int> unique_nums(nums.begin(), nums.end());
        int unique_sum = accumulate(unique_nums.begin(), unique_nums.end(), 0);

        // Calculate expected sum
        int expected_sum = n * (n + 1) / 2;

        // Calculate duplicate and missing
        int duplicate = actual_sum - unique_sum;
        int missing = expected_sum - unique_sum;

        return {duplicate, missing};
    }
};

// using sum to find duplicate and missing - MOST OPTIMIZED - in-place modification
// Time: O(n)
// Space: O(1)
class Solution6 {
   public:
    vector<int> findErrorNums(vector<int> &nums) {
        int n = (int)nums.size();
        int expectedSum = n * (n + 1) / 2;
        int actualSum = 0, uniqueSum = 0;

        int idx;
        for (int i = 0; i < n; ++i) {
            idx = abs(nums[i]) - 1;
            actualSum += abs(nums[i]);

            if (nums[idx] > 0) {
                uniqueSum += abs(nums[i]);
                nums[idx] = -nums[idx];
            }
        }

        int duplicate = actualSum - uniqueSum;
        int missing = expectedSum - uniqueSum;

        return {duplicate, missing};
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
    auto ans = sol.findErrorNums(v);
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