#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,abm,bmi,bmi2,mmx,avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define fastIO()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

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

// !! xxxxxxxx !! START FROM HERE !! xxxxxxxx !!
/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution {
   public:
    bool isPalindrome(string &s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (i < j && !isalnum(s[i])) ++i;
            while (i < j && !isalnum(s[j])) --j;

            if (tolower(s[i]) != tolower(s[j])) return false;

            ++i;
            --j;
        }
        return true;
    }
};
// @lc code=end

// Two pointer approach - 1
// Time complexity: O(n)
// Space complexity: O(1)
class Solution1 {
   public:
    bool isPalindrome(string &s) {
        // remove all non-alphanumeric characters
        string str = "";
        for (char c : s) {
            if (isalnum(c)) {
                str += tolower(c);
            }
        }

        int n = str.size() - 1;
        int j = n;
        for (int i = 0; i <= n; ++i) {
            if (str[i] == str[j--])
                continue;
            else
                return false;
        }

        return true;
    }
};

// Two pointer approach - 2
// Time complexity: O(n)
// Space complexity: O(1)
class Solution2 {
   public:
    bool isPalindrome(string &s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (i < j && !isalnum(s[i])) ++i;
            while (i < j && !isalnum(s[j])) --j;

            if (tolower(s[i]) != tolower(s[j])) return false;

            ++i;
            --j;
        }
        return true;
    }
};

// Recursive approach - unoptimized
// Time complexity: O(n)
// Space complexity: O(n)
class Solution3 {
   public:
    bool isPalindrome(string &s) {
        return checkPalindrome(s, 0, s.size() - 1);
    }

   private:
    bool checkPalindrome(const string &s, int i, int j) {
        // Base case: If pointers have crossed, we’re done
        if (i >= j) return true;

        // Move i forward if it's not alphanumeric
        if (!isalnum(s[i])) return checkPalindrome(s, i + 1, j);
        // Move j backward if it's not alphanumeric
        if (!isalnum(s[j])) return checkPalindrome(s, i, j - 1);

        // Compare characters at i and j (case-insensitively)
        if (tolower(s[i]) != tolower(s[j])) return false;

        // Recursive call for next characters
        return checkPalindrome(s, i + 1, j - 1);
    }
};

inline void solve() {
    // int n;
    // input(n);

    string s;
    string_input(s);

    // vector<int32_t> v(n);
    // array_input(v);

    // vector<string> vs(n);
    // string_array_input(vs);

    Solution sol;
    auto ans = sol.isPalindrome(s);
    if (ans)
        cout << "true" << endl;
    else
        cout << "false" << endl;
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