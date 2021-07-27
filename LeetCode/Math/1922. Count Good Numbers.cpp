#define mod 1000000007

int countGoodNumbers1(long long n) {
    if (n == 2) return 20;
    if (n == 1) return 5;
    if (n == 0) return 1;

    long long res;
    if ((n / 2) % 2 == 0) {
        res = countGoodNumbers1(n / 2);
        res = (res * res) % mod;
    } else {
        res = countGoodNumbers1((n / 2) - 1);
        res = (res * res) % mod;
        res = (res * 20) % mod;
    }

    if (n % 2 != 0)
        res = (res * 5) % mod;

    return (int) res;
}

int countGoodNumbers2(long long n) {
    long long y = (n & 1) ? (n - 1) / 2 : n / 2;
    long long res = 1;
    long long x = 20;

    while (y > 0) {
        if (y % 2 != 0)
            res = (res * x) % mod;

        y /= 2;
        x = (x * x) % mod;
    }

    return (int)((n % 2 != 0) ? (res * 5) % mod : res % mod);
}

int main() {
    cout << countGoodNumbers2(1) << endl;
    cout << countGoodNumbers2(3) << endl;
    cout << countGoodNumbers2(4) << endl;
    cout << countGoodNumbers2(50) << endl;
    cout << countGoodNumbers2(10000000000009) << endl;

    return 0;
}