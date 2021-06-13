void subsetsInternal(int idx, vector<int> &A, vector<int> &sofar, vector<vector<int>> &res) {
    int n  = A.size();

    res.push_back(sofar);
    for (int i = idx; i < n; i++) {
        sofar.push_back(A[i]);
        subsetsInternal(i + 1, A, sofar, res);
        sofar.pop_back();
    }
}

vector<vector<int>> subsets(vector<int> &A) {
    vector<vector<int>> res;
    vector<int> sofar;

    sort(A.begin(), A.end());
    subsetsInternal(0, A, sofar, res);

    return res;
}

int main() {
    vector<int> A = {4, 1, 2, 3};

    vector<vector<int>> res = subsets(A);

    for (auto &e: res) {
        for (int i: e) {
            cout << i << ", ";
        }
        cout << endl;
    }

    return 0;
}
