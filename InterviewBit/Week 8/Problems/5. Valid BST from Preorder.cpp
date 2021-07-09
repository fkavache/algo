int validBSTInternal(vector<int> &A, int s, int e) {
    if (s >= e) return true;

    int ns = e + 1;
    for (int i = s; i <= e; i++) {
        if (A[i] > A[s]) {
            ns = i;
            break;
        }
    }

    for (int i = ns + 1; i <= e; i++) {
        if (A[i] <= A[s]) return false;
    }

    int l = validBSTInternal(A, s + 1, ns - 1);
    int r = validBSTInternal(A, ns, e);

    return l && r;
}

int validBST1(vector<int> &A) {
    return validBSTInternal(A, 0, A.size() - 1);
}

int validBST2(vector<int> &A) {
    stack<int> s;
    int root = INT_MIN;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] <= root) return false;
        while (!s.empty() && A[i] > s.top()) {
            root = s.top();
            s.pop();
        }
        s.push(A[i]);
    }
    return true;
}

int main() {
    vector<int> A1 = {5, 3, 1, 4, 10, 6, 11};
    vector<int> A2 = {7, 7, 10, 10, 9, 5, 2, 8};
    vector<int> A3 = {5, 3, 1, 6, 10, 7, 11};
    vector<int> A4 = {5, 3, 1, 6, 10, 7, 9};
    vector<int> A5 = {52, 1000, 746, 222, 789, 81, 322, 456, 137, 89, 902, 978, 311, 610, 98, 53, 166, 355, 177, 336, 197};

    cout << validBST1(A1) << " 1 " << validBST2(A1) << endl;
    cout << validBST1(A2) << " 0 " << validBST2(A2) << endl;
    cout << validBST1(A3) << " 1 " << validBST2(A3) << endl;
    cout << validBST1(A4) << " 1 " << validBST2(A4) << endl;
    cout << validBST1(A5) << " 0 " << validBST2(A5) << endl;

    return 0;
}