void rotate(vector<int>& nums, int k) {
    int n = nums.size();

    if (k != 0 && k != n) {
        k %= n;

        reverse(nums.begin(), nums.begin() + (n - k));
        reverse(nums.begin() + (n - k), nums.end());
        reverse(nums.begin(), nums.end());
    }
}

int main() {
    vector<int> A = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    rotate(A, 4);
    rotate(A, 6);
    rotate(A, 1);
    rotate(A, 9);
    rotate(A, 5);
    rotate(A, 5);
    rotate(A, 3);
    rotate(A, 7);

    for (int i: A) cout << i << ", ";

    return 0;
}