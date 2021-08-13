int maxp3(vector<int> &A) {
    int n = A.size();

    sort(A.begin(), A.end(), greater<int>());

    int prod = A[0] * A[1] * A[2];
    int max1 = max(prod, A[0] * A[n - 1] * A[n - 2]);
    int max2 = (n - 2 <= 1) ? max1 : max(max1, A[1] * A[n - 1] * A[n - 2]);
    int max3 = (n - 2 <= 2) ? max2 : max(max2, A[2] * A[n - 1] * A[n - 2]);

    return max3;
}

int main() {
    vector<int> A1 = {0, -1, 3, -100, -70, -50};
    vector<int> A2 = {1, 2, -3};

    cout << maxp3(A1) << endl;
    cout << maxp3(A2) << endl;

    return 0;
}