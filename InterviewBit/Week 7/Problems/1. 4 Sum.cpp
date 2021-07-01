vector<vector<int>> fourSum(vector<int> &A, int B) {
    int n = A.size();

    set<vector<int>> sres;

    sort(A.begin(), A.end());

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int l = j + 1, r = n - 1;
            int target = B - (A[i] + A[j]);
            while (l < r) {
                if (A[l] + A[r] == target) {
                    sres.insert({A[i], A[j], A[l], A[r]});
                    l++, r--;
                } else if (A[l] + A[r] > target) {
                    r--;
                } else {
                    l++;
                }
            }
        }
    }

    return vector<vector<int>>(sres.begin(), sres.end());
}

int main() {
    vector<int> A = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> res = fourSum(A, 0);

    for (auto e: res) {
        for (int i:e) {
            cout << i << ", ";
        }
        cout << endl;
    }
    return 0;
}
