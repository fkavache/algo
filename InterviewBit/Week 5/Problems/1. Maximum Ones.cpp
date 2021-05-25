int maximumOnes(vector<int> &A, int B) {
    int L   = 0;
    int R   = 0;
    int b   = B;
    int res = 0;
    while (R < A.size()) {
        if (A[R] == 0) {
            b--;
        }
        while (b < 0) {
            if (A[L] == 0) b++;
            L++;
        }
        res = max(res, R-L+1);
        R++;
    }

    return res;
}

int main() {
    vector<int> A1 = {1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1};
    vector<int> A2 = {1, 0, 0, 1, 1, 0, 1};
    vector<int> A3 = {1, 0, 0, 1, 0, 1, 0, 1, 0, 1};
    vector<int> A4 = {0, 0, 1, 0};
    cout << maximumOnes(A1, 0) << endl;
    return 0;
}