#include <bits/stdc++.h>
using namespace std;

#define int long long

/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
class Solution {
   public:
    int fib(int n) {
    }
};
// @lc code=end


//*/*-------------- SOLUTIONS --------------*/*//

// Recursive solution
// Time complexity: O(2^n)
// Space complexity: O(n)
class Solution1 {
   public:
    int fib(int n) {
        if (n == 0 || n == 1)
            return n;
        else {
            return fib(n - 1) + fib(n - 2);
        }
    }
};

// Iterative solution
// Time complexity: O(n)
// Space complexity: O(1)
class Solution2 {
   public:
    int fib(int n) {
        if (n == 0 || n == 1)
            return n;
        int a = 0, b = 1, res = 0;
        for (int i = 2; i <= n; i++) {
            res = a + b;
            a = b;
            b = res;
        }
        return res;
    }
};

// DP - Tabulation (Bottom-up)
// Time complexity: O(n)
// Space complexity: O(n)
class Solution3 {
   public:
    int fib(int n) {
        if (n == 0 || n == 1)
            return n;

        // n+1 because we need to store the 0th index as well
        int dp[n + 1];
        dp[0] = 0, dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

// DP - Memoization (Top-down)
// Time complexity: O(n)
// Space complexity: O(n)
class Solution4 {
    static vector<int> dp;

   public:
    Solution4() {
        if (dp.empty()) {
            // Initialize the dp vector with -1, so that we can check if the value is already calculated or not
            dp.resize(100, -1);  // 31 if dealing with n <= 30 (because of integer overflow)
        }
    }

    int fib(int n) {
        if (n <= 1) {
            return n;
        }

        // Check if result is already computed
        if (dp[n] != -1) {
            return dp[n];
        }

        // Compute and store the result
        return dp[n] = fib(n - 1) + fib(n - 2);
    }
};
// Initialize the static member of the class
vector<int> Solution4::dp;

// Matrix Exponentiation
// Time complexity: O(logn)
// Space complexity: O(1)
/**
 * // exponentation
a^x can be calulated in logn as follows
        a^x = a^(x/2) * a^(x/2)       ..... if x is even
        a^x = a^(x/2) * a^(x/2) * a   ..... if x is odd
// matrix exponentation
any general recursive reln can be represented as
                M * currentState = nextState    (M is a matrix , we currently dont know)
fibbo relation ->  f(n) = f(n-1) + f(n-2)   and f(0)=0 and f(1) = 1
so we have f(0) and f(1) [i.e. 2 states] hence M would be of 2 X 2

                | a  b |  *  | f(n-1) |  =  | f(n)  |
                | c  d |     | f(n-2) |     | f(n-1)|

i.e.       M    *  currentState  =  nextState

now lets calulate M

        a*f(n-1) + b*f(n-2) = f(n)
        c*f(n-1) + d*f(n-2) = f(n-1)
        a=1, b=1, c=1, d=0

        lets calulate for f(2)
        | 1  1 |  *  | f(1) |  =  | f(2) |
        | 1  0 |     | f(0) |     | f(1) |

        lets calulate for f(3)
        | 1  1 |  *  | f(2) |  =  | f(3) |
        | 1  0 |     | f(1) |     | f(2) |

        ie

        | 1  1 |  *  | 1 1 | * | f(1) |  =  | f(3) |
        | 1  0 |     | 1 0 |   | f(0) |     | f(2) |

        ie
        for general n
        M^(n-1) * | f(1) |  =  | f(n)   |
                          | f(0) |     | f(n-1) |

        how to find M^(n-1) ? use  exponentation !

        let A = M^(n-1) ;

        then f(n) = A[0][0] * f(1) + A[0][1] * f(0)
                 f(n) = A[0][0]   //   f(0) = 0 and f(1) = 1
 */
class Solution5 {
    void multiply(vector<vector<int>> &M, vector<vector<int>> &A) {
        int M11 = M[0][0] * A[0][0] + M[0][1] * A[1][0];
        int M12 = M[0][0] * A[0][1] + M[0][1] * A[1][1];
        int M21 = M[1][0] * A[0][0] + M[1][1] * A[1][0];
        int M22 = M[1][0] * A[0][1] + M[1][1] * A[1][1];

        M[0][0] = M11, M[0][1] = M12, M[1][0] = M21, M[1][1] = M22;
    }
    void power(vector<vector<int>> &M, int k) {
        if (k == 0 or k == 1)
            return;
        power(M, k / 2);
        multiply(M, M);
        if (k & 1) {
            vector<vector<int>> A{{1, 1}, {1, 0}};
            multiply(M, A);
        }
    }

   public:
    int fib(int n) {
        if (n == 0)
            return 0;
        vector<vector<int>> M{{1, 1}, {1, 0}};
        power(M, n - 1);
        return M[0][0];
    }
};

//*/*-------------- SOLUTIONS --------------*/*//



inline void solve() {
    int n;
    cin >> n;
    Solution sol;
    auto ans = sol.fib(n);
    cout << ans << "\n";
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
