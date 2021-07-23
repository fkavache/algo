#define ll long long

int numSubarrayP(vector<int>& nums, int k) {
    int n = nums.size();

    int l = 0, r = 0, res = 0;
    ll p = 1;
    while (r < n) {
        p *= (ll) nums[r];
        while (l <= r && p >= k) {
            p /= nums[l];
            l++;
        }

        res += r - l + 1;
        r++;
    }

    return res;
}

int main() {
    vector<int> A1 = {10, 5, 2, 6};
    vector<int> A2 = {10, 5, 2, 6, 1000, 6, 7};
    vector<int> A3 = {10, 5, 2, 6, 100, 6, 7};
    vector<int> A4 = {10, 5, 99, 6, 7};
    vector<int> A5 = {1, 1, 1};

    cout << numSubarrayP(A1, 100) << endl;
    cout << numSubarrayP(A2, 100) << endl;
    cout << numSubarrayP(A3, 100) << endl;
    cout << numSubarrayP(A4, 100) << endl;
    cout << numSubarrayP(A5, 1)   << endl;

    return 0;
}