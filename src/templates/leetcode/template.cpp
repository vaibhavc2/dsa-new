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

template <typename T>
T parse_token(stringstream &ss, char delimiter = ' ') {
    string token;
    if (!getline(ss, token, delimiter)) {
        throw runtime_error("Failed to parse token");
    }
    stringstream value_stream(token);
    T value;
    value_stream >> value;
    if (value_stream.fail()) {
        throw invalid_argument("Invalid type conversion");
    }
    return value;
}

template <typename T>
vector<T> parse_array(stringstream &ss, char open_bracket = '[', char close_bracket = ']', char delimiter = ',') {
    vector<T> result;
    char ch;

    ss >> ch;
    if (ch != open_bracket) throw invalid_argument("Invalid array format");

    while (true) {
        if (ss.peek() == close_bracket) {
            ss.get();
            break;
        }
        result.push_back(parse_token<T>(ss, delimiter));
        if (ss.peek() == delimiter) ss.get();
    }

    return result;
}

template <typename T>
vector<vector<T>> parse_nested_array(stringstream &ss, char open_bracket = '[', char close_bracket = ']', char delimiter = ',') {
    vector<vector<T>> result;
    char ch;

    ss >> ch;
    if (ch != open_bracket) throw invalid_argument("Invalid nested array format");

    while (true) {
        if (ss.peek() == close_bracket) {
            ss.get();
            break;
        }
        result.push_back(parse_array<T>(ss, open_bracket, close_bracket, delimiter));
        if (ss.peek() == delimiter) ss.get();
    }

    return result;
}

template <typename T>
struct is_vector : std::false_type {};

template <typename T, typename Alloc>
struct is_vector<std::vector<T, Alloc>> : std::true_type {};

template <typename T>
inline constexpr bool is_vector_v = is_vector<T>::value;

// Updated parse_single_input function
template <typename T>
void parse_single_input(std::stringstream &ss, T &var) {
    if constexpr (is_vector_v<T>) {
        using ValueType = typename T::value_type;
        if constexpr (is_vector_v<ValueType>) {
            // T is a vector of vectors
            var = parse_nested_array<ValueType>(ss);
        } else {
            // T is a vector
            var = parse_array<ValueType>(ss);
        }
    } else {
        // T is a scalar type
        ss >> var;
    }
}

template <typename T>
vector<T> parse_space_separated_array(stringstream &ss) {
    vector<T> result;
    T value;
    while (ss >> value) {
        result.push_back(value);
    }
    return result;
}

template <typename... Args>
void parse_input(stringstream &ss, Args &...args) {
    (parse_single_input(ss, args), ...);
}

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

    // string line;
    // getline(cin, line);
    // stringstream ss(line);
    // parse_input(ss, v, k);

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