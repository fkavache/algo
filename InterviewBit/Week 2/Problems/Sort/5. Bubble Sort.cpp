void bubbleSortSwap(vector<int> &A, int i, int j) {
    int tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}

void bubbleSort(vector<int> &A) {
    int done = false;

    while (!done) {
        int i = 0;
        done = true;
        while (i < A.size() - 1) {
            if (A[i] > A[i + 1]) {
                bubbleSortSwap(A, i, i + 1);
                done = false;
            }
            i++;
        }
    }
}
int main() {
    vector<int> A = {5, 2, -10, 5, 33, 6, 7};

    bubbleSort(A);

    for (int i : A) {
        cout << i << ", ";
    }
    cout << endl;

    return 0;
}
