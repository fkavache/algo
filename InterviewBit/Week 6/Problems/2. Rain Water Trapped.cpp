int trap(const vector<int> &A) {
    int n = A.size();
    int resb = 0, rese = 0;
    int maxb = 0, maxe = 0;

    for (int i = 0; i < n; i++) {
        maxb = max(maxb, A[i]);
        resb += maxb - A[i];
    }

    for (int i = n-1; i >= 0; i--) {
        maxe = max(maxe, A[i]);
        rese -= maxb - maxe;
    }

    return resb + rese;
}

int main() {
    vector<int> A = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    cout << trap(A) << endl;

    return 0;
}
