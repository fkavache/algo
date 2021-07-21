int triangleNumber(vector<int>& nums) {
    int n = nums.size();

    sort(nums.begin(), nums.end());

    int res = 0;
    for (int i = n - 1; i >= 0; i--) {
        int l = i - 1, r = 0;
        while (r < l) {
            if (nums[i] < nums[l] + nums[r]) {
                res += l - r;
                l--;
            } else {
                r++;
            }
        }
    }

    return res;
}

int main() {
    vector<int> A1 = {2, 2, 3, 4};
    vector<int> A2 = {4, 2, 3, 4};

    cout << triangleNumber(A1) << endl;
    cout << triangleNumber(A2) << endl;

    return 0;
}