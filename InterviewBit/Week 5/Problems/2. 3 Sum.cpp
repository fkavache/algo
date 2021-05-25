#define ll long long

int threeSumClosest(vector<int> &A, int B) {
    int n = A.size();

    ll resT = LLONG_MAX;
    ll res = -1;

    sort(A.begin(), A.end());
    for (int i = 0; i < n; i++) {
        int l = i + 1;
        int r = n - 1;
        while (l < r) {
            ll sum = A[i] + A[l] + A[r];
            if (B > sum) l++;
            else r--;
            if (abs(B - sum) < resT) {
                resT = abs(B - sum);
                res = sum;
            }
        }
    }

    return (int) res;
}

int main() {
    vector<int> A1 = {-10, -10, -10};
    vector<int> A2 = {-4, -1, 1, 2};
    vector<int> A3 = {2147483647, -2147483648, -2147483648, 0, 1};

    cout << threeSumClosest(A2, 1) << endl;
    return 0;
}