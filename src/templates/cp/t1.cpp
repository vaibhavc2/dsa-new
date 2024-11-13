//* OPTIMIZATIONS
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

//* DEBUGGING
#ifdef DEBUG
#define debug(x) cerr << #x <<" = "<< x << "\n"
#else
#define debug(x)
#endif

#include <bits/stdc++.h>
using namespace std;

//* TYPEDEFS
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;

//* GLOBAL VARIABLES
ll MOD = 998244353;
double eps = 1e-12;

//* MACROS
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
// #define mp make_pair
// #define pb push_back
// #define fi first
// #define se second
// #define INF 2e18
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define FASTCIN() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

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
    FASTCIN();

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