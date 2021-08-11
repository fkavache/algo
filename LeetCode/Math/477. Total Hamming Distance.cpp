int totalHammingDistance(vector<int>& nums) {
    int n = nums.size();

    int res = 0;
    for (int i = 0; i < 32; i++) {
        int ones = 0;
        int mask = 1 << i;
        for (int j = 0; j < n; j++) {
            if (nums[j] & mask) ones++;
        }
        res += ones * (n - ones);
    }

    return res;
}

int main() {
    vector<int> A = {4, 14, 2};

    cout << totalHammingDistance(A) << endl;

    return 0;
}