int minDistance(string A, string B) {
    int m = A.length();
    int n = B.length();

    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        dp[i][0] = i;
    }

    for (int j = 0; j <= n; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
            }
        }
    }

    return dp[m][n];
}

int main() {
    cout << minDistance("babaaabaaab", "ababaabbab") << endl;
    cout << minDistance("abcdef", "x") << endl;
    cout << minDistance("abad", "abac") << endl;
    cout << minDistance("anshuman", "antihuman") << endl;

    return 0;
}