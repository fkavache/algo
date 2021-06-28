vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> res;

    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++) {
        int l = i + 1, r = n-1;
        int target = nums[i];

        if (i > 0 && nums[i] == nums[i-1]) continue;
        while (l < r) {
            int ll = nums[l], rr = nums[r];
            if (ll + rr == -target) {
                res.push_back({target, ll, rr});
                while (l < r && nums[l] == ll) l++;
                while (l < r && nums[r] == rr) r--;
            } else if (ll + rr > -target) {
                r--;
            } else {
                l++;
            }
        }
    }

    return res;
}

int main() {
    return 0;
}

