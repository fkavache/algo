void partitionSwap(vector<int> &A, int i, int j) {
    int tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}

int partition(vector<int> &A, int i, int j) {
    int p     = A[j];
    int p_idx = i;

    for (int k = i; k < j; k++) {
        if (A[k] <= p) {
            partitionSwap(A, k, p_idx);
            p_idx++;
        }
    }
    partitionSwap(A, j, p_idx);

    return p_idx;
}

void quickSortInternal(vector<int> &A, int i, int j) {
    if (i < j) {
        int idx = partition(A, i, j);
        quickSortInternal(A, i, idx - 1);
        quickSortInternal(A, idx + 1, j);
    }
}

void quickSort(vector<int> &A) {
    return quickSortInternal(A, 0, A.size() - 1);
}

int main() {
    vector<int> A = {5, 2, -10, 5, 33, 6, 7};

    quickSort(A);

    for (int i : A) {
        cout << i << ", ";
    }
    cout << endl;

    return 0;
}
