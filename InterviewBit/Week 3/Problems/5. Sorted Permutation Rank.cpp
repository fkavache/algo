#define mod 1000003

int findRank(string A) {
    int res = 1;

    int fact[1000] = {1};
    for (int i = 1; i < 1000; i++) {
        fact[i] = fact[i-1] * i % mod;
    }

    for (int i = 0; i < A.size(); i++) {
        int gr = 0;
        for (int j = i + 1; j < A.size(); j++) {
            if (A[i] > A[j]) gr++;
        }
        res += (gr * fact[A.size() - i - 1]) % mod;
    }

    return res % mod;
}

int main() {
    cout << findRank("DTNGJPURFHYEW") << endl;
    return 0;
}
