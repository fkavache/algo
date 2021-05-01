
// -----------------------------------------------------------------------
// -----------------------------------------------------------------------

int books_internal(vector<int> &A, vector<vector<int>> &dp, int n, int B) {
    if (B == 1) return A[n-1];
    if (n == 1) return A[0];

    int res = INT_MAX;
    for (int i = 1; i <= n; i++) {
        int rec = dp[B-1][i];
        if (rec == -1) {
            rec = dp[B-1][i] = books_internal(A, dp, i, B-1);
        }
        int sum = A[n-1] - A[i - 1];
        res = min(res, max(rec, sum));
    }

    return res;
}

int books_tddp(vector<int> &A, int B) {
    int n = A.size();
    vector<int> sum(n, A[0]);

    vector<vector<int> > dp(B, vector<int>(n + 1));

    for (int i = 0; i < B; i++) {
        fill(dp[i].begin(), dp[i].end(), -1);
    }

    for (int i = 1; i < A.size(); i++) {
        sum[i] = sum[i-1] + A[i];
    }

    return B > n ? -1 : books_internal(sum, dp, n, B);
}

// -----------------------------------------------------------------------
// -----------------------------------------------------------------------

int books_budp(vector<int> &A, int B) {
    if (B > A.size()) {
        return -1;
    }

    unsigned int n = A.size();

    vector<int> sum(n + 1);

    int dp[B + 1][n + 1];
    for (int i = 1; i <= B; i++) {
        for (int j = 1; j <= n; j++)
            dp[i][j] = -1;
        dp[i][1] = A[0];
    }

    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + A[i-1];
        dp[1][i] = sum[i];
    }

    for (int i = 2; i <= B; i++) {
        for (int j = 2; j <= n; j++){

            int mn = INT_MAX;
            for (int k = 1; k <= j; k++) {
                mn = min(mn, max(dp[i - 1][k], sum[j] - sum[k])) ;
            }

            dp[i][j] = mn;
        }
    }

    return dp[B][n];
}

// -----------------------------------------------------------------------
// -----------------------------------------------------------------------

bool possible(vector<int> &A, int B, int mid) {
    int sum = 0;
    for (int i : A) {
        if (i > mid) return false;
        sum += i;
        if (sum > mid) {
            B--;
            if (B == 0) return false;
            sum = i;
        }
    }
    return true;
}

int books_bsearch(vector<int> &A, int B) {
    unsigned int n = A.size();

    if (B > n) {
        return -1;
    }

    vector<int> sum(n, A[0]);
    for (int i = 1; i < n; i++) {
        sum[i] = sum[i - 1] + A[i];
    }

    int mn = 0;
    int mx = sum[n-1];
    int res = INT_MAX;

    while (mn <= mx) {
        int mid = (mn + mx) / 2;
        if (possible(A, B, mid)) {
            res = min(res, mid);
            mx = mid - 1;
        } else {
            mn = mid + 1;
        }
    }

    return res;
}

int main() {
    vector<int> A = {12, 34, 67, 90};
//    vector<int> A = {5, 17, 100, 11};
//    vector<int> A = {97, 26, 12, 67, 10, 33, 79, 49, 79, 21, 67, 72, 93, 36, 85, 45, 28, 91, 94, 57, 1, 53, 8, 44, 68, 90, 24};

    cout << books_bsearch(A, 2) << endl;

    return 0;
}
