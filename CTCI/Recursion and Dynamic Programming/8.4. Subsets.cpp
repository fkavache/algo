void subsets(vector<int> &A, vector<int> &sofar, int i, vector<vector<int>> &res) {
    if (i == A.size()){
        res.push_back(sofar);
        return;
    }

    sofar.push_back(A[i]);
    subsets(A, sofar, i + 1, res);

    sofar.pop_back();
    subsets(A, sofar, i + 1, res);
}

// o(2^n) - time
// o(n)   - space
vector<vector<int>> subsets(vector<int> &A) {
    vector<vector<int>> res;
    vector<int> sofar;

    subsets(A, sofar, 0, res);

    return res;
}

int main() {
    vector<int> A = {1, 2, 3};

    vector<vector<int>> res = subsets(A);

    for (auto arr: res) {
        for (auto e: arr) {
            cout << e << ",";
        }
        cout << endl;
    }

    return 0;
}
