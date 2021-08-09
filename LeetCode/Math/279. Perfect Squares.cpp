int numSquares(int n) {
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int mn = INT_MAX;
        for (int j = 1; j * j <= i; j++) {
            mn = min(mn, dp[i - j * j]);
        }
        dp[i] = mn + 1;
    }

    return dp[n];
}

int main() {
    cout << numSquares(12) << endl;
    cout << numSquares(13) << endl;

    return 0;
}