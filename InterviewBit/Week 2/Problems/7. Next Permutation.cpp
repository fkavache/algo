void swap(vector<int> &A, int i, int j) {
    int tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}

vector<int> nextPermutation(vector<int> &A) {
    int n = A.size();
    for (int i = n - 1; i > 0; i--) {
        if (A[i] > A[i - 1]) {
            for (int j = n - 1; j >= i; j--) {
                if (A[j] > A[i - 1]) {
                    swap(A, i-1, j);
                    sort(A.begin() + i, A.end());
                    return A;
                }
            }
        }
    }

    sort(A.begin(), A.end());

    return A;
}

void printPermutation(vector<int> &A){
    nextPermutation(A);

    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << ", ";
    }

    cout << endl;
}

int main() {
    vector<int> A = {1, 2, 3, 4, 5, 6};

    for (int i = 0; i < 1; i++) {
        printPermutation(A);
    }

    return 0;
}
