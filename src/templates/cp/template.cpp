// #define INTERACTIVE_PROBLEM
// #define INT_TO_LONG_LONG

// ---------- CP SETUP ---------- //
#ifndef DEBUG
#ifndef DEBUG
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,abm,bmi,bmi2,mmx,avx,avx2,fma")
#endif
#endif

#define CP_INCLUDES
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

#ifdef INT_TO_LONG_LONG
#define int long long
#endif
#define umap unordered_map
#define char unsigned char
using ui = unsigned int;
using ul = unsigned long;
using ll = long long;
using db = double;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<db,db>;
using vi = vector<int>;
using si = set<int>;
using sll = set<ll>;
using sch = set<char>;
using useti = unordered_set<int>;
using usetch = unordered_set<char>;
using usetll = unordered_set<ll>;
using vdb = vector<db>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vvpll = vector<vector<pll>>;
using vvpii = vector<vector<pii>>;
using vpll = vector<pll>;
using vpii = vector<pii>;
using vch = vector<char>;
using vstr = vector<string>;
using umapchi = umap<char, int>;
using umapii = umap<int, int>;
using mapii = map<int, int>;
using mapchi = map<char, int>;

// 'policy-based' DS (https://goo.gl/WVDL6g)
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using ordered_set_pair = tree< pair<T, T>, null_type, less<pair<T, T>>, rb_tree_tag, tree_order_statistics_node_update>;

#define MOD ((int) 1e9+7)
#define MOD2 ((int) 998244353)
#define EPS ((db) 1e-9)
#define INFll ((ll) 2e18)
#define negINFll ((ll) -2e18)
#define INFi ((int) 1e9+10)
#define negINFi ((int) -1e9-10)
#define mxN ((int) 2e5+5)
#define PI ((ld)(4 * atan(1)))
// #define PI std::numbers::pi // c++20

using a32 = array<int,mxN>;
using a64 = array<ll,mxN>;

#define ln '\n'
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fo(i,a,b) for(int i=a; i<=b; i++)
#define rev(i,a,b) for(int i=a; i>=b; i--)
#define fon(i,n) for(int i=0; i<n; i++)
#define revn(i,n) for(int i=n-1; i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sorta(v) sort((v).begin(),(v).end())
#define sortd(v) sort((v).begin(),(v).end(),greater<int>())
#define sortall(x) sorta(x)
#define sz(a) ((int)(a.size()))
#define one(x) memset(x,1,sizeof(x))
#define clr(x) memset(x, 0, sizeof(x))
#define imax numeric_limits<int32_t>::max()
#define lmax numeric_limits<int64_t>::max()
#define llmax numeric_limits<ll>::max()
#define imin numeric_limits<int32_t>::min()
#define lmin numeric_limits<int64_t>::min()
#define llmin numeric_limits<ll>::min()
#define db_precision numeric_limits<db>::digits10 + 1
#define ld_precision numeric_limits<ld>::digits10 + 1
#define set_bits __builtin_popcount
#define set_bitsl __builtin_popcountl
#define set_bitsll __builtin_popcountll
#define set_bits_parity __builtin_parity // 1 - odd no. of setbits, 0 - even no. of setbits
#define count_leading_zeros __builtin_clz
#define count_trailing_zeros __builtin_ctz
#define haveSameDataType(a, b) (typeid(a) == typeid(b))
#define checkParity(x) (x&1) //check even or odd
#define isOdd(x) ((x&1)? 1:0)
#define isEven(x) ((x&1)? 0:1)
#define equalityFloat(x,y) ((abs(x-y) < EPS)? true:false)
#define floatEquality(x,y) ((abs(x-y) < EPS)? true:false)
#define doubleEquality(x,y) ((abs(x-y) < EPS)? true:false)
#define DOUBLE() cout.precision(db_precision); cout << fixed; cerr.precision(db_precision); cerr << fixed
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
// use mt19937_64 for 64-bit numbers
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// use to calculate time of a piece of code: time__("Time Taken for solve") { while(t--) solve(); }
#define time__(d) for (auto blockTime = make_pair(chrono::high_resolution_clock::now(), true); blockTime.second; debug("\n%s: %ld ms\n", d, chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - blockTime.first).count()), blockTime.second = false)
constexpr auto fileIO = [](){
    #ifdef LOCAL_PROJECT // or, ONLINE_JUDGE
    (void)!freopen("INPUT.txt", "r", stdin);
    (void)!freopen("OUTPUT.txt", "w", stdout);
    #endif
};
#ifndef INTERACTIVE_PROBLEM
    #ifndef DEBUG
        #define endl '\n'
    #endif
    #define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr)
#else
    #define fastIO() ;
#endif
inline void dbg(string& str) { cerr << str << endl; }
template<typename T> constexpr void dbg(T x) { cerr << x << endl; }
template<typename T1, typename T2> constexpr void dbg(T1 x, T2 y) { cerr << x << " " << y << endl; }
template<typename T1, typename T2, typename T3> constexpr void dbg(T1 x, T2 y, T3 z) { cerr << x << " " << y << " " << z << endl; }
template<typename T> constexpr void dbg(pair<T,T>& p) { cerr << p.first << " " << p.second << endl; }
template<typename T> constexpr void dbg(vector<T>& arr) { auto n = arr.size(); auto i = n; i = 0; while(n--) cerr << arr[i++] << " "; cerr << endl; }
template<typename T> constexpr void dbg(array<T,mxN>& arr, int n) { int i = 0; while(n--) cerr << arr[i++] << " "; cerr << endl; }
template<typename T> constexpr void dbg(T* arr, int n) { int i = 0; while(n--) cerr << arr[i++] << " "; cerr << endl; }
template<typename T> constexpr void dbg(set<T>& s) { auto n = s.size(); auto i = n; i = 0; while(n--) cerr << *(next(s.begin(),i++)) << " "; cerr << endl; }
template<typename T> constexpr void dbg(list<T>& l) { auto n = l.size(); auto i = n; i = 0; while(n--) cerr << *(next(l.begin(),i++)) << " "; cerr << endl; }
template<typename T> constexpr void dbg(queue<T> q) { while (!q.empty()) { cerr << q.front() << " "; q.pop(); } cerr << endl; }
template<typename T> constexpr void dbg(deque<T>& dq) { auto n = dq.size(); auto i = n; i = 0; while(n--) cerr << *(next(dq.begin(),i++)) << " "; cerr << endl; }
inline void prt(string& str) { cout << str << endl; }
template<typename T> constexpr void prt(T x) { cout << x << endl; }
template<typename T1, typename T2> constexpr void prt(T1 x, T2 y) { cout << x << " " << y << endl; }
template<typename T1, typename T2, typename T3> constexpr void prt(T1 x, T2 y, T3 z) { cout << x << " " << y << " " << z << endl; }
template<typename T> constexpr void prt(pair<T,T>& p) { cout << p.first << " " << p.second << endl; }
template<typename T> constexpr void prt(vector<T>& arr) { auto n = arr.size(); auto i = n; i = 0; while(n--) cout << arr[i++] << " "; cout << endl; }
template<typename T> constexpr void prt(array<T,mxN>& arr, int n) { int i = 0; while(n--) cout << arr[i++] << " "; cout << endl; }
template<typename T> constexpr void prt(T* arr, int n) { int i = 0; while(n--) cout << arr[i++] << " "; cout << endl; }
template<typename T> constexpr void prt(set<T>& s) { auto n = s.size(); auto i = n; i = 0; while(n--) cout << *(next(s.begin(),i++)) << " "; cout << endl; }
template<typename T> constexpr void prt(list<T>& l) { auto n = l.size(); auto i = n; i = 0; while(n--) cout << *(next(l.begin(),i++)) << " "; cout << endl; }
template<typename T> constexpr void prt(queue<T> q) { while (!q.empty()) { cout << q.front() << " "; q.pop(); } cout << endl; }
template<typename T> constexpr void prt(deque<T>& dq) { auto n = dq.size(); auto i = n; i = 0; while(n--) cout << *(next(dq.begin(),i++)) << " "; cout << endl; }
template<typename T> constexpr void inp(vector<T>& v) { for (ul i = 0; i < v.size(); i++) { cin >> v[i]; } }
template<typename T> constexpr void inp(array<T,mxN>& arr, int n) { for (int i = 0; i < n; i++) { cin >> arr[i]; } }
template<typename T> constexpr void inp(T* arr, int n) { for (int i = 0; i < n; i++) { cin >> arr[i]; } }
template<typename T> constexpr bool isPrime(T n) { if(n <= 1) return 0; else if(n <= 2) return 1; if(n % 2 == 0 || n % 3 == 0)return 0; for (int i = 5; i * i <= n; i += 6) { if(n % i == 0 || n % (i + 2) == 0) return 0; } return 1; }
template<typename T> inline int linearSearch(T* arr, int size, T key) { for (int i = 0; i < size; i++) { if(arr[i] == key) return i; } return -1; }
template<typename T> inline int linearSearch(vector<T>& vt, T key) { for (size_t i = 0; i < vt.size(); i++) { if(vt[i] == key) return i; } return -1; }
template<typename T> inline T binarySearch(vector<T>& v, T key) { ll s = 0; ll e = v.size()-1; while(s <= e) { ll mid = s - (s - e) / 2; if (v[mid] == key) return mid; else if (v[mid] > key) e = mid - 1; else s = mid + 1; } return -1; }
template<typename T> inline T binarySearch(T* arr, int size, int key) { ll s = 0; ll e = size-1; while(s <= e) { ll mid = s - (s - e) / 2; if (arr[mid] == key) return mid; else if (arr[mid] > key) e = mid - 1; else s = mid + 1; } return -1; }
inline ll binarySearch(string& str, char key) { ll s = 0; ll e = str.size()-1; while(s <= e) { ll mid = s - (s - e) / 2; if (str[mid] == key) return mid; else if (str[mid] > key) e = mid - 1; else s = mid + 1; } return -1; }
template<typename T> inline T reverseNum(T n) { T x, cnt, rem; x = cnt = 0; while (n) { rem = n % 10; x = x * 10 + rem; n /= 10; } return x; }
template<typename T> inline T expo(T a, T b, T mod) {T res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
template<typename T> inline void extendgcd(T a, T b, T*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); T x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
template<typename T> inline T mminv(T a, T b) {T arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
template<typename T> inline T mminvprime(T a, T b) {return expo(a, b - 2, b);}
template<typename T> inline T mod_add(T a, T b, T m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
template<typename T> inline T mod_mul(T a, T b, T m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
template<typename T> inline T mod_sub(T a, T b, T m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
template<typename T> inline T mod_div(T a, T b, T m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}
template<typename T> constexpr T getRandomNumber(T l, T r) { return uniform_int_distribution<T>(l, r)(rng); }
#define YES() { cout << "YES" << endl; return; }
#define NO() { cout << "NO" << endl; return; }
//*/*-------------- SOLUTION --------------*/*//
// !! xxxxxxxx !! START FROM HERE !! xxxxxxxx !!

// #define M() { cout << "Marichka" << endl;return; }
// #define Z() { cout << "Zenyk" << endl;return; }

inline auto sort_desc = [](auto &vec) { sort(all(vec), greater<>()); };

constexpr const bool INPUT_TESTCASE_NUMBER = 1;

#define N ((int) 2e5+5)
// int a[N], b[N];
int n;

inline void solve() {
    cin >> n;
}

// !! xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx !!
//*/*----------- MAIN FUNCTION -----------*/*//

int32_t main() {
    fileIO();
#ifndef DEBUG
    fastIO();
#endif
    DOUBLE();

    ll t = 1;
    if(INPUT_TESTCASE_NUMBER) cin >> t;
    while(t--) solve();

#ifdef LOCAL_PROJECT
    cerr << setprecision(2) << "\nTime elapsed: " << (1000.0 * (db)clock() / (db)CLOCKS_PER_SEC) << " ms.\n";
#endif

    return 0;
}
