int increasingPath(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();

    vector<vector<int>> B(n + 1,  vector<int>(m + 1, INT_MAX));
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            B[i][j] = A[i - 1][j - 1];
        }
    }

    int res = INT_MIN;
    int ii, jj;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (B[i][j] > B[i - 1][j] && B[i][j] > B[i][j - 1]) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + 1;
            } else if (B[i][j] > B[i - 1][j]) {
                dp[i][j] = dp[i - 1][j] + 1;
            } else if (B[i][j] > B[i][j - 1]) {
                dp[i][j] = dp[i][j - 1] + 1;
            } else {
                dp[i][j] = 1;
            }

            if (dp[i][j] >= res) {
                res = dp[i][j];
                ii = i; jj = j;
            }
        }
    }

    return (ii == n && jj == m) ? res : -1;
}

int main() {
    vector<vector<int>> A1 = {
            {1, 2, 3, 4},
            {2, 2, 3, 4},
            {3, 2, 3, 4},
            {4, 5, 6, 7},
    };

    vector<vector<int>> A2 = {
            {35, 1, 70, 25, 79, 59, 63, 65},
            {6, 46, 82, 28, 62, 92, 96, 43}
    };

    vector<vector<int>> A3 = {
            {1, 1, 1, 1, 1},
            {2, 3, 1, 1, 1},
            {1, 4, 5, 1, 1},
            {1, 1, 6, 7, 1},
            {1, 1, 1, 8, 9},
            {1, 1, 1, 1, 10}
    };

    cout << increasingPath(A1) << endl;
    cout << increasingPath(A2) << endl;
    cout << increasingPath(A3) << endl;

    return 0;
}
