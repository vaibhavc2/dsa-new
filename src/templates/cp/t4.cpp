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
#define getParity __builtin_parity // 1 - odd no. of setbits, 0 - even no. of setbits
#define all(x) (x).begin(), (x).end()
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)


//! DEBUGGING ERRORS
//*/*----------------------------------*/*//
namespace Color {
    enum Code { FG_RED = 31,FG_GREEN = 32,FG_BLUE = 34,FG_DEFAULT  = 39,BG_RED = 41,BG_GREEN = 42,BG_BLUE= 44,BG_DEFAULT = 49 };
    class Modifier {
        Code code;
    public:
        Modifier(Code pCode) : code(pCode) {}
        friend std::ostream&
        operator<<(std::ostream& os, const Modifier& mod) {return os << "\033[" << mod.code << "m"; }
    };
}
auto debugger = [](){
    #ifdef DEBUG
    #define dbg(x) {Color::Modifier red(Color::FG_RED); Color::Modifier def(Color::FG_DEFAULT); int recur_depth = 0;++recur_depth; auto x_=x; --recur_depth; cerr<<string(recur_depth, '\t')<<red<<__func__<<":"<<__LINE__<<"\t"<<#x<<" = "<<x_<<def<<endl;}
    #else
    #define dbg(x)
    #endif
};
//* Operator overloading for dbg(x)
template<typename Ostream, typename Cont>
typename enable_if<is_same<Ostream,ostream>::value, Ostream&>::type operator<<(Ostream& os,  const Cont& v){
	os<<"[";
	for(auto& x:v){os<<x<<", ";}
	return os<<"]";
}
template<typename Ostream, typename ...Ts>
Ostream& operator<<(Ostream& os,  const pair<Ts...>& p){
	return os<<"{"<<p.first<<", "<<p.second<<"}";
}

//*/*----------------------------------*/*//

// Lambda expression (or function) for INPUT-OUTPUT to file
auto fileIO = [](){
    #ifdef LOCAL_PROJECT // or, ONLINE_JUDGE
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
    #endif
};


//*/*-------- SOLUTIONS & CUSTOM FUNCTIONS --------*/*//


template<typename T>
T solution(T n) {
    return n;
}


template<typename T>
void solve(T n) {
    cout << n << endl;
    dbg(n);
}


//*/*-------- MAIN FUNCTION --------*/*//
int main() {
    fastIO();
    fileIO();
    debugger();

    // !! xxxxxxxx !! START FROM HERE !! xxxxxxxx !!
    //*/*--------- implementation code ---------*/*//
    /* int8_t // char
    int16_t // short int
    int32_t // int
    int64_t // long
    uint8_t // unsigned char
    uint16_t // unsigned short int
    uint32_t // unsigned int
    uint64_t // unsigned long */

    // if(std::is_same<decltype(sol.solve()), void>::value) sol.solve();

    return 0;
}