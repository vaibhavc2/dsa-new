#include <bits/stdc++.h>
using namespace std;

auto countTotalDivisorsInDigitsOfNumber(int n) {
    uint16_t count = 0;
    int originalNum = n;

    while (n != 0) {
        int digit = n % 10;
        if (digit != 0 && originalNum % digit == 0) ++count;
        n /= 10;
    }

    return count;
}

bool isArmstrongNumber(int n) {
    int sum = 0;
    vector<int> digits;

    while (n != 0) {
        digits.push_back(n % 10);
        n /= 10;
    }

    const int s = (int)digits.size();
    for (auto& d : digits) {
        sum += pow(d, s);
    }

    if (sum == n) return true;
    return false;
}

bool isArmstrongNumber_optimized(int n) {
    int k = to_string(n).size();
    int sum = 0;

    while (n != 0) {
        sum += pow(n % 10, k);
        n /= 10;
    }

    return sum == n;
}

vector<int> LCM_GCD(int a, int b) {
    // way 1
    // int lcm = (a * b) / __gcd(a, b);
    // return {lcm, __gcd(a, b)};

    // way 2 - brute force
    // int lcm = 0, gcd = 0;
    // int max = a > b ? a : b;
    // while (true) {
    //     if (max % a == 0 && max % b == 0) {
    //         lcm = max;
    //         break;
    //     }
    //     ++max;
    // }

    // int min = a < b ? a : b;
    // while (min > 0) {
    //     if (a % min == 0 && b % min == 0) {
    //         gcd = min;
    //         break;
    //     }
    //     --min;
    // }

    // return {lcm, gcd};

    // way 3 - optimized
    int temp = 0;
    while (b != 0) { // gcd - Euclidean algorithm
        temp = b;
        b = a % b;
        a = temp;
    }
    return {(a * b) / a, a}; // {lcm, gcd};
}

int main() {
    cout << countTotalDivisorsInDigitsOfNumber(12) << endl;
    cout << isArmstrongNumber(145) << endl;
    cout << isArmstrongNumber_optimized(145) << endl;
    vector<int> results = LCM_GCD(4, 5);
    return 0;
}