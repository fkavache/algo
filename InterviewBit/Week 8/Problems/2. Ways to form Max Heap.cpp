#define mod 1000000007
#define ll long long

ll maxHeapsInternal(int A, vector<vector<int>> &ncr) {
    if (A <= 2) {
        return 1;
    }

    int L = 0;
    int h = (int) log2(A);
    int maxLast = 1 << h;
    int last = maxLast - ((1 << (h + 1)) - 1 - A);

    if (last > maxLast / 2) {
        L = (1 << h) - 1;
    } else {
        L = (1 << h) - 1 - (maxLast / 2 - last);
    }

    ll res = ncr[A - 1][L];
    res = res * (maxHeapsInternal(L, ncr)) % mod;
    res = res * maxHeapsInternal(A - L - 1, ncr) % mod;

    return  res;
}

int maxHeaps(int A) {
    vector<vector<int>> ncr(A, vector<int>(A, 0));

    for (int i = 0; i < A; i++) ncr[i][0] = 1;

    for (int i = 1; i < A; i++) {
        for (int j = 1; j <= i; j++) {
            ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % mod;
        }
    }

    return (int) maxHeapsInternal(A, ncr) % mod;
}

int main() {

    cout << maxHeaps(20) << endl;

    return 0;
}