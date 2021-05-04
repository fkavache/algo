int knapSackInternal(vector<int> wt, vector<int> val, int n, int W) {
    if (W < 0 || n == 0) {
        return 0;
    }

    int res = knapSackInternal(wt, val, n-1, W);
    if (W >= wt[n-1]) {
        res = max(res, knapSackInternal(wt, val, n-1, W-wt[n-1]) + val[n-1]);
    }

    return res;
}

int knapSack(vector<int> wt, vector<int> val, int W) {
    return knapSackInternal(wt, val, val.size(), W);
}

int knapSackDP(vector<int> wt, vector<int> val, int W) {
    int n = val.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));

    for (int i = 0; i <= W; i++) dp[0][i] = wt[0] <= W ? val[0] : 0;
    for (int i = 0; i <= n; i++) dp[i][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            int res = dp[i-1][j];
            if (wt[i] <= j) {
                res = max(res, dp[i-1][j-wt[i]] + val[i]);
            }
            dp[i][j] = res;
        }
    }
    return dp[n][W];
}

int main() {
    vector<int> val = {60, 100, 180};
    vector<int> wt  = {10, 20,  30};

    cout << knapSack  (wt, val, 30) << endl;
    cout << knapSackDP(wt, val, 30) << endl;

    return 0;
}