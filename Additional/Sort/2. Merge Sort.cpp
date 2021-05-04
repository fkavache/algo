void merge(vector<int> &A, int i, int mid, int j) {
    vector<int> merged;
    int         m_i = i;
    int         m_j = mid+1;

    while (m_i <= mid && m_j <= j) {
        if (A[m_i] < A[m_j]) {
            merged.push_back(A[m_i]);
            m_i++;
        } else {
            merged.push_back(A[m_j]);
            m_j++;
        }
    }

    while (m_j <= j) {
        merged.push_back(A[m_j]);
        m_j++;
    }

    while (m_i <= mid) {
        merged.push_back(A[m_i]);
        m_i++;
    }

    for (int k = 0; k < merged.size(); k++) {
        A[k + i] = merged[k];
    }
}

void mergeSortInternal(vector<int> &A, int i, int j) {
    if (i == j) {
        return;
    }

    int mid = (i + j) / 2;
    mergeSortInternal(A, i, mid);
    mergeSortInternal(A, mid + 1, j);
    merge(A, i, mid, j);
}

void mergeSort(vector<int> &A) {
    mergeSortInternal(A, 0, A.size() - 1);
}

int main() {
    vector<int> A = {5, 2, -10, 5, 33, 6, 7};

    mergeSort(A);

    for (int i : A) {
        cout << i << ", ";
    }
    cout << endl;

    return 0;
}
