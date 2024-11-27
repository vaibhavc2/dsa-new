#ifndef DEBUG
#ifndef DEBUG
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,abm,bmi,bmi2,mmx,avx,avx2,fma")
#endif
#endif

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int _MOD = 998244353;
const double EPS = 1e-9;
const long long INF = 2e18;
const int mxN = 2e5+5;
#define PI (4 * atan(1))
#define db_precision numeric_limits<double>::digits10 + 1
#define DOUBLE() cout.precision(db_precision); cout << fixed
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d) for (auto blockTime = make_pair(chrono::high_resolution_clock::now(), true); blockTime.second; debug("\n%s: %ld ms\n", d, chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - blockTime.first).count()), blockTime.second = false)

constexpr auto fileIO = [](){
    #ifdef LOCAL_PROJECT // or, ONLINE_JUDGE
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
    #endif
};

//*/*-------------- SOLUTION --------------*/*//
// !! xxxxxxxx !! START FROM HERE !! xxxxxxxx !!

constexpr const bool INPUT_TESTCASE_NUMBER = 0;


class Solution {
public:
    int solve() {
        return -1;
    }
};


// !! xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx !!
// ****************************************** //

inline void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    Solution sol;
    auto ans = sol.solve();
    cout << ans << "\n";
    // for (size_t i=0; i < ans.size(); i++) cout << ans[i] << " ";
    // cout << endl;
    // cout << "\n" << flush;
}

int main() {
    #ifndef DEBUG
    fastIO();
    #endif
    fileIO();
    DOUBLE();

    long long t = 1;
    if(INPUT_TESTCASE_NUMBER) cin >> t;

    #ifndef DEBUG
    time__("Time") { while(t--) solve(); }
    #else
    while(t--) solve();
    #endif

    return 0;
}