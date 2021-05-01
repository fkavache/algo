int repeatedNumber(const vector<int> &A) {
    int n = A.size() - 1;
    int res = 0;

    for (int i : A) {
        res += i;
    }

    return res - (n * (n + 1)) / 2;
}

int repeatedNumberEx(const vector<int> &A) {
    int n_arr[A.size() / 2 + A.size() % 2];

    memset(n_arr, 0, sizeof(n_arr));

    for (int i : A) {
        int idx = (i % 2 == 0) ? i / 2 - 1 : i / 2;
        int diff = n_arr[idx] - i;

        if (diff > i % 2 || diff == 0){
            return i;
        }

        n_arr[idx] += i;
    }

    return -1;
}

int repeatedNumberXor(const vector<int> &A) {
    int n = A.size();

    int x1 = 0;
    int x2 = 0;
    for (int i = 0; i < n; i++) {
        x1 ^= A[i];
        if (i != n - 1) x2 ^= (i + 1);
    }

    return x1 ^ x2;
}

int main() {
    vector<int> A = {1, 3, 2, 2, 4, 5};

    cout << repeatedNumber(A) << endl;

    return 0;
}
