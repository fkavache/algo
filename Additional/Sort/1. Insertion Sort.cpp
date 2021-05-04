void insertionSort(vector<int> &A) {
    for (int i = 1; i < A.size(); i++) {
        int value = A[i];
        int index = i-1;
        while (index >= 0 && A[index] > value) {
            A[index + 1] = A[index];
            index--;
        }
        A[index + 1] = value;
    }
}

int main() {
    vector<int> A = {5, 2, -10, 5, 33, 6, 7};

    insertionSort(A);

    for (int i : A) {
        cout << i << ", ";
    }
    cout << endl;

    return 0;
}
