// ---------- CP SETUP ---------- //
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define cerr cerr << "ERROR :: "

#define db_precision numeric_limits<double>::digits10 + 1
#define DOUBLE()                  \
    cout.precision(db_precision); \
    cout << fixed

// ************* IO Implementations *************

template <typename T>
inline void _print(const T &x) {
    cout << x;
}

template <typename T, typename V>
inline void _print(const pair<T, V> &p) {
    cout << "{ ";
    _print(p.first);
    cout << ", ";
    _print(p.second);
    cout << " }";
}

template <typename T>
inline void _print(const vector<T> &v) {
    cout << "{ ";
    for (size_t i = 0; i < v.size(); ++i) {
        _print(v[i]);
        if (i + 1 != v.size()) cout << ", ";
    }
    cout << " }";
}

template <typename T>
inline void _print(const deque<T> &d) {
    cout << "{ ";
    for (size_t i = 0; i < d.size(); ++i) {
        _print(d[i]);
        if (i + 1 != d.size()) cout << ", ";
    }
    cout << " }";
}

template <typename T>
inline void _print(const list<T> &l) {
    cout << "{ ";
    for (auto it = l.begin(); it != l.end(); ++it) {
        _print(*it);
        if (next(it) != l.end()) cout << ", ";
    }
    cout << " }";
}

template <typename T>
inline void _print(const set<T> &s) {
    cout << "{ ";
    for (auto it = s.begin(); it != s.end(); ++it) {
        _print(*it);
        if (next(it) != s.end()) cout << ", ";
    }
    cout << " }";
}

template <typename T>
inline void _print(const unordered_set<T> &s) {
    cout << "{ ";
    bool first = true;
    for (const auto &x : s) {
        if (!first) cout << ", ";
        _print(x);
        first = false;
    }
    cout << " }";
}

template <typename T>
inline void _print(const multiset<T> &ms) {
    cout << "{ ";
    for (auto it = ms.begin(); it != ms.end(); ++it) {
        _print(*it);
        if (next(it) != ms.end()) cout << ", ";
    }
    cout << " }";
}

template <typename T, typename V>
inline void _print(const map<T, V> &m) {
    cout << "{ ";
    for (auto it = m.begin(); it != m.end(); ++it) {
        _print(*it);
        if (next(it) != m.end()) cout << ", ";
    }
    cout << " }";
}

template <typename T, typename V>
inline void _print(const unordered_map<T, V> &m) {
    cout << "{ ";
    bool first = true;
    for (const auto p : m) {
        if (!first) cout << ", ";
        _print(p);
        first = false;
    }
    cout << " }";
}

template <typename T>
inline void _print(stack<T> s) {
    vector<T> temp;
    while (!s.empty()) {
        temp.push_back(s.top());
        s.pop();
    }
    reverse(temp.begin(), temp.end());
    _print(temp);
}

template <typename T>
inline void _print(queue<T> q) {
    vector<T> temp;
    while (!q.empty()) {
        temp.push_back(q.front());
        q.pop();
    }
    _print(temp);
}

template <typename T>
inline void _print(priority_queue<T> pq) {
    vector<T> temp;
    while (!pq.empty()) {
        temp.push_back(pq.top());
        pq.pop();
    }
    sort(temp.rbegin(), temp.rend());
    _print(temp);
}

template <typename T, size_t N>
inline void _print(const array<T, N> &arr) {
    cout << "{ ";
    for (size_t i = 0; i < N; ++i) {
        _print(arr[i]);
        if (i + 1 != N) cout << ", ";
    }
    cout << " }";
}

template <typename T, size_t N>
inline void _print(const T (&arr)[N]) {
    cout << "{ ";
    for (size_t i = 0; i < N; ++i) {
        _print(arr[i]);
        if (i + 1 != N) cout << ", ";
    }
    cout << " }";
}

template <typename... Args>
inline void _print(const tuple<Args...> &t) {
    cout << "( ";
    apply([](const auto &...args) { ((cout << args << ", "), ...); }, t);
    cout.seekp(-2, ios_base::cur);
    cout << " )";
}

template <typename T>
inline void print(const T x) {
    _print(x);
    cout << endl;
}

template <typename T, typename... Args>
inline void print(const T x, const Args... args) {
    _print(x);
    cout << endl;
    print(args...);
}

enum InputMethod {
    Standard,
    Line
};

template <typename T>
inline void _input(T &x, InputMethod method = Standard) {
    if constexpr (is_same<T, string>::value) {
        if (method == Line) {
            cin.ignore();  // ignores a new line ('\n')
            cin.ignore();  // ignores a new line ('\n')
            getline(cin, x);
        } else {
            cin >> x;
        }
    } else {
        cin >> x;
    }
}

template <typename T, size_t N>
inline void _input(array<T, N> &arr, InputMethod method = Standard) {
    for (auto &x : arr) {
        _input(x, method);
    }
}

template <typename T>
inline void _input(vector<T> &v, InputMethod method = Standard) {
    int n;
    cin >> n;
    v.resize(n);
    for (auto &x : v) {
        _input(x, method);
    }
}

template <typename T>
inline void _input(set<T> &s, InputMethod method = Standard) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        T x;
        _input(x, method);
        s.insert(x);
    }
}

template <typename T>
inline void _input(unordered_set<T> &s, InputMethod method = Standard) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        T x;
        _input(x, method);
        s.insert(x);
    }
}

template <typename T>
inline void _input(multiset<T> &s, InputMethod method = Standard) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        T x;
        _input(x, method);
        s.insert(x);
    }
}

template <typename T, typename V>
inline void _input(map<T, V> &m, InputMethod method = Standard) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        pair<T, V> p;
        _input(p, method);
        m.insert(p);
    }
}

template <typename T, typename V>
inline void _input(unordered_map<T, V> &m, InputMethod method = Standard) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        pair<T, V> p;
        _input(p, method);
        m.insert(p);
    }
}

template <typename T>
inline void _input(list<T> &l, InputMethod method = Standard) {
    int n;
    cin >> n;
    l.clear();
    for (int i = 0; i < n; ++i) {
        T x;
        _input(x, method);
        l.push_back(x);
    }
}

template <typename T>
inline void _input(queue<T> &q, InputMethod method = Standard) {
    int n;
    cin >> n;
    while (!q.empty()) q.pop();
    for (int i = 0; i < n; ++i) {
        T x;
        _input(x, method);
        q.push(x);
    }
}

template <typename T>
inline void _input(deque<T> &d, InputMethod method = Standard) {
    int n;
    cin >> n;
    d.resize(n);
    for (auto &x : d) {
        _input(x, method);
    }
}

template <typename T>
inline void _input(stack<T> &s, InputMethod method = Standard) {
    int n;
    cin >> n;
    vector<T> temp(n);
    for (int i = 0; i < n; ++i) {
        _input(temp[i], method);
    }
    reverse(temp.begin(), temp.end());
    while (!s.empty()) s.pop();
    for (auto &x : temp) {
        s.push(x);
    }
}

template <typename T>
inline void _input(priority_queue<T> &pq, InputMethod method = Standard) {
    int n;
    cin >> n;
    while (!pq.empty()) pq.pop();
    for (int i = 0; i < n; ++i) {
        T x;
        _input(x, method);
        pq.push(x);
    }
}

template <typename... Args>
inline void _input(tuple<Args...> &t, InputMethod method = Standard) {
    apply([method](auto &&...args) { ((_input(args, method)), ...); }, t);
}

template <typename T>
inline void _input(T *arr, size_t n, InputMethod method = Standard) {
    for (size_t i = 0; i < n; ++i) {
        _input(arr[i], method);
    }
}

template <typename T, size_t N>
inline void _input(T (&arr)[N]) {
    for (size_t i = 0; i < N; ++i) {
        cin >> arr[i];
    }
}

template <typename... Args>
inline void input(InputMethod method, Args &...args) {
    (_input(args, method), ...);
}

// !! xxxxxxxx !! START FROM HERE !! xxxxxxxx !!

//*/*-------------- SOLUTION --------------*/*//

// ******* START *******
// @lc code=start

// ------------- OPTIMIZATIONS -------------

#ifndef LOCAL_PROJECT
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,abm,bmi,bmi2,mmx,avx,avx2,fma")

auto fastIO = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
#endif

// ------------- CODE -------------

// const int N = 1e5+1;
// int a[N];
// const int MOD = 1e9+7;
// const int _MOD = 998244353;
// const double EPS = 1e-9;
// const long long INF = 2e18;
// const int mxN = 2e5+5;
// const double PI = 4 * atan(1);
using ll = long long;
namespace rng = std::ranges;
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

class Solution {
   public:
    int maxDistinctElements(vector<int> &nums, int k) {
        sort(all(nums));
        int ans = 0, last = INT_MIN;
        for (int i = 0; i < sz(nums); ++i) {
            int mn = nums[i] - k;
            int mx = nums[i] + k;
            if (last < mn) {
                last = mn;
                ++ans;
            } else if (last < mx) {
                last = last + 1;
                ++ans;
            }
        }
        return ans;
    }
};

// @lc code=end
// ******* END *******

//*/*-------------- SOLUTIONS --------------*/*//

class Solution1 {
   public:
    int maxDistinctElements(vector<int> &nums, int k) {
        if (k == 0) {
            unordered_set<int> unique(all(nums));
            return sz(unique);
        }
        sort(all(nums));
        int n = sz(nums);
        int nextRequired = nums[0] - k;
        int result = 0;
        int lastUsed = INT_MIN;

        for (int i = 0; i < n; i++) {
            int currentNum = nums[i];
            int maxPossible = currentNum + k;
            int minPossible = currentNum - k;

            if (nextRequired <= maxPossible && nextRequired >= minPossible &&
                nextRequired > lastUsed) {
                result++;
                lastUsed = nextRequired;
                nextRequired = nextRequired + 1;
            } else if (minPossible > lastUsed) {
                result++;
                lastUsed = minPossible;
                nextRequired = minPossible + 1;
            }
        }

        return result;
    }
};

class Solution2 {
   public:
    int maxDistinctElements(vector<int> &nums, int k) {
        int ans = 0;
        sort(all(nums));
        for (int i = 0, last = INT_MIN; i < sz(nums); ++i) {
            int mn = nums[i] - k;
            int mx = nums[i] + k;
            if (last < mn) {
                last = mn;
                ans++;
            } else if (last < mx) {
                last = last + 1;
                ans++;
            }
        }
        return ans;
    }
};

//*/*-------------- SOLUTIONS --------------*/*//

void solve() {
    int x;
    vector<int> v;
    input(Standard, v, x);
    Solution sol;
    auto ans = sol.maxDistinctElements(v, x);
    print(ans);
}

int32_t main() {
    DOUBLE();
    int t = 1;
    cin >> t;

#ifdef DEBUG
    while (t--) solve();
#else
    const int timeout_seconds = 5;
    for (int test_case = 1; test_case <= t; ++test_case) {
        auto future = async(launch::async, solve);  // Run solve() in a separate thread

        if (future.wait_for(chrono::seconds(timeout_seconds)) == future_status::timeout) {
            cerr << "Time Limit Exceeded at 'Test case: " << test_case << "'\n";
            exit(0);  // exit the program
        }
    }
#endif

    return 0;
}

// ------------- END -------------