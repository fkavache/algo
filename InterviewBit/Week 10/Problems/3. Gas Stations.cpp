int canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    int n = A.size();

    vector<int> stations(2 * n);

    for (int i = 0; i < n; i++) {
        stations[i] = A[i] - B[i];
        stations[i + n] = stations[i];
    }

    int res = -1;
    int sum = 0;
    int l   = 0;
    for (int i = 0; i < 2 * n; i++) {
        sum += stations[i];
        if (sum < 0) {
            sum = 0;
            l = i + 1;
        }

        if (i - l >= n) {
            res = l;
            break;
        }
    }

    return res;
}

int main() {
    vector<int> A = {1, 2, 3, 4, 5};
    vector<int> B = {3, 4, 5, 1, 2};

    cout << canCompleteCircuit(A, B) << endl;

    return 0;
}