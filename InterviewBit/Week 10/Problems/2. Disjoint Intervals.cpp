int disjointIntervals(vector<vector<int>> &A) {
    sort(A.begin(), A.end());

    int res = 0;
    int l = 0;
    int r = 1;

    while (r < A.size()) {
        if (A[l][1] < A[r][0]) {
            l = r; r++;
        } else if (A[r][1] >= A[l][1]) {
            r++;
            res++;
        } else if (A[r][1] <= A[l][1]) {
            l = r; r++;
            res++;
        }
    }

    return A.size() - res;
}

bool compare(vector<int> &i1, vector<int> &i2) {
    return i1[1] < i2[1];
}

int disjointIntervals2(vector<vector<int>> &A) {
    sort(A.begin(), A.end(), compare);

    int res = 1;
    vector<int> prev = A[0];
    for (int i = 1; i < A.size(); i++) {
        if (A[i][0] > prev[1]) {
            res++;
            prev = A[i];
        }
    }

    return res;
}

int main() {
    vector<vector<int>> A = {
            {1, 4},
            {2, 3},
            {4, 6},
            {8, 9},
    };

    cout << disjointIntervals2(A) << endl;

    return 0;
}