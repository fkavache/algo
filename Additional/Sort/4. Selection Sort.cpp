void selectionSortSwap(vector<int> &A, int i, int j) {
    int tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}

void selectionSort(vector<int> &A) {
    for (int i = 0; i < A.size(); i++) {
        int min_idx = i;
        for (int j = i + 1; j < A.size(); j++) {
            if (A[j] < A[min_idx]) {
                min_idx = j;
            }
        }
        selectionSortSwap(A, i, min_idx);
    }
}

int main() {
    vector<int> A = {5, 2, -10, 5, 33, 6, 7};

    selectionSort(A);

    for (int i : A) {
        cout << i << ", ";
    }
    cout << endl;

    return 0;
}

