bool canPartitionKSubsetsInternal(vector<int>& nums, int k, int n, int target, int parts[]) {
    if (n == 0) return true;

    for (int i = 0; i < k; i++) {
        if (parts[i] + nums[n-1] <= target) {
            parts[i] += nums[n-1];
            if (canPartitionKSubsetsInternal(nums, k, n-1, target, parts)) return true;
            parts[i] -= nums[n-1];
        }
        if (parts[i] == 0) break;
    }
    return false;
}

bool canPartitionKSubsets(vector<int>& nums, int k) {
    int parts[16] = {};
    int sum       = 0;
    int n         = nums.size();

    for (int i: nums) sum += i;

    int target = sum / k;

    sort(nums.begin(), nums.end());
    if (sum % k != 0 || nums[n-1] > target) return false;

    return canPartitionKSubsetsInternal(nums, k, n, target, parts);
}

int main() {
    vector<int> nums = {4, 3, 2, 3, 5, 2, 1};
    cout << canPartitionKSubsets(nums, 4) << endl;
    return 0;
}