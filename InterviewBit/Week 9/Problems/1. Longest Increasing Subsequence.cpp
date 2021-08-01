int lis(const vector<int> &A) {
    int n = A.size();

    vector<int> dp(n);
    dp[0] = 1;

    int res = 1;
    for (int i = 1; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }

    return res;
}

int main() {
    vector<int> A1 = {1, 2, 1, 5};
    vector<int> A2 = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    vector<int> A3 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> A4 = {14, 24, 18, 46, 55, 53, 82, 18, 101, 20, 78, 35, 68, 9, 16, 93, 101, 85, 81, 28, 78};

    cout << lis(A1) << endl;
    cout << lis(A2) << endl;
    cout << lis(A3) << endl;
    cout << lis(A4) << endl;

    return 0;
}