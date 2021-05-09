int findMinXor(vector<int> &A) {
    sort(A.begin(), A.end());

    int res = INT_MAX;
    for (int i = 0; i < A.size() - 1; i++) {
        res = min(res, A[i] ^ A[i + 1]);
    }

    return res;
}

int main() {
    vector<int> A = {10, 7, 33, 44, 55, 66, 77, 88, 99, 111};
    cout << findMinXor(A) << endl;
    return 0;
}