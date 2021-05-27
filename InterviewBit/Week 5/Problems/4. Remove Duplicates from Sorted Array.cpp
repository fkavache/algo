int removeDuplicates(vector<int> &A) {
    int l = 0, r = 1;
    while (l < A.size() && r < A.size()) {
        if (A[r] == A[r-1]) {
            r++;
        } else if (r - l > 2) {
            A.erase(A.begin() + l + 2, A.begin() + r);
            l =  r - (r - l - 2);
            r = l + 1;
        } else {
            l = r;
            r++;
        }
    }

    if (l + 2 < A.size())
        A.erase(A.begin() + l + 2, A.end());

    return A.size();
}

int main() {
    vector<int> A = {1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 5, 5, 5, 5, 5};
//    vector<int> A = {0, 0, 0, 1, 1, 2, 2, 3};
    cout << removeDuplicates(A) << endl;

    for (int i: A) {
        cout << i << ", ";
    }
    return 0;
}