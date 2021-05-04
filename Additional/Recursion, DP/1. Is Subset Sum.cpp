bool isSubsetSumRec(vector<int>& nums, int n, int sum) {
    if (sum == 0) return true;
    if (n == 0)   return false;

    return isSubsetSumRec(nums, n-1, sum) || isSubsetSumRec(nums, n-1, sum-nums[n-1]);
}

bool isSubsetSum2(vector<int>& nums, int sum) {
    return isSubsetSumRec(nums, nums.size(), sum);
}

bool isSubsetSum(vector<int>& nums, int sum) {
    int n = nums.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));

    for (int i = 0; i <= sum; i++) dp[0][i] = false;
    for (int i = 0; i <= n;   i++) dp[i][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= nums[i-1]) dp[i][j] = dp[i-1][j-nums[i-1]];
        }
    }

    return dp[n][sum];
}

int main() {
    vector<int> nums = {2, 2, 3};

    cout << isSubsetSum(nums, 7) << endl;

    return 0;
}