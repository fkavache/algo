int firstMissingPositive(vector<int> &A) {
    int n = A.size();

    for (int i = 0; i < n; i++) {
        if (A[i] > 0 && A[i] <= n) {
            int curr = A[i] - 1;
            if (A[curr] != A[i]) {
                swap(A[i], A[curr]);
                i--;
            }
        }
    }

    for (int i = 0; i < n; i++)
        if (A[i] != i + 1)
           return i + 1;

    return n + 1;
}

int main() {
    vector<int> A = { 6, 5, 10, 1, 2, 3, 4 };

    cout << firstMissingPositive(A) << endl;

    return 0;
}
