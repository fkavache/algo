int firstMissingPositive1(vector<int>& nums) {
    int n = nums.size();
    int res = n + 1;

    int i   = nums[0];
    int j   = 0;
    nums[0] = 0;
    while (true) {
        if (i > 0 && i <= n && i != nums[i - 1]) {
            int tmp = nums[i - 1];
            nums[i - 1] = i;
            i = tmp;
        } else {
            j++;
            if (j == n) break;
            i = nums[j];
        }
    }

    for (int k = 0; k < n; k++) {
        if (nums[k] != k + 1) {
            res = k + 1;
            break;
        }
    }

    return res;
}

int firstMissingPositive2(vector<int>& nums) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        int curr = nums[i];
        if (curr > 0 && curr <= n) {
            if (curr != nums[curr - 1]) {
                swap(nums[curr - 1], nums[i]);
                i--;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (i != nums[i] - 1) {
            return i + 1;
        }
    }

    return n + 1;
}

int main() {
    vector<int> A0  = {1, 2, 0};
    vector<int> A1 = {3, 4, -1, 1};
    vector<int> A2 = {7, 8, 9, 11, 12};
    vector<int> A3 = {1, 2, 9, 11, 12};
    vector<int> A4 = {0, 1, 2, 3, 4};
    vector<int> A5 = {-5, -6, -11, -11};
    vector<int> A6 = {0};
    vector<int> A7 = {4};
    vector<int> A8 = {1};
    vector<int> A9 = {1, 1};

    cout << firstMissingPositive1(A0) << " 3" << endl;
    cout << firstMissingPositive1(A1) << " 2" << endl;
    cout << firstMissingPositive1(A2) << " 1" << endl;
    cout << firstMissingPositive1(A3) << " 3" << endl;
    cout << firstMissingPositive1(A4) << " 5" << endl;
    cout << firstMissingPositive1(A5) << " 1" << endl;
    cout << firstMissingPositive1(A6) << " 1" << endl;
    cout << firstMissingPositive1(A7) << " 1" << endl;
    cout << firstMissingPositive1(A8) << " 2" << endl;
    cout << firstMissingPositive1(A9) << " 2" << endl;

    return 0;
}