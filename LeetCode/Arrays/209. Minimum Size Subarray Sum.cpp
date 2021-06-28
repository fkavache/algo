int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();

    int l = 0, sum = 0, res = INT_MAX;
    for (int r = 0; r < n; r++) {
        sum += nums[r];
        while (sum - nums[l] >= target) {
            sum -= nums[l];
            l++;
        }
        if (sum >= target) {
            res = min(res, r - l + 1);
        }
    }

    return res == INT_MAX ? 0 : res;
}

int main() {
    vector<int> A1 = {2, 3, 1, 2, 4, 3};
    vector<int> A2 = {1, 4, 4};
    vector<int> A3 = {1, 1, 1, 1, 1, 1, 1, 1};
    vector<int> A4 = {5, 5, 5, 5, 5};
    vector<int> A5 = {10};

    cout << minSubArrayLen(7,  A1) << endl;
    cout << minSubArrayLen(4,  A2) << endl;
    cout << minSubArrayLen(11, A3) << endl;
    cout << minSubArrayLen(17, A4) << endl;
    cout << minSubArrayLen(5,  A5) << endl;

    return 0;
}