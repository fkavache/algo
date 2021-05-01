int maxArr(vector<int> &A) {
    int max1 = INT_MIN;
    int min1 = INT_MAX;
    int max2 = INT_MIN;
    int min2 = INT_MAX;

    for (int i = 0; i < A.size(); i++) {
        max1 = max(max1, A[i] + i);
        min1 = min(min1, A[i] + i);

        max2 = max(max2, A[i] - i);
        min2 = min(min2, A[i] - i);
    }

    return max(max1 - min1, max2 - min2);
}

int main() {
    vector<int> A = {1, 3, -1};

    cout << maxArr(A) << endl;

    return 0;
}
