void heapify(vector<int> &A, int n, int i) {
    int root  = i;
    int left  = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && A[left] > A[root]) {
        root = left;
    }

    if (right < n && A[right] > A[root]) {
        root = right;
    }

    if (root != i) {
        swap(A[i], A[root]);
        heapify(A, n, root);
    }
}

void heapSort(vector<int> &A) {
    int n = A.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(A, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(A[0], A[i]);
        heapify(A, i, 0);
    }
}

int main() {
    vector<int> A = {15, 1, 7, 20, 15, 6, 100, 3, 5};

    heapSort(A);

    for (int i: A) {
        cout << i << ", ";
    }

    return 0;
}

