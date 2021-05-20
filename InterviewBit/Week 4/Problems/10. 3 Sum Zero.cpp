#define ll long long int

vector<vector<int>> threeSum(vector<int> &A) {
    int n = A.size();

    set<vector<int>> res;

    sort(A.begin(), A.end());

    for (int i = 0; i < n; i++) {
        int l = i + 1;
        int r = n - 1;
        while (l < r) {
            ll sum = (ll) A[i] + (ll) A[l] + (ll) A[r];
            if (sum == 0) {
                res.insert({A[i], A[l], A[r]});
                l++;
                r--;
            } else if (sum > 0) {
                r--;
            } else if (sum < 0) {
                l++;
            }
        }
    }

    vector<vector<int>> rres;
    for (auto &i: res) rres.push_back(i);

    return rres;
}

int main() {
    vector<int> A1 = {-1, 0, 1, 2, -1, -4};
    vector<int> A2 = {1, -4, 0, 0, 5, -5, 1, 0, -2, 4, -4, 1, -1, -4, 3, 4, -1, -1, -3};
    vector<int> A3 = {2147483647, -2147483648, -2147483648, 0, 1 };

    vector<vector<int>> res = threeSum(A1);

    for (auto &re : res) {
        for (int j : re) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}