int jump1(vector<int> &A) {
    int n = A.size();
    vector<int> dp(n, 0);

    for (int i = n - 2; i >= 0; i--) {
        int res = INT_MAX;
        for (int j = A[i]; j >= 1; j--) {
            if (i + j >= n - 1) {
                res = 0;
                break;
            }
            res = min(res, dp[i + j]);
        }
        dp[i] = (res == INT_MAX) ? res : res + 1;
    }

    return dp[0] == INT_MAX ? -1 : dp[0];
}

int jump2(vector<int> &A) {
    int n = A.size();

    if (n == 1) return A[0] != 0;

    int maxPossible = A[0];
    int currMax = maxPossible;
    int res = 1;

    for (int i = 1; i <= maxPossible; i++) {
        if (i == n - 1) return res;

        currMax = max(currMax, i + A[i]);
        if (i == maxPossible) {
            maxPossible = currMax;
            res++;
        }
    }

    return -1;
}

int main() {
    vector<int> A1 = {2, 3, 1, 1, 4};
    vector<int> A2 = {2, 3, 0, 1, 4};
    vector<int> A3 = {1, 50, 0, 0, 4};
    vector<int> A4 = {2, 1, 1};
    vector<int> A5 = {2, 1, 1};

    cout << jump2(A1) << endl;
    cout << jump2(A2) << endl;
    cout << jump2(A3) << endl;
    cout << jump2(A4) << endl;
    cout << jump2(A5) << endl;

    return 0;
}
