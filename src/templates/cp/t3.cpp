//* OPTIMIZATIONS
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

//* TYPEDEFS {with 'using' keyword}
using uint = unsigned int;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using p32 = pair<int,int>;
using p64 = pair<ll,ll>;
using pdd = pair<double,double>;
using v64 = vector<ll>;
using v32 = vector<int>;
using vv32 = vector<vector<int>>;
using vv64 = vector<vector<ll>>;
using vvp64 = vector<vector<p64>>;
using vp64 = vector<p64>;
using vp32 = vector<p32>;
//* Built-in typedefs:
/*
int8_t // char
int16_t // short int
int32_t // int
int64_t // long
uint8_t // unsigned char
uint16_t // unsigned short int
uint32_t // unsigned int
uint64_t // unsigned long
*/


//* MACROS
// Predefined constants
#define MOD 1000000007
#define MOD1 998244353
#define eps 1e-12
#define INF 2e18
#define PI 3.141592653589793238462
#define imax numeric_limits<int>::max()
#define lmax numeric_limits<int64_t>::max()
#define llmax numeric_limits<ll>::max()
#define imin numeric_limits<int>::min()
#define lmin numeric_limits<int64_t>::min()
#define llmin numeric_limits<ll>::min()
// Other Macros
#define endl "\n"
// #define ln "\n"     //use in interactive problems
#define set_bits __builtin_popcount
#define set_bitsl __builtin_popcountl
#define set_bitsll __builtin_popcountll
#define getParity __builtin_parity
#define all(x) (x).begin(), (x).end()
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)


//! DEBUGGING ERRORS
//*/*----------------------------------*/*//

#ifdef LOCAL_PROJECT
#define debug(x) cerr << #x <<" = "; __print(x); cerr << endl
#else
#define debug(x)
#endif

// template <typename T>
// void __print(vector<T> v) {
//     cerr << "[ ";
//     for (T i : v) {
//         __print(i);
//         if (!(i == v(v.size()-1))) { cerr << ", "; }
//         cerr << " ";
//     }
//     cerr << " ]";
// }
// function-declarations
template <class T, class V> void __print(pair <T, V> p);
template <class T> void __print(vector <T> v);
template <class T> void __print(set <T> v);
template <class T, class V> void __print(map <T, V> v);
template <class T, class V> void __print(unordered_map <T, V> v);
template <class T> void __print(multiset <T> v);
template <typename T> void __print(T x);
// function implementations
template <typename T> void __print(T x) { cerr << x; }
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


//*/*----------------------------------*/*//


//* LAMBDAS


//* CUSTOM FUNCTIONS


//*/*-------- SOLUTIONS & CUSTOM FUNCTIONS --------*/*//


template<typename T>
T solution(T n) {
    return n;
}


template<typename T>
void solve(T n) {
}


//*/*-------- MAIN FUNCTION --------*/*//
int main() {
    fastIO();

    //todo: FILEIO
    #ifdef LOCAL_PROJECT
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
    #endif
    // #ifndef ONLINE_JUDGE
    // freopen("INPUT.txt", "r", stdin);
    // freopen("OUTPUT.txt", "w", stdout);
    // #endif
    //todo: DEBUGGING
    #ifdef LOCAL_PROJECT
    freopen("DEBUG.txt", "w", stderr);
    #endif

    // !! xxxxxxxx !! START FROM HERE !! xxxxxxxx !!
    //*/*--------- implementation code ---------*/*//

    int n;
    cin >> n;
    // double x;

    solve<int>(n);
    // solve<ll>(n);
    cout << solution<int>(n) << endl;
    // cout << solution<ll>(n) << endl;

    //! Debugging:
    debug(n);

    

    return 0;
}