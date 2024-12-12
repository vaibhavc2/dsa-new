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

inline void input(int& n) {
    cin >> n;
}

inline void string_input(string& s) {
    getline(cin, s);
}

inline void array_input(vector<int32_t>& v) {
    for (int32_t i = 0; i < static_cast<int32_t>(v.size()); i++)
        cin >> v[i];
}

inline void string_array_input(vector<string>& v) {
    for (int32_t i = 0; i < static_cast<int32_t>(v.size()); i++)
        getline(cin, v[i]);
}
//*/*-------------- SOLUTION --------------*/*//
// !! xxxxxxxx !! START FROM HERE !! xxxxxxxx !!
/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
   public:
    int maxSubArray(vector<int>& nums) {}
};
// @lc code=end

//*/*-------------- SOLUTIONS --------------*/*//
// https://leetcode.com/problems/maximum-subarray/solutions/1595195/c-python-7-simple-solutions-w-explanation-brute-force-dp-kadane-divide-conquer

// Brute Force - TLE
// Time: O(n^2)
// Space: O(1)
class Solution1 {
   public:
    int maxSubArray(vector<int>& nums) {
        int n = size(nums), ans = INT_MIN;
        for (int i = 0; i < n; i++)
            for (int j = i, curSum = 0; j < n; j++)
                curSum += nums[j],
                    ans = max(ans, curSum);
        return ans;
    }
};

// Recursive Approach - TLE
// Time: O(n^2)
// Space: O(n)
class Solution2 {
   public:
    int maxSubArray(vector<int>& nums) {
        return solve(nums, 0, false);
    }
    int solve(vector<int>& A, int i, bool mustPick) {
        // our subarray must contain atleast 1 element. If mustPick is false at end means no element is picked and this is not valid case
        if (i >= size(A)) return mustPick ? 0 : -1e5;
        if (mustPick)
            return max(0, A[i] + solve(A, i + 1, true));                   // either stop here or choose current element and recurse
        return max(solve(A, i + 1, false), A[i] + solve(A, i + 1, true));  // try both choosing current element or not choosing
    }
};

// DP - Memoization
// Time: O(n)
// Space: O(n)
class Solution3 {
   public:
    int maxSubArray(vector<int>& nums) {
        vector<vector<int>> dp(2, vector<int>(size(nums), -1));
        return solve(nums, 0, false, dp);
    }
    int solve(vector<int>& A, int i, bool mustPick, vector<vector<int>>& dp) {
        if (i >= size(A)) return mustPick ? 0 : -1e5;
        if (dp[mustPick][i] != -1) return dp[mustPick][i];
        if (mustPick)
            return dp[mustPick][i] = max(0, A[i] + solve(A, i + 1, true, dp));
        return dp[mustPick][i] = max(solve(A, i + 1, false, dp), A[i] + solve(A, i + 1, true, dp));
    }
};

// DP - Tabulation
// Time: O(n)
// Space: O(n)
class Solution4 {
   public:
    int maxSubArray(vector<int>& nums) {
        vector<vector<int>> dp(2, vector<int>(size(nums)));
        dp[0][0] = dp[1][0] = nums[0];
        for (int i = 1; i < size(nums); i++) {
            dp[1][i] = max(nums[i], nums[i] + dp[1][i - 1]);
            dp[0][i] = max(dp[0][i - 1], dp[1][i]);
        }
        return dp[0].back();
    }
};

// Kadane's Algorithm - Approach 1
// Time: O(n)
// Space: O(1)
class Solution5 {
   public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int sum = nums[0];
        vector<int> sums = {sum};

        for (int i = 1; i < n; ++i) {
            sum += nums[i];
            if (sum <= nums[i]) {
                sum = nums[i];
            }
            sums.emplace_back(sum);
        }

        return *max_element(sums.begin(), sums.end());
    }
};

// Kadane's Algorithm - Most efficient and optimized
// Time: O(n)
// Space: O(1)
class Solution6 {
   public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = 0;
        int maxSum = INT_MIN;

        for (auto& num : nums) {
            currentSum = max(num, currentSum + num);
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};

// Divide and Conquer
// Time: O(nlogn)
// Space: O(logn)
class Solution7 {
   public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums, 0, size(nums) - 1);
    }
    int maxSubArray(vector<int>& A, int L, int R) {
        if (L > R) return INT_MIN;
        int mid = (L + R) / 2, leftSum = 0, rightSum = 0;
        // leftSum = max subarray sum in [L, mid-1] and starting from mid-1
        for (int i = mid - 1, curSum = 0; i >= L; i--)
            curSum += A[i],
                leftSum = max(leftSum, curSum);
        // rightSum = max subarray sum in [mid+1, R] and starting from mid+1
        for (int i = mid + 1, curSum = 0; i <= R; i++)
            curSum += A[i],
                rightSum = max(rightSum, curSum);
        // return max of 3 cases
        return max({maxSubArray(A, L, mid - 1), maxSubArray(A, mid + 1, R), leftSum + A[mid] + rightSum});
    }
};

// Divide and Conquer - Optimized
// Time: O(n)
// Space: O(n)
class Solution8 {
   public:
    vector<int> pre, suf;
    int maxSubArray(vector<int>& nums) {
        pre = suf = nums;
        for (int i = 1; i < size(nums); i++) pre[i] += max(0, pre[i - 1]);
        for (int i = size(nums) - 2; ~i; i--) suf[i] += max(0, suf[i + 1]);
        return maxSubArray(nums, 0, size(nums) - 1);
    }
    int maxSubArray(vector<int>& A, int L, int R) {
        if (L == R) return A[L];
        int mid = (L + R) / 2;
        return max({maxSubArray(A, L, mid), maxSubArray(A, mid + 1, R), pre[mid] + suf[mid + 1]});
    }
};

// Divide and Conquer - Optimized and Converted to Iterative
// Time: O(n)
// Space: O(n)
class Solution9 {
   public:
    int maxSubArray(vector<int>& nums) {
        vector<int> pre = nums;
        for (int i = 1; i < size(nums); i++) pre[i] += max(0, pre[i - 1]);
        return *max_element(begin(pre), end(pre));
    }
};

//*/*-------------- SOLUTIONS --------------*/*//

inline void solve() {
    int n;
    input(n);

    // string s;
    // string_input(s);

    vector<int32_t> v(n);
    array_input(v);

    // vector<string> vs(n);
    // string_array_input(vs);

    Solution sol;
    auto ans = sol.maxSubArray(v);
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