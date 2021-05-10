#define mod 1000000007
#define ll long long

int cntBits(vector<int> &A) {
    int n = A.size();

    ll res = 0;
    for (int i = 0; i < 8 * sizeof(int); i++) {
        ll setCnt = 0;
        for (int j = 0; j < n; j++) {
            if (A[j] & 1) setCnt++;
            A[j] >>= 1;
        }
        res += 2 * ((setCnt % mod * (n - setCnt) % mod) % mod);
    }

    return res % mod;
}

int main() {
    vector<int> A = {13, 2, 7};
    cout << cntBits(A) << endl;
    return 0;
}