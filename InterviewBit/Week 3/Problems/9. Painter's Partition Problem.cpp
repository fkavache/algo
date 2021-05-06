#define mod 10000003
#define ll long long

bool isPossible(vector<int> &C, int A, int mid) {
    int sum = 0;
    for (int i : C) {
        if (sum + i > mid) {
            sum = 0;
            A--;
        }
        if (A <= 0 || i > mid) return false;
        sum += i;
    }
    return true;
}

int paint(int A, int B, vector<int> &C) {
    int mn = INT_MAX;
    int mx = 0;
    for (int i : C) {
        mx += i;
        mn = min(mn, i);
    }

    ll res = LONG_LONG_MAX;
    while (mx >= mn) {
        int mid = (mn + mx) / 2;
        if (isPossible(C, A, mid)) {
            res = min(res, (ll) mid);
            mx = mid - 1;
        } else {
            mn = mid + 1;
        }
    }

    return int(((res % mod) * B) % mod);
}

int main() {
    vector<int> C = {1000000, 1000000};
    cout << paint(1, 1000000, C) << endl;
    return 0;
}