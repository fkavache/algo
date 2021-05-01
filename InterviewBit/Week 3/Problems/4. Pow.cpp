#define ll long long

ll mod(ll x, int m) {
    return (x % m + m) % m;
}

int pow(int x, int n, int d) {
    if (x == 0) {
        return 0;
    }

    ll ans = 1, base = x;
    while (n > 0) {
        if (n % 2 == 0) {
            base = mod(base * base, d);
            n /= 2;
        } else {
            ans = mod(ans * base, d);
            n--;
        }
    }

    return (int) ans;
}

int main() {
    cout << pow(71045970, 41535484, 64735492) << endl;
    cout << pow(2, 3, 3) << endl;
    cout << pow(0, 0, 1) << endl;

    return 0;
}
