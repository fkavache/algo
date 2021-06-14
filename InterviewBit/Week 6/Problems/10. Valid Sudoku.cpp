bool isValid(const vector<string> &A, int r, int c) {
    int rr = 0, cc = 0, dd = 0;
    for (int i = 0; i < A[0].size(); i++) {
        rr += A[r][i] == A[r][c];
        cc += A[i][c] == A[r][c];
        if (rr > 1 || cc > 1) return false;
    }

    rr = (r/3) * 3;
    cc = (c/3) * 3;
    for (int i = rr; i < rr + 3; i++) {
        for (int j = cc; j < cc + 3; j++) {
            dd += A[i][j] == A[r][c];
            if (dd > 1) return false;
        }
    }
    return true;
}

int isValidSudoku(const vector<string> &A) {
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[0].size(); j++) {
            if (A[i][j] != '.') {
                if (!isValid(A, i, j)) return false;
            }
        }
    }
    return true;
}

int main() {
    vector<string> A = {
        "53..7....",
        "6..195...",
        ".98....6.",
        "8...6...3",
        "4..8.3..1",
        "7...2...6",
        ".6....28.",
        "...419..5",
        "....8..79"
    };

    vector<string> B = {
        "....5..1.",
        ".4.3.....",
        ".....3..1",
        "8......2.",
        "..2.7....",
        ".15......",
        ".....2...",
        ".2.9.....",
        "..4......"
    };

    cout << isValidSudoku(A) << endl;
    cout << isValidSudoku(B) << endl;

    return 0;
}