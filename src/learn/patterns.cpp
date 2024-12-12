#include <bits/stdc++.h>
using namespace std;

class Patterns {
   private:
    vector<vector<char>> arr;

   public:
    vector<vector<char>> pattern1(const int& n) {
        arr = vector<vector<char>>(n, vector<char>(n, ' '));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j] = '*';
            }
        }
        return arr;
    }

    vector<vector<char>> pattern2(const int& n) {
        arr = vector<vector<char>>(n, vector<char>(n, ' '));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i + 1; j++) {
                arr[i][j] = '*';
            }
        }
        return arr;
    }

    vector<vector<char>> pattern3(const int& n) {
        arr = vector<vector<char>>(n, vector<char>(n, ' '));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i + 1; j++) {
                arr[i][j] = static_cast<char>(48 + j + 1);
            }
        }
        return arr;
    }

    vector<vector<char>> pattern4(const int& n) {
        arr = vector<vector<char>>(n, vector<char>(n, ' '));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i + 1; j++) {
                arr[i][j] = static_cast<char>(48 + i + 1);
            }
        }
        return arr;
    }

    vector<vector<char>> pattern5(const int& n) {
        arr = vector<vector<char>>(n, vector<char>(n, ' '));

        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= i; j--) {
                arr[i][j] = '*';
            }
        }
        return arr;
    }

    vector<vector<char>> pattern6(const int& n) {
        arr = vector<vector<char>>(n, vector<char>(n, ' '));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                arr[i][j] = static_cast<char>(48 + j + 1);
            }
        }
        return arr;
    }

    vector<vector<char>> pattern7(const int& n) {
        arr = vector<vector<char>>(n, vector<char>(2 * n - 1, ' '));

        for (int i = 0; i < n; i++) {
            int start = n - 1 - i;
            int end = n - 1 + i;

            for (int j = start; j <= end; j++) {
                arr[i][j] = '*';
            }
        }
        return arr;
    }

    vector<vector<char>> pattern8(const int& n) {
        arr = vector<vector<char>>(n, vector<char>(2 * n - 1, ' '));

        for (int i = 0; i < n; i++) {
            int start = i;
            int end = 2 * n - 1 - i - 1;

            for (int j = start; j <= end; j++) {
                arr[i][j] = '*';
            }
        }
        return arr;
    }

    vector<vector<char>> pattern9(const int& n) {
        vector<vector<char>> res;
        auto topPattern = pattern7(n);
        auto bottomPattern = pattern8(n);

        res.insert(res.end(), topPattern.begin(), topPattern.end());
        res.insert(res.end(), bottomPattern.begin(), bottomPattern.end());

        return res;
    }

    vector<vector<char>> pattern10(const int& n) {
        arr = vector<vector<char>>(2 * n - 1, vector<char>(2 * n - 1, ' '));

        for (int i = 0; i < n; i++) {
            for (int j = n - i - 1; j <= n + i - 1; j++) {
                arr[i][j] = '*';
            }
        }

        for (int k = n, l = n - 1; k < 2 * n - 1; k++, l--) {
            for (int m = n - l; m < n + l - 1; m++) {
                arr[k][m] = '*';
            }
        }

        return arr;
    }

    vector<vector<char>> pattern11(const int& n) {
        arr = vector<vector<char>>(2 * n - 1, vector<char>(n, ' '));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i + 1; j++) {
                arr[i][j] = '*';
            }
        }

        for (int k = n - 1, l = n; k > 0; k--, l++) {
            for (int j = 0; j < k; j++) {
                arr[l][j] = '*';
            }
        }

        return arr;
    }

    vector<vector<char>> pattern12(const int& n) {
        arr = vector<vector<char>>(2 * n - 1, vector<char>(2 * n - 1, ' '));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i + 1; j++) {
                arr[i][j] = '*';
            }
            for (int k = 2 * n - 2; k >= 2 * n - i - 2; k--) {
                arr[i][k] = '*';
            }
        }

        for (int k = n - 1, l = n; k > 0; k--, l++) {
            for (int j = 0; j < k; j++) {
                arr[l][j] = '*';
            }
            for (int m = l; m < 2 * n - 1; m++) {
                arr[l][m] = '*';
            }
        }

        return arr;
    }

    vector<vector<char>> pattern13(const int& n) {
        arr = vector<vector<char>>(n, vector<char>(n, ' '));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i + 1; j++) {
                if ((j + 1) % 2 == 1)
                    arr[i][j] = '1';
                else
                    arr[i][j] = '0';
            }
        }

        return arr;
    }

    vector<vector<char>> pattern14(const int& n) {
        arr = vector<vector<char>>(n, vector<char>(n, ' '));

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i + 1; j++) {
                if ((count + 1) % 2 == 1)
                    arr[i][j] = '1';
                else
                    arr[i][j] = '0';

                count++;
            }
            if ((i + 1) % 2 == 0) count++;
        }

        return arr;
    }

    vector<vector<char>> pattern15(const int& n) {
        arr = vector<vector<char>>(2 * n - 1, vector<char>(2 * n - 1, ' '));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i + 1; j++) {
                arr[i][j] = static_cast<char>(j + 1 + 48);
            }
            for (int k = 2 * n - 2, l = 0; k >= 2 * n - i - 2; k--, l++) {
                arr[i][k] = static_cast<char>(l + 1 + 48);
            }
        }

        for (int k = n - 1, l = n; k > 0; k--, l++) {
            for (int j = 0; j < k; j++) {
                arr[l][j] = static_cast<char>(j + 1 + 48);
            }
            for (int m = l, p = 2 * n - l - 1; m < 2 * n - 1; m++, p--) {
                arr[l][m] = static_cast<char>(p + 48);
            }
        }

        return arr;
    }

    vector<vector<char>> pattern16(const int& n) {
        arr = vector<vector<char>>(n, vector<char>(n, ' '));

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i + 1; j++) {
                arr[i][j] = static_cast<char>(++count + 48);
            }
        }

        return arr;
    }

    vector<vector<char>> pattern17(const int& n) {
        arr = vector<vector<char>>(2 * n - 1, vector<char>(2 * n - 1, ' '));

        for (int i = 0; i < n; i++) {
            for (int j = n - i - 1; j <= n + i - 1; j++) {
                arr[i][j] = static_cast<char>(65 + i);
            }
        }

        for (int j = n, k = n - 1; j < 2 * n - 1; j++, k--) {
            for (int l = n - k; l <= n + k - 2; l++) {
                arr[j][l] = static_cast<char>(65 + k - 1);
            }
        }

        return arr;
    }

    vector<vector<char>> pattern18(const int& n) {
        arr = vector<vector<char>>(2 * n - 1, vector<char>(2 * n - 1, ' '));

        for (int i = 0; i < n; i++) {
            int c = 0;
            for (int j = n - i - 1; j <= n + i - 1; j++) {
                arr[i][j] = static_cast<char>(65 + c);
                if (j >= n - 1)
                    c--;
                else
                    c++;
            }
        }

        for (int j = n, k = n - 1; j < 2 * n - 1; j++, k--) {
            int c = 0;
            for (int l = n - k; l <= n + k - 2; l++) {
                arr[j][l] = static_cast<char>(65 + c);
                if (l >= n - 1)
                    c--;
                else
                    c++;
            }
        }

        return arr;
    }

    vector<vector<char>> pattern19(const int& n) {
        arr = vector<vector<char>>(2 * n - 1, vector<char>(2 * n - 1, ' '));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                arr[i][j] = '*';
            }
            for (int j = n + i - 1; j < 2 * n - 1; j++) {
                arr[i][j] = '*';
            }
        }

        for (int j = n, l = n - 1; j < 2 * n - 1; j++, l--) {
            for (int k = 0; k < n - l + 1; k++) {
                arr[j][k] = '*';
            }
            for (int k = n + l - 2; k < 2 * n - 1; k++) {
                arr[j][k] = '*';
            }
        }

        return arr;
    }

    vector<vector<char>> pattern20(const int& n) {
        arr = vector<vector<char>>(2 * n, vector<char>(2 * n, ' '));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                arr[i][j] = '*';
            }
            for (int j = n + i; j < 2 * n; j++) {
                arr[i][j] = '*';
            }
        }

        for (int j = n, l = n - 1; j < 2 * n; j++, l--) {
            for (int k = 0; k < n - l; k++) {
                arr[j][k] = '*';
            }
            for (int k = n + l; k < 2 * n; k++) {
                arr[j][k] = '*';
            }
        }

        return arr;
    }

    vector<vector<char>> pattern21(const int& n) {
        arr = vector<vector<char>>(n, vector<char>(n, ' '));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0 || j == n - 1)
                    arr[i][j] = '*';
                else if (i == 0 || i == n - 1)
                    arr[i][j] = '*';
            }
        }

        return arr;
    }

    vector<vector<char>> pattern22(const int& n) {
        arr = vector<vector<char>>(n, vector<char>(n, ' '));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Compute the value based on the distance from edges
                int value = n / 2 - min(min(i, j), min(n - 1 - i, n - 1 - j));
                arr[i][j] = static_cast<char>('0' + value + 1);
            }
        }

        return arr;
    }
};

inline void printPattern(const vector<vector<char>>& arr) {
    for (const auto& row : arr) {
        for (const char& ch : row) {
            cout << ch << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    const auto patterns = new Patterns();
    printPattern(patterns->pattern1(n));
    printPattern(patterns->pattern2(n));
    printPattern(patterns->pattern3(n));
    printPattern(patterns->pattern4(n));
    printPattern(patterns->pattern5(n));
    printPattern(patterns->pattern6(n));
    printPattern(patterns->pattern7(n));
    printPattern(patterns->pattern8(n));
    printPattern(patterns->pattern9(n));
    printPattern(patterns->pattern10(n));
    printPattern(patterns->pattern11(n));
    printPattern(patterns->pattern12(n));
    printPattern(patterns->pattern13(n));
    printPattern(patterns->pattern14(n));
    printPattern(patterns->pattern15(n));
    printPattern(patterns->pattern16(n));
    printPattern(patterns->pattern17(n));
    printPattern(patterns->pattern18(n));
    printPattern(patterns->pattern19(n));
    printPattern(patterns->pattern20(n));
    printPattern(patterns->pattern21(n));
    printPattern(patterns->pattern22(n));

    return 0;
}