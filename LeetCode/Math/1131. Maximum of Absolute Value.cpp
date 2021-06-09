int maxAbsInternal(vector<int>& A, vector<int>& B) {
    int n = A.size();

    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN, max4 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX, min3 = INT_MAX, min4 = INT_MAX;

    for (int i = 0; i < n; i++) {
        max1 = max(max1, (A[i] + B[i] + i));
        max2 = max(max2, (A[i] + B[i] - i));
        max3 = max(max3, (A[i] - B[i] + i));
        max4 = max(max4, (A[i] - B[i] - i));

        min1 = min(min1, (A[i] + B[i] + i));
        min2 = min(min2, (A[i] + B[i] - i));
        min3 = min(min3, (A[i] - B[i] + i));
        min4 = min(min4, (A[i] - B[i] - i));
    }

    return max(max(max(max1 - min1, max2 - min2), max3 - min3), max4 - min4);
}

int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
    return maxAbsInternal(arr1, arr2);
}

int main() {
//    vector<int> A = {1, 2, 3, 4};
//    vector<int> B = {-1, 4, 5, 6};

    vector<int> A = {1, -2, -5, 0, 10};
    vector<int> B = {0, -2, -1, -7, -4};

    cout << maxAbsValExpr(A, B);

    return 0;
}
