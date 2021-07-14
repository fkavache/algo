bool checkWiggle(int prev, int curr) {
    return prev == 0 || (prev > 0 && curr < 0) || (prev < 0 && curr > 0);
}

int wiggleMaxLength(vector<int>& nums) {
    int n = nums.size();

    int res = 0;
    int prev = 0;
    for (int i = 1; i < n; i++) {
        int currDiff = nums[i] - nums[i - 1];
        if (!checkWiggle(prev, currDiff)) {
            prev += currDiff;
        } else if (currDiff != 0) {
            prev = currDiff;
            res++;
        }
    }

    return res +  1;
}

int main() {
    vector<int> A1 = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
    vector<int> A2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> A3 = {1, 7, 4, 9, 2, 5};
    vector<int> A4 = {1, 2, 3, 4, 5};
    vector<int> A5 = {1, 2};
    vector<int> A6 = {0, 0};
    vector<int> A7 = {5};

    cout << wiggleMaxLength(A1) << endl;
    cout << wiggleMaxLength(A2) << endl;
    cout << wiggleMaxLength(A3) << endl;
    cout << wiggleMaxLength(A4) << endl;
    cout << wiggleMaxLength(A5) << endl;
    cout << wiggleMaxLength(A6) << endl;
    cout << wiggleMaxLength(A7) << endl;

    return 0;
}