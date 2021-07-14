int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX - 1);

    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int coin: coins) {
            if (i - coin >= 0) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return (dp[amount] == INT_MAX - 1) ? -1 : dp[amount];
}

int main() {
    vector<int> A1 = {1, 2, 5};
    vector<int> A2 = {2};
    vector<int> A3 = {1};
    vector<int> A4 = {1};
    vector<int> A5 = {1};
    vector<int> A6 = {1, 2, 3, 4};
    vector<int> A7 = {9, 9, 9, 5};
    vector<int> A8 = {186, 419, 83, 408};

    cout << coinChange(A1, 11)   << endl;
    cout << coinChange(A2, 3)    << endl;
    cout << coinChange(A3, 0)    << endl;
    cout << coinChange(A4, 1)    << endl;
    cout << coinChange(A5, 2)    << endl;
    cout << coinChange(A6, 8)    << endl;
    cout << coinChange(A7, 5)    << endl;
    cout << coinChange(A8, 6249) << endl;

    return 0;
}