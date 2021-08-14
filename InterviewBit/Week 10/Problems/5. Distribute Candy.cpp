int candy(vector<int> &A) {
    int n = A.size();
    int res = 0;
    vector<int> left(n, 1);
    vector<int> right(n, 1);

    for (int i = 1; i < n; i++) {
        if (A[i] > A[i - 1]) {
            left[i] = left[i - 1] + 1;
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        if (A[i] > A[i + 1]) {
            right[i] = right[i + 1] + 1;
        }
    }

    for (int i = 0; i < n; i++) {
        res += max(left[i], right[i]);
    }

    return res;
}

int main() {
    vector<int> A = {1, 5, 2, 1};

    cout << candy(A) << endl;

    return 0;
}