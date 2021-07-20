int getNew(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] % 1001 != 0) {
            return i;
        }
    }
    return -1;
}

int getCurr(vector<int>& nums, int i, int l) {
    int n = nums.size();

    int tmp = nums[i];
    nums[i] = l * 1001;
    i += tmp;

    if (abs(i) >= n) i %= n;
    if (i <  0)      i += n;

    return i;
}

bool circularArrayLoop(vector<int>& nums) {
    int  i = 0;
    int  l = 1;
    int  c = 0;
    bool f = nums[i] > 0;
    while (true) {
        if (nums[i] % 1001 == 0) {
            if (nums[i] / 1001 == l && c > 1) return true;
            i = getNew(nums);
            if (i == -1) return false;
            c = 0;
            l++;
            f = nums[i] > 0;
            continue;
        }

        if ((f && nums[i] < 0) || (!f && nums[i] > 0)) {
            c = 0;
            f = !f;
            l++;
        }

        c++;
        int tmp = i;
        i = getCurr(nums, i, l);

        if (tmp == i) c = 1;
    }
}

int main() {
    vector<int> A1  = {2, -1, -5, 1, 1, 7, -3, -3, -1};
    vector<int> A2  = {2, -1, -5, 1, 2, 7, -3, -3, -1};
    vector<int> A3  = {2, 1, -1, -2, -2};
    vector<int> A4  = {2, -1, 1, 2, 2};
    vector<int> A5  = {3, 1, 2};
    vector<int> A6  = {-1, 2};
    vector<int> A7  = {1, 1, 2};
    vector<int> A8  = {-1, -2, -3, -4, -5};
    vector<int> A9  = {2,2,2,2,2,4,7};
    vector<int> A10 = {-2,-3,-9};

    cout << circularArrayLoop(A1) << endl;
    cout << circularArrayLoop(A2) << endl;
    cout << circularArrayLoop(A3) << endl;
    cout << circularArrayLoop(A4) << endl;
    cout << circularArrayLoop(A5) << endl;
    cout << circularArrayLoop(A6) << endl;
    cout << circularArrayLoop(A7) << endl;
    cout << circularArrayLoop(A8) << endl;
    cout << circularArrayLoop(A9) << endl;
    cout << circularArrayLoop(A10) << endl;

    return 0;
}