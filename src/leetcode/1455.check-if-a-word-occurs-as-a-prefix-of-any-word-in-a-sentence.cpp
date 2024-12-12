// ---------- CP SETUP ---------- //
#ifndef DEBUG
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,abm,bmi,bmi2,mmx,avx,avx2,fma")
#endif

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
// #define int long long
#define fastIO()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

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

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T, class V>
void _print(unordered_map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <typename T>
void _print(T x);

// function implementations
template <typename T>
void _print(T x) { cerr << x; }

template <class T, class V>
void _print(pair<T, V> p) {
    cerr << "{";
    _print(p.first);
    cerr << ",";
    _print(p.second);
    cerr << "}";
}

template <class T>
void _print(vector<T> v) {
    cerr << "[ ";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

template <class T>
void _print(set<T> v) {
    cerr << "[ ";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

template <class T>
void _print(multiset<T> v) {
    cerr << "[ ";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

template <class T, class V>
void _print(map<T, V> v) {
    cerr << "[ ";
    for (auto i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

template <class T, class V>
void _print(unordered_map<T, V> v) {
    cerr << "[ ";
    for (auto i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

inline void input(int &n) {
    cin >> n;
}

inline void string_input(string &s) {
    getline(cin, s);
}

inline void vector_input(vector<int32_t> &v) {
    for (int32_t i = 0; i < static_cast<int32_t>(v.size()); i++)
        cin >> v[i];
}

inline void string_vector_input(vector<string> &v) {
    for (int32_t i = 0; i < static_cast<int32_t>(v.size()); i++)
        getline(cin, v[i]);
}

inline void array_input(int32_t arr[], int32_t n) {
    for (int32_t i = 0; i < n; i++)
        cin >> arr[i];
}

inline void string_array_input(string arr[], int32_t n) {
    for (int32_t i = 0; i < n; i++)
        getline(cin, arr[i]);
}

inline void char_array_input(char arr[], int32_t n) {
    for (int32_t i = 0; i < n; i++)
        cin >> arr[i];
}

//*/*-------------- SOLUTION --------------*/*//
// !! xxxxxxxx !! START FROM HERE !! xxxxxxxx !!
/*
 * @lc app=leetcode id=1455 lang=cpp
 *
 * [1455] Check If a Word Occurs As a Prefix of Any Word in a Sentence
 */

// @lc code=start
class Solution {
   public:
    int isPrefixOfWord(string s, string w) {}
};
// @lc code=end

//*/*-------------- SOLUTIONS --------------*/*//

// approach 1 - Two Pointers in a Brute Force way
// Time - O(n), Space - O(1)
class Solution1 {
   public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int m = (int)searchWord.length();
        int n = (int)sentence.length();
        int i = 0, wordCnt = 1;
        bool found = false;

        while (i < n) {
            int preIdx = 0;
            bool prefixFinding = true;
            for (; i < n && sentence[i] != ' '; i++) {
                if (preIdx < m) {
                    if (prefixFinding) {
                        if (sentence[i] != searchWord[preIdx])
                            prefixFinding = false;
                        else {
                            preIdx++;
                            if (preIdx >= m) {
                                found = true;
                                break;
                            }
                        }
                    }
                } else {
                    found = true;
                    break;
                };
            }

            if (found) break;

            if (sentence[i] == ' ') {
                wordCnt++;
                i++;
            }
        }

        return found ? wordCnt : -1;
    }
};

// approach 2 - Two Pointers in a more optimized way
// Time - O(n), Space - O(1)
class Solution2 {
   public:
    int isPrefixOfWord(string s, string w) {
        int j = 0, curWord = 1; // j is the index of the searchWord

        for (int i = 0; i < (int)s.size(); ++i) {
            if (j != -1 && s[i] == w[j]) // if the current character matches the character in searchWord, and j is not -1 (i.e. we are searching), then increment j to search for the next character
                ++j;
            else if (s[i] == ' ')
                j = 0, ++curWord; // if we find a space, we reset j to 0 and increment the word count
            else
                j = -1; // -1 means we are not searching in this word, so we wait till we find a space and then reset j to 0 to start the search again!

            // if j reaches the end of the searchWord, then return the current word count - we have found the searchWord as a prefix of this word in the given sentence
            if (j == (int)w.size()) return curWord;
        }

        return -1;
    }
};

//*/*-------------- SOLUTIONS --------------*/*//

inline void solve() {
    string s, t;
    string_input(s);
    cin >> t;

    Solution sol;
    auto ans = sol.isPrefixOfWord(s, t);
    cout << ans << endl;
}

int32_t main() {
#ifndef DEBUG
    fastIO();
    DOUBLE();
#endif

    int t = 1;
    cin >> t;

    while (t--)
        solve();

    return 0;
}