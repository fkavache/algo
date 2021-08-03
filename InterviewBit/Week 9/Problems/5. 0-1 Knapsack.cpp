int knapsack(vector<int> &A, vector<int> &B, int C) {
    int n = A.size();

    vector<vector<int>> dp(n + 1, vector<int>(C + 1, 0));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= C; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (j - B[i - 1] < 0) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j - B[i - 1]] + A[i - 1], dp[i - 1][j]);
            }
        }
    }

    return dp[n][C];
}

int main() {
    vector<int> A = {60, 100, 120};
    vector<int> B = {10, 20, 30};

    cout << knapsack(A, B, 50) << endl;

    return 0;
}
