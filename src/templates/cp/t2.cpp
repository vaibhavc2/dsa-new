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

//* MACROS
// Predefined constants
#define MOD 1000000007
#define MOD1 998244353
#define eps 1e-12
#define INF 2e18
#define PI 3.141592653589793238462
#define imax numeric_limits<int>::max()
#define imin numeric_limits<int>::min()
// Other Macros
#define ln "\n"
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fi first
#define se second
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


//! DEBUGGING ERRORS
//*/*----------------------------------*/*//

#ifdef DEBUG
#define debug(x) cerr << #x <<" = "; printErrors(x); cerr << ln
#else
#define debug(x)
#endif

template<typename T> void printErrors(T x)
{
    cerr << x;
}
template<typename T> void printErrors(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        printErrors(i);
        if (!(i == v(v.size()-1))) { cerr << ", "; }
        cerr << " ";
    }
    cerr << " ]";
}


//*/*----------------------------------*/*//


//* LAMBDAS


//* CUSTOM FUNCTIONS


//*/*-------- SOLUTIONS & CUSTOM FUNCTIONS --------*/*//


template<typename T>
T solution(T n) 
{
    return n;
}


template<typename T>
void solve()
{}


//*/*-------- MAIN FUNCTION --------*/*//
int main()
{
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
    #ifdef DEBUG
    freopen("DEBUG.txt", "w", stderr);
    #endif

    // !! xxxxxxxx !! START FROM HERE !! xxxxxxxx !!
    //*/*--------- implementation code ---------*/*//

    ll n;
    cin >> n;
    // double x;

    // solve<>();
    cout << solution<ll>(n) << ln;
    // cout << n << " " << "A" << ln;

    debug(n);

    return 0;
}