void combinationSumInternal(vector<int> &A, int B, int idx, vector<int> &sofar, vector<vector<int>> &res) {
    if (B < 0) return;
    if (B == 0) {
        res.push_back(sofar);
        return;
    }

    for (int i = idx; i < A.size(); i++) {
        sofar.push_back(A[i]);
        combinationSumInternal(A, B - A[i], i, sofar, res);
        sofar.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &A, int B) {
    vector<vector<int>> res;
    vector<int> sofar;

    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    combinationSumInternal(A, B, 0, sofar, res);

    return res;
}

int main() {
    vector<int> A = {7, 2, 3, 6};

    vector<vector<int>> res = combinationSum(A, 7);

    for (auto &e: res) {
        for (int i: e) {
            cout << i << ", ";
        }
        cout << endl;
    }

    return 0;
}
