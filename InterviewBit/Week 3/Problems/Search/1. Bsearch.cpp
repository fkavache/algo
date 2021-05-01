int bsearch(vector<int> &A, int i, int j, int val) {
    int n = j - i;
    if (n < 0) {
        return  -1;
    }

    int idx = i + n / 2;
    if (A[idx] == val) {
        return idx;
    }

    return val > A[idx] ? bsearch(A, idx + 1, j, val) : bsearch(A, i, idx - 1, val);
}

int bsearch2(vector<int> &A, int val) {
    int n = A.size();
    int l = 0;
    int h = n-1;
    while (l <= h) {
        int idx = l + (h-l) / 2;
        int mid = A[idx];
        if (mid == val) {
            return idx;
        }
        l = val > mid ? idx + 1 : l;
        h = val > mid ? h : idx - 1;
    }

    return -1;
}

int main() {
    vector<int> A = {1, 2, 30, 40, 50, 600, 700};

    cout << bsearch2(A, 700) << endl;

    return 0;
}
