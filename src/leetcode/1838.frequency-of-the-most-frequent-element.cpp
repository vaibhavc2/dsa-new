// ---------- CP SETUP ---------- //
#ifndef DEBUG
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,abm,bmi,bmi2,mmx,avx,avx2,fma")
#endif

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

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
 * @lc app=leetcode id=1838 lang=cpp
 *
 * [1838] Frequency of the Most Frequent Element
 */

// @lc code=start
using ll = long long;
class Solution {
   public:
    int maxFrequency(vector<int> &nums, int k) {}
};
// @lc code=end

//*/*-------------- SOLUTIONS --------------*/*//

class Solution1 {
   public:
    int maxFrequency(vector<int> &nums, int k) {
        sort(begin(nums), end(nums));

        int l = 0, n = (int)nums.size();
        ll res = 1, sum = 0;

        for (int r = 0; r < n; ++r) {
            sum += nums[r];

            while ((ll)(r - l + 1) * nums[r] - sum > (ll)k)
                sum -= nums[l++];

            res = max(res, (ll)r - l + 1);
        }

        return res;
    }
};

class Solution2 {
   public:
    int maxFrequency(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = 0;
        ll res = 0, total = 0;

        while (right < (int)nums.size()) {
            total += nums[right];

            while (nums[right] * (ll)(right - left + 1) > total + k) {
                total -= nums[left];
                left += 1;
            }

            res = max(res, (ll)(right - left + 1));
            right += 1;
        }

        return (ll)res;
    }
};

class Solution3 {
   public:
    int maxFrequency(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());

        int l = 0, n = (int)nums.size();
        ll curr = 0;

        for (int r = 0; r < n; r++) {
            ll target = nums[r];
            curr += target;

            if ((r - l + 1) * target - curr > k) {
                curr -= nums[l];
                l++;
            }
        }

        return n - l;
    }
};

class Solution4 {
   public:
    int check(int i, int k, vector<int> &nums, vector<ll> &prefix) {
        int target = nums[i];
        int left = 0;
        int right = i;
        int best = i;

        while (left <= right) {
            int mid = (left + right) / 2;
            ll count = i - mid + 1;
            ll finalSum = count * target;
            int originalSum = prefix[i] - prefix[mid] + nums[mid];
            int operationsRequired = finalSum - originalSum;

            if (operationsRequired > k) {
                left = mid + 1;
            } else {
                best = mid;
                right = mid - 1;
            }
        }

        return i - best + 1;
    }

    int maxFrequency(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        vector<ll> prefix;
        prefix.push_back(nums[0]);
        int n = (int)nums.size();

        for (int i = 1; i < n; i++) {
            prefix.push_back(nums[i] + prefix.back());
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, check(i, k, nums, prefix));
        }

        return ans;
    }
};

//*/*-------------- SOLUTIONS --------------*/*//

inline void solve() {
    int n, k;
    input(n);

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    input(k);

    Solution sol;
    auto ans = sol.maxFrequency(v, k);
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