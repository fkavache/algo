bool isValid(vector<string> sofar, int r, int c, int A) {
    for (int i = 0; i < sofar.size(); i++) {
        string curr = sofar[i];
        int d1 = c + (r - i);
        int d2 = c - (r - i);
        if ((d1 < A  && curr[d1] == 'Q')
         || (d2 >= 0 && curr[d2] == 'Q')
         || curr[c] == 'Q') {
            return false;
        }
    }
    return true;
}

void solveNQueensInternal(int A, vector<vector<string>> &res, vector<string> sofar) {
    if (sofar.size() == A) {
        res.push_back(sofar);
        return;
    }

    for (int i = 0; i < A; i++) {
        if (isValid(sofar, sofar.size(), i, A)) {
            sofar.push_back(string(i, '.') + "Q" + string(A - i - 1, '.'));
            solveNQueensInternal(A, res, sofar);
            sofar.pop_back();
        }
    }
}

vector<vector<string>> solveNQueens(int A) {
    vector<vector<string>> res;

    solveNQueensInternal(A, res, {});

    return res;
}

int main() {
    vector<vector<string>> res = solveNQueens(4);

    for (auto &e: res) {
        for (auto &s: e) {
            cout << s << endl;
        }
        cout << endl;
    }
    return 0;
}

