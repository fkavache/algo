int findShortestSubArray(vector<int>& nums) {
    unordered_map<int, int> freq;
    int deg = INT_MIN;
    int n = nums.size();

    for (int e: nums) {
        freq[e]++;
        deg = max(deg, freq[e]);
    }

    unordered_map<int, int> tmp;

    int l = 0;
    int res = INT_MAX;
    for (int r = 0; r < n; r++) {
        tmp[nums[r]]++;
        if (tmp[nums[r]] == deg) {
            while (nums[l] != nums[r]) {
                tmp[nums[l]]--;
                l++;
            }
            res = min(res, r - l + 1);
        }
    }

    return res;
}

int main() {
    vector<int> nums1 = {1, 2, 2, 3, 1};
    vector<int> nums2 = {1, 2, 2, 3, 1, 4, 2};

    cout << findShortestSubArray(nums1) << endl;
    cout << findShortestSubArray(nums2) << endl;

    return 0;
}