int arithmeticSlices(vector<int>& nums) {
    int n = nums.size();

    if (n < 3) return 0;

    int l = 0, r = 1;
    int d = nums[r] - nums[l];
    int res = 0;
    while (r < n) {
        if (nums[r] - nums[r - 1] != d) {
            l = r - 1;
            d = nums[r] - nums[r - 1];
        }

        int size = r - l + 1;
        if (size >= 3) {
            res += size - 3 + 1;
        }
        r++;
    }

    return res;
}

int main() {
    vector<int> A1 = {1, 2, 3, 4, 5, 6, 7};
    vector<int> A2 = {1, 2, 3, 10, 3, 4, 5};
    vector<int> A3 = {4, 5, 5, 5};

    cout << arithmeticSlices(A1) << endl;
    cout << arithmeticSlices(A2) << endl;
    cout << arithmeticSlices(A3) << endl;

    return 0;
}